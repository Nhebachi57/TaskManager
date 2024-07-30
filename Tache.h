// Tache.h
#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
public:
    Tache(const std::string& titre, const std::string& dateLimite = "");

    std::string getTitre() const;
    std::string getDateLimite() const;
    std::string getDateCreation() const; // Ajout� pour obtenir la date de cr�ation
    bool estTerminee() const;
    void marquerTerminee();
    void marquerNonTerminee();
    void afficher() const; // Ajout� pour afficher une t�che

private:
    std::string titre;
    std::string dateLimite;
    std::string dateCreation; // Date de cr�ation
    bool terminee;
};

#endif // TACHE_H