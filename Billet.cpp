#include "Billet.h"

Billet::Billet() : refBillet(0), match(nullptr), zone(nullptr) {}

Billet::Billet(int ref, Match* m, Zone* z)
    : refBillet(ref), match(m), zone(z) {}

int Billet::getRefBillet() const { return refBillet; }
void Billet::setRefBillet(int ref) { refBillet = ref; }
Match* Billet::getMatch() const { return match; }
void Billet::setMatch(Match* m) { match = m; }
Zone* Billet::getZone() const { return zone; }
void Billet::setZone(Zone* z) { zone = z; }