#!/bin/bash

# Check if ncurses is installed
if ! command -v tput &> /dev/null; then
    echo "ncurses is not installed. Installing now..."

    # Check if the OS is Linux or macOS
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo apt-get update
        sudo apt-get install -y libncurses-dev
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        brew install ncurses
    else
        echo "Unsupported OS. Please install ncurses manually."
        exit 1
    fi
else
    echo "Compiling..."
    gcc src/*.c bin/main -Llib -lncurses
    echo "Compilation complete."
    echo "Running..."
    ./bin/main
fi