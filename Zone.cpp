#include "Zone.h"

Zone::Zone() : numZone(0), prixZone(0.0f), capaciteZone(0) {}

Zone::Zone(int num, float prix, int capacite)
    : numZone(num), prixZone(prix), capaciteZone(capacite) {}

int Zone::getNumZone() const { return numZone; }
void Zone::setNumZone(int num) { numZone = num; }
float Zone::getPrixZone() const { return prixZone; }
void Zone::setPrixZone(float prix) { prixZone = prix; }
int Zone::getCapaciteZone() const { return capaciteZone; }
void Zone::setCapaciteZone(int capacite) { capaciteZone = capacite; }