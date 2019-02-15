# Simulation Parameters pour Windows

![alt text](https://laboratoirehubertcurien.univ-st-etienne.fr/skins/labhcurien/resources//img/logo.png "Laboratoire Hubert Curien")

Un [Guide Utilisateur](https://github.com/cedric-gormond/simulation_parameters/blob/master/Guide%20utilisateur%20simulation%20parameters.pdf) illustré est disponible dans le dossier du projet.

## Pour commencer
**Simulation Parameters** pour Windows permet de créer des fichiers paramétrés pour les simulations sur des architectures NoC sur FPGA. Ce programme a été créé pour le **Laboratoire Hubert Curien (CNRS)**.

## Installation
Vous devez extraire le contenu de l'archive dans un espace de travail. Pour utiliser le programme, vous devez lancer l'exécutable `simulation_parameters.exe` contenue dans le dossier.

## Comment générer un fichier de simulation ?
1. Choisissez le nombre total de scénario que vous voulez réaliser (le nombre est de 2 par défaut). Ce nombre doit être strictement positif. Après avoir changé le nombre de scénarios, appuyez sur le boutton « Size changed », pour prendre en compte les modifications.

2. Précisez les dimensions de l’architecture NoC avec laquelle vous travaillez en entrant le nombre de routeurs en X (dimX) et le nombre de routeurs en Y (dimY).

3. Pour chaque scénario, remplissez ces paramètres en précisant le nombre d’audio, de vidéo, data, le nombre de paquets, leur taille et la charge (idle) comprise en 1% et 100%. Pour choisir un scénario, faites glisser le curseur.

4. (Optionnel) Vous avez la possibilité de choisir des paramètres aléatoires en cliquant sur le bouton « Random scenario ».
De plus, vous pouvez configurer ces paramètres aléatoires en spécifiant les bornes min et max où seront compris les nombres aléatoires pour chaque scénario. 
Par exemple,  vous pouvez choisir de générer un nombre aléatoire de paquets entre 0 et 10 pour le scénario numéro 1. Attention de bien vérifier les bornes pour chaque scénario : une borne maximale nulle entrainera une erreur.

5. Cliquez sur « Generate simulation parameters files » pour générer les fichiers de simulation.  Cela génèrera autant de fichiers que de scénarios.

## Comment récupérer un fichier de simulation généré ?
Les fichiers de simulation sont générés dans le dossier io du projet au format imposé. Les fichiers générés respectent les appellations suivantes : `Simulation Parameters i` avec `i` allant de 0 à nombre de scénario–1.

## Bugs
Le programme étant réalisé en peu de temps, celui-ci possède des bugs ou des erreurs mémoires. S’il-vous-plaît, envoyez un mail à l’adresse suivante ou de proposer une issue sur Github afin de les corriger : cedric.gormond@gmail.com 

### Crash après avoir appuyé sur le bouton « Random scenario»
L’application peut crasher après avoir appuyez sur le bouton « Random scenario » afin de générer des paramètres aléatoires. Si c’est le cas, le programme n’a pas pris en compte : 
- le changement du nombre de scénarios. Relancez le programme, appliquez le nombre de scénarios souhaité et appuyez sur le bouton « Size changed ». Appliquez ensuite les paramètres entrés avant le crash de l’application.
- les changement des bornes de la génération d’un nombre aléatoire pour chaque scénarios. Relancez le programme, appliquez le nombre de scénarios souhaité et appuyez sur le bouton « Size changed ». Appliquez ensuite les paramètres entrés avant le crash de l’application et vérifiez les bornes en cliquant sur la section Random Bound.

### Crash après avoir généré un fichier
L’application peut crasher après avoir généré un fichier. Si c’est le cas, vérifiez dans le répertoire io du projet si les fichiers ont bien été généré (regardez par exemple la date des fichiers). Sinon, relancez le programme.

### Crash en fermant le programme
L’application peut crasher après avoir tenté de la fermer. Si c’est le cas, ne vous inquiétez pas, les fichiers ont bien été générés dans le répertoire io du projet.
