# OneClickAppInstaller
[![GitHub release](https://img.shields.io/github/v/release/MasterJayanX/OneClickAppInstaller.svg)](https://github.com/MasterJayanX/OneClickAppInstaller/releases) [![GitHub all releases](https://img.shields.io/github/downloads/MasterJayanX/OneClickAppInstaller/total)](https://github.com/MasterJayanX/OneClickAppInstaller/releases)
### Langues
[English](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README.md) | [Español](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_ES.md) | [Français](https://github.com/MasterJayanX/OneClickAppInstaller/blob/main/README_FR.md)
## Description
OneClickAppInstaller est un simple outil de ligne de commandes qui vous permet de créer un script pour installer automatiquement toutes vos applications sur Windows, macOS ou Linux en un seul clic.
## Liste de compatibilité
### Windows :

- Windows 10 ou supérieur. Le logiciel peut fonctionner sur des versions plus anciennes de Windows, mais le script résultant ne s'exécutera que sur Windows 10 ou supérieur car il utilise [winget](https://github.com/microsoft/winget-cli "winget") pour installer des packages.

### macOS :

- macOS 12 (Monterey) ou supérieur avec [Homebrew](https://github.com/Homebrew/brew) installé.

### Linux :
Voici une liste de distributions Linux compatibles pour chaque option du menu :

- `Ubuntu/Debian` : Ubuntu, Debian, Linux Mint, PopOS!, toutes les saveurs d'Ubuntu comme Kubuntu, MX Linux, antiX, PeppermintOS, Deepin, elementaryOS et ChromeOS avec le mode Linux installé. **Note** : KDE Neon pourrait fonctionner, mais il pourrait y avoir des problèmes car le script utilise la commande `sudo apt upgrade` pour mettre à jour les applications.
- `Arch` : Arch Linux, Manjaro, EndeavourOS, Garuda, SteamOS, Crystal Linux et ChimeraOS.
- `Fedora / Red Hat` : Fedora, Fedora Spins, Red Hat Enterprise Linux (RHEL) 8 ou supérieur, AlmaLinux et Rocky Linux.
- `openSUSE` : SUSE, openSUSE Leap et openSUSE Tumbleweed.
- `Red Hat Enterprise Linux (RHEL)` : Red Hat Enterprise Linux (RHEL) 7 ou inférieur.
- `Flatpak` : Toute distribution Linux capable d'exécuter [Flatpak](https://flatpak.org).

### Autres systèmes d'exploitation :

- FreeBSD
- OpenBSD
- NetBSD
- Haiku

## Installation
Pour installer le créateur de scripts de OneClickAppInstaller, il vous suffit de télécharger et exécuter le logiciel disponible dans l'onglet Releases. Si vous êtes sous Windows, vous devez sélectionner le fichier .exe qui correspond à la langue de votre choix et l'exécuter. 
Si vous êtes sous macOS, Linux ou WSL (Windows Subsystem for Linux), vous devez sélectionner le fichier .sh qui correspond à la langue de votre choix et l'exécuter depuis le terminal avec la syntaxe suivante : ./file.sh 
(remplacer file avec le nom réel du fichier).

## Utilisation
Suivez ces étapes pour utiliser OneClickAppInstaller :
1. Ouvrez le fichier .exe ou .sh et lorsque le programme vous demande de sélectionner une langue, appuyez sur 1, 2 ou 3 selon la langue que vous souhaitez utiliser.
2. Ici, le programme vous demandera de sélectionner une option. Choisissez 1, 2 ou 3 en fonction du système opératif dans lequel vous souhaitez utiliser votre script résultant (1 pour Windows, 2 pour macOS, 3 pour Linux ou 4 pour autres systèmes opératifs). Si vous choisissez Linux, vous devrez sélectionner une distribution ou un groupe de distributions dans la liste. Si votre distribution n'apparaît pas dans la liste, c'est probablement parce que votre distribution est basée sur l'une des distributions de la liste. Par exemple, pour Linux Mint ou PopOS, choisissez Ubuntu/Debian et pour Manjaro, choisissez Arch.
3. Si vous choisissez Windows ou macOS, le programme vous demandera si vous souhaitez que le script installe winget (pour Windows) ou Homebrew (pour macOS). Appuyez sur y si vous souhaitez que le script installe cet outil ou n si vous l'avez déjà installé (vous aurez probablement installé winget si vous avez Windows 11, vous pouvez donc simplement appuyer sur n).
4. Le programme vous demandera maintenant si vous souhaitez un nom personnalisé pour votre script. Appuyez sur y si vous souhaitez nommer le script ou sur n si vous ne le souhaitez pas. Noter que vous pouvez renommer votre fichier à tout moment. Ensuite, il vous demandera si vous souhaitez recevoir un message de bienvenue personnalisé. Il s'agit d'une ligne de texte qui apparaîtra lorsque vous exécuterez le script. Appuyez sur y si vous souhaitez saisir un message de bienvenue personnalisé ou sur n si vous ne le souhaitez pas.
5. Après la configuration initiale, vous devez saisir les noms des applications que vous souhaitez installer à l'aide de votre script. Noter que vous devez saisir les noms de vos applications en utilisant une syntaxe spécifique en fonction de votre système d'exploitation et/ou gestionnaire de packages. Si vous voulez savoir quelles applications vous pouvez installer sur votre système d'exploitation, rendez-vous sur le site Web montré dans le programme.
6. Appuyez sur y lorsque le programme vous demande si vous souhaitez ajouter des applications à votre script. Une fois que vous avez terminé, appuyez simplement sur n lorsque le programme vous demande si vous souhaitez ajouter d'autres applications.

## Compilation
### Exigences
- Avoir le compilateur g++ installé sur votre ordinateur (pour les utilisateurs de Windows, vous pouvez l'installer avec MinGW ou utiliser WSL).

Pour compiler ce programme vous-même, vous devez télécharger les fichiers .cpp et .hpp et les enregistrer dans le même répertoire. Vous pouvez également télécharger les fichiers du référentiel à l'aide de la commande suivante sur une fenêtre de terminal : `git clone https://github.com/MasterJayanX/OneClickAppInstaller`.
Ensuite, vous devez ouvrir une fenêtre de terminal et compiler le fichier main.cpp avec la commande suivante : `g++ main.cpp -o output` (vous pouvez remplacer output par un nom de votre choix).

## FAQ (Foire aux questions)
### Quels systèmes opératifs sont pris en charge par ce logiciel ?
Les systèmes opératifs officiellement pris en charge pour le moment sont : Windows 10/11, macOS, Ubuntu, Debian, Arch Linux, Fedora, OpenSUSE, Red Hat Enterprise Linux et d'autres systèmes opératifs. Le logiciel lui-même fonctionnera sur tout ce qui peut exécuter des fichiers .sh, mais il ne peut créer des scripts que pour les systèmes opératifs mentionnés ci-dessus.
### Y a-t-il d'autres systèmes opératifs qui seront pris en charge à l'avenir ?
Je ne suis pas encore sûr des autres systèmes opératifs qui devraient être ajoutés dans les futures versions.
### J'ai trouvé un bogue ou le logiciel ne fonctionne pas bien. Où puis-je signaler ces problèmes ?
Vous pouvez ouvrir un nouveau problème dans la section "Issues" et je m'en occuperai dès que possible.
### Comment puis-je utiliser mes propres fichiers de langue ?
Après avoir créé votre fichier de langue basé sur le modèle fourni, vous devez simplement l'enregistrer dans le même dossier que celui où vous avez l'exécutable OneClickAppInstaller. Ensuite, dans la section de langue, choisissez "Autre / Otro" et lorsque vous êtes invité à entrer le nom de votre fichier, saisissez simplement le nom du fichier que vous avez créé (y compris l'extension).
### Comment puis-je créer un fichier de configuration ?
Pour créer votre propre fichier de configuration, vous pouvez simplement utiliser l'un des fichiers de configuration du dossier "config examples" et utiliser l'un de ces fichiers comme modèle. N'oubliez pas de renommer le fichier en oneclick_config.txt ou oneclickconfig.txt et de supprimer tous les commentaires avant de l'utiliser comme votre configuration.
### Comment puis-je partager mes fichiers de langue ?
Actuellement, vous ne pouvez pas le faire, mais vous pouvez me les envoyer via mes réseaux sociaux (mes pages de réseaux sociaux se trouvent dans [mon profil](https://github.com/MasterJayanX)).
## Donations
J'accepte des donations sur Ko-fi:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/D1D37FMC3)
