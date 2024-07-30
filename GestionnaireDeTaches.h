// GestionnaireDeTaches.h
#ifndef GESTIONNAIRE_DE_TACHES_H
#define GESTIONNAIRE_DE_TACHES_H

#include "Tache.h"
#include <vector>
#include <string>

class GestionnaireDeTaches {
public:
    void ajouterTache(const std::string& titre, const std::string& dateLimite = "");
    void afficherTaches() const;
    void marquerTacheTerminee(int index);
    void marquerTacheNonTerminee(int index);
    void supprimerTache(int index);
    void supprimerToutesLesTaches();
    void afficherHistorique() const;
    void viderHistorique() const;
    std::string getCurrentTime() const;

private:
    std::vector<Tache> taches;
    void enregistrerHistorique(const std::string& action) const;
};

#endif // GESTIONNAIRE_DE_TACHES_H