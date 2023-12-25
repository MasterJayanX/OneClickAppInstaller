#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale.h>
#include <map>
#include <unistd.h>
#include "oneclick.cpp"

// Programa hecho por MasterJayanX
#define START 1000

using namespace std;

int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    int option = START;
    string os;
    string update;
    int lang;
    config.open("oneclick_config.txt");
    if(config.is_open()){
        configfile = true;
    }
    // Step 1: Choose your language
    cout << "Select your language / Selecciona tu idioma: " << endl << "1. English" << endl << "2. Español" << endl << "3. Other / Otro" << endl;
    if(configfile){
        config >> lang;
    }
    else{
        cin >> lang;
    }
    if(lang == 1){
        language = "en";
    }
    else if(lang == 2){
        language = "es";
    }
    else if(lang == 3){
        // If you chose "Other", enter the name of your language file
        cout << "Enter the name of your your language file (example: fr.txt): ";
        cin >> language;
    }
    else{
        cerr << "Invalid option. / Opción no válida." << endl;
        cout << "Press Enter to exit. / Presiona Enter para salir." << endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    Translator translator(language);
    if(lang_file_opened == false){
        cout << "Press Enter to exit. / Presiona Enter para salir." << endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    cout << translator.translate("language") << endl;
    sleep(1);
    user_os = checkUserOS();
    // Step 2: Choose an operating system
    cout << translator.translate("welcome") << endl;
    while(option == START){
        cout << translator.translate("option") << endl << translator.translate("opt1") << endl << translator.translate("opt2") << endl << translator.translate("opt3") << endl << translator.translate("opt4") << endl << translator.translate("opt5") << endl;
        if(configfile){
            config >> option;
        }
        else{
            cin >> option;
        }
        if(option == 1){
            // Windows
            os = "Windows";
            update = "winget upgrade -h --all\n";
            char winget = 'a';
            while(winget != 'y' && winget != 'Y' && winget != 'n' && winget != 'N'){
                // If you chose Windows, choose if you want to install winget
                cout << translator.translate("winget") << endl;
                if(configfile){
                    config >> winget;
                }
                else{
                    cin >> winget;
                }
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
            // macOS
            os = "macOS";
            update = "softwareupdate -i -a";
            char brew = 'a';
            while(brew != 'y' && brew != 'Y' && brew != 'n' && brew != 'N'){
                // If you chose macOS, choose if you want to install Homebrew
                cout << translator.translate("homebrew") << endl;
                if(configfile){
                    config >> brew;
                }
                else{
                    cin >> brew;
                }
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
            // Linux
            int option2;
            // If you chose Linux, choose your distro
            cout << translator.translate("distro") << endl << "1. Ubuntu/Debian" << endl << "2. Arch" << endl << "3. Fedora / Red Hat " << translator.translate("newer") << endl << "4. OpenSUSE" << endl << "5. Red Hat Enterprise Linux (RHEL) " << translator.translate("older") << endl << "6. " << translator.translate("flat") << endl << "7. " << translator.translate("distroback") << endl;
            if(configfile){
                config >> option2;
            }
            else{
                cin >> option2;
            }
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
                update = "sudo zypper --non-interactive update";
            }
            else if(option2 == 5){
                os = "RHEL";
                update = "sudo yum update -y";
            }
            else if(option2 == 6){
                os = "Flatpak";
                update = "flatpak update -y";
            }
            else if(option2 == 7){
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
            // About
            cout << translator.translate("about1") << endl;
            cout << translator.translate("about2") << endl;
            cout << translator.translate("about3") << " " << version << endl;
            cout << translator.translate("about4") << endl;
            cout << translator.translate("useros") << user_os << endl;
            sleep(0.8);
            cout << translator.translate("pressenter") << endl;
            cin.ignore();
            cin.get();
            option = START;
        }
        else if(option == 5){
            // Exit
            return 0;
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