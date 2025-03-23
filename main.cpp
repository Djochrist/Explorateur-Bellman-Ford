#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <windows.h>

using namespace std;

// Fonction pour changer la couleur du texte en console
void changerCouleur(int couleur) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), couleur);
}

// Structure pour representer une connexion entre deux amis
struct Connexion {
    string source;
    string destination;
    int poids;
};

// Fonction pour implementer l'algorithme de Bellman-Ford
void bellmanFord(const vector<Connexion>& connexions, const vector<string>& amis, const string& depart, const string& arrivee) {
    unordered_map<string, int> distances;
    unordered_map<string, string> predecesseurs;

    for (const string& ami : amis) {
        distances[ami] = INT_MAX;
        predecesseurs[ami] = "";
    }
    distances[depart] = 0;

    changerCouleur(14);
    cout << "Initialisation des distances :" << endl;
    for (const string& ami : amis) {
        cout << ami << " : " << (distances[ami] == INT_MAX ? "INF" : to_string(distances[ami])) << endl;
    }
    Sleep(1000);

    for (size_t i = 1; i < amis.size(); ++i) {
        changerCouleur(11);
        cout << "\nEtape " << i << " : Relachement des connexions" << endl;

        for (const Connexion& connexion : connexions) {
            string u = connexion.source;
            string v = connexion.destination;
            int w = connexion.poids;

            if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                predecesseurs[v] = u;

                changerCouleur(10);
                cout << "Mise a jour : " << u << " -> " << v << " (nouvelle distance = " << distances[v] << ")" << endl;
                Sleep(500);
            }
        }
    }

    changerCouleur(12);
    cout << "\nVerification des cycles negatifs..." << endl;
    for (const Connexion& connexion : connexions) {
        string u = connexion.source;
        string v = connexion.destination;
        int w = connexion.poids;

        if (distances[u] != INT_MAX && distances[u] + w < distances[v]) {
            cout << "Le graphe contient un cycle negatif !" << endl;
            return;
        }
    }
    cout << "Aucun cycle negatif detecte." << endl;
    Sleep(1000);

    changerCouleur(13);
    cout << "\nResultat final :" << endl;
    if (distances[arrivee] == INT_MAX) {
        cout << "Aucun chemin trouve entre " << depart << " et " << arrivee << "." << endl;
    } else {
        cout << "Chemin le plus court de " << depart << " a " << arrivee << " : ";
        vector<string> chemin;
        string courant = arrivee;

        while (courant != "") {
            chemin.push_back(courant);
            courant = predecesseurs[courant];
        }

        for (int i = chemin.size() - 1; i >= 0; --i) {
            changerCouleur(15);
            cout << chemin[i];
            if (i != 0) cout << " -> ";
        }
        changerCouleur(10);
        cout << " (distance = " << distances[arrivee] << ")" << endl;
    }
}

int main() {
    vector<string> amis;
    cout << "Entrez le nombre d'amis : ";
    int nbAmis;
    cin >> nbAmis;
    cin.ignore();

    for (int i = 0; i < nbAmis; ++i) {
        string ami;
        cout << "Entrez l'ami " << i + 1 << " : ";
        getline(cin, ami);
        amis.push_back(ami);
    }

    vector<Connexion> connexions;
    cout << "\nEntrez le nombre de connexions : ";
    int nbConnexions;
    cin >> nbConnexions;
    cin.ignore();

    for (int i = 0; i < nbConnexions; ++i) {
        string source, destination;
        int poids;
        cout << "\nConnexion " << i + 1 << " :" << endl;
        cout << "Entrez l'ami source : ";
        getline(cin, source);
        cout << "Entrez l'ami destination : ";
        getline(cin, destination);
        cout << "Entrez le poids : ";
        cin >> poids;
        cin.ignore();
        connexions.push_back({source, destination, poids});
    }

    string depart, arrivee;
    cout << "\nEntrez l'ami de depart : ";
    getline(cin, depart);
    cout << "Entrez l'ami d'arrivee : ";
    getline(cin, arrivee);

    bellmanFord(connexions, amis, depart, arrivee);

    return 0;
}
