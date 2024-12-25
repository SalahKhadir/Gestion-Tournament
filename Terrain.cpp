#include "Terrain.h"
#include <iostream>

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

void Terrain::RechercheTerrain() {
    // À implémenter selon les besoins spécifiques
}