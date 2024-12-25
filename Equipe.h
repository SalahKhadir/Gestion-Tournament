#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>

class Equipe {
private:
    int idEquipe;
    std::string nomEquipe;
    int nombreJoueur;
    std::string villeEquipe;
    float score;
    int classement;

public:
    // Constructeurs
    Equipe();
    Equipe(int id, const std::string& nom, int nbJoueurs, const std::string& ville);

    // Getters & Setters
    int getIdEquipe() const;
    void setIdEquipe(int id);
    std::string getNomEquipe() const;
    void setNomEquipe(const std::string& nom);
    int getNombreJoueur() const;
    void setNombreJoueur(int nb);
    std::string getVilleEquipe() const;
    void setVilleEquipe(const std::string& ville);
    float getScore() const;
    void setScore(float s);
    int getClassement() const;
    void setClassement(int c);

    // Méthodes
    void consultationEquipe() const;
    Equipe rechercheEquipe(const std::string &critere, const std::string &valeur);
};

#endif // EQUIPE_H

