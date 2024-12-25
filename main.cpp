#include "Equipe.h"
#include "Arbitre.h"
#include "Terrain.h"
#include "Match.h"
#include "Zone.h"
#include "Billet.h"
#include "Spectateur.h"
#include <iostream>
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
    cout << "3. Modifier une equipe" << endl;
    cout << "4. Rechercher une equipe" << endl;
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
    cout << "4. Attribution des arbitres" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuSpectateur() {
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
                // Modification d'équipe
                break;
            }
            case 4: {
                // Recherche d'équipe
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
        // Implémentation similaire à gererEquipes
    } while (choix != 0);
}

void gererTerrains(vector<Terrain>& terrains) {
    int choix;
    do {
        afficherMenuTerrain();
        cin >> choix;
        // Implémentation de la gestion des terrains
    } while (choix != 0);
}

void gererMatchs(vector<Match>& matchs, vector<Equipe>& equipes,
                vector<Arbitre>& arbitres, vector<Terrain>& terrains) {
    int choix;
    do {
        afficherMenuMatch();
        cin >> choix;
        // Implémentation de la gestion des matchs
    } while (choix != 0);
}

void gererSpectateurs(vector<Spectateur>& spectateurs, vector<Match>& matchs,
                     vector<Zone>& zones) {
    int choix;
    do {
        afficherMenuSpectateur();
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
    vector<Spectateur> spectateurs;
    vector<Zone> zones;

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
                gererSpectateurs(spectateurs, matchs, zones);
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