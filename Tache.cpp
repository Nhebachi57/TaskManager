// Tache.cpp
#include "Tache.h"
#include <ctime>
#include <sstream>

Tache::Tache(const std::string& titre, const std::string& dateLimite)
    : titre(titre), dateLimite(dateLimite), terminee(false) {
    // Obtention de la date et heure actuelles
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::ostringstream oss;
    oss << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "-"
        << (ltm->tm_mon + 1 < 10 ? "0" : "") << (ltm->tm_mon + 1) << "-"
        << ltm->tm_year + 1900 << " "
        << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":"
        << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":"
        << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec;

    dateCreation = oss.str();
}

std::string Tache::getTitre() const {
    return titre;
}

std::string Tache::getDateLimite() const {
    return dateLimite;
}

std::string Tache::getDateCreation() const {
    return dateCreation;
}

bool Tache::estTerminee() const {
    return terminee;
}

void Tache::marquerTerminee() {
    terminee = true;
}

void Tache::marquerNonTerminee() {
    terminee = false;
}

void Tache::afficher() const {
    std::cout << "Titre: " << titre << "\n"
        << "Date de creation: " << dateCreation << "\n"
        << "Date limite: " << dateLimite << "\n"
        << "Etat: " << (terminee ? "Terminee" : "Non terminee") << "\n";
}