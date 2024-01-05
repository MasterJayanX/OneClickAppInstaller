# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases) [![GitHub all releases](https://img.shields.io/github/downloads/MasterJayanX/OneClickAppInstaller/total)](https://github.com/MasterJayanX/OneClickAppInstaller/releases) 

### Languages
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Français](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Description
OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with just one click.
## Compatibility list
### Windows:

- Windows 10 or above. The software might work on older versions of Windows, but the resulting script will only run on Windows 10 or above because it makes use of [winget](https://github.com/microsoft/winget-cli "winget") to install packages.

### macOS:

- macOS 12 (Monterey) or above with [Homebrew](https://github.com/Homebrew/brew) installed. Older versions could work, but they aren't officially supported by Homebrew.

### Linux:
Here's a list of compatible Linux distributions for each option in the menu:

- `Ubuntu/Debian`: Ubuntu, Debian, Linux Mint, PopOS!, any Ubuntu flavors like Kubuntu, Linux Lite, MX Linux, antiX, PeppermintOS, Deepin, elementaryOS and ChromeOS with Linux mode installed. Ubuntu 16.04 or Debian 8 or above is required because this script uses apt instead of apt-get. **Note**: KDE Neon might work, but it might have issues because the script makes use of the `sudo apt upgrade` command to update packages.
- `Arch`: Arch Linux, Manjaro, EndeavourOS, Garuda, SteamOS, Crystal Linux and ChimeraOS.
- `Fedora / Red Hat`: Fedora, Fedora Spins, Red Hat Enterprise Linux (RHEL) 8 or above, AlmaLinux and Rocky Linux. Fedora 22 or RHEL 8 or above is required for this option.
- `openSUSE`: SUSE, openSUSE Leap and openSUSE Tumbleweed.
- `Red Hat Enterprise Linux (RHEL)`: Red Hat Enterprise Linux (RHEL) 7 or below.
- `Flatpak`: Any Linux distribution that can run [Flatpak](https://flatpak.org).
- `Snap`: Any Linux distribution that can run [Snap](https://snapcraft.io).

### Other operating systems:

- FreeBSD
- OpenBSD
- NetBSD
- Haiku

## Installation
To install the OneClickAppInstaller Script Creator, you just need to download and run the latest software available on the Releases tab. If you are on Windows, you have to select the .exe file and run it by double clicking it. If you are on macOS, Linux, WSL (Windows Subsystem for Linux) or another OS, you have to select the .sh file that corresponds to your language of choice and run it from the terminal with the following syntax: ./file.sh (replace file with the actual name of the file).

## Usage
Follow these steps to use OneClickAppInstaller:
1. Open the .exe or .sh file and when the program prompts you to select a language, press 1, 2 or 3 depending on the language you want to use.
2. Here, the program will ask you to select an option. Choose 1, 2 or 3 depending on the operating system you want to use your resulting script in (1 for Windows, 2 for macOS, 3 for Linux or 4 for another OS). If you choose Linux, you will have to select a distribution or distribution group from the list. If your distribution doesn't appear on the list, it's probably because your distribution is based on one of the distributions on the list. For example, for Linux Mint or PopOS!, choose Ubuntu/Debian and for Manjaro or SteamOS (Steam Deck), choose Arch.
3. If you choose Windows or macOS, the program will ask you if you want the script to install winget (for Windows) or Homebrew (for macOS). Press y if you want the script to install this tool or n if you have it installed already (you will most likely have winget installed if you have Windows 11, so you can just press n).
4. The program will now ask you if you want a custom name for your script. Press y if you want to name the script or n if you don't want to. Keep in mind that you can rename your file at any point. Then, it will ask you if you want to have a custom welcome message. This is a line of text that will show up when you run the script. Press y if you want to enter a custom welcome message or n if you don't want to.
5. After the early setup, you have to enter the names of the applications you want to install using your script. Keep in mind that you have to enter the names of your applications using a specific syntax depending on your operating system and/or package manager. If you want to know what applications you can install on your operating system, go to the website linked on the program.
6. Press y when asked if you want to add applications to your script. After you're done, just press n when asked if you want to add more applications.

## Compiling
### Requirements
- Having the g++ compiler installed on your computer (for Windows users, you can install it with MinGW or use WSL).

To compile this program yourself, you need to download the .cpp and .hpp files and save them in the same directory. Alternatively, you can download the repository files using the following command on a terminal window: `git clone https://github.com/MasterJayanX/OneClickAppInstaller`. 
Then, you have to open a terminal window and compile the main.cpp file with the following command: `g++ main.cpp -o output` (you can replace output with any name you want).

## FAQ (Frequently Asked Questions)
### What operating systems are supported by this software?
The officially supported operating systems at the moment are: Windows 10/11, macOS, Ubuntu, Debian, Arch Linux, Fedora, OpenSUSE, Red Hat Enterprise Linux and other operating systems. The software itself will run on anything that can run .sh files, but it can only create scripts for the aforementioned operating systems.
### Are there any operating systems that will be supported in the future?
I'm currently not sure about what other operating systems should be added in future releases.
### I found a bug or the software is just not working well. Where can I report these issues?
You can open a new issue in the Issues section and I will take care of it as soon as I can.
### How can I use my own language files?
After creating your language file based on the template file, you just need to save it in the same folder you have the OneClickAppInstaller executable in. Then, in the language section, choose "Other / Otro" and when prompted to enter the name of your file, just enter the name of the file you created (including the extension).
### How can I create a config file?
To create your own config file, you can just use one of the config files in the folder called "config examples" and use one of those files as a template. Don't forget to rename the file to oneclick_config.txt or oneclickconfig.txt and remove all the comments in it before using it as your config.
### How can I share my language files?
Currently, you can't, but you can send them to me to my social media (my social media pages are in [my profile](https://github.com/MasterJayanX)).

## Donations
I accept donations through Ko-fi:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
