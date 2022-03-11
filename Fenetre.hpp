#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/window.h>                                   //car on va herité de fenetre
#include <gtkmm/box.h>                                      //modele de boite
#include <gtkmm/buttonbox.h>                                //modele de boite pour les bouttons
#include <gtkmm/imagemenuitem.h>                            //pour les sous menu
#include <gtkmm/main.h>                                     //pour la fonction principale de gtkmm
#include <gtkmm/menu.h>                                     //pour l'ajout des menus
#include <gtkmm/menubar.h>                                  //utilisation du barre de menu
#include <gtkmm/menuitem.h>                                 //gestion des sous menu
#include <gtkmm/stock.h>                                    //pour utiliser les Stock Items
#include <gtkmm/button.h>                                   //utilisation des boutton
#include <gtkmm/messagedialog.h>                            //boite de dialogue
#include <gtkmm/entry.h>

#include "Boutton.hpp"                                      //appele de notre objet boutton personnalisé

class Fenetre : public Gtk::Window {
    public :
        Fenetre();                                          //constructeur

        void cacherBouttonNewEtLoad();
        void sauvegarde();
        void afficheChoixLevel();
        void afficheTextEdit();
        void afficheLettre();
        void afficheZoneDeTextRepose();
    private:
        Gtk::VBox boiteV;    
            Gtk::HBox boiteH;                               //ici commence les items du menubar
                Gtk::MenuBar barreMenu;                     //Création d’une barre de menu.
                    Gtk::Menu menuMenu;                     //pack menuMenu
                        Gtk::MenuItem menuItemMenu;         //Création de l’item menu Menu
                        Gtk::ImageMenuItem menuNouveau;     //Menu->Nouveau
                        Gtk::ImageMenuItem menuEnregistrer; //Menu->Enregistrer
                        Gtk::ImageMenuItem menuQuitter;     //Menu->Quitter
                    Gtk::Menu menuAide;                     //pack menuMenu
                        Gtk::MenuItem menuItemAide;         //Menu Aide
                        Gtk::ImageMenuItem menuText;        //le long text contenant l aide est placé sous forme de menu
                                                            //ici se termine les items du menubarre
                        Gtk::Entry textReponse;
                        

        //ici commence les items dans le corps
        Gtk::HButtonBox boiteBouttonH;
            Gtk::Button nouveau;
            Gtk::Button load;
                    Gtk::Button level1;                 //boutton pour le niveau 1
                    Gtk::Button level2;                 //boutton pour le niveau 2
                    Gtk::Button level3;                 //boutton pour le niveau 3
                    Gtk::Button level4;                 //boutton pour le niveau 4                        Gtk::Button level5;                 //boutton pour le niveau 5

};

#endif