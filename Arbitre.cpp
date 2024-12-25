#include "Arbitre.h"
#include <iostream>

Arbitre::Arbitre() : codeArbitre(0), nomArbitre("") {}

Arbitre::Arbitre(int code, const std::string& nom)
    : codeArbitre(code), nomArbitre(nom) {}

int Arbitre::getCodeArbitre() const {
    return codeArbitre;
}

void Arbitre::setCodeArbitre(int code) {
    codeArbitre = code;
}

std::string Arbitre::getNomArbitre() const {
    return nomArbitre;
}

void Arbitre::setNomArbitre(const std::string& nom) {
    nomArbitre = nom;
}

std::vector<std::string> Arbitre::getDecisionsArbitre() const {
    return decisionsArbitre;
}

void Arbitre::ajouterDecision(const std::string& decision) {
    decisionsArbitre.push_back(decision);
}

void Arbitre::afficherArbitre() const {
    std::cout << "Code Arbitre: " << codeArbitre << std::endl;
    std::cout << "Nom Arbitre: " << nomArbitre << std::endl;
    std::cout << "Décisions: " << std::endl;
    for (const auto& decision : decisionsArbitre) {
        std::cout << "- " << decision << std::endl;
    }
}