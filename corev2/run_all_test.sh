#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NOC='\033[0m'
make
for file in $(ls ../sw/tests/I/); do 
    printf "Test ${file} non opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/I/$file >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else 
        printf "${RED} failed\n${NOC}"    
    fi
    printf "Test ${file} opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/I/$file -O >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else
        printf "${RED} failed\n${NOC}" 
    fi

done
for file in $(ls ../sw/tests/C/); do 
    printf "Test ${file} non opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/C/$file >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else 
        printf "${RED} failed\n${NOC}"    
    fi
    printf "Test ${file} opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/I/$file -O >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else
        printf "${RED} failed\n${NOC}" 
    fi

done
for file in $(ls ../sw/tests/M/); do 
    printf "Test ${file} non opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/M/$file >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else 
        printf "${RED} failed\n${NOC}"    
    fi
    printf "Test ${file} opt..." 
    timeout 30s obj_dir/Vcore ../sw/tests/M/$file -O >/dev/null 2>&1;
    RES=$?;
    if (($RES == 0)) 
    then
        printf "${GREEN} passed\n${NOC}"
    elif (($RES == 2))
    then
        printf "${YELLOW} exception occured\n${NOC}"
    else
        printf "${RED} failed\n${NOC}" 
    fi

done