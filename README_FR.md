# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases)
### Langues
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Français](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Description
OneClickAppInstaller est un simple outil de ligne de commandes qui vous permet de créer un script pour installer automatiquement toutes vos applications sur Windows, macOS ou Linux en un seul clic.
## Exigences
Windows:

- Windows 10 ou supérieur. Le logiciel peut fonctionner sur les anciennes versions de Windows, mais le script résultant ne s'exécutera que sur Windows 10 ou supérieur car il utilise [winget](https://github.com/microsoft/winget-cli "winget") pour installer les applications.

macOS :

- Toute version de macOS pouvant exécuter [Homebrew](https://github.com/Homebrew/brew).

Linux :

- Ubuntu ou Debian (toute version actuellement prise en charge devrait fonctionner). D'autres distributions basées sur Ubuntu ou Debian fonctionneront également.
- Arch/Manjaro, Fedora et OpenSUSE sont également désormais pris en charge.

## Installation
Pour installer le créateur de scripts de OneClickAppInstaller, il vous suffit d'exécuter le logiciel disponible dans l'onglet Releases. Si vous êtes sous Windows, vous devez sélectionner le fichier .exe qui correspond à la langue de votre choix et l'exécuter. 
Si vous êtes sous macOS, Linux ou WSL (Windows Subsystem for Linux), vous devez sélectionner le fichier .sh qui correspond à la langue de votre choix et l'exécuter depuis le terminal avec la syntaxe suivante : ./file.sh 
(remplacer file avec le nom réel du fichier).

## Utilisation
Suivez ces étapes pour utiliser OneClickAppInstaller :
1. Ouvrez le fichier .exe ou .sh et lorsque le programme vous demande de sélectionner une langue, appuyez sur 1 ou 2 selon la langue que vous souhaitez utiliser.
2. Ici, le programme vous demandera de sélectionner une option. Choisissez 1, 2 ou 3 en fonction du système opératif dans lequel vous souhaitez utiliser votre script résultant (1 pour Windows, 2 pour macOS ou 3 pour Linux). Si vous choisissez Linux, vous devrez sélectionner une distribution ou un groupe de distributions dans la liste. Si votre distribution n'apparaît pas dans la liste, c'est probablement parce que votre distribution est basée sur l'une des distributions de la liste. Par exemple, pour Linux Mint ou PopOS, choisissez Ubuntu/Debian et pour Manjaro, choisissez Arch.
3. Si vous choisissez Windows ou macOS, le programme vous demandera si vous souhaitez que le script installe winget (pour Windows) ou Homebrew (pour macOS). Appuyez sur y si vous souhaitez que le script installe cet outil ou n si vous l'avez déjà installé (vous aurez probablement installé winget si vous avez Windows 11, vous pouvez donc simplement appuyer sur n).
4. Le programme vous demandera maintenant si vous souhaitez un nom personnalisé pour votre script. Appuyez sur y si vous souhaitez nommer le script ou sur n si vous ne le souhaitez pas. Noter que vous pouvez renommer votre fichier à tout moment. Ensuite, il vous demandera si vous souhaitez recevoir un message de bienvenue personnalisé. Il s'agit d'une ligne de texte qui apparaîtra lorsque vous exécuterez le script. Appuyez sur y si vous souhaitez saisir un message de bienvenue personnalisé ou sur n si vous ne le souhaitez pas.
5. Après la configuration initiale, vous devez saisir les noms des applications que vous souhaitez installer à l'aide de votre script. Noter que vous devez saisir les noms de vos applications en utilisant une syntaxe spécifique en fonction de votre système d'exploitation et/ou gestionnaire de packages. Si vous voulez savoir quelles applications vous pouvez installer sur votre système d'exploitation, rendez-vous sur le site Web montré dans le programme.
6. Appuyez sur y lorsque le programme vous demande si vous souhaitez ajouter des applications à votre script. Une fois que vous avez terminé, appuyez simplement sur n lorsque le programme vous demande si vous souhaitez ajouter d'autres applications.

## Compilation
### Exigences
- Avoir le compilateur g++ installé sur votre ordinateur (pour les utilisateurs de Windows, vous pouvez l'installer avec MinGW ou utiliser WSL).

Pour compiler ce programme vous-même, vous devez télécharger les fichiers .cpp et .hpp et les enregistrer dans le même répertoire. Vous pouvez également télécharger les fichiers du référentiel à l'aide de la commande suivante sur une fenêtre de terminal : `git clone https://github.com/MasterJayanX/OneClickAppInstaller`.
Ensuite, vous devez ouvrir une fenêtre de terminal et compiler le fichier .cpp avec la commande suivante : `g++ oneclickscripter.cpp -o output` (vous pouvez remplacer output par un nom de votre choix).

## Donations
J'accepte des donations sur Ko-fi:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
