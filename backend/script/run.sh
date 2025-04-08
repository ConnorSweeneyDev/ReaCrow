#!/bin/bash

if [ "$OS" == "Windows_NT" ]; then
  ./binary/windows/backend.exe
elif [ "$(uname)" == "Linux" ]; then
  ./binary/linux/backend.out
else
  echo "Unsupported OS"
fi
