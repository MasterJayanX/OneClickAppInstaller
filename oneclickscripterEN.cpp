#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void programas(string os, ofstream& script){
    int opcion = 1;
    string pack, instruccion;
    while(opcion == 1){
        cout << "Do you want to add applications to the script?" << endl << "1. Yes" << endl << "Another option: No" << endl;
        cin >> opcion;
        if(opcion != 1){
            break;
        }
        cout << "Enter the name of the application package you want to install. Keep in mind that the name of the package should be a valid package name so that the script works correctly."<< endl;
        cout << "For Windows users (Winget), you can find the names of valid packages here: https://winget.run (it is not necessary to copy the part that Winget Install says, only the ID of the package)."<< endl;
        cout << "For Linux users (Ubuntu/Debian), you can find the names of valid packages here: https://packages.ubuntu.com, https://packages.debian.org/en/" << endl;
        cin >> pack;
        if(os == "Windows"){
            instruccion = "winget install " + pack;
        }
        else if(os == "Linux"){
            instruccion = "sudo apt install " + pack + " -y";
        }
        script << instruccion << endl;
    }
}

void script_windows(string os, string update){
    char personalizado;
    string nombre;
    cout << "Do you want to put a personalized name to your script? [y/n]" << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << "Choose a name for your file:" << endl;
        cin >> nombre;
        nombre += ".bat";
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        nombre = os + ".bat";
    }
    else{
        cout << "Non-valid option. We will not apply a personalized name." << endl;
    }
    ofstream script;
    script.open(nombre);
    script << update << endl;
    programas(os, script);
    script.close();
}
void script_linux(string os, string update){
    char personalizado;
    string nombre;
    cout << "Do you want to put a personalized name to your script? [y/n]" << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << "Choose a name for your file: " << endl;
        cin >> nombre;
        nombre += ".sh";
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        nombre = os + ".sh";
    }
    else{
        cout << "Non-valid option. We will not apply a personalized name." << endl;
        nombre = os + ".sh";
    }
    ofstream script;
    script.open(nombre);
    script << update << endl;
    programas(os, script);
    script.close();
}

int main(){
    int opcion;
    string os;
    string nombre;
    string update;
    cout << "Welcome to OneClickAppInstaller, a software that allows you to create a script that will install all your apps for Windows or Linux (Ubuntu/Debian) with a single click." << endl;
    cout << "Select the operating system for which you are going to do your script: " << endl << "1. Windows" << endl << "2. Linux (Ubuntu/Debian)" << endl << "3. Exit" << endl;
    cin >> opcion;
    if(opcion == 3){
        return 0;
    }
    else if(opcion == 1){
        os = "Windows";
        update = "winget upgrade -h -all";
        script_windows(os, update);
    }
    else if(opcion == 2){
        os = "Linux";
        update = "sudo apt update && sudo apt upgrade -y";
        script_linux(os, update);
    }
    else{
        cout << "Non-valid option." << endl;
        return 0;
    }
    return 0;
}