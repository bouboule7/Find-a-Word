#include "Fenetre.hpp"                                          //car on va utiliser la classe fenetre


Fenetre::Fenetre() {            
    
    
	//load css
	Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
	cssProvider->load_from_path("style.css");
	
	Glib::RefPtr<Gtk::StyleContext> styleContext = Gtk::StyleContext::create();
	
	//get default screen
	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	
	//add provider for screen in all application
	styleContext->add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    
                                    //constructeur
                                                                //Modification de la fenêtre.
    set_title("Find a word");                                   //pour editer le titre de la fenetre
    resize(500, 350);                                           //on redimensionne la fenetre au taille 640 * 480

    set_position(Gtk::WIN_POS_CENTER);                          //on positionne la fenetre au centre



    boitePrincipale.set_center_widget(boiteAlignement);	
    boiteAlignement.set_center_widget(boiteBouttonH);
    boiteAlignement.set_name("boiteAlignement");

    add(boitePrincipale);    
    boitePrincipale.set_name("boitePricipale");                                            //addition de boitePrincipale boite horizontale au fenetre qui va tout contenir
    boitePrincipale.pack_start(boiteHaut,Gtk::PACK_SHRINK);                 //on ajoute boiteHaut dans boitePrincipale              ///PACK_SHRINK sert a ajuster l'espacement des widgets
        boiteHaut.pack_start(barreMenu, Gtk::PACK_SHRINK);         //on ajoute la barre de Menu dans la boiteHaut
            barreMenu.append(menuItemMenu);                     //on ajoute des sous menu a menuItemMenu
            menuItemMenu.set_label("MENU");                     //on ajoute le text "MENU" du menuItemMenu
            menuItemMenu.set_name("menuItemMenu");
            menuItemMenu.set_submenu(menuMenu);                 //on donne le sub menuNouveau comme submenu
                menuNouveau.set_label("nouveau");               //on donne le text pour menuNouveau "nouveau"
                menuNouveau.set_name("menuNouveau");
                menuMenu.append(menuNouveau);                   //on fixe menuNoouveau comme submenu
                menuEnregistrer.set_label("Enregistrer");       //on donne le text pour menuNouveau "nouveau"
                menuEnregistrer.set_name("menuEnregistrer");
                menuMenu.append(menuEnregistrer);               //on ajoute menuEnregistrer au submenu
                menuQuitter.set_label("QUITTER !");             //on donne le text pour le surmenu quitter "QUITTER"
                menuQuitter.set_name("menuQuitter");     
                menuMenu.append(menuQuitter);                   //on ajoute le sub menu quitter
                
            menuItemAide.set_label("Aide");                     //on donne le text pour le second menu "aide"
            menuItemAide.set_name("menuItemAide");
            barreMenu.append(menuItemAide);                     //on ajouter le menu aide au barre de menu

            menuItemAide.set_submenu(menuAide);                 //on va ajouter des sub menu au menu aide
            menuText.set_label("Jeu du Find a word. \n Le but du jeu est de trouver un mot contenant \nles lettres proposer alléatoirement par le jeu.");
            menuText.set_name("menuText");
                                                                //on donne le text contenant l'aide
                menuAide.append(menuText);                      //on ajouter la section contenant l'aide au submenu de facon a ce que quand on se focalise sur le menu aide, le long text appareit
                  //on ajoute la boite contenant les deux bouttons dans boitePrincipale
                                                  //les bouttons principale au demarage
            boiteBouttonH.set_name("boiteBouttonH");
            boiteBouttonH.pack_start(nouveau,Gtk::PACK_SHRINK);     //on ajoute dans la boite de boutton le boutton nouveau
                nouveau.set_label("Nouveau");                       //on donne le text pour le boutton nouveau*
                nouveau.set_name("nouveau");
            boiteBouttonH.pack_start(load,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton load
                load.set_label("Load");                             //on donne le text pour le boutton loads
                load.set_name("load");

            boiteBouttonH.pack_start(textChoixNiveau,Gtk::PACK_SHRINK);
                textChoixNiveau.set_label("choisissez votre niveau pour le jeu");
                textChoixNiveau.set_name("textChoixNiveau");
                
            boiteBouttonH.pack_start(level1,Gtk::PACK_SHRINK);    //on ajoute dans la boite de boutton le boutton level1
                level1.set_label(" 1 ");                            //on donne le text pour le boutton level1
                level1.set_name("level1");
            boiteBouttonH.pack_start(level2,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton lelev2
                level2.set_label(" 2 ");                            //on donne le text pour le boutton level2
                level2.set_name("level2");
            boiteBouttonH.pack_start(level3,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level3
                level3.set_label(" 3 ");                            //on donne le text pour le boutton level3
                level3.set_name("level3");
            boiteBouttonH.pack_start(level4,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level4
                level4.set_label(" 4 ");                            //on donne le text pour le boutton level4
                level4.set_name("level4");
            boiteBouttonH.pack_start(level5,Gtk::PACK_SHRINK);        //on ajoute dans la boite de boutton le boutton level5s
                level5.set_label(" 5 ");                            //on donne le text pour le boutton level5     
                level5.set_name("level5");
    boitePrincipale.pack_start(boiteCorps,Gtk::PACK_SHRINK);
            boiteCorps.set_name("boiteCorps");
            boiteCorps.pack_start(textReponse,Gtk::PACK_SHRINK);
                textReponse.set_name("textReponse");
            boiteCorps.pack_start(lettreAlleatoire,Gtk::PACK_SHRINK);
                lettreAlleatoire.set_name("lettreAlleatoire");
            boiteCorps.pack_start(valider,Gtk::PACK_SHRINK);    
                valider.set_label("Valider");
                valider.set_name("valider");          
                                                                    //on affiche le necessaire au demarage
    boitePrincipale.show();                                         //on affiche le boitePrincipale  
        boiteHaut.show();                                           //on affiche le boiteHaut
            barreMenu.show();                                   //on affiche barreMenu 
                menuItemMenu.show();                            //on affiche menuItemMenu    
                    menuMenu.show();                            //on affiche menuMenu
                    menuNouveau.show();                         //on affiche menuNouveau
                    menuEnregistrer.show();                     //on affiche menuEnregistrer
                    menuQuitter.show();                         //on affiche menuQuitter
                menuItemAide.show();                            //on affiche menuItemAide
                    menuAide.show();                            //on affiche menuAide
                    menuText.show();                            //on affiche menuText
        boiteAlignement.show();
            boiteBouttonH.show();                                   //on affiche boiteBouttonH            contenant tout le corps
                nouveau.show();                                     //on affiche le boutton nouveau
                load.show();                                        //on affiche le boutton load
            boiteCorps.show();

    //on change d'ecran cad appele du fonction changerEcran
    nouveau.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::afficheChoixLevel));
    load.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::cacherBouttonNewEtLoad));

    //edition de l'action menuEnregistrer
    menuEnregistrer.signal_activate().connect(sigc::mem_fun(*this, &Fenetre::sauvegarde));
    //edition de l'action menuQuitter
    menuQuitter.signal_activate().connect(sigc::ptr_fun(&Gtk::Main::quit));   
    level1.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Fenetre::play),1));
    load.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Fenetre::play),1));
    
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
void Fenetre::cacherChoixLevel(){
    level1.hide();
    level2.hide();
    level3.hide();
    level4.hide();
    level5.hide();
}
void Fenetre::sauvegarde(){
    Gtk::MessageDialog dialogue(*this,"",true);
    dialogue.set_title("Sauvegarde");
    dialogue.set_secondary_text("Votre progression et vos donné ont été enregistrer avec <b>SUCCESS</b>",true);
    dialogue.run();
}
void Fenetre::play(int level){
    afficheBouttonValider();
    afficheLettreAlleatoire();
    afficheZoneDeTextRepose();
    cacherChoixLevel();
    valider.show();
    textReponse.show();
    lettreAlleatoire.show();
    lettreAlleatoire.set_label("zone de text");
}
void Fenetre::afficheBouttonValider(){
    valider.show();
}
void Fenetre::afficheLettreAlleatoire(){
    lettreAlleatoire.show();
}
void Fenetre::afficheZoneDeTextRepose(){
    textReponse.show();
}