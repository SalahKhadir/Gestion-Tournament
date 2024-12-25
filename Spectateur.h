// Spectateur.h
#ifndef SPECTATEUR_H
#define SPECTATEUR_H

#include "Billet.h"
#include <string>
using namespace std;

class Spectateur {
private:
    int cin;
    string nomSpectateur;
    Billet* billet; // Pointeur vers le billet du spectateur

public:
    // Constructeurs
    Spectateur();
    Spectateur(int _cin, const string& nom);
    ~Spectateur(); // Destructeur pour gérer la mémoire du billet

    // Getters & Setters
    int getCin() const;
    void setCin(int _cin);
    string getNomSpectateur() const;
    void setNomSpectateur(const string& nom);
    Billet* getBillet() const;
    void setBillet(Billet* _billet);

    // Méthodes spécifiques
    void acheterBillet(Billet* nouveauBillet);
    void afficherInfos() const;
};

#endif //SPECTATEUR_H
