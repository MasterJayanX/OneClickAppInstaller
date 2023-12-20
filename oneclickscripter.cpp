#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <map>
#include "oneclickscripter.hpp"
/*Programa hecho por MasterJayanX*/
#define INICIO 1000

using namespace std;

bool install_winget = false;
bool install_brew = false;
string language;
int s;

void programas(string os, ofstream& script, Translator translator){
    char opcion = 'y';
    bool first = true;
    string pack, instruccion;
    while(opcion == 'y' || opcion == 'Y'){
        if(first){
            cout << translator.translate("addapps") << endl;
            cin >> opcion;
        }
        else{
            cout << translator.translate("addmoreapps") << endl;
            cin >> opcion;
        }
        if(opcion != 'y' && opcion != 'Y'){
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
                opcion = 1;
            }
            first = false;
        }
        cout << translator.translate("packagename");
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
        else if(os == "OpenSUSE"){
            instruccion = "sudo zypper install " + pack + " -y";
        }
        else if(os == "Flatpak"){
            instruccion = "flatpak install " + pack + " -y";
        }
        else{
            cout << translator.translate("invalid") << endl;
            opcion = 1;
        }
        script << instruccion << endl;
    }
}

void script(string os, string update, Translator translator){
    char personalizado;
    string nombre, ext;
    if(os == "Windows"){
        ext = ".bat";
    }
    else{
        ext = ".sh";
    }
    cout << translator.translate("qcustomname") << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << translator.translate("customname") << endl;
        cin >> nombre;
        if(nombre == "ascii_shrek"){
            s = 1;
            secrets(s, translator);
        }
        else if(nombre == "among_us" || nombre == "amongus"){
            s = 3;
            secrets(s, translator);
        }
        nombre += ext;
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        if(os == "Ubuntu/Debian"){
            nombre = "ubuntu-debian" + ext;
        }
        else{
            nombre = os + ext;
        }
    }
    else{
        cout << translator.translate("nocustomname") << endl;
        nombre = os + ext;
    }
    ofstream script;
    script.open(nombre);
    char msj;
    cout << translator.translate("qwelcomemsg") << endl;
    cin >> msj;
    if(msj == 'y' || msj == 'Y'){
        string mensaje;
        cout << translator.translate("welcomemsg") << endl;
        cin.ignore();
        getline(cin, mensaje);
        if(mensaje == "Skibidi Toilet"){
            s = 2;
            secrets(s, translator);
        }
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
    int opcion = INICIO;
    string os, update;
    int lang;
    cout << "Select your language / Selecciona tu idioma: " << endl << "1. English" << endl << "2. Español" << endl;
    cin >> lang;
    if(lang == 1){
        language = "en";
    }
    else if(lang == 2){
        language = "es";
    }
    else{
        cout << "Invalid option." << endl;
        return 0;
    }
    Translator translator(language);
    cout << translator.translate("welcome") << endl;
    while(opcion == INICIO){
        cout << translator.translate("option") << endl << translator.translate("opt1") << endl << translator.translate("opt2") << endl << translator.translate("opt3") << endl << translator.translate("opt4") << endl << translator.translate("opt5") << endl;
        cin >> opcion;
        if(opcion == 5){
            return 0;
        }
        else if(opcion == 1){
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
        else if(opcion == 2){
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
        else if(opcion == 3){
            int opcion2;
            cout << translator.translate("distro") << endl << "1. Ubuntu/Debian" << endl << "2. Arch" << endl << "3. Fedora" << endl << "4. OpenSUSE" << endl << "5. " << translator.translate("flat") << endl << "6. " << translator.translate("distroback") << endl;
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
                os = "OpenSUSE";
                update = "sudo zypper update -y";
            }
            else if(opcion2 == 5){
                os = "Flatpak";
                update = "flatpak update -y";
            }
            else if(opcion2 == 6){
                opcion = INICIO;
            }
            else{
                cout << translator.translate("invalid") << endl;
                opcion = INICIO;
            }
            if(opcion2 != 6 && opcion != INICIO){
                script(os, update, translator);
            }
        }
        else if(opcion == 4){
            cout << translator.translate("about1") << endl;
            cout << translator.translate("about2") << endl;
            cout << translator.translate("about3") << endl;
            cout << translator.translate("about4") << endl;
            cout << translator.translate("pressenter") << endl;
            cin.ignore();
            cin.get();
            opcion = INICIO;
        }
        else{
            cout << translator.translate("invalid") << endl;
            opcion = INICIO;
        }
    }
    cout << translator.translate("pressenter") << endl;
    cin.ignore();
    cin.get();
    return 0;
}
