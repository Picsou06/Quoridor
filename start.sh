#!/bin/bash

if ! command -v tput &> /dev/null; then
    echo -e "\e[31mncurses is not installed. Installing now...\e[0m"

    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo apt-get update
        sudo apt-get install -y libncurses-dev
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        brew install ncurses
    else
        echo -e "\e[31mUnsupported OS. Please install ncurses manually.\e[0m"
        exit 1
    fi
fi

echo -e "\e[32mCompiling...\e[0m"
gcc src/*.c -o bin/main -Llib -lncurses

if [ ! -f ./bin/main ]; then
    echo -e "\e[31mCompilation error. The file ./bin/main does not exist.\e[0m"
    exit 1
else
    echo -e "\e[32mCompilation complete.\e[0m"
fi

echo -e "\e[32mRunning...\e[0m"
./bin/main