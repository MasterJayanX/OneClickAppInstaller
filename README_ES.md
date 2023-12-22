# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases)
### Idiomas
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Français](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
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
Para instalar el Creador de Scripts de OneClickAppInstaller, solo necesitas descargar y ejecutar el software más reciente disponible en la pestaña Lanzamientos (Releases). Si estás en Windows, debe seleccionar el archivo .exe que corresponda al idioma de su elección y ejecutarlo. Si estás en macOS, Linux o WSL (Subsistema de Windows para Linux), debes seleccionar el archivo .sh que corresponda al idioma de su elección y ejecutarlo desde la terminal con la siguiente sintaxis: ./archivo.sh (reemplace archivo por el verdadero nombre del archivo).

## Uso
Sigue estos pasos para utilizar OneClickAppInstaller:
1. Abre el archivo .exe o .sh y cuando el programa te solicite seleccionar un idioma, presiona 1 o 2 según el idioma que desees utilizar.
2. Aquí, el programa te pedirá que selecciones una opción. Elija 1, 2 o 3 según el sistema operativo en el que desees utilizar el script resultante (1 para Windows, 2 para macOS o 3 para Linux). Si eliges Linux, deberás seleccionar una distribución o grupo de distribuciones de la lista. Si su distribución no aparece en la lista, probablemente se deba a que tu distribución se basa en una de las distribuciones de la lista. Por ejemplo, para Linux Mint o PopOS, elige Ubuntu/Debian y para Manjaro, elige Arch.
3. Si eliges Windows o macOS, el programa te preguntará si deseas que el script instale winget (para Windows) o Homebrew (para macOS). Presione y si deseas que el script instale esta herramienta o n si ya la tienes instalada (lo más probable es que tengas instalado winget si usas Windows 11, por lo que en ese caso puedes simplemente presionar n).
4. El programa ahora te preguntará si deseas ponerle un nombre personalizado a tu script. Presiona y si deseas nombrar el script o n en caso contrario. Ten en cuenta que puedes cambiar el nombre del archivo en cualquier momento. Luego, te preguntará si deseas tener un mensaje de bienvenida personalizado. Esta es una línea de texto que aparecerá cuando ejecutes el script. Presiona y si quieres ingresar un mensaje de bienvenida personalizado o n si no quieres.
5. Después de la configuración inicial, debes ingresar los nombres de las aplicaciones que deseas instalar usando el script. Ten en cuenta que debes ingresar los nombres de las aplicaciones usando una sintaxis específica dependiendo de su sistema operativo y/o gestor de paquetes. Si quieres saber qué aplicaciones puedes instalar en tu sistema operativo, accede al sitio web que se muestra en el programa.
6. Presiona y cuando se te pregunte si deseas agregar aplicaciones a tu script. Una vez que hayas terminado de agregar aplicaciones, simplemente presiona n cuando se te pregunte si desea agregar más aplicaciones.
​
## Compilación
### Requisitos
- Tener instalado el compilador g++ en tu computadora (para usuarios de Windows, puedes instalar con MinGW o usar WSL).

Para compilar este programa tú mismo, debes descargar los archivos .cpp y .hpp y guardarlos en el mismo directorio. Alternativamente, puedes descargar los archivos del repositorio usando el siguiente comando en una ventana de terminal: `git clone https://github.com/MasterJayanX/OneClickAppInstaller`.
Luego, debes abrir una ventana de terminal y compilar el archivo .cpp con el siguiente comando: `g++ oneclickscripter.cpp -o salida` (puedes reemplazar la salida con el nombre que desee).

## Preguntas frecuentes
### ¿Qué sistemas operativos son compatibles con este software?
Los sistemas operativos oficialmente soportados en este momento son: Windows 10/11, macOS, Ubuntu, Debian, Arch Linux, Fedora y OpenSUSE. El software en sí se ejecutará en cualquier cosa que pueda ejecutar archivos .sh, pero sólo puede crear scripts para los sistemas operativos antes mencionados.
### ¿Hay algún sistema operativo que será compatible en el futuro?
Planeo agregar compatibilidad con RHEL (Red Hat Enterprise Linux) en la próxima versión.
### Encontré un error o el software simplemente no funciona bien. ¿Dónde puedo informar estos problemas?
Puede abrir un nuevo problema en la sección Problemas y me ocuparé de ello tan pronto como pueda.
### ¿Cómo puedo utilizar mis propios archivos de idioma?
Después de crear tu archivo de idioma basado en el archivo de plantilla, solo necesitas guardarlo en la misma carpeta donde tienes el ejecutable OneClickAppInstaller. Luego, en la sección de idioma, elige "Other / Otro" y cuando se te solicite ingresar el nombre de su archivo, simplemente ingresa el nombre del archivo creado (incluyendo la extensión).
### ¿Cómo puedo compartir mis archivos de idioma?
Actualmente no puedes, pero puedes enviármelos a mis redes sociales (mis páginas de redes sociales están en [mi perfil](https://github.com/MasterJayanX)).

## Donaciones
Acepto donaciones a través de Ko-fi:
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
