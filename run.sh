#!/bin/bash

if [ $# = 0 ]; then
    mkdir build/ && cd build/
    cmake ../
    make
    cd ../
    mkdir bin/
    mv ./build/Tempest bin/
    exit 0
fi
if [[ $1 == "clean" ]]; then
        rm -r build
        rm -r bin
fi
exit 0
