#include <gtkmm/box.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/main.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/stock.h>
#include <gtkmm/window.h>

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Gtk::Window fenetre;
    fenetre.resize(640, 480);
    
    Gtk::VBox boiteV;
    fenetre.add(boiteV);
    
    //Création d’une barre de menu.
    Gtk::MenuBar barreMenu;
    boiteV.pack_start(barreMenu, Gtk::PACK_SHRINK);
    
    //Création de l’item menu fichier et ajout à la barre de menu.
    Gtk::MenuItem menuItemFichier("_Fichier", true);
    barreMenu.append(menuItemFichier);
    
    //Création du menu Fichier et ajout à l’item de menu Fichier.
    Gtk::Menu menuFichier;
    menuItemFichier.set_submenu(menuFichier);
    
    //Création d’un item de menu à partir d’un Stock Item et ajout au menu.
    Gtk::ImageMenuItem menuNouveau(Gtk::Stock::NEW);
    menuFichier.append(menuNouveau);
    
    //Sous-menu : Fichier->Récents
    Gtk::MenuItem menuItemFichiersRecents("_Récents", true);
    menuFichier.append(menuItemFichiersRecents);
    
    //Utilisation de set_submenu() afin de créer un sous-menu.
    Gtk::Menu menuRecents;
    menuItemFichiersRecents.set_submenu(menuRecents);
    
    Gtk::MenuItem fichierRecent1("Fichier récent 1");
    menuRecents.append(fichierRecent1);
    Gtk::MenuItem fichierRecent2("Fichier récent 2");
    menuRecents.append(fichierRecent2);
    
    //Fichier->Ouvrir
    Gtk::ImageMenuItem menuOuvrir(Gtk::Stock::OPEN);
    menuFichier.append(menuOuvrir);
    
    //Fichier->Enregistrer
    Gtk::ImageMenuItem menuEnregistrer(Gtk::Stock::SAVE);
    menuFichier.append(menuEnregistrer);
    
    //Ajout d’un séparateur au menu Fichier.
    Gtk::SeparatorMenuItem separateur;
    menuFichier.append(separateur);
    
    //Fichier->Fermer
    Gtk::ImageMenuItem menuFermer(Gtk::Stock::CLOSE);
    menuFichier.append(menuFermer);
    
    //Fichier->Quitter
    Gtk::ImageMenuItem menuQuitter(Gtk::Stock::QUIT);
    //Connexion du clic sur le menu Quitter à la fonction Gtk::Main::quit().
    menuQuitter.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
    menuFichier.append(menuQuitter);
    
    //Menu édition
    Gtk::MenuItem menuItemEdition("É_dition", true);
    barreMenu.append(menuItemEdition);
    
    Gtk::Menu menuEdition;
    menuItemEdition.set_submenu(menuEdition);
    
    fenetre.show_all();
    Gtk::Main::run(fenetre);
    return 0;
}