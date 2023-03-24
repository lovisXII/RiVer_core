#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include "elfio/elfio.hpp"
#include "systemc.h"
#include "include/colors.h"
#include <sys/stat.h>  // mkdir
#include <verilated.h>
#include "Vcore.h"
#define MAX_CYCLES 2000000
#if VM_TRACE
#include <verilated_vcd_sc.h>
#endif

using namespace std;
using namespace ELFIO;

enum error_type {HELP = 0, ARG_MISS = 1, OV_CYCLES, DEBUG};

void helper(int error){
    cout << endl << endl;
    if(error == ARG_MISS){
        cerr << "[Error] Wrong or missing argument" << endl;
        cerr << "[info] run --help to see the options" << endl ;
    }
    else if (error == OV_CYCLES){
        cerr << "[Error] Number of cycles for simulation exceed, maximum is";
        cerr << MAX_CYCLES << endl;
    }
    else if(error == HELP){
        cerr << "Usage: obj_dir/Vcore test_filename [options] ..." << endl;
        cerr << "file_name type accepted are .s, .S, .c or elf file" << endl;
        cerr << "Options:" << endl << endl;
        cerr << "-O                          \t Compile test_filename with -O option" << endl;
        cerr << "--riscof signature_filename \t Allow to enable the riscof gestion and store the signature in the file named signature_filename" << endl ;
        cerr << "--riscof signature_filename --debug \t Allow to visualise all the store made by the cpu" << endl;
        cerr << "--stats                     \t Allow to use the statistic such as the number of cycle needed to end the program" << endl;
    }
    else if(error == DEBUG)
    {
        cerr << "[Error] Please enter a valide option" << endl;
        cerr << "[info] run --help to see the options" << endl ;
    }
    exit(1);
}

void cleanup(Vcore &core, VerilatedVcdSc *tf, int retval){
     // Final model cleanup
    core.final();
    // Close trace if opened
    if (tf) {
        tf->close();
        tf = nullptr;
    }
    // Coverage analysis (calling write only after the test is known to pass)
    #if VM_COVERAGE
        Verilated::mkdir("logs");
        VerilatedCov::write("logs/coverage.dat");
    #endif
    exit(retval);
}

int sc_main(int argc, char* argv[]) {

    /*
    ##############################################################
                    Checking main arguments 
    ##############################################################
    */
    if(argc < 2){
        helper(ARG_MISS);
    }
    
    // Compiling options 

    bool                    debug = false;
    string                  opt;
    bool                    riscof = false;
    bool                    stats = false ;

    // Addresses and sections
    int                     reset_adr;
    int                     start_adr;
    int                     good_adr;
    int                     exception_occur ;
    int                     bad_adr;
    int                     rvtest_code_end     = 0xFFFFFFFF;
    int                     rvtest_entry_point  = 0xFFFFFFFF;
    int                     begin_signature;
    int                     end_signature;
    int                     rvtest_end          = 0xFFFFFFFF;

    // Files settings

    fstream                 test_stats;
    string                  signature_name;
    string                  filename_stats;
    string                  test_filename(argv[1]);
    string                  path(argv[1]);
    char                    test[512] = "> a.out.txt.s";
    
    // Ram and elfio object

    unordered_map<int, int> ram;
    elfio                   reader;  
    cout << argc << endl;
    if(argc == 2){
        if(std::string(argv[1]) == "--help")
            helper(HELP);
    }
    else if (argc >= 3 && std::string(argv[2]) == "-O") {
        opt = "-O2";
    } 
    else if (argc >= 4 && std::string(argv[2]) == "--riscof") {
        cout << "riscof" << endl;
        if(argc == 5 && string(argv[4]) == "--debug")
            debug = true;
        else if(argc == 5 && string(argv[4]) != "--debug")
            helper(DEBUG);
        signature_name          = string(argv[3]);
        riscof                  = true;
        stats                   = true;

        int tmp                 = test_filename.find("src/");
        int tmp2                = test_filename.find("dut/");

        string tempo_string     = test_filename.substr(0,tmp);
        string tempo_string2    = test_filename.substr(0,tmp2);
        int tmp3                = tempo_string2.size() - (tempo_string.size() + 4);

        test_filename           = test_filename.substr(tmp+4, tmp3); 
        filename_stats          = "stats.txt";
        test_stats.open(filename_stats, fstream::app);
        
        if(!test_stats.is_open())
        {
            cout << "Impossible to open " << filename_stats << endl ;
            exit(1);
        }
    } 
    else if(argc >= 3 && std::string(argv[2]) == "--stats")
    {
        stats                   = true;
        int tmp                 = test_filename.rfind("/");
        test_filename           = test_filename.substr(tmp+1, test_filename.size());
        filename_stats          = "test_stats.txt";
        test_stats.open(filename_stats, fstream::app);

        if(!test_stats.is_open())
        {
            cout << "Impossible to open " << filename_stats << endl ;
            exit(1);
        }
    }
    else{
        helper(ARG_MISS);
    }

    /*
    ##############################################################
                    Waves setup 
    ##############################################################
    */

    // trace file settings
    Verilated::mkdir("logs");
    Verilated::traceEverOn(true);
    VerilatedVcdSc* tfp     = nullptr;
    tfp                     = new VerilatedVcdSc;
    
    // Core instanciation
    Vcore core_inst("core_inst");

    (riscof) ? cout << "[info] riscof enable" << endl : cout << "[info] riscof disable" << endl; 
/*
    ##############################################################
                    PARSING ELF/.s/.c file 
    ##############################################################
*/
    char temp_text[512];
    string extension           = path.substr(path.find_last_of(".") + 1) ; 
    
    if (extension == "s" || extension == "S" || extension == "c") {  
        char temp[512];
        sprintf(temp,
                "riscv32-unknown-elf-gcc -nostdlib -march=rv32im -T ../sw/app.ld %s %s",
                opt.c_str(),
                path.c_str());          
        system((char*)temp);    
        path = "a.out";         
    }
    if (!reader.load(path)) {  
        std::cout << "Can't find or process ELF file " << argv[1] << std::endl;
        return -3;
    }
    sprintf(temp_text, "riscv32-unknown-elf-objdump -D %s", path.c_str());
    strcat(temp_text, test);
    system((char*)temp_text);

    cout << "Loading ELF file..." << endl;
    int n_sec = reader.sections.size();  // get the total amount of sections

/*
    ##############################################################
                    PLACING DATA INTO THE RAM 
    ##############################################################
*/

    for (int i = 0; i < n_sec; i++) {
        section* sec = reader.sections[i];
        cout << "Section " << sec->get_name() << " at address 0x" << std::hex << sec->get_address() << endl;
        int  adr  = sec->get_address();
        int  size = sec->get_size();
        int* data = (int*)sec->get_data();
        if (adr) {
            cout << "Loading data";
            for (int j = 0; j < size; j += 4) {
                cout << ".";
                ram[adr + j] = data[j / 4]; 
            }
            cout << endl;
        }

/*
    ##############################################################
                    LOOKING FOR SECTIONS IN ELF FILE 
    ##############################################################
*/

        if (sec->get_type() == SHT_SYMTAB) {
            cout << "Reading symbols table..." << endl;
            const symbol_section_accessor symbols(reader, sec);

            for (unsigned int j = 0; j < symbols.get_symbols_num(); ++j) {
                std::string   name;
                Elf64_Addr    value;
                Elf_Xword     size;
                unsigned char bind;
                unsigned char type;
                Elf_Half      section_index;
                unsigned char other;

                symbols.get_symbol(j, name, value, size, bind, type, section_index, other);

                if (name == "_reset") {
                    reset_adr = value ;  
                    cout << "Found reset at address 0x" << std::hex << reset_adr << endl;
                }
                if (name == "_start") {
                    start_adr = value - 4;  
                    cout << "Found start at address 0x" << std::hex << start_adr << endl;
                }
                if (name == "_bad") {
                    bad_adr = value;
                    cout << "Found bad at address 0x" << std::hex << bad_adr << endl;
                }
                if (name == "_good") {
                    good_adr = value;
                    cout << "Found good at address 0x" << std::hex << good_adr  << endl;
                }
                if (name == "_exception_occur") {
                    exception_occur = value;
                    cout << "Found exception_occur at address 0x" << std::hex << exception_occur << endl;
                }
                if (name == "rvtest_code_end") {
                    rvtest_code_end = value;
                    cout << "Found rvtest_code_end at address 0x" << std::hex << rvtest_code_end << endl;
                }
                if (name == "rvtest_entry_point") {
                    reset_adr = value ;
                    cout << "Found rvtest_entry_point at address 0x" << std::hex << reset_adr << endl;
                }
                if (name == "begin_signature") {
                    begin_signature = value;
                    cout << "Found begin_signature at address 0x" << std::hex << begin_signature << endl;
                }
                if (name == "end_signature") {
                    end_signature = value;
                    cout << "Found end_signature at address 0x" << std::hex << end_signature << endl;
                }
                if (name == "rvtest_end") {
                    rvtest_end = value;
                    cout << "Found rvtest_end at address 0x " << std::hex << rvtest_end << endl;
                }
            }
        }
    }

/*
    ##############################################################
                    COMPONENT INSTANCIATION
    ##############################################################
*/


    core_inst.trace(tfp, 99);  // Trace 99 levels of hierarchy
    Verilated::mkdir("logs");
    tfp->open("logs/vlt_dump.vcd");
    
    sc_clock        clk("clk", 1, SC_NS);
    sc_signal<bool> reset_n;

    sc_signal<bool> MCACHE_STALL_SM;        // mem need to stall
    sc_signal<bool> MCACHE_ADR_VALID_SM;    // address send by mem is valid
    sc_signal<bool> MCACHE_STORE_SM;        // access is a store
    sc_signal<bool> MCACHE_LOAD_SM;         // access is a load
    sc_signal<uint32_t> byt_sel;            // tells what part of the data to consider
    
    sc_signal<bool> IC_STALL_SI;            // Ifetch stall
    sc_signal<bool> ADR_VALID_SI;           // send by ifetch is valid

    sc_signal<uint32_t> MCACHE_RESULT_SM;   // data send by data cache
    sc_signal<uint32_t> MCACHE_DATA_SM;     // data send by mem to be stored
    sc_signal<uint32_t> MCACHE_ADR_SM;      // address for the access

    sc_signal<uint32_t> IC_INST_SI;         // instruction
    sc_signal<uint32_t> ADR_SI;             // PC from ifetch
    sc_signal<uint32_t> PC_INIT;            // tells if pc if valid
    sc_signal<uint32_t> DEBUG_PC_READ;

    core_inst.clk(clk);
    core_inst.reset_n(reset_n);

    core_inst.MCACHE_STALL_SM(MCACHE_STALL_SM);
    core_inst.MCACHE_ADR_VALID_SM(MCACHE_ADR_VALID_SM);
    core_inst.MCACHE_STORE_SM(MCACHE_STORE_SM);
    core_inst.MCACHE_LOAD_SM(MCACHE_LOAD_SM);
    core_inst.byt_sel(byt_sel);
    
    core_inst.IC_STALL_SI(IC_STALL_SI);
    core_inst.ADR_VALID_SI(ADR_VALID_SI);
    
    core_inst.MCACHE_RESULT_SM(MCACHE_RESULT_SM);
    core_inst.MCACHE_DATA_SM(MCACHE_DATA_SM);
    core_inst.MCACHE_ADR_SM(MCACHE_ADR_SM);
    
    core_inst.IC_INST_SI(IC_INST_SI);
    core_inst.ADR_SI(ADR_SI);
    core_inst.PC_INIT(PC_INIT);
    core_inst.DEBUG_PC_READ(DEBUG_PC_READ);



    cout << "Reseting...";

    reset_n.write(false);  
    PC_INIT.write(reset_adr);

    sc_start(3, SC_NS);
    reset_n.write(true);   
    
    cerr << "done." << endl;

    int NB_CYCLES = 0;

    int if_adr;
    int if_result;
    int mem_adr;
    int mem_size;

    // Use to let the time to riscof to execute the last instruction
    // When it arrives to the end of the code it will start the countdown before exiting

    int countdown = 100 ;
    bool start_countdown = false;

    while (1) 
    {

        if(start_countdown)
            countdown --;

        // mem interface
        mem_adr       = MCACHE_ADR_SM.read() & 0XfffffffC; // removing the least 2 significant bits
        mem_size      = byt_sel.read() ;
        bool         mem_adr_valid = MCACHE_ADR_VALID_SM.read();

        unsigned int mem_data      = MCACHE_DATA_SM.read();
        bool         mem_store     = MCACHE_STORE_SM.read();
        bool         mem_load      = MCACHE_LOAD_SM.read();
        
        unsigned int mem_result;
        // Ifetch interface
        if_adr       = ADR_SI.read();
        bool         if_afr_valid = ADR_VALID_SI.read();


/*
    ##############################################################
                    END OF TEST GESTION
    ##############################################################
*/

        unsigned int pc_adr = ADR_SI.read();
        NB_CYCLES = sc_time_stamp().to_double()/1000;
        
        if(NB_CYCLES > MAX_CYCLES){
            // Final model cleanup
            core_inst.final();
            // Close trace if opened
            if (tfp) {
                tfp->close();
                tfp = nullptr;
            }
            // Coverage analysis (calling write only after the test is known to pass)
            #if VM_COVERAGE
                Verilated::mkdir("logs");
                VerilatedCov::write("logs/coverage.dat");
            #endif
            helper(OV_CYCLES);
        }
        // starting the countdown
        if(!riscof && !start_countdown && signature_name == "" && (pc_adr == bad_adr || pc_adr == good_adr 
        || pc_adr == exception_occur && if_afr_valid)){
            cout << "Reaching ending point, starting countdown" << endl;
            start_countdown = true;
        }    
        // riscof :   
        else if(((riscof && !start_countdown && pc_adr == rvtest_code_end) || (pc_adr ==  rvtest_end)) && if_afr_valid){
            cout << "Reaching ending point, starting countdown" << endl;
            start_countdown = true;
        }

        // Exciting when countdown reach 0 
        if(!riscof && countdown == 0){
            cout << "countdown reach 0"<<endl;
            if (signature_name == "" && (pc_adr == bad_adr || pc_adr == bad_adr +4)) {
                cout << FRED("Error ! ") << "Found bad at adr 0x" << std::hex << pc_adr << endl;
                sc_start(3, SC_NS);
                cleanup(core_inst, tfp,1);
            } 
            else if(signature_name == "" && (pc_adr == exception_occur || pc_adr == exception_occur +4)){
                cout << FYEL("Error ! ") << "Found exception_occur at adr 0x" << std::hex << pc_adr << endl;
                sc_start(3, SC_NS);
                cleanup(core_inst, tfp, 2);
            }
            else if (signature_name == "" && (pc_adr == good_adr || pc_adr == good_adr +4)) {
                if(stats)
                {
                    test_stats << test_filename << " " << NB_CYCLES  << " " << "SCALAR" << endl;
                    test_stats.close();
                }
                
                cout << FGRN("Success ! ") << "Found good at adr 0x" << std::hex << pc_adr << endl;
                sc_start(3, SC_NS);
                cleanup(core_inst, tfp, 0);
            } 
        }
        else if (riscof && countdown == 0)
        {
            cout << "Test ended at " << std::hex << pc_adr << endl;
            sc_start(3, SC_NS);

            // Stats Gestion riscof
            test_stats << test_filename << " " << NB_CYCLES  << " " << "SCALAR" << endl;
            test_stats.close();
            
            
            ofstream signature;
            signature.open(signature_name, ios::out | ios::trunc);
            cout << "signature_name :" << signature_name << endl ;
            cout << "begin_signature :" << begin_signature << endl ;
            cout << "end_signature :" << end_signature << endl ;
           
            for (int i = begin_signature; i < end_signature; i += 4) {
                signature << setfill('0') << setw(8) << hex << ram[i] << endl;
            }
            cleanup(core_inst, tfp, 0);
        }

/*
    ##############################################################
                    MEMORY ACCESS GESTION
    ##############################################################
*/

  if (mem_store && mem_adr_valid) {
            switch (mem_size)
            {
            case 1 :
                ram[mem_adr] = (ram[mem_adr] & 0xFFFFFF00) | (MCACHE_DATA_SM.read() & ~(0xFFFFFF00));
                break;
            case 2:
                ram[mem_adr] = (ram[mem_adr] & 0xFFFF00FF) | ((MCACHE_DATA_SM.read() << 8) & ~(0xFFFF00FF));
                break;
            case 4:
                ram[mem_adr] = (ram[mem_adr] & 0xFF00FFFF) | ((MCACHE_DATA_SM.read() << 16) & ~(0xFF00FFFF));   
                break;
            case 8:
                ram[mem_adr] = (ram[mem_adr] & 0x00FFFFFF) | ((MCACHE_DATA_SM.read() << 24) & ~(0x00FFFFFF));  
                break;
            // store half word 
            case 3:
                ram[mem_adr] = (ram[mem_adr] & 0xFFFF0000) | (MCACHE_DATA_SM.read() & ~(0xFFFF0000));   
                break;
            case 12:
                ram[mem_adr] = (ram[mem_adr] & 0x0000FFFF) | ((MCACHE_DATA_SM.read() << 16) & ~(0x0000FFFF));
                break;
            // store word
            case 15:  
                ram[mem_adr] = MCACHE_DATA_SM.read();
                break;
            default:
                break;
            }
        if(debug)
            cout << FBLU("[Debug] ") << "0x" << std::hex << mem_adr << " : "<< std::hex << MCACHE_DATA_SM.read() << endl;
}
            
        mem_result = ram[mem_adr];
        MCACHE_RESULT_SM.write(mem_result);
        MCACHE_STALL_SM.write(false);
        IC_INST_SI = ram[if_adr];
        IC_STALL_SI.write(false);

        sc_start(500, SC_PS);
}
    return 0;
}