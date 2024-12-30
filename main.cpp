#include "Tournoi.h"
#include <iostream>
#include <limits>
using namespace std;

void afficherMenuPrincipal() {
    cout << "\n====== GESTION DU TOURNOI DE FOOTBALL ======" << endl;
    cout << "1. Création et configuration du tournoi" << endl;
    cout << "2. Gestion des équipes" << endl;
    cout << "3. Gestion des arbitres" << endl;
    cout << "4. Gestion des terrains" << endl;
    cout << "5. Gestion des matchs" << endl;
    cout << "6. Afficher le classement" << endl;
    cout << "0. Quitter" << endl;
    cout << "Choix: ";
}

void afficherMenuCreationTournoi() {
    cout << "\n====== CREATION DU TOURNOI ======" << endl;
    cout << "1. Configurer le tournoi" << endl;
    cout << "2. Ajouter des équipes" << endl;
    cout << "3. Ajouter des arbitres" << endl;
    cout << "4. Ajouter des terrains" << endl;
    cout << "5. Planifier les phases" << endl;
    cout << "6. Afficher les informations du tournoi" << endl;
    cout << "7. Commencer le tournoi" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void afficherMenuEquipe() {
    cout << "\n====== GESTION DES ÉQUIPES ======" << endl;
    cout << "1. Ajouter une équipe" << endl;
    cout << "2. Afficher les équipes" << endl;
    cout << "3. Rechercher une équipe" << endl;
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
    cout << "3. Enregistrer un résultat" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void nettoyerBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void gererCreationTournoi(Tournoi& tournoi) {
    int choix;
    do {
        afficherMenuCreationTournoi();
        cin >> choix;
        nettoyerBuffer();

        switch (choix) {
            case 1: {
                string nom, date;
                int nbEquipes;
                cout << "Nom du tournoi: ";
                getline(cin, nom);
                cout << "Date du tournoi (JJ/MM/AAAA): ";
                getline(cin, date);
                cout << "Nombre d'équipes maximum: ";
                cin >> nbEquipes;

                if (tournoi.configurationInitiale(nom, date, nbEquipes)) {
                    cout << "Configuration du tournoi réussie!" << endl;
                }
                break;
            }
            case 2: {
                if (!tournoi.getNombreEquipesMax()) {
                    cout << "Veuillez d'abord configurer le tournoi." << endl;
                    break;
                }
                int id, nbJoueurs;
                string nom, ville;
                cout << "ID de l'équipe: ";
                cin >> id;
                nettoyerBuffer();
                cout << "Nom de l'équipe: ";
                getline(cin, nom);
                cout << "Nombre de joueurs: ";
                cin >> nbJoueurs;
                nettoyerBuffer();
                cout << "Ville: ";
                getline(cin, ville);

                tournoi.ajouterEquipe(Equipe(id, nom, nbJoueurs, ville));
                break;
            }
            case 3: {
                int code;
                string nom;
                cout << "Code de l'arbitre: ";
                cin >> code;
                nettoyerBuffer();
                cout << "Nom de l'arbitre: ";
                getline(cin, nom);

                tournoi.ajouterArbitre(Arbitre(code, nom));
                break;
            }
            case 4: {
                int id, capacite;
                string nom, ville, proprietaire;
                cout << "ID du terrain: ";
                cin >> id;
                nettoyerBuffer();
                cout << "Nom du terrain: ";
                getline(cin, nom);
                cout << "Ville: ";
                getline(cin, ville);
                cout << "Propriétaire: ";
                getline(cin, proprietaire);
                cout << "Capacité: ";
                cin >> capacite;

                tournoi.ajouterTerrain(Terrain(id, nom, ville, proprietaire, capacite));
                break;
            }
            case 5: {
                if (tournoi.peutCommencer()) {
                    tournoi.planifierPhaseGroupe();
                    tournoi.planifierPhaseEliminatoire();
                    tournoi.genererCalendrier();
                }
                break;
            }
            case 6: {
                tournoi.afficherInfoTournoi();
                break;
            }
            case 7: {
                if (tournoi.peutCommencer()) {
                    tournoi.setEstCommence(true);
                    cout << "Le tournoi commence!" << endl;
                }
                break;
            }
        }
    } while (choix != 0);
}

void gererEquipes(Tournoi& tournoi) {
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
                nettoyerBuffer();
                cout << "Nom de l'équipe: ";
                getline(cin, nom);
                cout << "Nombre de joueurs: ";
                cin >> nbJoueurs;
                nettoyerBuffer();
                cout << "Ville: ";
                getline(cin, ville);

                tournoi.ajouterEquipe(Equipe(id, nom, nbJoueurs, ville));
                break;
            }
            case 2:
                tournoi.afficherEquipes();
                break;
            case 3: {
                string critere, valeur;
                cout << "Rechercher par (id/nom/ville/score/classement): ";
                cin >> critere;
                cout << "Valeur: ";
                nettoyerBuffer();
                getline(cin, valeur);

                Equipe* equipe = tournoi.rechercherEquipe(critere, valeur);
                if (equipe) {
                    equipe->consultationEquipe();
                } else {
                    cout << "Aucune équipe trouvée." << endl;
                }
                break;
            }
        }
    } while (choix != 0);
}

void gererArbitres(Tournoi& tournoi) {
    int choix;
    do {
        afficherMenuArbitre();
        cin >> choix;
        switch (choix) {
            case 1: {
                int code;
                string nom;
                cout << "Code de l'arbitre: ";
                cin >> code;
                nettoyerBuffer();
                cout << "Nom de l'arbitre: ";
                getline(cin, nom);

                tournoi.ajouterArbitre(Arbitre(code, nom));
                break;
            }
            case 2:
                tournoi.afficherArbitres();
                break;
            case 3: {
                int code;
                string decision;
                cout << "Code de l'arbitre: ";
                cin >> code;
                nettoyerBuffer();
                cout << "Décision: ";
                getline(cin, decision);

                tournoi.ajouterDecisionArbitrale(code, decision);
                break;
            }
        }
    } while (choix != 0);
}

void gererTerrains(Tournoi& tournoi) {
    int choix;
    do {
        afficherMenuTerrain();
        cin >> choix;
        switch (choix) {
            case 1: {
                int id, capacite;
                string nom, ville, proprietaire;
                cout << "ID du terrain: ";
                cin >> id;
                nettoyerBuffer();
                cout << "Nom du terrain: ";
                getline(cin, nom);
                cout << "Ville: ";
                getline(cin, ville);
                cout << "Propriétaire: ";
                getline(cin, proprietaire);
                cout << "Capacité: ";
                cin >> capacite;

                tournoi.ajouterTerrain(Terrain(id, nom, ville, proprietaire, capacite));
                break;
            }
            case 2:
                tournoi.afficherTerrains();
                break;
            case 3: {
                string critere, valeur;
                cout << "Rechercher par (id/nom/ville/proprietaire): ";
                cin >> critere;
                nettoyerBuffer();
                cout << "Valeur: ";
                getline(cin, valeur);

                Terrain* terrain = tournoi.rechercherTerrain(critere, valeur);
                if (terrain) {
                    terrain->AfficherTerrain();
                } else {
                    cout << "Aucun terrain trouvé." << endl;
                }
                break;
            }
        }
    } while (choix != 0);
}

void gererMatchs(Tournoi& tournoi) {
    int choix;
    do {
        afficherMenuMatch();
        cin >> choix;
        switch (choix) {
            case 1: {
                int phaseInt;
                cout << "\nPhase du match (0: Groupes, 1: Éliminatoires, "
                     << "2: Quarts, 3: Demi, 4: Finale): ";
                cin >> phaseInt;
                if (phaseInt >= 0 && phaseInt <= 4) {
                    tournoi.creerMatch(static_cast<Phase>(phaseInt));
                } else {
                    cout << "Phase invalide!" << endl;
                }
                break;
            }
            case 2:
                tournoi.afficherMatchs();
                break;
            case 3: {
                int refMatch, score1, score2;
                cout << "Référence du match: ";
                cin >> refMatch;
                cout << "Score équipe 1: ";
                cin >> score1;
                cout << "Score équipe 2: ";
                cin >> score2;

                tournoi.enregistrerResultatMatch(refMatch, score1, score2);
                break;
            }
        }
    } while (choix != 0);
}

int main() {
    Tournoi tournoi;
    int choix;

    do {
        afficherMenuPrincipal();
        if (!(cin >> choix)) {
            nettoyerBuffer();
            cout << "Entrée invalide. Veuillez entrer un numéro." << endl;
            continue;
        }

        switch (choix) {
            case 1:
                gererCreationTournoi(tournoi);
            break;
            case 2:
                gererEquipes(tournoi);
            break;
            case 3:
                gererArbitres(tournoi);
            break;
            case 4:
                gererTerrains(tournoi);
            break;
            case 5:
                    if (!tournoi.getEstCommence()) {
                        cout << "Le tournoi n'a pas encore commencé. Veuillez le démarrer depuis le menu de création." << endl;
                    } else {
                        gererMatchs(tournoi);
                    }
            break;
            case 6:
                tournoi.afficherClassement();
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