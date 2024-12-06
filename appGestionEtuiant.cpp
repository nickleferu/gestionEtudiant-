#include <iostream>
#include <vector>
#include <string>

class Etudiant {
private:
    std::string matricule;
    std::string nom;
    std::string prenom;
    std::string sexe;
    int age;
    float note1, note2, note3;

public:
    Etudiant(std::string mat, std::string n, std::string p, std::string s, int a, float n1, float n2, float n3)
        : matricule(mat), nom(n), prenom(p), sexe(s), age(a), note1(n1), note2(n2), note3(n3) {}

    void afficher() {
        std::cout << "Matricule : " << matricule << std::endl;
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Prénom : " << prenom << std::endl;
        std::cout << "Sexe : " << sexe << std::endl;
        std::cout << "Âge : " << age << std::endl;
        std::cout << "Note 1 : " << note1 << std::endl;
        std::cout << "Note 2 : " << note2 << std::endl;
        std::cout << "Note 3 : " << note3 << std::endl;
    }

    void mettreAJourNotes(float n1, float n2, float n3) {
        note1 = n1;
        note2 = n2;
        note3 = n3;
    }

    std::string getMatricule() {
        return matricule;
    }
};

class GestionEtudiants {
private:
    std::vector<Etudiant> etudiants;

public:
    void ajouterEtudiant(Etudiant etudiant) {
        etudiants.push_back(etudiant);
    }

    void mettreAJourEtudiant(std::string matricule, float n1, float n2, float n3) {
        for (auto &etudiant : etudiants) {
            if (etudiant.getMatricule() == matricule) {
                etudiant.mettreAJourNotes(n1, n2, n3);
                return;
            }
        }
    }

    void supprimerEtudiant(std::string matricule) {
        etudiants.erase(std::remove_if(etudiants.begin(), etudiants.end(),
            [&matricule](Etudiant &etudiant) { return etudiant.getMatricule() == matricule; }), etudiants.end());
    }

    void afficherEtudiants() {
        for (const auto &etudiant : etudiants) {
            etudiant.afficher();
            std::cout << std::endl;
        }
    }
};

int main() {
    GestionEtudiants gestion;
    int choix;

    do {
        std::cout << "Menu :\n";
        std::cout << "1 - Ajouter un étudiant\n";
        std::cout << "2 - Mettre à jour un étudiant\n";
        std::cout << "3 - Supprimer un étudiant\n";
        std::cout << "4 - Afficher les étudiants\n";
        std::cout << "5 - Quitter\n";
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1: {
                std::string matricule, nom, prenom, sexe;
                int age;
                float note1, note2, note3;
                std::cout << "Matricule : ";
                std::cin >> matricule;
                std::cout << "Nom : ";
                std::cin >> nom;
                std::cout << "Prénom : ";
                std::cin >> prenom;
                std::cout << "Sexe : ";
                std::cin >> sexe;
                std::cout << "Âge : ";
                std::cin >> age;
                std::cout << "Note 1 : ";
                std::cin >> note1;
                std::cout << "Note 2 : ";
                std::cin >> note2;
                std::cout << "Note 3 : ";
                std::cin >> note3;
                Etudiant etudiant(matricule, nom, prenom, sexe, age, note1, note2, note3);
                gestion.ajouterEtudiant(etudiant);
                break;
            }
            case 2: {
                std::string matricule;
                float note1, note2, note3;
                std::cout << "Matricule : ";
                std::cin >> matricule;
                std::cout << "Nouvelle Note 1 : ";
                std::cin >> note1;
                std::cout << "Nouvelle Note 2 : ";
                std::cin >> note2;
                std::cout << "Nouvelle Note 3 : ";
                std::cin >> note3;
                gestion.mettreAJourEtudiant(matricule, note1, note2, note3);
                break;
            }
            case 3: {
                std::string matricule;
                std::cout << "Matricule : ";
                std::cin >> matricule;
                gestion.supprimerEtudiant(matricule);
                break;
            }
            case 4:
                gestion.afficherEtudiants();
                break;
            case 5:
                std::cout << "Au revoir !\n";
                break;
            default:
                std::cout << "Choix invalide !\n";
        }
    } while (choix != 5);

    return 0;
}
