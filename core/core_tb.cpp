#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include "elfio/elfio.hpp"
#include "systemc.h"
#include "include/colors.h"

// Include common routines
#include <verilated.h>
#if VM_TRACE
#include <verilated_vcd_sc.h>
#endif

#include "Vcore.h"

using namespace std;
using namespace ELFIO;


int sc_main(int argc, char* argv[]) {
    unordered_map<int, int> ram;
    elfio                   reader;  // creation of an elfio object

    if(argc < 2){
        cerr << "First argument must be a .S, .s or .c file, please use --help" << endl;
        exit(0);
    }
    string                  test_filename(argv[1]);
    string                  path(argv[1]);
    int                     reset_adr;
    int                     start_adr;
    int                     good_adr;
    int                     exception_occur ;
    int                     bad_adr;
    int                     rvtest_code_end;
    int                     rvtest_entry_point;
    int                     begin_signature;
    int                     end_signature;
    int                     rvtest_end;

    fstream test_stats;
    string filename_stats;

    char   test[512] = "> a.out.txt.s";
    string opt;
    string signature_name;
    bool   riscof;
    bool   stats;
/*
    ##############################################################
                    PARSING ELF/.s/.c file 
    ##############################################################
*/
    if(argc == 2 && std::string(argv[1]) == "--help"){
        cout << endl << endl;
        cout << "Usage: ./core_tb test_filename [options] ..." << endl;
        cout << "Options:" << endl << endl;
        cout << "-O                          \t Optimise the .c file" << endl;
        cout << "--riscof signature_filename \t Allow to enable the riscof gestion and store the signature in the file named signature_filename" << endl ;
        cout << "--stats                     \t Allow to use the statistic such as the number of cycle needed to end the program" << endl;
        exit(0);
    }
    else if (argc >= 3 && std::string(argv[2]) == "-O") {
        opt = "-O2";
    } 
    else if (argc >= 3 && std::string(argv[2]) == "--riscof") {
        signature_name = string(argv[3]);
        riscof         = true;
        stats          = true;

        int tmp = test_filename.find("src/");
        int tmp2 = test_filename.find("dut/");

        string tempo_string = test_filename.substr(0,tmp);
        string tempo_string2 = test_filename.substr(0,tmp2);
        int tmp3 = tempo_string2.size() - (tempo_string.size() + 4);

        test_filename = test_filename.substr(tmp+4, tmp3);
        
        #ifdef BRANCH_PREDICTION 
        filename_stats = "stats_branch_SS1.txt";        
        #elif  RET_BRANCH_PREDICTION
        filename_stats = "stats_stack_branch_SS1.txt";        
        #elif BRANCH_PREDICTION & RET_BRANCH_PREDICTION
        filename_stats = "stat_all_branch_SS1.txt";
        #elif ICACHE_ON & DCACHE_ON
        filename_stats = "stats_caches_SS1.txt";
        #else
        filename_stats = "test_stats_SS1.txt";
        #endif
        test_stats.open(filename_stats, fstream::app);
        if(!test_stats.is_open())
        {
            cout << "Impossible to open " << filename_stats << endl ;
            exit(1);
        }
    } 
    else if(argc >= 3 && std::string(argv[2]) == "--stats")
    {
        stats          = true;
        int tmp = test_filename.rfind("/");
        test_filename = test_filename.substr(tmp+1, test_filename.size());
        
        #ifdef BRANCH_PREDICTION 
        filename_stats = "stats_branch_SS1.txt";        
        #elif  RET_BRANCH_PREDICTION
        filename_stats = "stats_stack_branch_SS1.txt";        
        #elif BRANCH_PREDICTION & RET_BRANCH_PREDICTION
        filename_stats = "stat_all_branch_SS1.txt";
        #elif ICACHE_ON & DCACHE_ON
        filename_stats = "stats_caches_SS1.txt";
        #else
        filename_stats = "test_stats_SS1.txt";
        #endif
        test_stats.open(filename_stats, fstream::app);
        if(!test_stats.is_open())
        {
            cout << "Impossible to open " << filename_stats << endl ;
            exit(1);
        }
    }

    char temp_text[512];
    if (path.substr(path.find_last_of(".") + 1) == "s" || path.substr(path.find_last_of(".") + 1) == "S" 
    || path.substr(path.find_last_of(".") + 1) == "c") {  
        char temp[512];

        sprintf(temp,
                "riscv32-unknown-elf-gcc -nostdlib -march=rv32im -T ../SOFT/app.ld %s %s",
                opt.c_str(),
                path.c_str());  
                                
        system((char*)temp);    
        path = "a.out";         
    }else{
        cerr << "Please use a supported file format, file format are .S, .s or .c";
        exit(1);

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
                    cout << "Found reset" << endl;
                    reset_adr = value - 4;  // minus 4 to acount for init inc_pc
                }
                if (name == "_start") {
                    cout << "Found start" << endl;
                    start_adr = value - 4;  // minus 4 to acount for init inc_pc
                }
                if (name == "_bad") {
                    cout << "Found bad" << endl;
                    bad_adr = value;
                }
                if (name == "_good") {
                    cout << "Found good" << endl;
                    good_adr = value;
                }
                if (name == "_exception_occur") {
                    cout << "Found exception_occur" << endl;
                    exception_occur = value;
                }
                if (name == "rvtest_code_end") {
                    cout << "Found rvtest_code_end" << endl;
                    rvtest_code_end = value;
                }
                if (name == "rvtest_entry_point") {
                    cout << "Found rvtest_entry_point" << endl;
                    reset_adr = value - 4;
                }
                if (name == "begin_signature") {
                    cout << "Found begin_signature" << endl;
                    begin_signature = value;
                }
                if (name == "end_signature") {
                    cout << "Found end_signature" << endl;
                    end_signature = value;
                }
                if (name == "rvtest_end") {
                    rvtest_end = value;
                    cout << "Found rvtest_end at adr " << std::hex << rvtest_end << endl;
                }
            }
        }
    }

    cout << "test2" << endl;
/*
    ##############################################################
                    COMPONENT INSTANCIATION
    ##############################################################
*/

    Vcore core_inst("core_inst");


    sc_signal<bool> clk;
    sc_signal<bool> reset_n;
    sc_signal<bool> MCACHE_STALL_SM;
    sc_signal<bool> MCACHE_ADR_VALID_SM;
    sc_signal<bool> MCACHE_STORE_SM;
    sc_signal<bool> MCACHE_LOAD_SM;
    sc_signal<uint32_t> byt_sel;
    sc_signal<bool> IC_STALL_SI;
    sc_signal<bool> ADR_VALID_SI;
    sc_signal<uint32_t> MCACHE_RESULT_SM;
    sc_signal<uint32_t> MCACHE_DATA_SM;
    sc_signal<uint32_t> MCACHE_ADR_SM;
    sc_signal<uint32_t> IC_INST_SI;
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


    sc_trace_file* tf;
    tf = sc_create_vcd_trace_file("tf");

    cout << "Reseting...";

    reset_n.write(false);  
    PC_INIT.write(reset_adr);

    sc_start(3, SC_NS);
    reset_n.write(true);   
    
    cerr << "done." << endl;

    int NB_CYCLES = 0;
    int cycles = 0;
    int countdown;

    int if_adr;
    int if_result;
    int mem_adr;
    int mem_size;

    while (1) 
    {
//         if (countdown) countdown--;
//         cycles++;
//         // mem interface
//         mem_adr       = MCACHE_ADR_SM.read() & 0XfffffffC; // removing the least 2 significant bits
//         mem_size      = byt_sel.read() ;
//         bool         mem_adr_valid = MCACHE_ADR_VALID_SM.read();
//         unsigned int mem_data      = MEM_DATA.read();
//         bool         mem_store     = MCACHE_STORE_SM.read();
//         bool         mem_load      = MCACHE_LOAD_SM.read();
//         unsigned int mem_result;
//         // Ifetch interface
//         if_adr       = ADR_SI.read();
//         bool         if_afr_valid = ADR_SI.read();


// /*
//     ##############################################################
//                     END OF TEST GESTION
//     ##############################################################
// */

//         unsigned int pc_adr = ADR_SI.read();
//         NB_CYCLES = sc_time_stamp().to_double()/1000;
        
//         if (signature_name == "" && pc_adr == bad_adr) {
//             cout << FRED("Error ! ") << "Found bad at adr 0x" << std::hex << pc_adr << endl;
//             sc_start(3, SC_NS);
//             exit(1);
//         } else if (signature_name == "" && pc_adr == good_adr) {
//             if(stats)
//             {
//                 #ifdef BRANCH_PREDICTION || RET_BRANCH_PREDICTION
//                     cout << "NB BRANCH TAKEN = "    <<  nb_jump_taken   <<  endl;
//                 #endif
//                 test_stats << test_filename << " " << NB_CYCLES  << " " << "SCALAR" << endl;
//                 test_stats.close();
//             }
            
//             cout << FGRN("Success ! ") << "Found good at adr 0x" << std::hex << pc_adr << endl;
//             sc_start(3, SC_NS);
//             exit(0);
//         } 
//         else if(signature_name == "" && pc_adr == exception_occur){
//             cout << FYEL("Error ! ") << "Found exception_occur at adr 0x" << std::hex << pc_adr << endl;
//             sc_start(3, SC_NS);
//             exit(2);
//         }
//         else if (countdown == 0 && ((pc_adr == rvtest_code_end) || (pc_adr ==  rvtest_end) || (signature_name != "" && cycles > 2000000))) {
//             countdown = 50;
//         }
//         if (countdown == 1) {
//             cout << "Test ended at " << std::hex << pc_adr << endl;
//             sc_start(3, SC_NS);
            
//             // Stats Gestion riscof
//             test_stats << test_filename << " " << NB_CYCLES  << " " << "SCALAR" << endl;
//             test_stats.close();
            
            
//             ofstream signature;
//             signature.open(signature_name, ios::out | ios::trunc);
//             cout << "signature_name :" << signature_name << endl ;
//             cout << "begin_signature :" << begin_signature << endl ;
//             cout << "end_signature :" << end_signature << endl ;
           
//             for (int i = begin_signature; i < end_signature; i += 4) {
//                 signature << setfill('0') << setw(8) << hex << ram[i] << endl;
//             }
//             exit(0);
//         }

// /*
//     ##############################################################
//                     MEMORY ACCESS GESTION
//     ##############################################################
// */

//         if (mem_store && mem_adr_valid) {
//             int temporary_value = ram[mem_adr] ; 
//             unsigned int temporary_store_value = mem_data;
//             if(mem_size == 2){//access in byte
//             // doing a mask on the least 2 significant bits
//                 int mask_adr = MEM_ADR.read() & 0x00000003 ;
//                 // The switch will allow to keep only the bits we want to store
//                 switch (mask_adr)
//                 {
//                 case 0 :
//                     temporary_store_value = temporary_store_value & 0x000000FF ;
//                     temporary_value = 0xFFFFFF00 & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;
//                 case 1 :
//                     temporary_store_value = temporary_store_value & 0x0000FF00 ;
//                     temporary_value = 0xFFFF00FF & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;
//                 case 2 :
//                     temporary_store_value = temporary_store_value & 0x00FF0000 ;
//                     temporary_value = 0xFF00FFFF & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;
//                 case 3 :      
//                     temporary_store_value = temporary_store_value & 0xFF000000 ;
//                     temporary_value = 0x00FFFFFF & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;
//                 default:
//                     break;
//                 }
//             }
//             else if(mem_size == 1){//access in half word
//                 int mask_adr = MEM_ADR.read() & 0x00000003 ;
//                 switch (mask_adr)
//                 {
//                 case 0 :
//                     temporary_store_value = temporary_store_value & 0x0000FFFF ;
//                     temporary_value = 0xFFFF0000 & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;
//                 case 2 :          
//                     temporary_store_value = temporary_store_value & 0xFFFF0000 ;
//                     temporary_value = 0x00000FFFF & temporary_value ;
//                     ram[mem_adr] = temporary_value | temporary_store_value ;
//                     break ;      
//                 default:
//                     break;
//                 }
//             }
//             else//access in word
//             {
//                 ram[mem_adr] = mem_data;}
//         }
//         mem_result = ram[mem_adr];
//         MEM_RESULT.write(mem_result);
//         MEM_STALL.write(false);
//         if_result = ram[if_adr];
//         INST_SIC.write(if_result);
//         STALL_SIC.write(false);

        sc_start(500, SC_PS);
}
    return 0;
}