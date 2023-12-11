#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void programas(string os, ofstream& script){
    int opcion = 1;
    string pack, instruccion;
    while(opcion == 1){
        cout << "¿Deseas agregar aplicaciones al script?" << endl << "1. Sí" << endl << "Otra opción: No" << endl;
        cin >> opcion;
        if(opcion != 1){
            break;
        }
        cout << "Ingrese el nombre del paquete de la aplicación que deseas instalar. Ten en cuenta que el nombre del paquete debe ser un nombre de paquete válido para que el script funcione correctamente." << endl;
        cout << "Para usuarios de Windows (winget), pueden encontrar los nombres de paquetes válidos aquí: https://winget.run (no es necesario copiar la parte que dice winget install, solo el ID del paquete)." << endl;
        cout << "Para usuarios de Linux (Ubuntu/Debian) , pueden encontrar los nombres de paquetes válidos aquí: https://packages.ubuntu.com, https://packages.debian.org/en/" << endl;
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
    cout << "¿Deseas ponerle un nombre personalizado a tu script? [y/n]" << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << "Elige un nombre para tu archivo: " << endl;
        cin >> nombre;
        nombre += ".bat";
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        nombre = os + ".bat";
    }
    else{
        cout << "Opción no válida." << endl;
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
    cout << "¿Deseas ponerle un nombre personalizado a tu script? [y/n]" << endl;
    cin >> personalizado;
    if(personalizado == 'y' || personalizado == 'Y'){
        cout << "Elige un nombre para tu archivo: " << endl;
        cin >> nombre;
        nombre += ".sh";
    }
    else if(personalizado == 'n' || personalizado == 'N'){
        nombre = os + ".sh";
    }
    else{
        cout << "Opción no válida. No se aplicará un nombre personalizado." << endl;
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
    cout << "Selecciona el sistema operativo para el que vas a hacer tu script: " << endl << "1. Windows" << endl << "2. Linux (Ubuntu/Debian)" << endl << "3. Salir" << endl;
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
        cout << "Opción no válida." << endl;
        return 0;
    }
    return 0;
}