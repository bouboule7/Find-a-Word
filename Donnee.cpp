#include "Donnee.hpp"
#include <iostream>
using namespace std;
Donnee::Donnee(){
    fichierProgression.open("data.data/progression.data", ios::in);
    if(!fichierProgression)
    {
        cout<<"Erreur lors des chargements des donnés. Veuiller verifier les fichier necessaires. \nMerci"<<endl;
        exit(-1);
    }
}
void Donnee::changerDeNiveau(int niveauUtilisateur){
    niveau=niveauUtilisateur;
}
int Donnee::getNiveau(){
    return niveau;
}
bool Donnee::rechercheResultatDansListeDeMot(vector <string> lettreAlleatoire, string motUtilisateur){
    bool retour(false);
    motFrancais.open(nomDuFichier(motUtilisateur), ios::out);
    if(!motFrancais)
    {
        cout<<"Erreur lors des chargements des donnés. Veuiller verifier les fichier necessaires. \nMerci"<<endl;
        exit(-1);
    }
    while(getline(motFrancais,mot)){
        if (mot==motUtilisateur){
            retour=true;
        }
    }
    if(retour){
        for(int i=0;i<lettreAlleatoire.size();i++){
            if(!(motUtilisateur.find(lettreAlleatoire.at(i))))
                retour=false;
        }
    }
    motFrancais.close();
    return retour;
}
string Donnee::nomDuFichier(string lettre){
    for(int i=0;i<lettre.size();i++){
        if(!((lettre[i]>='a' && lettre[i]<='z')||(lettre[i]>='A' && lettre[i]<='Z'))){
            lettre[i]='\0';
        }
         if (lettre[i]>='A' && lettre[i]<='Z') {
            lettre[i] = lettre[i] + ('a'-'A');
        }
    }
    string nom{"data.data/lettre.data/"};
    nom+=lettre.at(0);
    nom+=".data";
    return nom;
}
