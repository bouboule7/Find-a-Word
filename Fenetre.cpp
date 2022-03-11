#include "Fenetre.hpp"                                          //car on va utiliser la classe fenetre

Fenetre::Fenetre() {                                            //constructeur
                                                                //Modification de la fenêtre.
    set_title("Find a word");                                   //pour editer le titre de la fenetre
    resize(500, 350);                                           //on redimensionne la fenetre au taille 640 * 480

    set_position(Gtk::WIN_POS_CENTER);                          //on positionne la fenetre au centre

    
    add(boiteH);                                                //addition de boiteH boite horizontale au fenetre qui va tout contenir
    boiteH.pack_start(boiteV,Gtk::PACK_SHRINK);                 //on ajoute boiteV dans boiteH              ///PACK_SHRINK sert a ajuster l'espacement des widgets
        boiteV.pack_start(barreMenu, Gtk::PACK_SHRINK);         //on ajoute la barre de Menu dans la boiteV
            menuItemMenu.set_label("MENU");                     //on ajoute le text "MENU" du menuItemMenu
            barreMenu.append(menuItemMenu);                     //on ajoute des sous menu a menuItemMenu

            menuItemMenu.set_submenu(menuMenu);                 //on donne le sub menuNouveau comme submenu
                menuNouveau.set_label("nouveau");               //on donne le text pour menuNouveau "nouveau"
                menuMenu.append(menuNouveau);                   //on fixe menuNoouveau comme submenu
                menuEnregistrer.set_label("Enregistrer");       //on donne le text pour menuNouveau "nouveau"
                menuMenu.append(menuEnregistrer);               //on ajoute menuEnregistrer au submenu
                menuQuitter.set_label("QUITTER !");             //on donne le text pour le surmenu quitter "QUITTER"     
                menuMenu.append(menuQuitter);                   //on ajoute le sub menu quitter
                
            menuItemAide.set_label("Aide");                     //on donne le text pour le second menu "aide"
            barreMenu.append(menuItemAide);                     //on ajouter le menu aide au barre de menu

            menuItemAide.set_submenu(menuAide);                 //on va ajouter des sub menu au menu aide
            menuText.set_label("Jeu du Find a word. \n Le but du jeu est de trouver un mot contenant \nles lettres proposer alléatoirement par le jeu.");
                                                                //on donne le text contenant l'aide
                menuAide.append(menuText);                      //on ajouter la section contenant l'aide au submenu de facon a ce que quand on se focalise sur le menu aide, le long text appareit

    boiteH.pack_start(boiteBouttonH);                             //on ajoute la boite contenant les deux bouttons dans boiteH
                                                                //les bouttons principale au demarage
        boiteBouttonH.pack_start(nouveau,Gtk::PACK_SHRINK);     //on ajoute dans la boite de boutton le boutton nouveau
            nouveau.set_label("Nouveau");                       //on donne le text pour le boutton nouveau
        boiteBouttonH.pack_start(load,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton load
            load.set_label("Load");                             //on donne le text pour le boutton loads
        boiteBouttonH.pack_end(level1,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level1
            level1.set_label(" 1 ");                             //on donne le text pour le boutton level1
        boiteBouttonH.pack_end(level2,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton lelev2
            level2.set_label(" 2 ");                             //on donne le text pour le boutton level2
        boiteBouttonH.pack_end(level3,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level3
            level3.set_label(" 3 ");                             //on donne le text pour le boutton level3
        boiteBouttonH.pack_end(level4,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level4
            level4.set_label(" 4 ");                             //on donne le text pour le boutton level4
        boiteBouttonH.pack_end(level5,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level5s
            level5.set_label(" 5 ");                             //on donne le text pour le boutton level5
    boiteH.pack_start(textReponse);

    boiteV.show();                                              //on affiche le boiteV                 boite pricipale
        boiteH.show();                                          //on affiche le boiteH                 contenant le menu en haut
            barreMenu.show();                                   //on affiche barreMenu 
                menuItemMenu.show();                            //on affiche menuItemMenu    
                    menuMenu.show();                            //on affiche menuMenu
                    menuNouveau.show();                         //on affiche menuNouveau
                    menuEnregistrer.show();                     //on affiche menuEnregistrer
                    menuQuitter.show();                         //on affiche menuQuitter
                menuItemAide.show();                            //on affiche menuItemAide
                    menuAide.show();                            //on affiche menuAide
                    menuText.show();                            //on affiche menuText
        boiteBouttonH.show();                                   //on affiche boiteBouttonH            contenant tout le corps
            nouveau.show();                                     //on affiche le boutton nouveau
            load.show();                                        //on affiche le boutton load
        textReponse.show();

    //on change d'ecran cad appele du fonction changerEcran
    nouveau.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficheChoixLevel));
    load.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::cacherBouttonNewEtLoad));

    //edition de l'action menuEnregistrer
    menuEnregistrer.signal_activate().connect(sigc::mem_fun(*this, &Fenetre::sauvegarde));
    //edition de l'action menuQuitter
    menuQuitter.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));
}

void Fenetre::cacherBouttonNewEtLoad(){                         //definition du fonction changerEcran
    load.hide();                                                //on cache le boutton load
    nouveau.hide();                                             //on cache le boutton nouveau
}
void Fenetre::afficheChoixLevel(){
    cacherBouttonNewEtLoad();
    level1.show();
    level2.show();
    level3.show();
    level4.show();
    level5.show();
}
void Fenetre::sauvegarde(){
    Gtk::MessageDialog dialogue(*this,"",true);
    dialogue.set_title("Sauvegarde");
    dialogue.set_secondary_text("Votre progression et vos donné ont été enregistrer avec <b>SUCCESS</b>",true);
    dialogue.run();
}
/*
void Fenetre::afficheTextEdit();
void Fenetre::afficheLettre();
void Fenetre::afficheZoneDeTextRepose();
*/