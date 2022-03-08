#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm/window.h>   //car on va herité de fenetre
#include <gtkmm/box.h>      //modele de boite
#include <gtkmm/alignment.h>    //pour pouvoir aligner horizontalement ou vertivalement les widgets
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/main.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/stock.h>
#include <gtkmm/button.h>

#include "Boutton.hpp"      //appele de notre objet boutton personnalisé

class Fenetre : public Gtk::Window {
    public :
        Fenetre();      //constructeur
    private:
    //ici commence les items du menubar
        Gtk::Button boutonAide;     //boutton aide
        Gtk::VBox boiteV;    
        Gtk::HBox boiteH;
        Gtk::HButtonBox boiteBouttonH;
        Gtk::MenuBar barreMenu;        //Création d’une barre de menu.
        //Création de l’item menu Menu et ajout à la barre de menu.
        Gtk::MenuItem menuItemMenu;
        //Création du menu Menu et ajout à l’item de menu Menu.
        Gtk::Menu menuMenu;
        //Création d’un item de menu à partir d’un Stock Item et ajout au menu.
        Gtk::ImageMenuItem menuNouveau;
        //Menu->Enregistrer
        Gtk::ImageMenuItem menuEnregistrer;
        //Ajout d’un séparateur au menu Menu.
        Gtk::SeparatorMenuItem separateur;
        //Menu->Quitter
        Gtk::ImageMenuItem menuQuitter;
        //Menu Aide
        Gtk::MenuItem menuItemAide;
        Gtk::ImageMenuItem menuText;       //le long text contenant l aide est placé sous forme de menu
        Gtk::Menu menuAide;
    //ici se termine les items du menubar

    //ici commence les items dans le corps
        Gtk::Button nouveau;
        Gtk::Button load;

};

#endif