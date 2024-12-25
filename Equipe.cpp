#include "Equipe.h"
#include <iostream>
#include <string>
using namespace std;

Equipe::Equipe() 
    : idEquipe(0), nomEquipe(""), nombreJoueur(0), 
      villeEquipe(""), score(0.0f), classement(0) {}

Equipe::Equipe(int id, const string& nom, int nbJoueurs, const string& ville)
    : idEquipe(id), nomEquipe(nom), nombreJoueur(nbJoueurs),
      villeEquipe(ville), score(0.0f), classement(0) {}

int Equipe::getIdEquipe() const {
    return idEquipe;
}

void Equipe::setIdEquipe(int id) {
    idEquipe = id;
}

string Equipe::getNomEquipe() const {
    return nomEquipe;
}

void Equipe::setNomEquipe(const string& nom) {
    nomEquipe = nom;
}

int Equipe::getNombreJoueur() const {
    return nombreJoueur;
}

void Equipe::setNombreJoueur(int nb) {
    nombreJoueur = nb;
}

string Equipe::getVilleEquipe() const {
    return villeEquipe;
}

void Equipe::setVilleEquipe(const string& ville) {
    villeEquipe = ville;
}

float Equipe::getScore() const {
    return score;
}

void Equipe::setScore(float s) {
    score = s;
}

int Equipe::getClassement() const {
    return classement;
}

void Equipe::setClassement(int c) {
    classement = c;
}

void Equipe::consultationEquipe() const {
    cout << "ID Equipe: " << idEquipe << endl;
    cout << "Nom: " << nomEquipe << endl;
    cout << "Nombre de joueurs: " << nombreJoueur << endl;
    cout << "Ville: " << villeEquipe << endl;
    cout << "Score: " << score << endl;
    cout << "Classement: " << classement << endl;
}

Equipe Equipe::rechercheEquipe(const string& critere, const string& valeur) {
    if (critere == "id") {
        if (to_string(idEquipe) == valeur) {
            cout << "ID de l'équipe: " << idEquipe << endl;
            cout << "Nom de l'équipe: " << nomEquipe << endl;
            cout << "Nombre de joueurs: " << nombreJoueur << endl;
            cout << "Ville: " << villeEquipe << endl;
            cout << "Score: " << score << endl;
            cout << "Classement: " << classement << endl;
            return *this;
        }
    } else if (critere == "nom") {
        if (nomEquipe == valeur) {
            cout << "ID de l'équipe: " << idEquipe << endl;
            cout << "Nom de l'équipe: " << nomEquipe << endl;
            cout << "Nombre de joueurs: " << nombreJoueur << endl;
            cout << "Ville: " << villeEquipe << endl;
            cout << "Score: " << score << endl;
            cout << "Classement: " << classement << endl;
            return *this;
        }
    } else if (critere == "ville") {
        if (villeEquipe == valeur) {
            cout << "ID de l'équipe: " << idEquipe << endl;
            cout << "Nom de l'équipe: " << nomEquipe << endl;
            cout << "Nombre de joueurs: " << nombreJoueur << endl;
            cout << "Ville: " << villeEquipe << endl;
            cout << "Score: " << score << endl;
            cout << "Classement: " << classement << endl;
            return *this;
        }
    } else if (critere == "score") {
        if (to_string(score) == valeur) {
            cout << "ID de l'équipe: " << idEquipe << endl;
            cout << "Nom de l'équipe: " << nomEquipe << endl;
            cout << "Nombre de joueurs: " << nombreJoueur << endl;
            cout << "Ville: " << villeEquipe << endl;
            cout << "Score: " << score << endl;
            cout << "Classement: " << classement << endl;
            return *this;
        }
    } else if (critere == "classement") {
        if (to_string(classement) == valeur) {
            cout << "ID de l'équipe: " << idEquipe << endl;
            cout << "Nom de l'équipe: " << nomEquipe << endl;
            cout << "Nombre de joueurs: " << nombreJoueur << endl;
            cout << "Ville: " << villeEquipe << endl;
            cout << "Score: " << score << endl;
            cout << "Classement: " << classement << endl;
            return *this;
        }
    }
    return {};
}
