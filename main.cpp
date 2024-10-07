#include <iostream>
using namespace std;
//fonction pour savoir si la nombre est premier ou pas
bool estPremier(int nombre) {
    for (int i = 2; i * i <= nombre; i++) {
        if (nombre % i == 0) {
            return false;
        }
    }
    return true;
}

//main
int main() {
    int limite;
    char recommencer;
    //fonction récurrente tant que utilisateur n'a pas dit N
    do {
        cout << "Ce programme ..." << endl << endl;
        cout << "Entrer une valeur [2-1000] :" << endl;
        cin >> limite; //foncti2434on beuge si on met des lettres (a pas régler)
        //check de limite(jsp pk la fonction beuge à des nbr très grand)
        while (limite < 2 || limite > 1000) {
            cout << " Entrer une valeur [2-1000] :" << endl;
            cin >> limite;
        }

        cout << "Voici la liste des nombres premiers :" << endl;

        int compteur = 0; // Compteur pour les colonnes
        for (int nombre = 1; nombre <= limite; nombre++) {
            if (estPremier(nombre)) {
                cout << nombre << '\t'; // Affiche le nombre avec une tabulation
                compteur++;
                // Saut de ligne après chaque cinquième nombre
                if (compteur % 5 == 0) {
                    cout << endl;
                }
            }
        }
        if (compteur % 5 != 0) {
            cout << endl; // Sauter une ligne si la dernière ligne n'est pas complète
        }
        // Demander si l'utilisateur veut recommencer(la phrase répète si on mets plusieurs lettres)
        cout << "Voulez-vous recommencer [O/N] : " << endl;
        cin >> recommencer;

        // Valider l'entrée de l'utilisateur
        while (recommencer != 'O' && recommencer != 'N') {
            cout << " Voulez-vous recommencer [O/N] :" << endl;
            cin >> recommencer;
        }
    } while (recommencer == 'O');
    //Fin
    cout << "Fin du programme" << endl;
    return EXIT_SUCCESS;
}
