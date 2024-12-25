#ifndef ZONE_H
#define ZONE_H

using namespace std;

class Zone {
private:
    int numZone;
    float prixZone;
    int capaciteZone;

public:
    Zone();
    Zone(int num, float prix, int capacite);

    // Getters & Setters
    int getNumZone() const;
    void setNumZone(int num);
    float getPrixZone() const;
    void setPrixZone(float prix);
    int getCapaciteZone() const;
    void setCapaciteZone(int capacite);
};

#endif