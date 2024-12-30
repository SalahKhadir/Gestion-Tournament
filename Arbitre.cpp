#include "Arbitre.h"
#include <iostream>

using namespace std;

Arbitre::Arbitre() : codeArbitre(0), nomArbitre("") {}

Arbitre::Arbitre(int code, const string& nom)
    : codeArbitre(code), nomArbitre(nom) {}

int Arbitre::getCodeArbitre() const { return codeArbitre; }
void Arbitre::setCodeArbitre(int code) { codeArbitre = code; }
string Arbitre::getNomArbitre() const { return nomArbitre; }
void Arbitre::setNomArbitre(const string& nom) { nomArbitre = nom; }
vector<string> Arbitre::getDecisionsArbitre() const { return decisionsArbitre; }

void Arbitre::ajouterDecision(const string& decision) {
    decisionsArbitre.push_back(decision);
}

void Arbitre::afficherArbitre() const {
    cout << "Code Arbitre: " << codeArbitre << endl;
    cout << "Nom Arbitre: " << nomArbitre << endl;
    if (!decisionsArbitre.empty()) {
        cout << "Décisions: " << endl;
        for (const auto& decision : decisionsArbitre) {
            cout << "- " << decision << endl;
        }
    }
}