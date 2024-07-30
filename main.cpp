// main.cpp
#include <iostream>
#include "GestionnaireDeTaches.h"

void afficherMenu() {
    std::cout << "1. Ajouter une tache\n";
    std::cout << "2. Afficher les taches\n";
    std::cout << "3. Marquer une tache comme terminee\n";
    std::cout << "4. Marquer une tache comme non terminee\n";
    std::cout << "5. Supprimer une tache\n";
    std::cout << "6. Supprimer toutes les taches\n";
    std::cout << "7. Afficher l'historique\n";
    std::cout << "8. Vider l'historique\n";
    std::cout << "9. Quitter\n";
}

int main() {
    GestionnaireDeTaches gestionnaire;
    int choix;

    do {
        afficherMenu();
        std::cout << "Entrez votre choix: ";
        std::cin >> choix;
        std::cin.ignore(); // Ignorer le retour à la ligne laissé par std::cin

        switch (choix) {
        case 1: {
            std::string titre, dateLimite;
            std::cout << "Entrez le titre de la tache: ";
            std::getline(std::cin, titre);
            std::cout << "Entrez la date limite (JJ-MM-AAAA): ";
            std::getline(std::cin, dateLimite);
            gestionnaire.ajouterTache(titre, dateLimite);
            break;
        }
        case 2:
            gestionnaire.afficherTaches();
            break;
        case 3: {
            int index;
            std::cout << "Entrez l'index de la tache a marquer comme terminee: ";
            std::cin >> index;
            gestionnaire.marquerTacheTerminee(index);
            break;
        }
        case 4: {
            int index;
            std::cout << "Entrez l'index de la tache a marquer comme non terminee: ";
            std::cin >> index;
            gestionnaire.marquerTacheNonTerminee(index);
            break;
        }
        case 5: {
            int index;
            std::cout << "Entrez l'index de la tache a supprimer: ";
            std::cin >> index;
            gestionnaire.supprimerTache(index);
            break;
        }
        case 6:
            gestionnaire.supprimerToutesLesTaches();
            break;
        case 7:
            gestionnaire.afficherHistorique();
            break;
        case 8:
            gestionnaire.viderHistorique();
            break;
        case 9:
            std::cout << "Au revoir!\n";
            break;
        default:
            std::cout << "Choix invalide. Veuillez essayer de nouveau.\n";
            break;
        }
    } while (choix != 9);

    return 0;
}