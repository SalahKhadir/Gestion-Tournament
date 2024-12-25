#ifndef MATCH_H
#define MATCH_H

#include "Terrain.h"
#include "Equipe.h"
#include "Arbitre.h"
#include "Spectateur.h"

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
    vector<Arbitre> arbitres;
    int terrain;  // référence au Terrain
    vector<Spectateur> spectateurs;

public:
    Match();
    Match(int ref, Phase p);

    // Getters & Setters
    int getRefMatch() const;
    void setRefMatch(int ref);
    Phase getPhase() const;
    void setPhase(Phase p);
    vector<Equipe> getEquipes() const;
    void ajouterEquipe(const Equipe& equipe);
    vector<Arbitre> getArbitres() const;
    void ajouterArbitre(const Arbitre& arbitre);
    int getTerrain() const;
    void setTerrain(int terrainId);
    vector<Spectateur> getSpectateurs() const;
    void ajouterSpectateur(const Spectateur& spectateur);

    // Méthodes spécifiques
    void attributionMatchs();
    void selectionEquipes();
    bool verificationDisponibilite() const;
};

#endif