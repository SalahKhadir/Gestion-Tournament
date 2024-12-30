#include "Tournoi.h"
#include <iostream>
#include <algorithm>

Tournoi::Tournoi() : codeTournoi(0) {}

Tournoi::Tournoi(int code) : codeTournoi(code) {}

Tournoi::~Tournoi() {
    // Libérer la mémoire des matchs
    for(auto match : matchs) {
        delete match;
    }
    matchs.clear();
}

int Tournoi::getCodeTournoi() const {
    return codeTournoi;
}

void Tournoi::setCodeTournoi(int code) {
    codeTournoi = code;
}

vector<Match*> Tournoi::getMatchs() const {
    return matchs;
}

void Tournoi::ajouterMatch(Match* match) {
    matchs.push_back(match);
}

bool Tournoi::validationInscription(const Equipe& equipe) {
    // Vérifier si l'équipe répond aux critères d'inscription
    // Par exemple : nombre minimum de joueurs, frais d'inscription payés, etc.
    if(equipe.getNombreJoueur() < 11) {
        cout << "Équipe refusée : nombre insuffisant de joueurs" << endl;
        return false;
    }
    cout << "Inscription validée pour l'équipe " << equipe.getNomEquipe() << endl;
    return true;
}

void Tournoi::afficherMatchs() const {
    cout << "\n=== Liste des Matchs du Tournoi ===" << endl;
    if(matchs.empty()) {
        cout << "Aucun match programmé" << endl;
        return;
    }

    for(const auto& match : matchs) {
        cout << "Match ID: " << match->getRefMatch() << endl;
        cout << "Phase: ";
        switch(match->getPhase()) {
            case PHASE_GROUPES: cout << "Phase de groupes"; break;
            case ELIMINATOIRES: cout << "Éliminatoires"; break;
            case QUARTS_FINALE: cout << "Quarts de finale"; break;
            case DEMI_FINALE: cout << "Demi-finale"; break;
            case FINALE: cout << "Finale"; break;
        }
        cout << endl << "------------------------" << endl;
    }
}

void Tournoi::planifierPhaseGroupe() {
    cout << "Planification de la phase de groupes..." << endl;
    // Implémentation de la logique de planification des groupes
}

void Tournoi::planifierPhaseEliminatoire() {
    cout << "Planification de la phase éliminatoire..." << endl;
    // Implémentation de la logique des phases éliminatoires
}

void Tournoi::genererCalendrier() {
    cout << "Génération du calendrier des matchs..." << endl;
    // Logique pour générer le calendrier complet du tournoi
}

void Tournoi::afficherClassement() const {
    cout << "\n=== Classement du Tournoi ===" << endl;
    // Implémenter la logique d'affichage du classement
}

bool Tournoi::verifierDisponibiliteTerrain(const Terrain& terrain, const string& date) const {
    // Vérifier si le terrain est disponible à la date donnée
    return true; // À implémenter selon la logique souhaitée
}

void Tournoi::attribuerArbitres(Match* match) {
    cout << "Attribution des arbitres pour le match " << match->getRefMatch() << endl;
    // Implémenter la logique d'attribution des arbitres
}
void Tournoi::enregistrerResultat(Match* match, int scoreEquipe1, int scoreEquipe2) {
    if (!match) {
        cout << "Match invalide." << endl;
        return;
    }

    vector<Equipe> equipes = match->getEquipes();
    if (equipes.size() < 2) {
        cout << "Le match ne contient pas deux équipes valides." << endl;
        return;
    }

    Equipe& equipe1 = equipes[0];
    Equipe& equipe2 = equipes[1];

    cout << "Résultat pour le match entre " << equipe1.getNomEquipe()
         << " et " << equipe2.getNomEquipe() << endl;
    cout << equipe1.getNomEquipe() << ": " << scoreEquipe1
         << " | " << equipe2.getNomEquipe() << ": " << scoreEquipe2 << endl;

    // Update scores based on results
    if (scoreEquipe1 > scoreEquipe2) {
        equipe1.setScore(equipe1.getScore() + 3); // Win for equipe1
        cout << equipe1.getNomEquipe() << " gagne 3 points." << endl;
    } else if (scoreEquipe1 < scoreEquipe2) {
        equipe2.setScore(equipe2.getScore() + 3); // Win for equipe2
        cout << equipe2.getNomEquipe() << " gagne 3 points." << endl;
    } else {
        equipe1.setScore(equipe1.getScore() + 1); // Draw
        equipe2.setScore(equipe2.getScore() + 1); // Draw
        cout << "Match nul. Chaque équipe gagne 1 point." << endl;
    }
}
