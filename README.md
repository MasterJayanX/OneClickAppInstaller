# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases)
### Languages
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Francais](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Description
OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with just one click.
## Requirements
Windows:

- Windows 10 or above. The software might work on older versions of Windows, but the resulting script will only run on Windows 10 or above because it makes use of [winget](https://github.com/microsoft/winget-cli "winget") to install packages.

macOS:

- Any version of macOS that can run [Homebrew](https://github.com/Homebrew/brew).

Linux:

- Ubuntu or Debian (any currently supported version should work). Other Ubuntu-based or Debian-based distros will work as well.
- Arch/Manjaro and Fedora are also supported now.

## Installation
To install the OneClickAppInstaller Script Creator, you just need to execute the software available on the Releases tab. If you are on Windows, you have to select the .exe file that corresponds to your language of choice and run it. If you are on macOS, Linux or WSL (Windows Subsystem for Linux), you have to select the .sh file that corresponds to your language of choice and run it from the terminal with the following syntax: ./file.sh (replace file with the actual name of the file).

## Compiling
### Requirements
- Having the g++ compiler installed on your computer (for Windows users, you can install it with MinGW or use WSL).

To compile this program yourself, you need to download the .cpp and .hpp files and save them in the same directory. Alternatively, you can download the repository files using the following command on a terminal window: `git clone https://github.com/MasterJayanX/OneClickAppInstaller`. 
Then, you have to open a terminal window and compile the .cpp file with the following command: `g++ oneclickscripter.cpp -o output` (you can replace output with any name you want).
