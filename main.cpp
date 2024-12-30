#include "Equipe.h"
#include "Arbitre.h"
#include "Terrain.h"
#include "Match.h"
#include "Tournoi.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
using namespace std;

// Menus d'affichage
void afficherMenuPrincipal() {
    cout << "\n====== GESTION DU TOURNOI DE FOOTBALL ======" << endl;
    cout << "1. Gestion des equipes" << endl;
    cout << "2. Gestion des arbitres" << endl;
    cout << "3. Gestion des terrains" << endl;
    cout << "4. Gestion des matchs" << endl;
    cout << "5. Gestion des spectateurs et billets" << endl;
    cout << "6. Afficher le classement" << endl;
    cout << "0. Quitter" << endl;
    cout << "Choix: ";
}

void afficherMenuEquipe() {
    cout << "\n====== GESTION DES EQUIPES ======" << endl;
    cout << "1. Ajouter une equipe" << endl;
    cout << "2. Afficher les equipes" << endl;
    cout << "3. Rechercher une equipe" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuArbitre() {
    cout << "\n====== GESTION DES ARBITRES ======" << endl;
    cout << "1. Ajouter un arbitre" << endl;
    cout << "2. Afficher les arbitres" << endl;
    cout << "3. Ajouter une décision arbitrale" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuTerrain() {
    cout << "\n====== GESTION DES TERRAINS ======" << endl;
    cout << "1. Ajouter un terrain" << endl;
    cout << "2. Afficher les terrains" << endl;
    cout << "3. Rechercher un terrain" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuMatch() {
    cout << "\n====== GESTION DES MATCHS ======" << endl;
    cout << "1. Créer un match" << endl;
    cout << "2. Afficher les matchs" << endl;
    cout << "3. Enregistrer un resultat" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuTournoi() {
    cout << "\n====== GESTION DES SPECTATEURS ET BILLETS ======" << endl;
    cout << "1. Acheter un billet" << endl;
    cout << "2. Afficher les billets d'un spectateur" << endl;
    cout << "3. Vérifier la disponibilité des places" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

// Fonctions de gestion
void gererEquipes(vector<Equipe>& equipes) {
    int choix;
    do {
        afficherMenuEquipe();
        cin >> choix;
        switch (choix) {
            case 1: {
                int id, nbJoueurs;
                string nom, ville;
                cout << "ID de l'équipe: ";
                cin >> id;
                cout << "Nom de l'équipe: ";
                cin.ignore();
                getline(cin, nom);
                cout << "Nombre de joueurs: ";
                cin >> nbJoueurs;
                cout << "Ville: ";
                cin.ignore();
                getline(cin, ville);
                equipes.emplace_back(id, nom, nbJoueurs, ville);
                cout << "Équipe ajoutée avec succès!" << endl;
                break;
            }
            case 2: {
                if (equipes.empty()) {
                    cout << "Aucune équipe enregistrée." << endl;
                } else {
                    for (const auto& equipe : equipes) {
                        equipe.consultationEquipe();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            }
            case 3: {
                string critere, valeur;
                cout << "Rechercher par (id/nom/ville/score/classement): ";
                cin >> critere;
                cout << "Entrez la valeur du critère: ";
                cin.ignore();
                getline(cin, valeur);

                bool found = false;
                for (auto& equipe : equipes) {
                    if (!equipe.rechercheEquipe(critere, valeur).getNomEquipe().empty()) {
                        found = true;
                    }
                    cout << "------------------------" << endl;
                }

                if (!found) {
                    cout << "Aucune équipe trouvée avec ce critère." << endl;
                }
                break;
            }
        }
    } while (choix != 0);
}

void gererArbitres(vector<Arbitre>& arbitres) {
    int choix;
    do {
        afficherMenuArbitre();
        cin >> choix;

        // Vérifie si une erreur s'est produite lors de la saisie
        if (cin.fail()) {
            cin.clear(); // Réinitialise le flux en cas d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore les caractères restants
            cout << "Entrée invalide. Veuillez réessayer." << endl;
            continue; // Retourne au début de la boucle
        }

        switch (choix) {
            case 1: {
                int code;
                string nom;
                cout << "Code de l'arbitre: ";
                cin >> code;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nom de l'arbitre: ";
                getline(cin, nom);
                arbitres.emplace_back(code, nom);
                cout << "Arbitre ajouté avec succès!" << endl;
                break;
            }
            case 2: { // Afficher les arbitres
                if (arbitres.empty()) {
                    cout << "Aucun arbitre enregistré." << endl;
                } else {
                    for (const auto& arbitre : arbitres) {
                        arbitre.afficherArbitre();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            }
            case 3: { // Ajouter une décision arbitrale
                int code;
                string decision;
                cout << "Code de l'arbitre (pour ajouter une décision): ";
                cin >> code;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                auto it = find_if(arbitres.begin(), arbitres.end(), [code](const Arbitre& arb) {
                    return arb.getCodeArbitre() == code;
                });

                if (it != arbitres.end()) {
                    cout << "Entrez la décision: ";
                    getline(cin, decision); // Lecture de la décision
                    it->ajouterDecision(decision);
                    cout << "Décision ajoutée avec succès!" << endl;
                } else {
                    cout << "Arbitre introuvable." << endl;
                }
                break;
            }
            case 0: // Retour
                cout << "Retour au menu principal." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 0);
}


void gererTerrains(vector<Terrain>& terrains) {
    int choix;
    do {
        afficherMenuTerrain();
        cin >> choix;

        // Vérifie si une erreur s'est produite lors de la saisie
        if (cin.fail()) {
            cin.clear(); // Réinitialise le flux en cas d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore les caractères restants
            cout << "Entrée invalide. Veuillez réessayer." << endl;
            continue; // Retourne au début de la boucle
        }

        switch (choix) {
            case 1: { // Ajouter un terrain
                int id, capacite;
                string nom, ville, proprietaire;

                cout << "ID du terrain: ";
                cin >> id;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Nettoyer le flux
                cout << "Nom du terrain: ";
                getline(cin, nom);

                cout << "Ville: ";
                getline(cin, ville);

                cout << "Propriétaire (équipe): ";
                getline(cin, proprietaire);

                cout << "Capacité du terrain: ";
                cin >> capacite;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Nettoyer le flux
                terrains.emplace_back(id, nom, ville, proprietaire, capacite);
                cout << "Terrain ajouté avec succès!" << endl;
                break;
            }
            case 2: { // Afficher les terrains
                if (terrains.empty()) {
                    cout << "Aucun terrain enregistré." << endl;
                } else {
                    for (const auto& terrain : terrains) {
                        terrain.AfficherTerrain();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            }
            case 3: { // Rechercher un terrain
                string critere, valeur;
                cout << "Rechercher par (id/nom/ville/proprietaire/capacite): ";
                cin >> critere;

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Nettoyer le flux
                cout << "Entrez la valeur du critère: ";
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
                        }
                    cout << "------------------------" << endl;
                }

                if (!found) {
                    cout << "Aucun terrain trouvé avec ce critère." << endl;
                }
                break;
            }
            case 0: // Retour
                cout << "Retour au menu principal." << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 0);
}


void gererMatchs(vector<Match>& matchs, vector<Equipe>& equipes,
                 vector<Arbitre>& arbitres, vector<Terrain>& terrains) {
    int choix;
    do {
        afficherMenuMatch();
        cin >> choix;

        switch (choix) {
        case 1: { // Créer un match
            cout << "\nCréation d'un nouveau match...\n";
            Match match;
            int ref, phaseInput;

            // Référence du match
            cout << "Référence du match: ";
            cin >> ref;
            match.setRefMatch(ref);

            // Phase du match
            cout << "Phase du match :\n";
            cout << "0. PHASE_GROUPES\n1. ELIMINATOIRES\n2. QUARTS_FINALE\n3. DEMI_FINALE\n4. FINALE\n";
            cout << "Entrez le numéro correspondant : ";
            cin >> phaseInput;
            if (phaseInput < 0 || phaseInput > 4) {
                cout << "Phase invalide. Annulation de la création du match.\n";
                break;
            }
            match.setPhase(static_cast<Phase>(phaseInput));

            // Sélectionner les équipes
            if (equipes.size() < 2) {
                cout << "Nombre insuffisant d'équipes pour organiser un match.\n";
                break;
            }
            cout << "Sélection des équipes...\n";
            for (size_t i = 0; i < equipes.size(); ++i) {
                cout << i + 1 << ". " << equipes[i].getNomEquipe() << endl;
            }
            int equipe1Idx, equipe2Idx;
            cout << "Choisissez l'indice de la première équipe: ";
            cin >> equipe1Idx;
            cout << "Choisissez l'indice de la deuxième équipe: ";
            cin >> equipe2Idx;

            if (equipe1Idx < 1 || equipe1Idx > equipes.size() ||
                equipe2Idx < 1 || equipe2Idx > equipes.size() ||
                equipe1Idx == equipe2Idx) {
                cout << "Indices d'équipes invalides. Annulation de la création du match.\n";
                break;
            }

            match.ajouterEquipe(equipes[equipe1Idx - 1]);
            match.ajouterEquipe(equipes[equipe2Idx - 1]);

            // Sélectionner le terrain
            if (terrains.empty()) {
                cout << "Aucun terrain disponible.\n";
                break;
            }
            cout << "Sélection d'un terrain...\n";
            for (size_t i = 0; i < terrains.size(); ++i) {
                cout << i + 1 << ". " << terrains[i].getNomTerrain()
                     << " (" << terrains[i].getVilleTerrain() << ")" << endl;
            }
            int terrainIdx;
            cout << "Choisissez l'indice du terrain: ";
            cin >> terrainIdx;

            if (terrainIdx < 1 || terrainIdx > terrains.size()) {
                cout << "Indice de terrain invalide. Annulation de la création du match.\n";
                break;
            }

            match.setTerrain(terrains[terrainIdx - 1].getIdTerrain());
            match.setTerrainNom(terrains[terrainIdx - 1].getNomTerrain());

            // Sélectionner les arbitres
            if (arbitres.size() < 2) {
                cout << "Nombre insuffisant d'arbitres disponibles.\n";
                break;
            }
            cout << "Sélection des arbitres...\n";
            for (size_t i = 0; i < arbitres.size(); ++i) {
                cout << i + 1 << ". " << arbitres[i].getNomArbitre() << endl;
            }
            int arbitre1Idx, arbitre2Idx;
            cout << "Choisissez l'indice du premier arbitre: ";
            cin >> arbitre1Idx;
            cout << "Choisissez l'indice du deuxième arbitre: ";
            cin >> arbitre2Idx;

            if (arbitre1Idx < 1 || arbitre1Idx > arbitres.size() ||
                arbitre2Idx < 1 || arbitre2Idx > arbitres.size() ||
                arbitre1Idx == arbitre2Idx) {
                cout << "Indices d'arbitres invalides. Annulation de la création du match.\n";
                break;
            }

            match.ajouterArbitre(arbitres[arbitre1Idx - 1]);
            match.ajouterArbitre(arbitres[arbitre2Idx - 1]);

            // Ajouter le match à la liste des matchs
            matchs.push_back(match);
            cout << "Match créé avec succès !\n";
            break;
        }
        case 2: { // Afficher les matchs
            cout << "\nListe des matchs:\n";
            if (matchs.empty()) {
                cout << "Aucun match à afficher.\n";
                break;
            }
            for (const auto& match : matchs) {
                cout << "Référence: " << match.getRefMatch()
                     << ", Phase: ";
                switch (match.getPhase()) {
                    case PHASE_GROUPES:
                        cout << "Phase de Groupes";
                    break;
                    case ELIMINATOIRES:
                        cout << "Éliminatoires";
                    break;
                    case QUARTS_FINALE:
                        cout << "Quarts de Finale";
                    break;
                    case DEMI_FINALE:
                        cout << "Demi-Finale";
                    break;
                    case FINALE:
                        cout << "Finale";
                    break;
                    default:
                        cout << "Phase inconnue";
                    break;
                }
                     cout << ", Équipes: ";
                for (const auto& equipe : match.getEquipes()) {
                    cout << equipe.getNomEquipe() << " x ";
                }
                cout << ", Terrain: " << match.getTerrainNom() << endl;
            }
            break;
        }
        default:
            if (choix != 0) {
                cout << "Choix invalide. Réessayez.\n";
            }
        }
    } while (choix != 0);
}


void gererTournois(vector<Match>& matchs) {
    int choix;
    do {
        afficherMenuTournoi();
        cin >> choix;
        // Implémentation de la gestion des spectateurs et billets
    } while (choix != 0);
}

void afficherClassement(const vector<Equipe>& equipes) {
    cout << "\n====== CLASSEMENT DES ÉQUIPES ======" << endl;
    // Implémentation de l'affichage du classement
}

int main() {
    // Déclaration des vecteurs pour stocker les données
    vector<Equipe> equipes;
    vector<Arbitre> arbitres;
    vector<Terrain> terrains;
    vector<Match> matchs;

    int choix;
    do {
        afficherMenuPrincipal();
        cin >> choix;

        switch (choix) {
            case 1:
                gererEquipes(equipes);
                break;
            case 2:
                gererArbitres(arbitres);
                break;
            case 3:
                gererTerrains(terrains);
                break;
            case 4:
                gererMatchs(matchs, equipes, arbitres, terrains);
                break;
            case 5:
                gererTournois(matchs);
                break;
            case 6:
                afficherClassement(equipes);
                break;
            case 0:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Option invalide!" << endl;
        }
    } while (choix != 0);

    return 0;
}