#ifndef TOURNOI_H
#define TOURNOI_H

#include "Match.h"
#include <vector>
#include <memory>
using namespace std;

class Tournoi {
private:
    int codeTournoi;
    string nomTournoi;
    string dateTournoi;
    int nombreEquipesMax;
    bool estCommence;
    vector<Match*> matchs;
    vector<Equipe> equipes;
    vector<Arbitre> arbitres;
    vector<Terrain> terrains;

public:
    Tournoi();
    Tournoi(int code);
    ~Tournoi();

    // Getters pour les collections
    const vector<Equipe>& getEquipes() const { return equipes; }
    const vector<Arbitre>& getArbitres() const { return arbitres; }
    const vector<Terrain>& getTerrains() const { return terrains; }
    const vector<Match*>& getMatchs() const { return matchs; }

    // Getters & Setters pour les propriétés
    int getCodeTournoi() const { return codeTournoi; }
    void setCodeTournoi(int code) { codeTournoi = code; }
    string getNomTournoi() const { return nomTournoi; }
    void setNomTournoi(const string& nom) { nomTournoi = nom; }
    string getDateTournoi() const { return dateTournoi; }
    void setDateTournoi(const string& date) { dateTournoi = date; }
    int getNombreEquipesMax() const { return nombreEquipesMax; }
    void setNombreEquipesMax(int nb) { nombreEquipesMax = nb; }
    bool getEstCommence() const { return estCommence; }
    void setEstCommence(bool commence) { estCommence = commence; }
    
    // Méthodes de gestion des équipes
    void ajouterEquipe(const Equipe& equipe);
    void afficherEquipes() const;
    Equipe* rechercherEquipe(const string& critere, const string& valeur);
    void mettreAJourClassement();
    
    // Méthodes de gestion des arbitres
    void ajouterArbitre(const Arbitre& arbitre);
    void afficherArbitres() const;
    void ajouterDecisionArbitrale(int codeArbitre, const string& decision);
    Arbitre* rechercherArbitre(int code);
    
    // Méthodes de gestion des terrains
    void ajouterTerrain(const Terrain& terrain);
    void afficherTerrains() const;
    Terrain* rechercherTerrain(const string& critere, const string& valeur);
    
    // Méthodes de gestion des matchs
    void creerMatch(Phase phase);
    void afficherMatchs() const;
    void enregistrerResultatMatch(int refMatch, int score1, int score2);
    Match* rechercherMatch(int refMatch);
    
    // Méthodes de gestion du tournoi
    bool configurationInitiale(const string& nom, const string& date, int nbEquipes);
    void afficherInfoTournoi() const;
    bool peutCommencer() const;
    void planifierPhaseGroupe();
    void planifierPhaseEliminatoire();
    void genererCalendrier();
    void afficherClassement() const;
};

#endif