# Simulation Parameters pour MacOS & Linux

![alt text](https://laboratoirehubertcurien.univ-st-etienne.fr/skins/labhcurien/resources//img/logo.png "Laboratoire Hubert Curien")

Un [Guide Utilisateur](https://github.com/cedric-gormond/simulation_parameters/blob/master/Guide%20utilisateur%20simulation%20parameters.pdf) illustré est disponible dans le dossier du projet.

## Pour commencer
**Simulation Parameters** pour MacOS & Linux permet de créer des fichiers paramétrés pour les simulations sur des architectures NoC sur FPGA. Ce programme a été créé pour le **Laboratoire Hubert Curien (CNRS)**.

## Installation
Vous devez extraire le contenu de l'archive dans un espace de travail. Pour utiliser le programme, vous devez lancer l'exécutable `simulation_parameters.exe` contenue dans le dossier.

##	Comment générer un fichier de simulation ?
1. Choisissez le nombre total de scénario que vous voulez réaliser. Ce nombre doit être **strictement positif**.

2.  Pour chaque scénario, remplissez ces paramètres en précisant le nombre **d’audio**, de **vidéo**, **data**, le **nombre de paquets**, leur **taille** et la **charge** (idle) comprise en 1% et 100%.

     Vous avez la possibilité de choisir des paramètre aléatoires en cliquant sur le bouton « **Random scenario** ».

3.  Cliquez sur **« Generate simulation parameters files »** pour générer les fichiers de simulation.  Cela génèrera autant de fichiers que de scénarios. 


## Comment récupérer un fichier de simulation généré ?
Les fichiers de simulation sont générés dans le dossier io du projet au format imposé. Les fichiers générés respectent les appellations suivantes : `Simulation Parameters i` avec `i` allant de 0 à nombre de scénario–1.

## Logs
Le logiciel possède une partie log permettant de vous informer sur les différentes opérations effectuées.

## Bugs
Il se peut que le programme possède des bugs ou des erreurs mémoires. S’il-vous-plaît, envoyez un mail à l’adresse suivante ou de proposer une issue sur Github afin de les corriger : cedric.gormond@gmail.com 
