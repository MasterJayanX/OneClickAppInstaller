# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases)
### Idiomas
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Francais](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Descripción
OneClickAppInstaller es una herramienta de línea de comandos sencilla que te permite crear un script para instalar todas tus aplicaciones en Windows, macOS o Linux automáticamente con solo un clic.
## Requisitos
Windows:

- Windows 10 en adelante. Es posible que el software funcione en versiones anteriores de Windows, pero el script resultante solo se ejecutará en Windows 10 o superiores, porque utiliza [winget](https://github.com/microsoft/winget-cli "winget") para instalar paquetes.

macOS:

- Cualquier versión de macOS que pueda ejecutar [Homebrew](https://github.com/Homebrew/brew).

Linux:

- Ubuntu o Debian (cualquier versión con soporte debería funcionar). Otras distribuciones basadas en Ubuntu o Debian también funcionarán.
- Arch/Manjaro, Fedora y OpenSUSE también son compatibles ahora.

## Instalación
Para instalar el Creador de Scripts de OneClickAppInstaller, solo necesitas ejecutar el software disponible en la pestaña Lanzamientos (Releases). Si estás en Windows, debe seleccionar el archivo .exe que corresponda al idioma de su elección y ejecutarlo. Si estás en macOS, Linux o WSL (Subsistema de Windows para Linux), debes seleccionar el archivo .sh que corresponda al idioma de su elección y ejecutarlo desde la terminal con la siguiente sintaxis: ./archivo.sh (reemplace archivo por el verdadero nombre del archivo).

## Compilar
### Requisitos
- Tener instalado el compilador g++ en tu computadora (para usuarios de Windows, puedes instalar con MinGW o usar WSL).

Para compilar este programa tú mismo, debes descargar los archivos .cpp y .hpp y guardarlos en el mismo directorio. Alternativamente, puedes descargar los archivos del repositorio usando el siguiente comando en una ventana de terminal: `git clone https://github.com/MasterJayanX/OneClickAppInstaller`.
Luego, debes abrir una ventana de terminal y compilar el archivo .cpp con el siguiente comando: `g++ oneclickscripter.cpp -o salida` (puedes reemplazar la salida con el nombre que desee).

## Donaciones
Acepto donaciones a través de Ko-fi:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
