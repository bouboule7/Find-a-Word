#include <gtkmm/main.h>

#include "Fenetre.hpp"      //pour l'appel de l'objet fenetre

int main(int argc, char* argv[]) {
    Gtk::Main app(argc, argv);
    Fenetre fenetre;        //declaration d'une nouvelle objet fenetre appelé "fenetre"
    Gtk::Main::run(fenetre);    //execution du fentre et ouverture du boucle principale
    return 0;
}