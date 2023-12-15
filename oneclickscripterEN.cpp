/*Program made by MasterJayanX*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define START 1000

using namespace std;

bool install_winget = false;
bool install_brew = false;

void programas(string os, ofstream& script){
    int opcion = 1;
    bool first = true;
    string pack, instruccion;
    while(opcion == 1){
        if(first){
            cout << "Do you want to add applications to the script?" << endl << "1. Yes" << endl << "Other option: No (exit)" << endl;
        }
        else{
            cout << "Do you want to add more applications to the script?" << endl << "1. Yes" << endl << "Other option: No (exit)" << endl;
        }
        cin >> opcion;
        if(opcion != 1){
            break;
        }
        cout << "" << endl;
        cout << "Enter the name of the application package you want to install. Keep in mind that the name of the package must be a valid package name for the script to function properly." << endl;
        if(first){
            cout << "" << endl;
            cout << "For Windows (winget) users, you can find the names of valid packages here: https://winget.run (it is not necessary to copy the part that says winget install, only the ID of the package)." << endl;
            cout << "For macOS users (brew), you can find the names of valid packages here: https://formulae.brew.sh (it is not necessary to copy the part that says brew install, only the name of the package)." << endl;
            cout << "For Ubuntu/Debian (apt) users, you can find the names of valid packages here: https://packages.ubuntu.com/ (it is not necessary to copy the part that says sudo apt install, only the name of the package is required)." << endl;
            cout << "For Arch (btw) users (pacman), you can find the names of valid packages here: https://archlinux.org/packages/ (it is not necessary to copy the part that says sudo pacman -S, only the name of the package is required)." << endl;
            cout << "For Fedora users (dnf), you can find the names of valid packages here: https://apps.fedoraproject.org/packages/ (it is not necessary to copy the part that says sudo dnf install, only the name of the package is required)." << endl;
            first = false;
        }
        cout << "Enter the name of the package here:";
        cin >> pack;
        if(os == "Windows"){
            instruccion = "winget install " + pack;
        }
        else if(os == "macOS"){
            instruccion = "brew install " + pack;
        }
        else if(os == "Ubuntu/Debian"){
            instruccion = "sudo apt install " + pack + " -y";
        }
        else if(os == "Arch"){
            instruccion = "sudo pacman -S " + pack + " --noconfirm";
        }
        else if(os == "Fedora"){
            instruccion = "sudo dnf install " + pack + " -y";
        }
        else{
            cout << "Non-valid option." << endl;
            opcion = 1;
        }
        script << instruccion << endl;
    }
}

void script(string os, string update){
    char personalizado;
    string nombre, ext;
    if(os == "Windows"){
        ext = ".bat";
    }
    else{
        ext = ".sh";
    }
    cout << "Do you want to put a custom name to your script? [y/n]" << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << "Elige un nombre para tu archivo: " << endl;
        cin >> nombre;
        nombre += ext;
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        nombre = os + ext;
    }
    else{
        cout << "Non-valid option. The script will not have a custom name." << endl;
        nombre = os + ext;
    }
    ofstream script;
    script.open(nombre);
    char msj;
    cout << "Do you want to add a custom welcome message to the script? [y/n]" << endl;
    cin >> msj;
    if(msj == 'y' || msj == 'Y'){
        string mensaje;
        cout << "Enter your message: " << endl;
        cin.ignore();
        getline(cin, mensaje);
        if(os == "Windows"){
            script << "@echo off" << endl;
            script << "echo " << mensaje << endl;
        }
        else{
            script << "#!/bin/bash" << endl;
            script << "echo " << mensaje << endl;
        }
    }
    else if(msj == 'n' || msj == 'N'){
        if(os == "Windows"){
            script << "@echo off" << endl;
        }
        else{
            script << "#!/bin/bash" << endl;
        }
    }
    else{
        cout << "Non-valid option. A welcome message will not be added." << endl;
        if(os == "Windows"){
            script << "@echo off" << endl;
        }
        else{
            script << "#!/bin/bash" << endl;
        }
    }
    if(os == "Windows"){
        if(install_winget){
            script << "echo Installing winget..." << endl;
            script << "powershell -command \"Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe\"" << endl;
        }
    }
    else if(os == "macOS"){
        if(install_brew){
            script << "echo Installing brew..." << endl;
            script << "/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"" << endl;
        }
    }
    script << "echo Installing updates..." << endl;
    script << update << endl;
    programas(os, script);
    script.close();
}

int main(){
    int opcion = START;
    string os, update;
    cout << "Welcome to OneClickAppinstaller, a software that allows you to create a script that installs Windows or Linux applications with a single click." << endl;
    cout << "This software was created by MasterJayanX." << endl;
    while(opcion == START){
        cout << "Select an option:" << endl << "1. Create a script for Windows" << endl << "2. Create a script for macOS" << endl << "3. Create a script for Linux" << endl <<"4. About" << endl << "5. Exit" << endl;
        cin >> opcion;
        if(opcion == 5){
            return 0;
        }
        else if(opcion == 1){
            os = "Windows";
            update = "winget upgrade -h -all";
            cout << "This script makes use of the winget package manager to install applications. Do you want the script to install winget? [y/n]" << endl;
            char winget;
            cin >> winget;
            if(winget == 'y' || winget == 'Y'){
                install_winget = true;
            }
            else if(winget == 'n' || winget == 'N'){
                cout << "Winget will not be installed." << endl;
                install_winget = false;
            }
            else{
                cout << "Non-valid option. Winget will not be installed." << endl;
                install_winget = false;
            }
            script(os, update);
        }
        else if(opcion == 2){
            os = "macOS";
            update = "softwareupdate -i -a";
            cout << "This script makes use of the Homebrew package manager to install applications. Do you want the script to install Homebrew (brew)? [y/n]" << endl;
            char brew;
            cin >> brew;
            if(brew == 'y' || brew == 'Y'){
                install_brew = true;
            }
            else if(brew == 'n' || brew == 'N'){
                install_brew = false;
                cout << "Homebrew will not be installed." << endl;
            }
            else{
                cout << "Non -valid option. Homebrew will not be installed." << endl;
                install_brew = false;
            }
            script(os, update);
        }
        else if(opcion == 3){
            int opcion2;
            cout << "Select your Linux distribution: "<< endl <<" 1.Ubuntu/Debian"<< endl <<" 2.Arch"<< endl <<" 3.Fedora"<< endl <<" 4.Back to Start" << endl;
            cin >> opcion2;
            if(opcion2 == 1){
                os = "Ubuntu/Debian";
                update = "sudo apt update && sudo apt upgrade -y";
            }
            else if(opcion2 == 2){
                os = "Arch";
                update = "sudo pacman -Syu";
            }
            else if(opcion2 == 3){
                os = "Fedora";
                update = "sudo dnf upgrade -y";
            }
            else if(opcion2 == 4){
                opcion = START;
            }
            else{
                cout << "Non-valid option." << endl;
                opcion = START;
            }
            script(os, update);
        }
        else if(opcion == 4){
            cout << "OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with only one click." << endl;
            cout << "This tool was created by MasterJayanX." << endl;
            cout << "Version: 1.0.1 (2023.12.14)" << endl;
            cout << "See the full changelog here: https://github.com/MasterJayanX/OneClickAppInstaller/releases" << endl;
            opcion = START;
        }
        else{
            cout << "Non-valid option." << endl;
            opcion = START;
        }
    }
    system("pause");
    return 0;
}
