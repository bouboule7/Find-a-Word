#ifndef DONNEE_HPP
#define DONNEE_HPP
#include <fstream>              //utilisation des fichier
#include <vector>
using namespace std;

class Donnee{
    private:
        char debutDeMot;
        int score;
        int niveau;
        fstream fichierProgression;
        ifstream motFrancais;
        string mot;
    public:
        Donnee();
        void changerDeNiveau(int niveauUtilisateur);
        int getNiveau();
        bool rechercheResultatDansListeDeMot(vector <string> lettreAlleatoire, string motUtilisateur);
        string nomDuFichier(string lettre);
};
#endif
