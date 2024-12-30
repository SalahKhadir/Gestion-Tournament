#include "Tournoi.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

Tournoi::Tournoi() : codeTournoi(0), nombreEquipesMax(0), estCommence(false) {
    srand(time(nullptr));
}

Tournoi::Tournoi(int code) : codeTournoi(code), nombreEquipesMax(0), estCommence(false) {
    srand(time(nullptr));
}

Tournoi::~Tournoi() {
    for(auto match : matchs) {
        delete match;
    }
    matchs.clear();
}

bool Tournoi::configurationInitiale(const string& nom, const string& date, int nbEquipes) {
    if (nbEquipes < 2) {
        cout << "Le nombre d'équipes doit être au moins 2." << endl;
        return false;
    }
    nomTournoi = nom;
    dateTournoi = date;
    nombreEquipesMax = nbEquipes;
    return true;
}

void Tournoi::afficherInfoTournoi() const {
    cout << "\n=== Informations du Tournoi ===" << endl;
    cout << "Nom: " << nomTournoi << endl;
    cout << "Date: " << dateTournoi << endl;
    cout << "Nombre d'équipes maximum: " << nombreEquipesMax << endl;
    cout << "Nombre d'équipes inscrites: " << equipes.size() << endl;
    cout << "Nombre d'arbitres: " << arbitres.size() << endl;
    cout << "Nombre de terrains: " << terrains.size() << endl;
    cout << "État: " << (estCommence ? "En cours" : "Non commencé") << endl;
}

bool Tournoi::peutCommencer() const {
    if (equipes.size() < 2) {
        cout << "Il faut au moins 2 équipes pour commencer le tournoi." << endl;
        return false;
    }
    for (const auto& equipe : equipes) {
        if (equipe.getNombreJoueur() < 20) {
            cout << "L'équipe " << equipe.getNomEquipe()
                 << " n'a pas le minimum requis de 20 joueurs." << endl;
            return false;
        }
    }
    if (arbitres.empty()) {
        cout << "Il faut au moins un arbitre pour commencer le tournoi." << endl;
        return false;
    }
    if (terrains.empty()) {
        cout << "Il faut au moins un terrain pour commencer le tournoi." << endl;
        return false;
    }
    if (nomTournoi.empty() || dateTournoi.empty()) {
        cout << "Les informations du tournoi doivent être complètes." << endl;
        return false;
    }
    return true;
}

void Tournoi::ajouterEquipe(const Equipe& equipe) {
    if (equipes.size() >= nombreEquipesMax) {
        cout << "Nombre maximum d'équipes atteint (" << nombreEquipesMax << " équipes)." << endl;
        return;
    }

    if (equipe.getNombreJoueur() < 20) {
        cout << "L'équipe doit avoir au minimum 20 joueurs. Équipe non ajoutée." << endl;
        return;
    }

    for (const auto& e : equipes) {
        if (e.getIdEquipe() == equipe.getIdEquipe()) {
            cout << "Une équipe avec cet ID existe déjà." << endl;
            return;
        }
    }

    equipes.push_back(equipe);
    cout << "Équipe ajoutée avec succès." << endl;
}

void Tournoi::afficherEquipes() const {
    if (equipes.empty()) {
        cout << "Aucune équipe inscrite." << endl;
        return;
    }

    cout << "\n=== Liste des Équipes ===" << endl;
    for (const auto& equipe : equipes) {
        equipe.consultationEquipe();
        cout << "------------------------" << endl;
    }
}

Equipe* Tournoi::rechercherEquipe(const string& critere, const string& valeur) {
    for (auto& equipe : equipes) {
        if ((critere == "id" && to_string(equipe.getIdEquipe()) == valeur) ||
            (critere == "nom" && equipe.getNomEquipe() == valeur) ||
            (critere == "ville" && equipe.getVilleEquipe() == valeur)) {
            return &equipe;
        }
    }
    return nullptr;
}

void Tournoi::ajouterArbitre(const Arbitre& arbitre) {
    for (const auto& a : arbitres) {
        if (a.getCodeArbitre() == arbitre.getCodeArbitre()) {
            cout << "Un arbitre avec ce code existe déjà." << endl;
            return;
        }
    }

    arbitres.push_back(arbitre);
    cout << "Arbitre ajouté avec succès." << endl;
}

void Tournoi::afficherArbitres() const {
    if (arbitres.empty()) {
        cout << "Aucun arbitre enregistré." << endl;
        return;
    }

    cout << "\n=== Liste des Arbitres ===" << endl;
    for (const auto& arbitre : arbitres) {
        arbitre.afficherArbitre();
        cout << "------------------------" << endl;
    }
}

void Tournoi::ajouterDecisionArbitrale(int codeArbitre, const string& decision) {
    Arbitre* arbitre = rechercherArbitre(codeArbitre);
    if (arbitre) {
        arbitre->ajouterDecision(decision);
        cout << "Décision ajoutée avec succès!" << endl;
    } else {
        cout << "Arbitre non trouvé." << endl;
    }
}

Arbitre* Tournoi::rechercherArbitre(int code) {
    for (auto& arbitre : arbitres) {
        if (arbitre.getCodeArbitre() == code) {
            return &arbitre;
        }
    }
    return nullptr;
}

void Tournoi::ajouterTerrain(const Terrain& terrain) {
    for (const auto& t : terrains) {
        if (t.getIdTerrain() == terrain.getIdTerrain()) {
            cout << "Un terrain avec cet ID existe déjà." << endl;
            return;
        }
    }

    terrains.push_back(terrain);
    cout << "Terrain ajouté avec succès." << endl;
}

void Tournoi::afficherTerrains() const {
    if (terrains.empty()) {
        cout << "Aucun terrain enregistré." << endl;
        return;
    }

    cout << "\n=== Liste des Terrains ===" << endl;
    for (const auto& terrain : terrains) {
        terrain.AfficherTerrain();
        cout << "------------------------" << endl;
    }
}

Terrain* Tournoi::rechercherTerrain(const string& critere, const string& valeur) {
    for (auto& terrain : terrains) {
        if ((critere == "id" && to_string(terrain.getIdTerrain()) == valeur) ||
            (critere == "nom" && terrain.getNomTerrain() == valeur) ||
            (critere == "ville" && terrain.getVilleTerrain() == valeur) ||
            (critere == "proprietaire" && terrain.getEquipePropritere() == valeur)) {
            return &terrain;
        }
    }
    return nullptr;
}

void Tournoi::creerMatch(Phase phase) {
    if (equipes.size() < 2) {
        cout << "Pas assez d'équipes pour créer un match." << endl;
        return;
    }

    int index1 = rand() % equipes.size();
    int index2;
    do {
        index2 = rand() % equipes.size();
    } while (index2 == index1);

    Match* match = new Match(matchs.size() + 1, phase);
    match->ajouterEquipe(equipes[index1]);
    match->ajouterEquipe(equipes[index2]);

    if (!arbitres.empty()) {
        match->setArbitre(arbitres[0]); // Toujours utiliser le premier arbitre
    }

    if (!terrains.empty()) {
        int terrainIndex = rand() % terrains.size();
        match->setTerrain(terrains[terrainIndex].getIdTerrain());
        match->setTerrainNom(terrains[terrainIndex].getNomTerrain());
    }

    matchs.push_back(match);
    cout << "Match créé avec succès!" << endl;
    match->afficherMatch();
}

void Tournoi::afficherMatchs() const {
    if (matchs.empty()) {
        cout << "Aucun match programmé." << endl;
        return;
    }

    cout << "\n=== Liste des Matchs ===" << endl;
    for (const auto& match : matchs) {
        match->afficherMatch();
        cout << "------------------------" << endl;
    }
}

void Tournoi::enregistrerResultatMatch(int refMatch, int score1, int score2) {
    Match* match = rechercherMatch(refMatch);
    if (!match) {
        cout << "Match non trouvé." << endl;
        return;
    }

    if (match->estTermine()) {
        cout << "Ce match est déjà terminé." << endl;
        return;
    }

    match->enregistrerScore(score1, score2);
    match->setTermine(true);

    // Récupérer les équipes du match
    vector<Equipe> equipesMatch = match->getEquipes();
    if (equipesMatch.size() != 2) {
        cout << "Erreur: nombre incorrect d'équipes pour le match." << endl;
        return;
    }

    // Chercher les équipes dans le vecteur principal pour pouvoir modifier leurs scores
    Equipe* equipe1 = rechercherEquipe("id", to_string(equipesMatch[0].getIdEquipe()));
    Equipe* equipe2 = rechercherEquipe("id", to_string(equipesMatch[1].getIdEquipe()));

    if (!equipe1 || !equipe2) {
        cout << "Erreur: équipes non trouvées." << endl;
        return;
    }

    // Mettre à jour les scores selon le résultat
    if (score1 > score2) {
        // Équipe 1 gagne
        equipe1->setScore(equipe1->getScore() + 3);
        cout << equipe1->getNomEquipe() << " gagne 3 points" << endl;
    }
    else if (score2 > score1) {
        // Équipe 2 gagne
        equipe2->setScore(equipe2->getScore() + 3);
        cout << equipe2->getNomEquipe() << " gagne 3 points" << endl;
    }
    else {
        // Match nul
        equipe1->setScore(equipe1->getScore() + 1);
        equipe2->setScore(equipe2->getScore() + 1);
        cout << "Match nul - Chaque équipe gagne 1 point" << endl;
    }

    // Mettre à jour le classement
    mettreAJourClassement();

    cout << "Résultat enregistré avec succès!" << endl;
    cout << "\nClassement mis à jour:" << endl;
    afficherClassement();
}

void Tournoi::mettreAJourClassement() {
    // Trier les équipes par score
    sort(equipes.begin(), equipes.end(),
         [](const Equipe& a, const Equipe& b) {
             return a.getScore() > b.getScore();
         });

    // Mettre à jour le rang de chaque équipe
    for (size_t i = 0; i < equipes.size(); ++i) {
        equipes[i].setClassement(i + 1);
    }
}

void Tournoi::afficherClassement() const {
    if (equipes.empty()) {
        cout << "Aucune équipe inscrite." << endl;
        return;
    }

    cout << "\n=== Classement du Tournoi ===" << endl;
    cout << "Rang\tÉquipe\t\tPoints" << endl;
    cout << "--------------------------------" << endl;
    for (const auto& equipe : equipes) {
        cout << equipe.getClassement() << "\t"
             << equipe.getNomEquipe() << "\t\t"
             << equipe.getScore() << " pts" << endl;
    }
    cout << "--------------------------------" << endl;
}
void Tournoi::planifierPhaseGroupe() {
    if (!peutCommencer()) return;

    cout << "\n=== Planification de la phase de groupes ===" << endl;

    for (size_t i = 0; i < equipes.size(); i++) {
        for (size_t j = i + 1; j < equipes.size(); j++) {
            Match* match = new Match(matchs.size() + 1, PHASE_GROUPES);
            match->ajouterEquipe(equipes[i]);
            match->ajouterEquipe(equipes[j]);

            // Assigner l'arbitre
            match->setArbitre(arbitres[0]);

            // Assigner un terrain aléatoirement
            int terrainIndex = rand() % terrains.size();
            match->setTerrain(terrains[terrainIndex].getIdTerrain());
            match->setTerrainNom(terrains[terrainIndex].getNomTerrain());

            matchs.push_back(match);

            // Afficher le match créé
            cout << "Match " << matchs.size() << " : "
                 << equipes[i].getNomEquipe() << " vs "
                 << equipes[j].getNomEquipe() << endl;
            cout << "Terrain: " << terrains[terrainIndex].getNomTerrain() << endl;
            cout << "Arbitre: " << arbitres[0].getNomArbitre() << endl;
            cout << "------------------------" << endl;
        }
    }

    cout << "Phase de groupes planifiée avec " << matchs.size() << " matchs." << endl;
}

void Tournoi::planifierPhaseEliminatoire() {
    if (!peutCommencer()) return;

    cout << "\n=== Planification de la phase éliminatoire ===" << endl;

    // Trier les équipes par score
    vector<Equipe> equipesQualifiees = equipes;
    sort(equipesQualifiees.begin(), equipesQualifiees.end(),
         [](const Equipe& a, const Equipe& b) {
             return a.getScore() > b.getScore();
         });

    // Prendre les 8 meilleures équipes pour les quarts de finale
    int nbEquipesQualifiees = min(8, (int)equipesQualifiees.size());
    cout << "\n=== Quarts de finale ===" << endl;
    for (int i = 0; i < nbEquipesQualifiees; i += 2) {
        Match* match = new Match(matchs.size() + 1, QUARTS_FINALE);
        match->ajouterEquipe(equipesQualifiees[i]);
        match->ajouterEquipe(equipesQualifiees[i + 1]);

        // Assigner l'arbitre
        match->setArbitre(arbitres[0]);

        // Assigner un terrain aléatoirement
        int terrainIndex = rand() % terrains.size();
        match->setTerrain(terrains[terrainIndex].getIdTerrain());
        match->setTerrainNom(terrains[terrainIndex].getNomTerrain());

        matchs.push_back(match);

        // Afficher le match créé
        cout << "Match " << matchs.size() << " : "
             << equipesQualifiees[i].getNomEquipe() << " vs "
             << equipesQualifiees[i + 1].getNomEquipe() << endl;
        cout << "Terrain: " << terrains[terrainIndex].getNomTerrain() << endl;
        cout << "Arbitre: " << arbitres[0].getNomArbitre() << endl;
        cout << "------------------------" << endl;
    }
}

void Tournoi::genererCalendrier() {
    if (!peutCommencer()) return;

    cout << "\n======= CALENDRIER DU TOURNOI =======" << endl;
    cout << "Nom du tournoi: " << nomTournoi << endl;
    cout << "Date: " << dateTournoi << endl;
    cout << "\nÉquipes participantes:" << endl;
    for (const auto& equipe : equipes) {
        cout << "- " << equipe.getNomEquipe() << endl;
    }

    cout << "\nArbitre du tournoi: " << arbitres[0].getNomArbitre() << endl;

    cout << "\nTerrains disponibles:" << endl;
    for (const auto& terrain : terrains) {
        cout << "- " << terrain.getNomTerrain() << endl;
    }

    planifierPhaseGroupe();
    planifierPhaseEliminatoire();

    cout << "\n=== Le tournoi est prêt à commencer! ===" << endl;
}
