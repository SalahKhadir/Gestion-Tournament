#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <vector>
using namespace std;

class Terrain {
private:
    int idTerrain;
    string nomTerrain;
    string villeTerrain;
    string equipePropritere;
    int capaciteTerrain;

public:
    Terrain();
    Terrain(int id, string nom, string ville, string proprietaire, int capacite);

    // Getters & Setters
    int getIdTerrain() const;
    void setIdTerrain(int id);
    string getNomTerrain() const;
    void setNomTerrain(const string& nom);
    string getVilleTerrain() const;
    void setVilleTerrain(const string& ville);
    string getEquipePropritere() const;
    void setEquipePropritere(const string& equipe);
    int getCapaciteTerrain() const;
    void setCapaciteTerrain(int capacite);

    // Méthodes
    void AfficherTerrain() const;
    void RechercheTerrain(const vector<Terrain>& terrains);
};

#endif