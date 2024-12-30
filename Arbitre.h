#ifndef ARBITRE_H
#define ARBITRE_H

#include <string>
#include <vector>

using namespace std;

class Arbitre {
private:
    int codeArbitre;
    string nomArbitre;
    vector<string> decisionsArbitre;

public:
    Arbitre();
    Arbitre(int code, const string& nom);

    int getCodeArbitre() const;
    void setCodeArbitre(int code);
    string getNomArbitre() const;
    void setNomArbitre(const string& nom);
    vector<string> getDecisionsArbitre() const;
    void ajouterDecision(const string& decision);

    void afficherArbitre() const;
};

#endif
