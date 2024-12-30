// Equipe.h
#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>

using namespace std;

class Equipe {
private:
    int idEquipe;
    string nomEquipe;
    int nombreJoueur;
    string villeEquipe;
    float score;
    int classement;

public:
    Equipe();
    Equipe(int id, const string& nom, int nbJoueurs, const string& ville);

    int getIdEquipe() const;
    void setIdEquipe(int id);
    string getNomEquipe() const;
    void setNomEquipe(const string& nom);
    int getNombreJoueur() const;
    void setNombreJoueur(int nb);
    string getVilleEquipe() const;
    void setVilleEquipe(const string& ville);
    float getScore() const;
    void setScore(float s);
    int getClassement() const;
    void setClassement(int c);

    void consultationEquipe() const;
    Equipe rechercheEquipe(const string& critere, const string& valeur);
};

#endif
