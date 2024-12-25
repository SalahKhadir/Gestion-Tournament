
#include "Equipe.h"
#include <iostream>

Equipe::Equipe() 
    : idEquipe(0), nomEquipe(""), nombreJoueur(0), 
      villeEquipe(""), score(0.0f), classement(0) {}

Equipe::Equipe(int id, const std::string& nom, int nbJoueurs, const std::string& ville)
    : idEquipe(id), nomEquipe(nom), nombreJoueur(nbJoueurs),
      villeEquipe(ville), score(0.0f), classement(0) {}

int Equipe::getIdEquipe() const {
    return idEquipe;
}

void Equipe::setIdEquipe(int id) {
    idEquipe = id;
}

std::string Equipe::getNomEquipe() const {
    return nomEquipe;
}

void Equipe::setNomEquipe(const std::string& nom) {
    nomEquipe = nom;
}

int Equipe::getNombreJoueur() const {
    return nombreJoueur;
}

void Equipe::setNombreJoueur(int nb) {
    nombreJoueur = nb;
}

std::string Equipe::getVilleEquipe() const {
    return villeEquipe;
}

void Equipe::setVilleEquipe(const std::string& ville) {
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
    std::cout << "ID Equipe: " << idEquipe << std::endl;
    std::cout << "Nom: " << nomEquipe << std::endl;
    std::cout << "Nombre de joueurs: " << nombreJoueur << std::endl;
    std::cout << "Ville: " << villeEquipe << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Classement: " << classement << std::endl;
}

Equipe Equipe::rechercheEquipe(const std::string& critere) {
    // Implémentation de la recherche à faire selon vos besoins
    return Equipe();
}