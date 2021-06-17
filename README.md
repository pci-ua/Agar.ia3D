# Agar.ia 3D

Agar.ia est un jeu vidéo développé en C++ par l'association PC[i], une version de Agar.io destiné a des IA

![Build linux](https://github.com/pci-ua/Agar.ia3D/actions/workflows/c-cpp.yml/badge.svg)

## Installation

#### Linux
1. Assurez-vous d'être à jour :

    ```bash
    sudo apt update
    sudo apt upgrade
    ```

2. Installez les dépendances :

    ```bash
    sudo apt install make g++
    sudo apt install qtchooser #Inutilisée pour l'instant
    sudo apt install qt5-default qtmultimedia5-dev build-essential freeglut3-dev #Inutilisée pour l'instant
    ```

3. Compilez le programme :
     ```bash
    make
    ```

#### Windows

 En préparation


## Création de votre IA

Pour créé votre programme d'IA, vous pouvez créé dans le dossier `/Intelligence` une IA
soit en partant de zéro, soit en partant d'un modèle déjà éxistant :

  - Tay : Une IA parfaite pour débuter tranquillement !
     Vous avez juste besoin d'écrire votre code dans le fichier `Tay.cc`
     toutes les informations sont directement mise dans ce fichier.

  - Indila : Un pattern d'IA plus pousser.
    Si vous avez de bonne base en C++ et que la programmation orienté objet ne vous fait pas peur,
    ce template est fait pour vous, en effet vous trouverez dans `Indila.cc` et dans `Indila.hh`
    un code qui n'attend que votre implémentation, toutes les indications sur les prérequis sont à l'interrieur!


## Contribué
Pour l'instant toutes les contributions sont limités au groupes de développeur qui y sont affecté

## License
Pour l'instant aucune utilisiation (qu'elle soit personnel ou non,commercial ou non)
