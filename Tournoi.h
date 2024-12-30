// Tournoi.h
#ifndef TOURNOI_H
#define TOURNOI_H

#include "Match.h"
#include <vector>
#include <string>
using namespace std;

class Tournoi {
private:
    int codeTournoi;
    vector<Match*> matchs;

public:
    // Constructeurs et destructeur
    Tournoi();
    Tournoi(int code);
    ~Tournoi();

    // Getters & Setters
    int getCodeTournoi() const;
    void setCodeTournoi(int code);
    vector<Match*> getMatchs() const;
    void ajouterMatch(Match* match);

    // Méthodes spécifiques
    void enregistrerResultat(Match* match, int scoreEquipe1, int scoreEquipe2);
    bool validationInscription(const Equipe& equipe);
    void afficherMatchs() const;
    void planifierPhaseGroupe();
    void planifierPhaseEliminatoire();
    void genererCalendrier();
    void afficherClassement() const;

    // Méthodes utilitaires
    bool verifierDisponibiliteTerrain(const Terrain& terrain, const string& date) const;
    void attribuerArbitres(Match* match);
};

#endif
