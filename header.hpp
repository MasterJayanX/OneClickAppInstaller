/**
 * @file header.hpp
 * @brief This file contains the declaration of the Translator class and the translations map.
 * 
 * The Translator class is responsible for loading translations for different languages and providing translation functionality.
 * The translations map stores the translations for each language.
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

bool lang_file_opened = true;

class Translator {
public:
    Translator(const string& language) {
        // This constructor calls the loadTranslations function
        loadTranslations(language);
    }

    string translate(const string& key) const {
        // This function returns the translation of a string
        auto it = translations.find(key);
        return (it != translations.end()) ? it->second : "Translation not found";
    }

private:
    // This map contains the translations for each language
    map<string, string> translations;

    void loadTranslations(const string& language) {
        // This function loads the translations for each language
        if (language == "en") {
            // English
            translations["welcome"] = "Welcome to OneClickAppInstaller, a software that allows you to create a script that installs Windows, macOS or Linux applications with a single click. This software was created by MasterJayanX.";
            translations["option"] = "Select an option: ";
            translations["opt1"] = "1. Create script for Windows";
            translations["opt2"] = "2. Create script for macOS";
            translations["opt3"] = "3. Create script for Linux";
            translations["opt4"] = "4. Create script for another OS";
            translations["opt5"] = "5. About";
            translations["opt6"] = "6. Exit";
            translations["invalid"] = "Invalid option.";
            translations["winget"] = "This script uses the Windows Package Manager (winget) to install applications. Do you want the script to install winget? [y/n]";
            translations["nowinget"] = "Winget will not be installed.";
            translations["homebrew"] = "This script uses the Homebrew Package Manager to install applications. Do you want the script to install Homebrew (brew)? [y/n]";
            translations["nohomebrew"] = "Homebrew will not be installed.";
            translations["distro"] = "Select your Linux distribution:";
            translations["otherdistro"] = "(for other distributions)";
            translations["back"] = "Return to Main Menu";
            translations["older"] = "(older versions)";
            translations["newer"] = "(newer versions)";
            translations["otheros"] = "Select your operating system:";
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
            translations["foroldwindows"] = "For users of older versions of Windows (pmfow), you can find valid package names here: https://github.com/MasterJayanX/pmfow/wiki/Software-List.";
            translations["formacos"] = "For macOS (brew) users, you can find valid package names here: https://formulae.brew.sh (you don't need to copy the part that says brew install, just the package name).";
            translations["forubuntu"] = "For Ubuntu (apt) users, you can find valid package names here: https://packages.ubuntu.com/ (you don't need to copy the part that says sudo apt install, just the package name).";
            translations["fordebian"] = "For Debian (apt) users, you can find valid package names here: https://packages.debian.org/en/ (also you don't need to copy the part that says sudo apt install, just the package name).";
            translations["forotherapt"] = "For other Ubuntu-based or Debian-based distributions, you can find valid package names on their respective websites.";
            translations["forarch"] = "For Arch (pacman) users, you can find valid package names here: https://archlinux.org/packages/ (you don't need to copy the part that says sudo pacman -S, just the package name).";
            translations["forfedora"] = "For Fedora (dnf) users, you can find valid package names here: https://apps.fedoraproject.org/packages/ (you don't need to copy the part that says sudo dnf install, just the package name) .";
            translations["foropensuse"] = "For OpenSUSE (zypper) users, you can find valid package names here: https://software.opensuse.org/ (you don't need to copy the part that says sudo zypper install, just the package name).";
            translations["forrhel"] = "For Red Hat Enterprise Linux (yum) users, there is no official website to find valid package names, but you can find them here: https://rhel.pkgs.org.";
            translations["forflatpak"] = "For Flatpak users, you can find valid package names here: https://flathub.org/home (you don't need to copy the part that says flatpak install, just the package name).";
            translations["forfreebsd"] = "For FreeBSD users, you can find valid package names here: https://freebsd.pkgs.org.";
            translations["foropenbsd"] = "For OpenBSD users, you can find valid package names here: https://openbsd.app.";
            translations["fornetbsd"] = "For NetBSD users, you can find valid package names here: https://netbsd.pkgs.org.";
            translations["forhaiku"] = "For Haiku users, you can find valid package names here: https://depot.haiku-os.org/.";
            translations["forsnap"] = "For Snap users, you can find valid package names here: https://snapcraft.io/store.";
            translations["packagename"] = "Enter the package name here: ";
            translations["about1"] = "OneClickAppInstaller is a simple CLI tool that allows you to create a script to automatically install all of your apps on Windows, macOS or Linux with just one click.";
            translations["about2"] = "This tool was created by MasterJayanX.";
            translations["about3"] = "Version: ";
            translations["about4"] = "Check out the full release history here: https://github.com/MasterJayanX/OneClickAppInstaller/releases";
            translations["nomoreapps"] = "No more applications will be added.";
            translations["enablesearch"] = "Do you want to enable the search function? [y/n] This will allow you to search the package names from here. However, it will only work if you are on the same OS as the one you're creating the script for.";
            translations["search"] = "Enter the name of the package you want to search for: ";
            translations["found"] = "Did you find the application you were looking for? [y/n] If you didn't find it, type n to search again.";
            translations["added"] = "Application added.";
            translations["pressenter"] = "Press Enter to exit...";
            translations["pressenter2"] = "Press Enter to return to the Main Menu...";
            translations["cringe"] = "Bruh, you're cringe.";
            translations["how"] = "How did you get here?";
            translations["language"] = "Selected language: English";
            translations["autoapps"] = "Your applications will be added automatically. Number of applications to be added: ";
            translations["useros"] = "User operating system: ";
            translations["selected"] = "Selected option: ";
            translations["done"] = "Done! All of your applications have been installed.";
            translations["choosewin"] = "Choose your Windows version: ";
            translations["win10"] = "Windows 10 or above";
            translations["oldwin"] = "Windows 8.1 or below";
        } 
        else if (language == "es") {
            // Spanish
            translations["welcome"] = "Bienvenido a OneClickAppInstaller, un software que te permite crear un script que instala aplicaciones de Windows, macOS o Linux con un solo clic. Este software fue creado por MasterJayanX.";
            translations["option"] = "Selecciona una opción: ";
            translations["opt1"] = "1. Crear script para Windows";
            translations["opt2"] = "2. Crear script para macOS";
            translations["opt3"] = "3. Crear script para Linux";
            translations["opt4"] = "4. Crear script para otro SO";
            translations["opt5"] = "5. Acerca de";
            translations["opt6"] = "6. Salir";
            translations["invalid"] = "Opción no válida.";
            translations["winget"] = "Este script hace uso del Gestor de paquetes de Windows (winget) para instalar las aplicaciones. ¿Deseas que el script instale winget? [y/n]";
            translations["nowinget"] = "No se instalará winget.";
            translations["homebrew"] = "Este script hace uso del Gestor de paquetes Homebrew para instalar las aplicaciones. ¿Deseas que el script instale Homebrew (brew)? [y/n]";
            translations["nohomebrew"] = "No se instalará Homebrew.";
            translations["distro"] = "Selecciona tu distribución Linux:";
            translations["otherdistro"] = "(para otras distribuciones)";
            translations["back"] = "Volver al Menú Principal";
            translations["older"] = "(versiones antiguas)";
            translations["newer"] = "(versiones más recientes)";
            translations["otheros"] = "Selecciona tu sistema operativo:";
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
            translations["foroldwindows"] = "Para usuarios de versiones antiguas de Windows (pmfow), pueden encontrar los nombres de paquetes válidos aquí: https://github.com/MasterJayanX/pmfow/wiki/Software-List.";
            translations["formacos"] = "Para usuarios de macOS (brew), pueden encontrar los nombres de paquetes válidos aquí: https://formulae.brew.sh (no es necesario copiar la parte que dice brew install, solo el nombre del paquete).";
            translations["forubuntu"] = "Para usuarios de Ubuntu (apt), pueden encontrar los nombres de paquetes válidos aquí: https://packages.ubuntu.com/ (no es necesario copiar la parte que dice sudo apt install, solo el nombre del paquete).";
            translations["fordebian"] = "Para usuarios de Debian (apt), pueden encontrar los nombres de paquetes válidos aquí: https://packages.debian.org/en/ (igualmente no es necesario copiar la parte que dice sudo apt install, solo el nombre del paquete).";
            translations["forotherapt"] = "Para otras distribuciones basadas en Ubuntu o Debian, pueden encontrar los nombres de paquetes válidos en sus respectivos sitios web.";
            translations["forarch"] = "Para usuarios de Arch (pacman), pueden encontrar los nombres de paquetes válidos aquí: https://archlinux.org/packages/ (no es necesario copiar la parte que dice sudo pacman -S, solo el nombre del paquete).";
            translations["forfedora"] = "Para usuarios de Fedora (dnf), pueden encontrar los nombres de paquetes válidos aquí: https://apps.fedoraproject.org/packages/ (no es necesario copiar la parte que dice sudo dnf install, solo el nombre del paquete).";
            translations["foropensuse"] = "Para usuarios de OpenSUSE (zypper), pueden encontrar los nombres de paquetes válidos aquí: https://software.opensuse.org/ (no es necesario copiar la parte que dice sudo zypper install, solo el nombre del paquete).";
            translations["forrhel"] = "Para usuarios de Red Hat Enterprise Linux (yum), no hay un sitio web oficial para encontrar nombres de paquetes válidos, pero pueden encontrarlos aquí: https://rhel.pkgs.org.";
            translations["forflatpak"] = "Para usuarios de Flatpak, pueden encontrar los nombres de paquetes válidos aquí: https://flathub.org/home (no es necesario copiar la parte que dice flatpak install, solo el nombre del paquete).";
            translations["forfreebsd"] = "Para usuarios de FreeBSD, pueden encontrar los nombres de paquetes válidos aquí: https://freebsd.pkgs.org.";
            translations["foropenbsd"] = "Para usuarios de OpenBSD, pueden encontrar los nombres de paquetes válidos aquí: https://openbsd.app.";
            translations["fornetbsd"] = "Para usuarios de NetBSD, pueden encontrar los nombres de paquetes válidos aquí: https://netbsd.pkgs.org.";
            translations["forhaiku"] = "Para usuarios de Haiku, pueden encontrar los nombres de paquetes válidos aquí: https://depot.haiku-os.org/.";
            translations["forsnap"] = "Para usuarios de Snap, pueden encontrar los nombres de paquetes válidos aquí: https://snapcraft.io/store.";
            translations["packagename"] = "Escribe el nombre del paquete aquí: ";
            translations["about1"] = "OneClickAppInstaller es una herramienta de línea de comandos sencilla que te permite crear un script para instalar todas tus aplicaciones en Windows, macOS o Linux automáticamente con solo un clic.";
            translations["about2"] = "Esta herramienta fue creada por MasterJayanX.";
            translations["about3"] = "Versión: ";
            translations["about4"] = "Revisa el historial de versiones completo aquí: https://github.com/MasterJayanX/OneClickAppInstaller/releases";
            translations["nomoreapps"] = "No se agregarán más aplicaciones.";
            translations["enablesearch"] = "¿Deseas habilitar la función de búsqueda? [y/n] Esto te permitirá buscar los nombres de paquetes desde aquí. Sin embargo, solo funcionará si estás usando el mismo SO que el que elegiste para el script.";
            translations["search"] = "Escribe el nombre del paquete que deseas buscar: ";
            translations["found"] = "¿Encontraste la aplicación que buscabas? [y/n] Si no la encontraste, escribe n para buscar de nuevo.";
            translations["added"] = "Aplicación agregada.";
            translations["pressenter"] = "Presiona Enter para salir...";
            translations["pressenter2"] = "Presiona Enter para volver al Menú...";
            translations["cringe"] = "Bruh, das cringe.";
            translations["how"] = "¿Cómo llegaste aquí?";
            translations["language"] = "Idioma seleccionado: Español";
            translations["autoapps"] = "Tus aplicaciones se agregarán automáticamente. Número de aplicaciones que se agregarán: ";
            translations["useros"] = "Sistema operativo del usuario: ";
            translations["selected"] = "Opción seleccionada: ";
            translations["done"] = "¡Listo! Todas tus aplicaciones han sido instaladas.";
            translations["choosewin"] = "Elige tu versión de Windows: ";
            translations["win10"] = "Windows 10 o superior";
            translations["oldwin"] = "Windows 8.1 o inferior";
        }
        else{
            // Open a language file
            ifstream file(language);
            if (!file.is_open()) {
                cerr << "Language file not found. / Archivo de idioma no encontrado." << endl;
                lang_file_opened = false;
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
    }
};
void secrets(int s, Translator translator){
    // Secrets
    if(s == 0){
        cout << translator.translate("how") << endl;
    }
    if(s == 1){
        // Shrek
        ofstream shrek("shrek.txt");
        shrek << "Shrek is love, Shrek is life." << endl; // This line was generated by Copilot
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
        // Cringe
        cout << translator.translate("cringe") << endl;
    }
    else if(s == 3){
        /*Among Us is a video game developed by Innersloth LLC. It was released on June 15, 2018 on iOS and Android, and on August 18, 2018 on Steam. 
        The game is about a group of crew members aboard a spaceship. One of them is an impostor who will kill the other crew members. 
        The crew members must find out who the impostor is and vote him out of the ship. The impostor must kill all the crew members without being discovered. 
        The game has become very popular in 2020, and has been played by many famous YouTubers and Twitch streamers. Thanks for the description, Copilot.*/ 
        ofstream amongus("amongus.txt");
        cout << "sus" << endl;
        amongus << "ඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞ" << endl;
        amongus << "Among Us is a video game developed by Innersloth LLC. It was released on June 15, 2018 on iOS and Android, and on August 18, 2018 on Steam." << endl;
        amongus << "The game is about a group of crew members aboard a spaceship. One of them is an impostor who will kill the other crew members." << endl;
        amongus << "The crew members must find out who the impostor is and vote him out of the ship. The impostor must kill all the crew members without being discovered." << endl;
        amongus << "The game has become very popular in 2020, and has been played by many famous YouTubers and Twitch streamers." << endl;
        amongus << "ඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞඞ" << endl;
        amongus.close();
    }
    else if(s == 4){
        // Dubidubidu
        int pausa = 2;
        cout << "Chipi chipi, chapa chapa" << endl;
        sleep(pausa);
        cout << "Dubi dubi, daba daba" << endl;
        sleep(pausa);
        cout << "Mágico mi dubi dubi" << endl; // It's not Magic Pony, you know?
        sleep(pausa);
        cout << "Boom boom boom boom" << endl;
        sleep(pausa);
        cout << "Chipi chipi, chapa chapa" << endl;
        sleep(pausa);
        cout << "Dubi dubi, daba daba" << endl;
        sleep(pausa);
        cout << "Mágico mi dubi dubi" << endl;
        sleep(pausa);
        cout << "Boom" << endl;
        sleep(1);
    }
}