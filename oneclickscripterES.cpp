/*Programa hecho por MasterJayanX*/
#include <iostream>
#include <string>
#include <fstream>
#define INICIO 1000

using namespace std;

bool install_winget = false;
bool install_brew = false;

void programas(string os, ofstream& script){
    int opcion = 1;
    bool first = true;
    string pack, instruccion;
    while(opcion == 1){
        if(first){
            cout << "¿Deseas agregar aplicaciones al script?" << endl << "1. Sí" << endl << "Otra opción: No (salir)" << endl;
        }
        else{
            cout << "¿Deseas agregar más aplicaciones al script?" << endl << "1. Sí" << endl << "Otra opción: No (salir)" << endl;
        }
        cin >> opcion;
        if(opcion != 1){
            break;
        }
        cout << "" << endl;
        cout << "Ingrese el nombre del paquete de la aplicación que deseas instalar. Ten en cuenta que el nombre del paquete debe ser un nombre de paquete válido para que el script funcione correctamente." << endl;
        if(first){
            cout << "" << endl;
            cout << "Para usuarios de Windows (winget), pueden encontrar los nombres de paquetes válidos aquí: https://winget.run (no es necesario copiar la parte que dice winget install, solo el ID del paquete)." << endl;
            cout << "Para usuarios de macOS (brew), pueden encontrar los nombres de paquetes válidos aquí: https://formulae.brew.sh (no es necesario copiar la parte que dice brew install, solo el nombre del paquete)." << endl;
            cout << "Para usuarios de Ubuntu/Debian (apt), pueden encontrar los nombres de paquetes válidos aquí: https://packages.ubuntu.com/ (no es necesario copiar la parte que dice sudo apt install, solo el nombre del paquete)." << endl;
            cout << "Para usuarios de Arch (pacman), pueden encontrar los nombres de paquetes válidos aquí: https://archlinux.org/packages/ (no es necesario copiar la parte que dice sudo pacman -S, solo el nombre del paquete)." << endl;
            cout << "Para usuarios de Fedora (dnf), pueden encontrar los nombres de paquetes válidos aquí: https://apps.fedoraproject.org/packages/ (no es necesario copiar la parte que dice sudo dnf install, solo el nombre del paquete)." << endl;
            first = false;
        }
        cout << "Escribe el nombre del paquete aquí: ";
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
            cout << "Opción no válida." << endl;
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
    cout << "¿Deseas ponerle un nombre personalizado a tu script? [y/n]" << endl;
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
        cout << "Opción no válida. No se aplicará un nombre personalizado." << endl;
        nombre = os + ext;
    }
    ofstream script;
    script.open(nombre);
    char msj;
    cout << "¿Deseas agregar un mensaje de bienvenida personalizado al script? [y/n]" << endl;
    cin >> msj;
    if(msj == 'y' || msj == 'Y'){
        string mensaje;
        cout << "Escribe tu mensaje: " << endl;
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
        cout << "Opción no válida. No se agregará un mensaje de bienvenida." << endl;
        if(os == "Windows"){
            script << "@echo off" << endl;
        }
        else{
            script << "#!/bin/bash" << endl;
        }
    }
    if(os == "Windows"){
        if(install_winget){
            script << "echo Instalando winget..." << endl;
            script << "powershell -command \"Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe\"" << endl;
        }
    }
    else if(os == "macOS"){
        if(install_brew){
            script << "echo Instalando brew..." << endl;
            script << "/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"" << endl;
        }
    }
    script << "echo Instalando actualizaciones..." << endl;
    script << update << endl;
    programas(os, script);
    script.close();
}

int main(){
    int opcion = INICIO;
    string os, update;
    cout << "Bienvenido a OneClickAppInstaller, un software que te permite crear un script que instala aplicaciones de Windows o Linux con un solo clic." << endl;
    cout << "Este software fue creado por MasterJayanX." << endl;
    while(opcion == INICIO){
        cout << "Selecciona una opción: " << endl << "1. Crear script para Windows" << endl << "2. Crear script para macOS" << endl << "3. Crear script para Linux" << endl << "4. Acerca de" << endl << "5. Salir" << endl;
        cin >> opcion;
        if(opcion == 5){
            return 0;
        }
        else if(opcion == 1){
            os = "Windows";
            update = "winget upgrade -h -all";
            cout << "Este script hace uso del gestor de paquetes winget para instalar las aplicaciones. ¿Deseas que el script instale winget? [y/n]" << endl;
            char winget;
            cin >> winget;
            if(winget == 'y' || winget == 'Y'){
                install_winget = true;
            }
            else if(winget == 'n' || winget == 'N'){
                install_winget = false;
            }
            else{
                cout << "Opción no válida. No se instalará winget." << endl;
                install_winget = false;
            }
            script(os, update);
        }
        else if(opcion == 2){
            os = "macOS";
            update = "softwareupdate -i -a";
            cout << "Este script hace uso del gestor de paquetes brew para instalar las aplicaciones. ¿Deseas que el script instale brew? [y/n]" << endl;
            char brew;
            cin >> brew;
            if(brew == 'y' || brew == 'Y'){
                install_brew = true;
            }
            else if(brew == 'n' || brew == 'N'){
                install_brew = false;
            }
            else{
                cout << "Opción no válida. No se instalará brew." << endl;
                install_brew = false;
            }
            script(os, update);
        }
        else if(opcion == 3){
            int opcion2;
            cout << "Selecciona tu distribución Linux: " << endl << "1. Ubuntu/Debian" << endl << "2. Arch" << endl << "3. Fedora" << endl << "4. Volver al inicio" << endl;
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
                opcion = INICIO;
            }
            else{
                cout << "Opción no válida." << endl;
                opcion = INICIO;
            }
            script(os, update);
        }
        else if(opcion == 4){
            cout << "OneClickAppInstaller es una herramienta de línea de comandos sencilla que te permite crear un script para instalar todas tus aplicaciones en Windows, macOS o Linux automáticamente con solo un clic." << endl;
            cout << "Esta herramienta fue creada por MasterJayanX." << endl;
            cout << "Versión: 1.0.0 (2023.12.12)" << endl;
            opcion = INICIO;
        }
        else{
            cout << "Opción no válida." << endl;
            opcion = INICIO;
        }
    }

    return 0;
}
