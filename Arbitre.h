#ifndef ARBITRE_H
#define ARBITRE_H

#include <string>
#include <vector>

class Arbitre {
private:
    int codeArbitre;
    std::string nomArbitre;
    std::vector<std::string> decisionsArbitre;

public:
    // Constructeurs
    Arbitre();
    Arbitre(int code, const std::string& nom);

    // Getters & Setters
    int getCodeArbitre() const;
    void setCodeArbitre(int code);
    std::string getNomArbitre() const;
    void setNomArbitre(const std::string& nom);
    std::vector<std::string> getDecisionsArbitre() const;
    void ajouterDecision(const std::string& decision);

    // Méthodes
    void afficherArbitre() const;
};


#endif //ARBITRE_H
