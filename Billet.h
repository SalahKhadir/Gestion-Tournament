#ifndef BILLET_H
#define BILLET_H

using namespace std;

class Match;
class Zone;

class Billet {
private:
    int refBillet;
    Match* match;
    Zone* zone;

public:
    Billet();
    Billet(int ref, Match* m, Zone* z);

    // Getters & Setters
    int getRefBillet() const;
    void setRefBillet(int ref);
    Match* getMatch() const;
    void setMatch(Match* m);
    Zone* getZone() const;
    void setZone(Zone* z);
};

#endif //BILLET_H
