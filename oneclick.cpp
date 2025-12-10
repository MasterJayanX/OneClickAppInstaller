/**
 * @file oneclick.cpp
 * @brief This file contains the implementation of the "One-Click App Installer" program.
 *
 * The program allows users to generate a script that installs multiple applications on different operating systems.
 * It supports Windows, macOS, Ubuntu/Debian, Arch Linux, Fedora, OpenSUSE, RHEL, and Flatpak.
 * Users can customize the script by choosing the applications they want to install and providing a custom script name.
 * The program also provides options to search for packages and displays available packages based on the selected operating system.
 * The script generated can be executed to install the chosen applications.
 *
 * @author MasterJayanX
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <map>
#include <unistd.h>
#include "header.hpp"

bool install_winget = false;
bool install_brew = false;
string language;
string version = "v2.0.0-rc1 (2025-12-11)";
int s;
ifstream config;
bool configfile = false;
string user_os, general_os;

void openConfig(){
    config.open("oneclick_config.txt");
    if(config.is_open()){
        configfile = true;
    }
    else{
        config.open("oneclickconfig.txt");
        if(config.is_open()){
            configfile = true;
        }
        else{
            configfile = false;
        }
    }
}

void programs(string os, ofstream& script, Translator translator){
    char option = 'y';
    bool first = true;
    char search, found;
    string pack, instruction, searched_package;
    // Step 5: Choose if you want to search for the packages you want to install
    cout << translator.translate("enablesearch") << endl;
    if(configfile){
        config >> search;
        cout << translator.translate("selected") << search << endl;
    }
    else{
        cin >> search;
    }
    if(search != 'y' && search != 'Y' && search != 'n' && search != 'N'){
        cout << translator.translate("invalid") << endl;
        search = 'n';
    }
    int i = 0;
    // Step 6: Choose the applications you want the script to install
    if(configfile){
        config >> i;
    }
    if(i > 0 && configfile){
        cout << translator.translate("autoapps") << i << endl;
        sleep(1);
        for(int j = 1; j <= i; j++){
            config >> pack;
            if(os == "Windows"){
                // This command installs your applications on Windows 10/11
                instruction = "winget install " + pack + "\n";
            }
            else if(os == "Old Windows"){
                // This command installs your applications on Windows 8.1 or below
                instruction = "pmfow install " + pack + "\n";
            }
            else if(os == "macOS"){
                // This command installs your applications on macOS
                instruction = " && brew install " + pack;
            }
            else if(os == "Ubuntu/Debian"){
                // This command installs your applications on Ubuntu, Debian or Ubuntu/Debian-based distros
                instruction = " && sudo apt install " + pack + " -y";
            }
            else if(os == "Arch"){
                // This command installs your applications on Arch Linux or Arch-based distros
                instruction = " && sudo pacman -S " + pack + " --noconfirm";
            }
            else if(os == "Fedora"){
                // This command installs your applications on Fedora or Fedora-based distros
                instruction = " && sudo dnf install " + pack + " -y";
            }
            else if(os == "OpenSUSE"){
                // This command installs your applications on SUSE Linux or OpenSUSE
                instruction = " && sudo zypper --non-interactive install " + pack;
            }
            else if(os == "Flatpak"){
                // This command installs your applications on any distro that supports Flatpak
                instruction = " && flatpak install " + pack + " -y";
            }
            else if(os == "Snap"){
                // This command installs your applications on any distro that supports Snap
                instruction = " && sudo snap install " + pack;
            }
            else if(os == "FreeBSD"){
                // This command installs your applications on FreeBSD
                instruction = " && sudo pkg install " + pack + " -y";
            }
            else if(os == "OpenBSD"){
                // This command installs your applications on OpenBSD
                instruction = " && sudo pkg_add " + pack;
            }
            else if(os == "NetBSD"){
                // This command installs your applications on Android
                instruction = " && sudo pkgin install " + pack;
            }
            else if(os == "Haiku"){
                // This command installs your applications on Cygwin (most likely Windows)
                instruction = " && pkgman install " + pack;
            }
            else{
                cout << translator.translate("invalid") << endl;
                j = i + 1;
            }
            script << instruction;
            cout << translator.translate("added") << endl;
        }
        if(os == "Ubuntu/Debian"){
            // This command removes unnecessary packages on Ubuntu, Debian or Ubuntu/Debian-based distros
            script << " && sudo apt autoremove -y";
        }
        if(os != "Windows"){
            script << " && echo " + translator.translate("done") << endl;
        }
        else{
            script << "echo " + translator.translate("done") << endl;
        }
    }
    else{
        while(option == 'y' || option == 'Y'){
            if(first){
                cout << translator.translate("addapps") << endl;
                cin >> option;
            }
            else{
                cout << translator.translate("addmoreapps") << endl;
                cin >> option;
            }
            if(option != 'y' && option != 'Y'){
                // No more applications to install
                cout << translator.translate("nomoreapps") << endl;
                if(os == "Ubuntu/Debian"){
                    // This command removes unnecessary packages on Ubuntu, Debian or Ubuntu/Debian-based distros
                    script << " && sudo apt autoremove -y";
                }
                if(os != "Windows" && os != "Old Windows"){
                    script << " && echo " + translator.translate("done") << endl;
                }
                else{
                    script << "echo " + translator.translate("done") << endl;
                }
                break;
            }
            cout << "" << endl;
            cout << translator.translate("addpackage") << endl;
            found = 'n';
            while(found == 'n' || found == 'N'){
                if(search == 'y' || search == 'Y'){
                    cout << translator.translate("search") << endl;
                    cin >> searched_package;
                    if(os == "Windows"){
                        system(("winget search " + searched_package).c_str());
                    }
                    if (os == "Old Windows"){
                        system(("pmfow search " + searched_package).c_str());
                    }
                    else if(os == "macOS"){
                        system(("brew search " + searched_package).c_str());
                    }
                    else if(os == "Ubuntu/Debian"){
                        system(("apt search --names-only " + searched_package).c_str());
                    }
                    else if(os == "Arch"){
                        system(("pacman -Ss " + searched_package).c_str());
                    }
                    else if(os == "Fedora"){
                        system(("dnf search " + searched_package).c_str());
                    }
                    else if(os == "OpenSUSE"){
                        system(("zypper search " + searched_package).c_str());
                    }
                    else if(os == "Flatpak"){
                        system(("flatpak search " + searched_package).c_str());
                    }
                    else if(os == "FreeBSD"){
                        system(("pkg search " + searched_package).c_str());
                    }
                    else if(os == "OpenBSD"){
                        system(("pkg_info " + searched_package).c_str());
                    }
                    else if(os == "NetBSD"){
                        system(("pkgin search " + searched_package).c_str());
                    }
                    else if(os == "Haiku"){
                        system(("pkgman search " + searched_package).c_str());
                    }
                    else if(os == "Snap"){
                        system(("snap search " + searched_package).c_str());
                    }
                    else{
                        cout << translator.translate("invalid") << endl;
                    }
                    cout << translator.translate("found") << endl;
                    cin >> found;
                }
                else{
                    break;
                }
            }
            if(first && (search == 'n' || search == 'N')){
                if(os == "Windows"){
                    cout << translator.translate("forwindows") << endl;
                }
                else if(os == "Old Windows"){
                    cout << translator.translate("foroldwindows") << endl;
                }
                else if(os == "macOS"){
                    cout << translator.translate("formacos") << endl;
                }
                else if(os == "Ubuntu/Debian"){
                    cout << translator.translate("forubuntu") << endl;
                    cout << translator.translate("fordebian") << endl;
                    cout << translator.translate("forotherapt") << endl;
                }
                else if(os == "Arch"){
                    cout << translator.translate("forarch") << endl;
                }
                else if(os == "Fedora"){
                    cout << translator.translate("forfedora") << endl;
                }
                else if(os == "OpenSUSE"){
                    cout << translator.translate("foropensuse") << endl;
                }
                else if(os == "Flatpak"){
                    cout << translator.translate("forflatpak") << endl;
                }
                else if(os == "FreeBSD"){
                    cout << translator.translate("forfreebsd") << endl;
                }
                else if(os == "OpenBSD"){
                    cout << translator.translate("foropenbsd") << endl;
                }
                else if(os == "NetBSD"){
                    cout << translator.translate("fornetbsd") << endl;
                }
                else if(os == "Haiku"){
                    cout << translator.translate("forhaiku") << endl;
                }
                else if(os == "Snap"){
                    cout << translator.translate("forsnap") << endl;
                }
                else{
                    cout << translator.translate("invalid") << endl;
                    return;
                }
            }
            if(first){
                first = false;
            }
            cout << translator.translate("packagename");
            cin >> pack;
            if(os == "Windows"){
                // This command installs your applications on Windows 10/11
                instruction = "winget install " + pack + "\n";
            }
            else if(os == "Old Windows"){
                instruction = "pmfow install " + pack + "\n";
            }
            else if(os == "macOS"){
                // This command installs your applications on macOS
                instruction = "brew install " + pack + "\n";
            }
            else if(os == "Ubuntu/Debian"){
                // This command installs your applications on Ubuntu, Debian or Ubuntu/Debian-based distros
                instruction = " && sudo apt install " + pack + " -y";
            }
            else if(os == "Arch"){
                // This command installs your applications on Arch Linux or Arch-based distros
                instruction = " && sudo pacman -S " + pack + " --noconfirm";
            }
            else if(os == "Fedora"){
                // This command installs your applications on Fedora or Fedora-based distros
                instruction = " && sudo dnf install " + pack + " -y";
            }
            else if(os == "OpenSUSE"){
                // This command installs your applications on SUSE Linux or OpenSUSE
                instruction = " && sudo zypper --non-interactive install " + pack;
            }
            else if(os == "Flatpak"){
                // This command installs your applications on any distro that supports Flatpak
                instruction = " && flatpak install " + pack + " -y";
            }
            else if(os == "FreeBSD"){
                // This command installs your applications on FreeBSD
                instruction = " && sudo pkg install " + pack + " -y";
            }
            else if(os == "OpenBSD"){
                // This command installs your applications on OpenBSD
                instruction = " && sudo pkg_add " + pack;
            }
            else if(os == "NetBSD"){
                // This command installs your applications on Android
                instruction = " && sudo pkgin install " + pack;
            }
            else if(os == "Haiku"){
                // This command installs your applications on Cygwin (most likely Windows)
                instruction = " && pkgman install " + pack;
            }
            else{
                cout << translator.translate("invalid") << endl;
                option = 1;
            }
            script << instruction;
            cout << translator.translate("added") << endl;
            found = 'n';
        }
    }
}

void script(string os, string update, Translator translator){
    char customname;
    string filename, ext;
    if(os == "Windows" || os == "Old Windows"){
        ext = ".bat";
    }
    else{
        ext = ".sh";
    }
    // Step 3: Choose a name for your script (if you want a custom name)
    cout << translator.translate("qcustomname") << endl;
    if(configfile){
        config >> customname;
        cout << translator.translate("selected") << customname << endl;
    }
    else{
        cin >> customname;
    }
    if(customname == 'y' || customname == 'Y'){
        cout << translator.translate("customname") << endl;
        if(configfile){
            config >> filename;
            cout << filename << endl;
        }
        else{
            cin >> filename;
        }
        if(filename == "ascii_shrek"){
            s = 1;
            secrets(s, translator);
        }
        else if(filename == "among_us" || filename == "amongus"){
            s = 3;
            secrets(s, translator);
        }
        else if(filename == "chipichipichapachapa" || filename == "chipichapa"){
            s = 4;
            secrets(s, translator);
        }
        filename += ext;
    }
    else if(customname == 'n' || customname == 'N'){
        if(os == "Ubuntu/Debian"){
            filename = "ubuntu-debian" + ext;
        }
        else if (os == "Old Windows"){
            filename = "old-windows" + ext;
        }
        else{
            filename = os + ext;
        }
    }
    else{
        cout << translator.translate("invalid") << endl;
        cout << translator.translate("nocustomname") << endl;
        if(os == "Ubuntu/Debian"){
            filename = "ubuntu-debian" + ext;
        }
        else if (os == "Old Windows"){
            filename = "old-windows" + ext;
        }
        else{
            filename = os + ext;
        }
    }
    ofstream script;
    script.open(filename);
    char msj;
    // Step 4: Choose if you want to add a welcome message
    cout << translator.translate("qwelcomemsg") << endl;
    if(configfile){
        config >> msj;
        cout << translator.translate("selected") << msj << endl;
    }
    else{
        cin >> msj;
    }
    if(msj == 'y' || msj == 'Y'){
        string message;
        cout << translator.translate("welcomemsg") << endl;
        if(configfile){
            config >> message;
            cout << message << endl;
        }
        else{
            cin >> message;
        }
        if(message == "Skibidi Toilet"){
            s = 2;
            secrets(s, translator);
        }
        if(os == "Windows"){
            script << "@echo off" << endl;
            script << "echo " << message << endl;
        }
        else{
            script << "echo " << message << endl;
        }
    }
    else if(msj == 'n' || msj == 'N'){
        cout << translator.translate("nowelcomemsg") << endl;
    }
    else{
        cout << translator.translate("invalid") << endl;
    }
    if(os == "Windows"){
        script << "@echo off" << endl;
    }
    if(os == "Windows"){
        if(install_winget){
            script << "echo " + translator.translate("instwinget") << endl;
            // This command installs winget on Windows 10/11
            script << "powershell -command Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe" << endl;
        }
    }
    if(os == "macOS"){
        if(install_brew){
            script << "echo " + translator.translate("instbrew") << endl;
            // This command installs Homebrew on macOS
            script << "/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"" << endl;
        }
    }
    script << "echo " + translator.translate("updates") << endl;
    script << update;
    if(os == "Old Windows"){
        script << "pmfow-updater\n";
    }
    programs(os, script, translator);
    script.close();
}

string checkUserOS(){
    // This function checks the user's operating system
    string os;
    #ifdef _WIN32
        general_os = "Windows";
        #ifdef _WIN64
            os = "Windows 64-bit";
        #else
            os = "Windows 32-bit";
        #endif
    #elif __APPLE__ || __MACH__
        #include "TargetConditionals.h"
        #if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
            os = "iPhone simulator";
        #elif TARGET_OS_IPHONE
            os = "iOS";
        #elif TARGET_OS_MAC
            os = "macOS";
        #else
            os = "Other Apple OS";
        #endif
        general_os = "macOS";
    #elif __ANDROID__
        os = "Android";
        general_os = os;
    #elif __linux__
        os = "Linux";
        general_os = os;
    #elif __FreeBSD__
        os = "FreeBSD";
        general_os = os;
    #elif __OpenBSD__
        os = "OpenBSD";
        general_os = os;
    #elif __NetBSD__
        os = "NetBSD";
        general_os = os;
    #elif __unix || __unix__
        os = "Unix";
        general_os = os;
    #elif _CYGWIN
        os = "Cygwin (most likely Windows)";
        general_os = "Windows";
    #else
        os = "Other OS";
        general_os = os;
    #endif
    return os;
}

void clearTerminal(){
    // This function clears the terminal window
    if(user_os != "Old Windows"){
        system("clear");
    }
}