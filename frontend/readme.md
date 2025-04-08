# Setting Up and Executing
This project is optimized to be build on the following targets:
- Windows 10+
- Ubuntu 22.04

After following the platform specific instructions below you can execute `script/run.sh` from the root of the project to
run it.

### Windows
Do the following to ensure your environment is setup correctly:
- Install Node by running `winget install OpenJS.NodeJS`.
- Run `npm install` from the root of the project.

### Linux
Do the following to ensure your environment is setup correctly:
- Install Node by running the following commands:
  - `curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.0/install.sh | bash`
  - `source ~/.bashrc`
  - `nvm list-remote`
  - `nvm install [LATEST VERSION]`
- Run `npm install` from the root of the project.
