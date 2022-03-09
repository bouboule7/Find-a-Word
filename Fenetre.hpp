#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/window.h>                                   //car on va herité de fenetre
#include <gtkmm/box.h>                                      //modele de boite
#include <gtkmm/buttonbox.h>                                //modele de boite pour les bouttons
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/main.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/stock.h>
#include <gtkmm/button.h>

#include "Boutton.hpp"                                      //appele de notre objet boutton personnalisé

class Fenetre : public Gtk::Window {
    public :
        Fenetre();                                          //constructeur

        void changerEcran();
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

        //ici commence les items dans le corps
        Gtk::HButtonBox boiteBouttonH;
            Gtk::Button nouveau;
            Gtk::Button load;

};

#endif