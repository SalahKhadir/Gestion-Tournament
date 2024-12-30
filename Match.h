#ifndef MATCH_H
#define MATCH_H

#include "Terrain.h"
#include "Equipe.h"
#include "Arbitre.h"
#include <vector>
#include <string>

using namespace std;

enum Phase {
    PHASE_GROUPES,
    ELIMINATOIRES,
    QUARTS_FINALE,
    DEMI_FINALE,
    FINALE
};

class Match {
private:
    int refMatch;
    Phase phase;
    vector<Equipe> equipes;
    Arbitre arbitre;
    int terrain;
    string nomTerrain;
    int scoreEquipe1;
    int scoreEquipe2;
    bool matchTermine;

public:
    Match();
    Match(int ref, Phase p);

    int getRefMatch() const;
    void setRefMatch(int ref);
    Phase getPhase() const;
    void setPhase(Phase p);
    vector<Equipe> getEquipes() const;
    void ajouterEquipe(const Equipe& equipe);
    Arbitre getArbitre() const;
    void setArbitre(const Arbitre& arbitre);
    int getTerrain() const;
    void setTerrain(int terrainId);
    string getTerrainNom() const;
    void setTerrainNom(const string& nom);
    bool estTermine() const;
    void setTermine(bool termine);

    bool verifierDisponibilite() const;
    void enregistrerScore(int score1, int score2);
    void afficherMatch() const;
    string getPhaseString() const;
    bool peutCommencer() const;
};

#endif