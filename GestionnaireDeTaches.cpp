// GestionnaireDeTaches.cpp
#include "GestionnaireDeTaches.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

void GestionnaireDeTaches::ajouterTache(const std::string& titre, const std::string& dateLimite) {
    taches.emplace_back(titre, dateLimite);
    enregistrerHistorique("Ajout de la tache: " + titre);
}

void GestionnaireDeTaches::afficherTaches() const {
    if (taches.empty()) {
        std::cout << "Aucune tache a afficher.\n";
        return;
    }

    std::cout << std::left << std::setw(30) << "Titre"
        << std::setw(20) << "Date de creation"
        << std::setw(20) << "Date limite"
        << "Etat\n";
    std::cout << std::string(90, '-') << "\n";

    for (size_t i = 0; i < taches.size(); ++i) {
        const Tache& tache = taches[i];
        std::cout << std::setw(30) << tache.getTitre()
            << std::setw(20) << tache.getDateCreation()
            << std::setw(20) << tache.getDateLimite()
            << (tache.estTerminee() ? "Terminee" : "Non terminee") << "\n";
    }
}

void GestionnaireDeTaches::marquerTacheTerminee(int index) {
    if (index < 0 || index >= static_cast<int>(taches.size())) {
        std::cout << "Index de tache invalide.\n";
        return;
    }
    taches[index].marquerTerminee();
    enregistrerHistorique("Marquage de la tache comme terminee: " + taches[index].getTitre());
}

void GestionnaireDeTaches::marquerTacheNonTerminee(int index) {
    if (index < 0 || index >= static_cast<int>(taches.size())) {
        std::cout << "Index de tache invalide.\n";
        return;
    }
    taches[index].marquerNonTerminee();
    enregistrerHistorique("Marquage de la tache comme non terminee: " + taches[index].getTitre());
}

void GestionnaireDeTaches::supprimerTache(int index) {
    if (index < 0 || index >= static_cast<int>(taches.size())) {
        std::cout << "Index de tache invalide.\n";
        return;
    }
    std::string titre = taches[index].getTitre();
    taches.erase(taches.begin() + index);
    enregistrerHistorique("Suppression de la tache: " + titre);
}

void GestionnaireDeTaches::supprimerToutesLesTaches() {
    if (taches.empty()) {
        std::cout << "Aucune tache a supprimer.\n";
        return;
    }

    std::string confirmation;
    std::cout << "Etes-vous sur de vouloir supprimer toutes les taches ? (oui/non) : ";
    std::cin >> confirmation;

    if (confirmation == "oui") {
        taches.clear();
        enregistrerHistorique("Suppression de toutes les taches");
        std::cout << "Toutes les taches ont ete supprimees.\n";
    }
    else {
        std::cout << "Suppression annulee.\n";
    }
}

void GestionnaireDeTaches::afficherHistorique() const {
    std::ifstream historique("historique.txt");
    if (!historique.is_open()) {
        std::cout << "Impossible d'ouvrir le fichier d'historique.\n";
        return;
    }

    std::string ligne;
    while (std::getline(historique, ligne)) {
        std::cout << ligne << "\n";
    }

    historique.close();
}

void GestionnaireDeTaches::viderHistorique() const {
    std::ofstream historique("historique.txt", std::ofstream::trunc);
    if (!historique.is_open()) {
        std::cout << "Impossible d'ouvrir le fichier d'historique.\n";
        return;
    }
    historique.close();
    std::cout << "Historique vide.\n";
}

std::string GestionnaireDeTaches::getCurrentTime() const {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    std::ostringstream oss;
    oss << (ltm.tm_mday < 10 ? "0" : "") << ltm.tm_mday << "-"
        << (ltm.tm_mon + 1 < 10 ? "0" : "") << (ltm.tm_mon + 1) << "-"
        << ltm.tm_year + 1900 << " "
        << (ltm.tm_hour < 10 ? "0" : "") << ltm.tm_hour << ":"
        << (ltm.tm_min < 10 ? "0" : "") << ltm.tm_min << ":"
        << (ltm.tm_sec < 10 ? "0" : "") << ltm.tm_sec;

    return oss.str();
}

void GestionnaireDeTaches::enregistrerHistorique(const std::string& action) const {
    std::ofstream historique("historique.txt", std::ios_base::app);
    if (!historique.is_open()) {
        std::cout << "Impossible d'ouvrir le fichier d'historique.\n";
        return;
    }

    historique << getCurrentTime() << " - " << action << "\n";
    historique.close();
}