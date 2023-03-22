#!/bin/bash
#This script allow you to install systemc on your system
#echo "Please execute this script in sudo mode to properly work"
OS="`uname`"
echo "This script allow you to choose the path where you want to install SystemC for Scientific Linux Distribution"
echo "On other distribution it will be installed in /usr/local/systemc-2.3.3/"
echo "So if you are running on scientific Linux please enter the path where you want systemC"

rm systemc-2.3.3.gz
rm systemc-2.3.3.gz.*

if ( cat /etc/*-release | grep Ubuntu > /dev/null 2>&1) then
    if grep -q microsoft /proc/version; then
    echo "Ubuntu on Windows"
        if ( "$1" = "clean" )
        then    
            echo "rm systemc-2.3.3.gz" 
            sudo rm -f /usr/local/systemc-2.3.3.gz
        else
            echo "Installing systemc for Linux distribution"
            cd /usr/local/
            sudo apt install build-essential make wget git gcc g++ automake
            wget http://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.gz
            echo "Uncompressing the tar archive into current directory"
            tar -xzf systemc-2.3.3.gz
            
            if ( ! -d /usr/local/systemc-2.3.3/ )
            then
                mkdir /usr/local/systemc-2.3.3/
            fi
            cd systemc-2.3.3 && mkdir -p objdir && cd objdir
            sudo  ../configure --prefix=/usr/local/systemc-2.3.3/
            sudo make -j$(nproc)
            sudo make install
        fi
    fi
fi
if ( cat /etc/*-release | grep Ubuntu > /dev/null 2>&1) && ( ! grep -q microsoft /proc/version ) then
  echo "native Linux"
    if ( "$1" = "clean" )
    then    
        echo "systemc-2.3.3 and rm systemc-2.3.3.gz"
        rm -r systemc-2.3.3 && rm systemc-2.3.3.gz
    else
            echo "Installing systemc for Linux distribution"
            sudo apt install build-essential make wget git gcc g++ automake
            wget http://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.gz
            echo "Uncompressing the tar archive into current directory"
            tar -xzf systemc-2.3.3.gz
            
            if ( ! -d /usr/local/systemc-2.3.3/ )
            then
                mkdir /usr/local/systemc-2.3.3/
            fi
            cd systemc-2.3.3 && mkdir -p objdir && cd objdir
            sudo ../configure --prefix=/usr/local/systemc-2.3.3/
            sudo make -j$(nproc)
            sudo make install
    fi
fi
