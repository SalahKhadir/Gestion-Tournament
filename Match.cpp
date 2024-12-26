#include "Match.h"

Match::Match() : refMatch(0), phase(PHASE_GROUPES), terrain(0), nomTerrain("") {}

Match::Match(int ref, Phase p) : refMatch(ref), phase(p), terrain(0), nomTerrain("") {}

int Match::getRefMatch() const { return refMatch; }
void Match::setRefMatch(int ref) { refMatch = ref; }
Phase Match::getPhase() const { return phase; }
void Match::setPhase(Phase p) { phase = p; }
vector<Equipe> Match::getEquipes() const { return equipes; }
void Match::ajouterEquipe(const Equipe& equipe) { equipes.push_back(equipe); }
vector<Arbitre> Match::getArbitres() const { return arbitres; }
void Match::ajouterArbitre(const Arbitre& arbitre) { arbitres.push_back(arbitre); }
int Match::getTerrain() const { return terrain; }
void Match::setTerrain(int terrainId) { terrain = terrainId; }
string Match::getTerrainNom() const {return nomTerrain;}
void Match::setTerrainNom(string NomTerrain) {nomTerrain = NomTerrain;}
vector<Spectateur> Match::getSpectateurs() const { return spectateurs; }
void Match::ajouterSpectateur(const Spectateur& spectateur) { spectateurs.push_back(spectateur); }

void Match::attributionMatchs() {
    // Implémentation de l'attribution des matchs
}

void Match::selectionEquipes() {
    // Implémentation de la sélection des équipes
}

bool Match::verificationDisponibilite() const {
    // Vérification de la disponibilité du terrain et des équipes
    return true; // À modifier selon la logique souhaitée
}
