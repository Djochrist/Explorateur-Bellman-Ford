Ce projet est une implémentation en C++ de l'algorithme de Bellman-Ford, conçue pour trouver le chemin le plus court entre deux nœuds dans un graphe pondéré. Le programme permet à l'utilisateur de saisir interactivement les nœuds (appelés "amis" dans le code), les connexions entre ces nœuds (appelées "connexions"), et les poids associés à ces connexions. Ensuite, il calcule et affiche le chemin le plus court entre deux nœuds spécifiés par l'utilisateur.

Fonctionnalités principales :
Saisie interactive : L'utilisateur peut entrer les nœuds, les connexions et les poids.

Calcul du chemin le plus court : Le programme utilise l'algorithme de Bellman-Ford pour déterminer le chemin optimal entre deux nœuds.

Détection des cycles négatifs : Le programme vérifie si le graphe contient des cycles négatifs, qui pourraient rendre le problème insoluble.

Affichage détaillé : Chaque étape de l'algorithme est affichée en temps réel, avec des couleurs pour une meilleure lisibilité.

Déroulement du programme :
L'utilisateur entre le nombre de nœuds (amis) et leurs noms.

L'utilisateur entre le nombre de connexions, puis pour chaque connexion, il spécifie le nœud source, le nœud destination et le poids de la connexion.

L'utilisateur spécifie le nœud de départ et le nœud d'arrivée.

Le programme exécute l'algorithme de Bellman-Ford, affiche les étapes intermédiaires (initialisation des distances, relâchement des connexions, détection des cycles négatifs), et enfin affiche le chemin le plus court et la distance totale.

Exemple d'utilisation :
Entrée :

Nombre d'amis : 5 (Alice, Bob, Charlie, Diana, Eve)

Connexions :

Alice -> Bob (poids = 1)

Bob -> Charlie (poids = 1)

Charlie -> Diana (poids = 1)

Diana -> Eve (poids = 1)

Alice -> Diana (poids = 2)

Nœud de départ : Alice

Nœud d'arrivée : Eve

Sortie :

Le programme affiche le chemin le plus court (Alice -> Diana -> Eve) et la distance totale (3).

Cas d'utilisation :
Réseaux sociaux : Trouver le chemin le plus court entre deux utilisateurs (par exemple, le nombre minimum d'amis communs pour relier deux personnes).

Réseaux de transport : Optimiser les trajets en fonction des distances ou des coûts.

Réseaux informatiques : Calculer les routes les plus efficaces pour envoyer des données.

Apprentissage : Comprendre et visualiser le fonctionnement de l'algorithme de Bellman-Ford.

Technologies utilisées :
Langage : C++

Bibliothèques : iostream, vector, climits, unordered_map, windows.h (pour les couleurs en console)

Comment exécuter le programme :
Compilez le code avec un compilateur C++ (par exemple, g++).

Exécutez le programme et suivez les instructions à l'écran pour entrer les données et obtenir le résultat.

Ce projet est à la fois éducatif et pratique, permettant de comprendre et d'appliquer l'algorithme de Bellman-Ford dans un contexte interactif et visuel.
