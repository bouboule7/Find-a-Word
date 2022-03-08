#include "Fenetre.hpp"  //car on va utiliser la classe fenetre

Fenetre::Fenetre() {
    //Modification de la fenêtre.
    set_title("Find a word");   //pour editer le titre de la fenetre
    resize(500, 350);       //on redimensionne la fenetre au taille 640 * 480

    set_position(Gtk::WIN_POS_CENTER);      //on positionne la fenetre au centre
    
    add(boiteH);
    boiteH.pack_start(boiteV,Gtk::PACK_SHRINK);
    boiteH.pack_end(boiteBouttonH);
    boiteBouttonH.pack_start(nouveau,Gtk::PACK_SHRINK);
    boiteBouttonH.pack_start(load,Gtk::PACK_SHRINK);
    
    boiteV.pack_start(barreMenu, Gtk::PACK_SHRINK);
    menuItemMenu.set_label("MENU");
    barreMenu.append(menuItemMenu);

    menuItemMenu.set_submenu(menuMenu);
    menuNouveau.set_label("nouveau");
    menuMenu.append(menuNouveau);
    menuEnregistrer.set_label("Enregistrer");
    menuMenu.append(menuEnregistrer);
    
    menuMenu.append(separateur);
    
    menuQuitter.set_label("QUITTER !");
    menuMenu.append(menuQuitter);
    
    menuItemAide.set_label("Aide");
    barreMenu.append(menuItemAide);

    menuItemAide.set_submenu(menuAide);
    menuText.set_label("Jeu du Find a word. \n Le but du jeu est de trouver un mot contenant \nles lettres proposer alléatoirement par le jeu.");
    menuAide.append(menuText);

    //les bouttons principale
    nouveau.set_label("Nouveau");
    load.set_label("Load");
    
    boiteV.show();
    boiteH.show();
    menuItemMenu.show();
    barreMenu.show();

    menuItemMenu.show();
    menuNouveau.show();
    menuMenu.show();
    menuEnregistrer.show();
    menuMenu.show();
    
    menuMenu.show();
    
    menuQuitter.show();
    menuMenu.show();
    
    menuItemAide.show();
    barreMenu.show();

    menuItemAide.show();
    menuText.show();
    menuAide.show();

    //visibilité des deux boutton
    boiteBouttonH.show();
    nouveau.show();
    load.show();
}