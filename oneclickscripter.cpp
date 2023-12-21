#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <map>
#include <unistd.h>
#include "oneclickscripter.hpp"
/*Programa hecho por MasterJayanX*/
#define START 1000

using namespace std;

bool install_winget = false;
bool install_brew = false;
string language;
int s;

void programas(string os, ofstream& script, Translator translator){
    char option = 'y';
    bool first = true;
    string pack, instruction;
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
            if(os == "Ubuntu/Debian"){
                script << "sudo apt autoremove -y" << endl;
            }
            break;
        }
        cout << "" << endl;
        cout << translator.translate("addpackage") << endl;
        if(first){
            if(os == "Windows"){
                cout << translator.translate("forwindows") << endl;
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
            else{
                cout << translator.translate("invalid") << endl;
                option = 1;
            }
            first = false;
        }
        cout << translator.translate("packagename");
        cin >> pack;
        if(os == "Windows"){
            instruction = "winget install " + pack;
        }
        else if(os == "macOS"){
            instruction = "brew install " + pack;
        }
        else if(os == "Ubuntu/Debian"){
            instruction = "sudo apt install " + pack + " -y";
        }
        else if(os == "Arch"){
            instruction = "sudo pacman -S " + pack + " --noconfirm";
        }
        else if(os == "Fedora"){
            instruction = "sudo dnf install " + pack + " -y";
        }
        else if(os == "OpenSUSE"){
            instruction = "sudo zypper install " + pack + " -y";
        }
        else if(os == "Flatpak"){
            instruction = "flatpak install " + pack + " -y";
        }
        else{
            cout << translator.translate("invalid") << endl;
            option = 1;
        }
        script << instruction << endl;
    }
}

void script(string os, string update, Translator translator){
    char customname;
    string filename, ext;
    if(os == "Windows"){
        ext = ".bat";
    }
    else{
        ext = ".sh";
    }
    cout << translator.translate("qcustomname") << endl;
    cin >> customname;
    if(customname == 'y' || customname == 'Y'){
        cout << translator.translate("customname") << endl;
        cin >> filename;
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
        else{
            filename = os + ext;
        }
    }
    else{
        cout << translator.translate("nocustomname") << endl;
        filename = os + ext;
    }
    ofstream script;
    script.open(filename);
    char msj;
    cout << translator.translate("qwelcomemsg") << endl;
    cin >> msj;
    if(msj == 'y' || msj == 'Y'){
        string message;
        cout << translator.translate("welcomemsg") << endl;
        cin.ignore();
        getline(cin, message);
        if(message == "Skibidi Toilet"){
            s = 2;
            secrets(s, translator);
        }
        if(os == "Windows"){
            script << "@echo off" << endl;
            script << "echo " << message << endl;
        }
        else{
            script << "#!/bin/bash" << endl;
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
    else{
        script << "#!/bin/bash" << endl;
    }
    if(os == "Windows"){
        if(install_winget){
            script << "echo " + translator.translate("instwinget") << endl;
            script << "powershell -command \"Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe\"" << endl;
        }
    }
    if(os == "macOS"){
        if(install_brew){
            script << "echo " + translator.translate("instbrew") << endl;
            script << "/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"" << endl;
        }
    }
    script << "echo " + translator.translate("updates") << endl;
    script << update << endl;
    programas(os, script, translator);
    script.close();
}

int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    int option = START;
    string os, update;
    int lang;
    cout << "Select your language / Selecciona tu idioma: " << endl << "1. English" << endl << "2. Español" << endl << "3. Other / Otro" << endl;
    cin >> lang;
    if(lang == 1){
        language = "en";
    }
    else if(lang == 2){
        language = "es";
    }
    else if(lang == 3){
        cout << "Enter the name of your your language file (example: fr.txt): ";
        cin >> language;
    }
    else{
        cerr << "Invalid option. / Opción no válida." << endl;
        cout << "Press enter to exit. / Presiona enter para salir." << endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    Translator translator(language);
    if(lang_file_opened == false){
        cout << "Press enter to exit. / Presiona enter para salir." << endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    cout << translator.translate("welcome") << endl;
    while(option == START){
        cout << translator.translate("option") << endl << translator.translate("opt1") << endl << translator.translate("opt2") << endl << translator.translate("opt3") << endl << translator.translate("opt4") << endl << translator.translate("opt5") << endl;
        cin >> option;
        if(option == 5){
            return 0;
        }
        else if(option == 1){
            os = "Windows";
            update = "winget upgrade -h --all";
            char winget = 'a';
            while(winget != 'y' && winget != 'Y' && winget != 'n' && winget != 'N'){
                cout << translator.translate("winget") << endl;
                cin >> winget;
                if(winget == 'y' || winget == 'Y'){
                    install_winget = true;
                }
                else if(winget == 'n' || winget == 'N'){
                    cout << translator.translate("nowinget") << endl;
                    install_winget = false;
                }
                else{
                    cout << translator.translate("invalid") << endl;
                    install_winget = false;
                }
            }
            script(os, update, translator);
        }
        else if(option == 2){
            os = "macOS";
            update = "softwareupdate -i -a";
            char brew = 'a';
            while(brew != 'y' && brew != 'Y' && brew != 'n' && brew != 'N'){
                cout << translator.translate("homebrew") << endl;
                cin >> brew;
                if(brew == 'y' || brew == 'Y'){
                    install_brew = true;
                }
                else if(brew == 'n' || brew == 'N'){
                    install_brew = false;
                    cout << translator.translate("nohomebrew") << endl;
                }
                else{
                    cout << translator.translate("invalid") << endl;
                    install_brew = false;
                }
            }
            script(os, update, translator);
        }
        else if(option == 3){
            int option2;
            cout << translator.translate("distro") << endl << "1. Ubuntu/Debian" << endl << "2. Arch" << endl << "3. Fedora" << endl << "4. OpenSUSE" << endl << "5. " << translator.translate("flat") << endl << "6. " << translator.translate("distroback") << endl;
            cin >> option2;
            if(option2 == 1){
                os = "Ubuntu/Debian";
                update = "sudo apt update && sudo apt upgrade -y";
            }
            else if(option2 == 2){
                os = "Arch";
                update = "sudo pacman -Syu";
            }
            else if(option2 == 3){
                os = "Fedora";
                update = "sudo dnf upgrade -y";
            }
            else if(option2 == 4){
                os = "OpenSUSE";
                update = "sudo zypper update -y";
            }
            else if(option2 == 5){
                os = "Flatpak";
                update = "flatpak update -y";
            }
            else if(option2 == 6){
                option = START;
            }
            else{
                cout << translator.translate("invalid") << endl;
                option = START;
            }
            if(option2 != 6 && option != START){
                script(os, update, translator);
            }
        }
        else if(option == 4){
            cout << translator.translate("about1") << endl;
            cout << translator.translate("about2") << endl;
            cout << translator.translate("about3") << endl;
            cout << translator.translate("about4") << endl;
            sleep(0.8);
            cout << translator.translate("pressenter") << endl;
            cin.ignore();
            cin.get();
            option = START;
        }
        else{
            cout << translator.translate("invalid") << endl;
            option = START;
        }
    }
    cout << translator.translate("pressenter") << endl;
    cin.ignore();
    cin.get();
    return 0;
}
