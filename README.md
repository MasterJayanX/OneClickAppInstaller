# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases) [![GitHub all releases](https://img.shields.io/github/downloads/MasterJayanX/OneClickAppInstaller/total)](https://github.com/MasterJayanX/OneClickAppInstaller/releases) 

### Languages
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Français](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Description
OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with just one click.
## Requirements
Windows:

- Windows 10 or above. The software might work on older versions of Windows, but the resulting script will only run on Windows 10 or above because it makes use of [winget](https://github.com/microsoft/winget-cli "winget") to install packages.

macOS:

- Any version of macOS that can run [Homebrew](https://github.com/Homebrew/brew).

Linux:

- Ubuntu or Debian (any currently supported version should work). Other Ubuntu-based or Debian-based distros will work as well.
- Arch/Manjaro, Fedora and OpenSUSE are also supported now.

## Installation
To install the OneClickAppInstaller Script Creator, you just need to download and run the latest software available on the Releases tab. If you are on Windows, you have to select the .exe file that corresponds to your language of choice and run it. If you are on macOS, Linux or WSL (Windows Subsystem for Linux), you have to select the .sh file that corresponds to your language of choice and run it from the terminal with the following syntax: ./file.sh (replace file with the actual name of the file).

## Usage
Follow these steps to use OneClickAppInstaller:
1. Open the .exe or .sh file and when the program prompts you to select a language, press 1 or 2 depending on the language you want to use.
2. Here, the program will ask you to select an option. Choose 1, 2 or 3 depending on the operating system you want to use your resulting script in (1 for Windows, 2 for macOS or 3 for Linux). If you choose Linux, you will have to select a distribution or distribution group from the list. If your distribution doesn't appear on the list, it's probably because your distribution is based on one of the distributions on the list. For example, for Linux Mint or PopOS, choose Ubuntu/Debian and for Manjaro, choose Arch.
3. If you choose Windows or macOS, the program will ask you if you want the script to install winget (for Windows) or Homebrew (for macOS). Press y if you want the script to install this tool or n if you have it installed already (you will most likely have winget installed if you have Windows 11, so you can just press n).
4. The program will now ask you if you want a custom name for your script. Press y if you want to name the script or n if you don't want to. Keep in mind that you can rename your file at any point. Then, it will ask you if you want to have a custom welcome message. This is a line of text that will show up when you run the script. Press y if you want to enter a custom welcome message or n if you don't want to.
5. After the early setup, you have to enter the names of the applications you want to install using your script. Keep in mind that you have to enter the names of your applications using a specific syntax depending on your operating system and/or package manager. If you want to know what applications you can install on your operating system, go to the website linked on the program.
6. Press y when asked if you want to add applications to your script. After you're done, just press n when asked if you want to add more applications.

## Compiling
### Requirements
- Having the g++ compiler installed on your computer (for Windows users, you can install it with MinGW or use WSL).

To compile this program yourself, you need to download the .cpp and .hpp files and save them in the same directory. Alternatively, you can download the repository files using the following command on a terminal window: `git clone https://github.com/MasterJayanX/OneClickAppInstaller`. 
Then, you have to open a terminal window and compile the .cpp file with the following command: `g++ oneclickscripter.cpp -o output` (you can replace output with any name you want).

## FAQ (Frequently Asked Questions)
### What operating systems are supported by this software?
The officially supported operating systems at the moment are: Windows 10/11, macOS, Ubuntu, Debian, Arch Linux, Fedora and OpenSUSE. The software itself will run on anything that can run .sh files, but it can only create scripts for the aforementioned operating systems.
### Are there any operating systems that will be supported in the future?
I plan on adding compatibility with RHEL (Red Hat Enterprise Linux) in the next release.
### I found a bug or the software is just not working well. Where can I report these issues?
You can open a new issue in the Issues section and I will take care of it as soon as I can.
### How can I use my own language files?
After creating your language file based on the template file, you just need to save it in the same folder you have the OneClickAppInstaller executable in. Then, in the language section, choose "Other / Otro" and when prompted to enter the name of your file, just enter the name of the file you created (including the extension).
### How can I share my language files?
Currently, you can't, but you can send them to me to my social media (my social media pages are in [my profile](https://github.com/MasterJayanX)).

## Donations
I accept donations through Ko-fi:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
