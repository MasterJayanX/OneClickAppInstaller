#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class Translator {
public:
    Translator(const string& language) {
        loadTranslations(language);
    }

    string translate(const string& key) const {
        auto it = translations.find(key);
        return (it != translations.end()) ? it->second : "Translation not found";
    }

private:
    map<string, string> translations;

    void loadTranslations(const string& language) {
        if (language == "en") {
            translations["welcome"] = "Welcome to OneClickAppInstaller, a software that allows you to create a script that installs Windows or Linux applications with a single click. This software was created by MasterJayanX.";
            translations["option"] = "Select an option: ";
            translations["opt1"] = "1. Create script for Windows";
            translations["opt2"] = "2. Create script for macOS";
            translations["opt3"] = "3. Create script for Linux";
            translations["opt4"] = "4. About";
            translations["opt5"] = "5. Exit";
            translations["invalid"] = "Invalid option.";
            translations["winget"] = "This script uses the winget package manager to install applications. Do you want the script to install winget? [y/n]";
            translations["nowinget"] = "Winget will not be installed.";
            translations["homebrew"] = "This script uses the Homebrew package manager to install applications. Do you want the script to install Homebrew (brew)? [y/n]";
            translations["nohomebrew"] = "Homebrew will not be installed.";
            translations["distro"] = "Select your Linux distribution:";
            translations["flat"] = "Flatpak (for other distributions)";
            translations["distroback"] = "Return to Main Menu";
            translations["qcustomname"] = "Do you want to give your script a custom name? [y/n]";
            translations["customname"] = "Enter a name for your file: ";
            translations["nocustomname"] = "Invalid option. A custom name will not be applied.";
            translations["qwelcomemsg"] = "Do you want to add a custom welcome message to the script? [y/n]";
            translations["welcomemsg"] = "Enter your message: ";
            translations["nowelcomemsg"] = "No welcome message will be added.";
            translations["instwinget"] = "Installing winget...";
            translations["instbrew"] = "Installing brew...";
            translations["updates"] = "Installing updates...";
            translations["addapps"] = "Do you want to add applications to the script? [y/n]";
            translations["addmoreapps"] = "Do you want to add more applications to the script? [y/n]";
            translations["addpackage"] = "Enter the package name of the application you want to install. Note that the package name must be a valid package name for the script to work correctly.";
            translations["forwindows"] = "For Windows (winget) users, you can find valid package names here: https://winget.run (you don't need to copy the part that says winget install, just the package ID).";
            translations["formacos"] = "For macOS (brew) users, you can find valid package names here: https://formulae.brew.sh (you don't need to copy the part that says brew install, just the package name).";
            translations["forubuntu"] = "For Ubuntu (apt) users, you can find valid package names here: https://packages.ubuntu.com/ (you don't need to copy the part that says sudo apt install, just the package name).";
            translations["fordebian"] = "For Debian (apt) users, you can find valid package names here: https://packages.debian.org/en/ (also you don't need to copy the part that says sudo apt install, just the package name).";
            translations["forotherapt"] = "For other Ubuntu or Debian based distributions, you can find valid package names on their respective websites.";
            translations["forarch"] = "For Arch (pacman) users, you can find valid package names here: https://archlinux.org/packages/ (you don't need to copy the part that says sudo pacman -S, just the package name).";
            translations["forfedora"] = "For Fedora (dnf) users, you can find valid package names here: https://apps.fedoraproject.org/packages/ (no need to copy the part that says sudo dnf install, just the package name) .";
            translations["foropensuse"] = "For OpenSUSE (zypper) users, you can find valid package names here: https://software.opensuse.org/ (you don't need to copy the part that says sudo zypper install, just the package name).";
            translations["forflatpak"] = "For Flatpak users, you can find valid package names here: https://flathub.org/home (you don't need to copy the part that says flatpak install, just the package name).";
            translations["packagename"] = "Enter the package name here: ";
            translations["about1"] = "OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with just one click.";
            translations["about2"] = "This tool was created by MasterJayanX.";
            translations["about3"] = "Version: 1.1.1 (2023-12-20)";
            translations["about4"] = "Check out the full changelog here: https://github.com/MasterJayanX/OneClickAppInstaller/releases";
            translations["pressenter"] = "Press Enter to exit...";
            translations["cringe"] = "Bruh, you're cringe.";
        } 
        else if (language == "es") {
            translations["welcome"] = "Bienvenido a OneClickAppInstaller, un software que te permite crear un script que instala aplicaciones de Windows o Linux con un solo clic. Este software fue creado por MasterJayanX.";
            translations["option"] = "Selecciona una opción: ";
            translations["opt1"] = "1. Crear script para Windows";
            translations["opt2"] = "2. Crear script para macOS";
            translations["opt3"] = "3. Crear script para Linux";
            translations["opt4"] = "4. Acerca de";
            translations["opt5"] = "5. Salir";
            translations["invalid"] = "Opción no válida.";
            translations["winget"] = "Este script hace uso del gestor de paquetes winget para instalar las aplicaciones. ¿Deseas que el script instale winget? [y/n]";
            translations["nowinget"] = "No se instalará winget.";
            translations["homebrew"] = "Este script hace uso del gestor de paquetes Homebrew para instalar las aplicaciones. ¿Deseas que el script instale Homebrew (brew)? [y/n]";
            translations["nohomebrew"] = "No se instalará Homebrew.";
            translations["distro"] = "Selecciona tu distribución Linux:";
            translations["flat"] = "Flatpak (para otras distribuciones)";
            translations["distroback"] = "Volver al inicio";
            translations["qcustomname"] = "¿Deseas ponerle un nombre personalizado a tu script? [y/n]";
            translations["customname"] = "Escribe un nombre para tu archivo: ";
            translations["nocustomname"] = "Opción no válida. No se aplicará un nombre personalizado.";
            translations["qwelcomemsg"] = "¿Deseas agregar un mensaje de bienvenida personalizado al script? [y/n]";
            translations["welcomemsg"] = "Escribe tu mensaje: ";
            translations["nowelcomemsg"] = "No se agregará un mensaje de bienvenida.";
            translations["instwinget"] = "Instalando winget...";
            translations["instbrew"] = "Instalando brew...";
            translations["updates"] = "Instalando actualizaciones...";
            translations["addapps"] = "¿Deseas agregar aplicaciones al script? [y/n]";
            translations["addmoreapps"] = "¿Deseas agregar más aplicaciones al script? [y/n]";
            translations["addpackage"] = "Ingrese el nombre del paquete de la aplicación que deseas instalar. Ten en cuenta que el nombre del paquete debe ser un nombre de paquete válido para que el script funcione correctamente.";
            translations["forwindows"] = "Para usuarios de Windows (winget), pueden encontrar los nombres de paquetes válidos aquí: https://winget.run (no es necesario copiar la parte que dice winget install, solo el ID del paquete).";
            translations["formacos"] = "Para usuarios de macOS (brew), pueden encontrar los nombres de paquetes válidos aquí: https://formulae.brew.sh (no es necesario copiar la parte que dice brew install, solo el nombre del paquete).";
            translations["forubuntu"] = "Para usuarios de Ubuntu (apt), pueden encontrar los nombres de paquetes válidos aquí: https://packages.ubuntu.com/ (no es necesario copiar la parte que dice sudo apt install, solo el nombre del paquete).";
            translations["fordebian"] = "Para usuarios de Debian (apt), pueden encontrar los nombres de paquetes válidos aquí: https://packages.debian.org/en/ (igualmente no es necesario copiar la parte que dice sudo apt install, solo el nombre del paquete).";
            translations["forotherapt"] = "Para otras distribuciones basadas en Ubuntu o Debian, pueden encontrar los nombres de paquetes válidos en sus respectivos sitios web.";
            translations["forarch"] = "Para usuarios de Arch (pacman), pueden encontrar los nombres de paquetes válidos aquí: https://archlinux.org/packages/ (no es necesario copiar la parte que dice sudo pacman -S, solo el nombre del paquete).";
            translations["forfedora"] = "Para usuarios de Fedora (dnf), pueden encontrar los nombres de paquetes válidos aquí: https://apps.fedoraproject.org/packages/ (no es necesario copiar la parte que dice sudo dnf install, solo el nombre del paquete).";
            translations["foropensuse"] = "Para usuarios de OpenSUSE (zypper), pueden encontrar los nombres de paquetes válidos aquí: https://software.opensuse.org/ (no es necesario copiar la parte que dice sudo zypper install, solo el nombre del paquete).";
            translations["forflatpak"] = "Para usuarios de Flatpak, pueden encontrar los nombres de paquetes válidos aquí: https://flathub.org/home (no es necesario copiar la parte que dice flatpak install, solo el nombre del paquete).";
            translations["packagename"] = "Escribe el nombre del paquete aquí: ";
            translations["about1"] = "OneClickAppInstaller es una herramienta de línea de comandos sencilla que te permite crear un script para instalar todas tus aplicaciones en Windows, macOS o Linux automáticamente con solo un clic.";
            translations["about2"] = "Esta herramienta fue creada por MasterJayanX.";
            translations["about3"] = "Versión: 1.1.1 (2023-12-20)";
            translations["about4"] = "Revisa el historial de cambios completo aquí: https://github.com/MasterJayanX/OneClickAppInstaller/releases";
            translations["pressenter"] = "Presiona Enter para salir...";
            translations["cringe"] = "Bruh, das cringe.";
        }
<<<<<<< Updated upstream
=======
        else{
            ifstream file(language + ".txt");
            if (!file.is_open()) {
                cerr << "Unable to open file: " << language + ".txt" << endl;
                return;
            }
            string line;
            while (getline(file, line)) {
                size_t delimiterPos = line.find('=');
                if (delimiterPos != string::npos) {
                    string key = line.substr(0, delimiterPos);
                    string value = line.substr(delimiterPos + 1);
                    translations[key] = value;
                }
            }
        file.close();
        }
>>>>>>> Stashed changes
    }
};
void secrets(int s, Translator translator){
    if(s == 1){
        ofstream shrek("shrek.txt");
        shrek << "Shrek is love, Shrek is life." << endl;
        shrek << "⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆\n"
                << "⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿\n"
                << "⠀⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀\n"
                << "⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡿⠉⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                << "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉";
        shrek.close();
    }
    else if(s == 2){
        cout << translator.translate("cringe") << endl;
    }
    else if(s == 3){
        ofstream amongus("amongus.txt");
        cout << "sus" << endl;
        amongus << "ඞ" << endl;
        amongus.close();
    }
}