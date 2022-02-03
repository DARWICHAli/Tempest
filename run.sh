#!/bin/bash

if [ $# = 0 ]; then
    mkdir build/ && cd build/
    cmake ../
    make
    cd ../
    mkdir bin/
    mv ./build/Tempest bin/
    exit 0

elif [[ $1 == "clean" ]]; then
    rm -r build
    rm -r bin
elif [[ $1 == "test" ]]; then
    echo "begin Testing"
    # lance sh qui lance des test unit && intégration
    sh test.sh
    echo "Done testing"
fi
exit 0
