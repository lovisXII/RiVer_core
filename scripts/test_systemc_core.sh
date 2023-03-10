#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
NOC='\033[0m'
export PATH=$PATH:$HOME/riscv/bin
 
printf "ls\n"
ls

cd SIM/SystemC/CORE
for file in $(ls ../../../SOFT/TESTS/I/); do 
    printf "Test ${file} non opt..." 
    timeout 40s ./core_tb ../../../SOFT/TESTS/I/$file >/dev/null 2>&1
    if (($? == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    else
        printf "${RED} failed\n${NOC}"
        exit -1
    fi
    printf "Test ${file} opt..." 
    timeout 40s ./core_tb ../../../SOFT/TESTS/I/$file -O >/dev/null 2>&1
    if (($? == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    else
        printf "${RED} failed\n${NOC}"
        exit -1
    fi
done
for file in $(ls ../../../SOFT/TESTS/M/); do 
    printf "Test ${file} non opt..." 
    timeout 40s ./core_tb ../../../SOFT/TESTS/M/$file >/dev/null 2>&1
    if (($? == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    else
        printf "${RED} failed\n${NOC}"
        exit -1
    fi
    printf "Test ${file} opt..." 
    timeout 40s ./core_tb ../../../SOFT/TESTS/M/$file -O >/dev/null 2>&1
    if (($? == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    else
        printf "${RED} failed\n${NOC}"
        exit -1
    fi
done
# for file in $(ls tests_exception); do 
#     timeout 40s ./CORE/core_tb CORE/tests/$file >/dev/null 2>&1
#     printf "Test ${file} non opt..." 
#     if (($? == 0)) 
#     then
#         printf "${GREEN} passed\n${NOC}"
#     else
#         printf "${RED} failed\n${NOC}"
#         exit -1
#     fi
#     printf "Test ${file} opt..." 
#     timeout 40s ./CORE/core_tb CORE/tests/$file -O >/dev/null 2>&1
#     if (($? == 0)) 
#     then
#         printf "${GREEN} passed\n${NOC}"
#     else
#         printf "${RED} failed\n${NOC}"
#         exit -1
#     fi
# done
