# Building and Executing
This project is optimized to be built with the following targets in mind:
- Windows 11 MinGW 64-bit GCC 14.2.0
- Ubuntu 22.04 GLIBC Version 2.35

Version information for dependencies can be found in `external/version_info.txt`.

The output executable is fully statically linked.

After following the platform specific instructions below you can execute `script/build.sh` followed by `script/run.sh`
from the root of the project to build and run the project.

### Windows
Do the following to ensure your environment is set up correctly:
- Download a 64-bit [MinGW](https://winlibs.com/) distribution with Clang/LLVM support and put the `[DISTRIBUTION]/bin`
  directory in your path.
- Install GNUMake by running `winget install ezwinports.make`.
- Ensure that you have `[GIT_INSTALLATION]/bin` in your path.

### Linux
Do the following on Ubuntu to ensure your environment is set up correctly:
- Only run `sudo apt update && sudo apt upgrade` if you haven't already.
- Run `sudo apt install git g++ gdb make`.

# Updating Crow
Go to the [releases page](https://github.com/CrowCpp/Crow/releases) and download the source code for the desired
release. Extract it and put the contents of the `include` directory in `external/include/crow` in this project.

# Updating ASIO
Go to the [official ASIO website](https://think-async.com/Asio/) and download the release you want from the download
link. Extract it and put the contents of the `include` directory in `external/include/asio` in this project.

# Updating SQLite
Go to the [official SQLite website](https://www.sqlite.org/) and download the sqlite-amalgamation zip file for the
version you want. Extract it and put `sqlite3.h` in `external/include/sqlite` and `sqlite3.c` in
`external/source/sqlite` in this project.
