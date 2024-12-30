#include "Terrain.h"
#include <iostream>
#include <limits>

Terrain::Terrain()
    : idTerrain(0), nomTerrain(""), villeTerrain(""),
      equipePropritere(""), capaciteTerrain(0) {}

Terrain::Terrain(int id, string nom, string ville, string proprietaire, int capacite)
    : idTerrain(id), nomTerrain(nom), villeTerrain(ville),
      equipePropritere(proprietaire), capaciteTerrain(capacite) {}

int Terrain::getIdTerrain() const { return idTerrain; }
void Terrain::setIdTerrain(int id) { idTerrain = id; }
string Terrain::getNomTerrain() const { return nomTerrain; }
void Terrain::setNomTerrain(const string& nom) { nomTerrain = nom; }
string Terrain::getVilleTerrain() const { return villeTerrain; }
void Terrain::setVilleTerrain(const string& ville) { villeTerrain = ville; }
string Terrain::getEquipePropritere() const { return equipePropritere; }
void Terrain::setEquipePropritere(const string& equipe) { equipePropritere = equipe; }
int Terrain::getCapaciteTerrain() const { return capaciteTerrain; }
void Terrain::setCapaciteTerrain(int capacite) { capaciteTerrain = capacite; }

void Terrain::AfficherTerrain() const {
    cout << "ID Terrain: " << idTerrain << endl;
    cout << "Nom: " << nomTerrain << endl;
    cout << "Ville: " << villeTerrain << endl;
    cout << "Proprietaire: " << equipePropritere << endl;
    cout << "Capacite: " << capaciteTerrain << endl;
}

void Terrain::RechercheTerrain(const vector<Terrain>& terrains) {
    string critere, valeur;
    cout << "Rechercher par (id/nom/ville/proprietaire/capacite): ";
    cin >> critere;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Nettoyer le flux
    cout << "Entrez la valeur du critere: ";
    getline(cin, valeur);

    bool found = false;

    for (const auto& terrain : terrains) {
        if ((critere == "id" && to_string(terrain.getIdTerrain()) == valeur) ||
            (critere == "nom" && terrain.getNomTerrain() == valeur) ||
            (critere == "ville" && terrain.getVilleTerrain() == valeur) ||
            (critere == "proprietaire" && terrain.getEquipePropritere() == valeur) ||
            (critere == "capacite" && to_string(terrain.getCapaciteTerrain()) == valeur)) {
            terrain.AfficherTerrain();
            found = true; // Indique qu'au moins un terrain a été trouvé
            cout << "------------------------" << endl;
            }
    }

    if (!found) {
        cout << "Aucun terrain trouvé avec ce critère." << endl;
    }
}