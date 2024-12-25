#include "Spectateur.h"
#include <iostream>

Spectateur::Spectateur() : cin(0), nomSpectateur(""), billet(nullptr) {}

Spectateur::Spectateur(int _cin, const string& nom) 
    : cin(_cin), nomSpectateur(nom), billet(nullptr) {}

Spectateur::~Spectateur() {
    // Ne pas supprimer le billet ici car il pourrait être géré ailleurs
    // delete billet;
    billet = nullptr;
}

int Spectateur::getCin() const {
    return cin;
}

void Spectateur::setCin(int _cin) {
    cin = _cin;
}

string Spectateur::getNomSpectateur() const {
    return nomSpectateur;
}

void Spectateur::setNomSpectateur(const string& nom) {
    nomSpectateur = nom;
}

Billet* Spectateur::getBillet() const {
    return billet;
}

void Spectateur::setBillet(Billet* _billet) {
    billet = _billet;
}

void Spectateur::acheterBillet(Billet* nouveauBillet) {
    if (billet != nullptr) {
        cout << "Le spectateur possède déjà un billet." << endl;
        return;
    }
    billet = nouveauBillet;
    cout << "Billet acheté avec succès." << endl;
}

void Spectateur::afficherInfos() const {
    cout << "=== Informations du Spectateur ===" << endl;
    cout << "CIN: " << cin << endl;
    cout << "Nom: " << nomSpectateur << endl;
    if (billet != nullptr) {
        cout << "Numéro de billet: " << billet->getRefBillet() << endl;
    } else {
        cout << "Aucun billet associé" << endl;
    }
}