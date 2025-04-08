#!/bin/bash

if [ "$OS" == "Windows_NT" ]; then
  gdb -tui ./binary/windows/backend.exe
elif [ "$(uname)" == "Linux" ]; then
  gdb -tui ./binary/linux/backend.out
else
  echo "Unsupported OS"
fi
