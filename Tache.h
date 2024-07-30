// Tache.h
#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
public:
    Tache(const std::string& titre, const std::string& dateLimite = "");

    std::string getTitre() const;
    std::string getDateLimite() const;
    std::string getDateCreation() const; // Ajouté pour obtenir la date de création
    bool estTerminee() const;
    void marquerTerminee();
    void marquerNonTerminee();
    void afficher() const; // Ajouté pour afficher une tâche

private:
    std::string titre;
    std::string dateLimite;
    std::string dateCreation; // Date de création
    bool terminee;
};

#endif // TACHE_H