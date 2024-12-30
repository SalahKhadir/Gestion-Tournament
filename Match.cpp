#include "Match.h"
#include <iostream>

using namespace std;

Match::Match()
    : refMatch(0), phase(PHASE_GROUPES), terrain(0), nomTerrain(""),
      scoreEquipe1(0), scoreEquipe2(0), matchTermine(false) {}

Match::Match(int ref, Phase p)
    : refMatch(ref), phase(p), terrain(0), nomTerrain(""),
      scoreEquipe1(0), scoreEquipe2(0), matchTermine(false) {}

int Match::getRefMatch() const { return refMatch; }
void Match::setRefMatch(int ref) { refMatch = ref; }
Phase Match::getPhase() const { return phase; }
void Match::setPhase(Phase p) { phase = p; }
vector<Equipe> Match::getEquipes() const { return equipes; }
Arbitre Match::getArbitre() const { return arbitre; }
void Match::setArbitre(const Arbitre& a) { arbitre = a; }
int Match::getTerrain() const { return terrain; }
void Match::setTerrain(int terrainId) { terrain = terrainId; }
string Match::getTerrainNom() const { return nomTerrain; }
void Match::setTerrainNom(const string& nom) { nomTerrain = nom; }
bool Match::estTermine() const { return matchTermine; }
void Match::setTermine(bool termine) { matchTermine = termine; }

void Match::ajouterEquipe(const Equipe& equipe) {
    if (equipes.size() < 2) {
        equipes.push_back(equipe);
    }
}

bool Match::verifierDisponibilite() const {
    return equipes.size() == 2 && arbitre.getCodeArbitre() != 0 && terrain != 0;
}

void Match::enregistrerScore(int score1, int score2) {
    scoreEquipe1 = score1;
    scoreEquipe2 = score2;
    matchTermine = true;
}

void Match::afficherMatch() const {
    cout << "\n=== Détails du Match ===" << endl;
    cout << "Référence: " << refMatch << endl;
    cout << "Phase: " << getPhaseString() << endl;
    cout << "Terrain: " << nomTerrain << endl;

    cout << "\nÉquipes:" << endl;
    for (const auto& equipe : equipes) {
        cout << "- " << equipe.getNomEquipe() << endl;
    }

    cout << "\nArbitre: " << arbitre.getNomArbitre() << endl;

    if (matchTermine) {
        cout << "\nScore: " << scoreEquipe1 << " - " << scoreEquipe2 << endl;
    }
}

string Match::getPhaseString() const {
    switch (phase) {
        case PHASE_GROUPES: return "Phase de Groupes";
        case ELIMINATOIRES: return "Éliminatoires";
        case QUARTS_FINALE: return "Quarts de Finale";
        case DEMI_FINALE: return "Demi-Finale";
        case FINALE: return "Finale";
        default: return "Phase Inconnue";
    }
}

bool Match::peutCommencer() const {
    return equipes.size() == 2 && arbitre.getCodeArbitre() != 0 && terrain != 0;
}