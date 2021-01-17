
#include <iostream>
#include <fstream> // permet la gestion des flux vers et depuis les fichiers
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath>
#include <random> // nombres aléatoires


using namespace std;


void affiche_menu ();
void netoit_ecran ();
bool nb_j_is_2 ();


#include "pendu.cpp"
#include "jeu_nombre.cpp"
#include "melange_mot.cpp"
#include "mastermind.cpp"



int main () {

      /* instructions */
   cout << endl << endl;
   cout << "     ------------------------------------------------------------------" << endl;
   cout << "     |  Bienvenu dans le recueil de jeux opensources ecrits en C++ !  |" << endl;
   cout << "     ------------------------------------------------------------------" << endl;
   cout << endl << endl;
   cout << "Une fois dans ce menu, vous pouvez entrer #quit pour quitter." << endl << endl;

   cout << "Choisissez un jeu parmis ceux-ci :" << endl << endl;

   cout << "1) jeu du pendu" << endl;
   cout << "2) jeu du nombre" << endl;
   cout << "3) melange mot" << endl;
   cout << "4) mastermind" << endl << endl;

   cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << endl << ">> ";

   string reponce_joueur ("");

   while (1) {

      getline (cin, reponce_joueur);

      if (reponce_joueur == "#quit" || reponce_joueur == "#QUIT") {
         exit (0);
      }
      else if (reponce_joueur == "1" || reponce_joueur == "jeu du pendu") {
         netoit_ecran ();
         pendu (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "2" || reponce_joueur == "jeu du nombre") {
         netoit_ecran ();
         jeu_nombre (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "3" || reponce_joueur == "melange mot") {
         netoit_ecran ();
         melange_mot (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "4" || reponce_joueur == "mastermind") {
         netoit_ecran ();
         mastermind (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else { // la reponse ne correspond pas
         cout << endl << "Desole, je ne connais pas ce jeu... Entrez de nouveau :" << endl << ">> ";
      }
   }

   return EXIT_SUCCESS;
}

void affiche_menu () {

   cout << endl << endl;

   cout << "     ---------------------------------------" << endl;
   cout << "     |  Vous etes de retour dans le menu.  |" << endl;
   cout << "     ---------------------------------------" << endl << endl;

   cout << "Choisissez un jeu parmis ceux-ci :" << endl << endl;

   cout << "1) jeu du pendu" << endl;
   cout << "2) jeu du nombre" << endl;
   cout << "3) melange mot" << endl;
   cout << "4) mastermind" << endl << endl;

   cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << endl << ">> ";
}

void netoit_ecran () {
   for (unsigned int i = 0; i < 75; i += 1) {
      cout << endl;
   }
}

bool nb_j_is_2 () {

   cout << "combien de joueurs etes vous ? (1 ou 2)" << endl;

   string nb_j ("0");

   while (nb_j == "0") {

      cout << ">> ";

      cin >> nb_j;

      if (nb_j == "1")
         return false;
      else if (nb_j == "2")
         return true;
      else
         nb_j = "0";

      cout << endl << endl << "merci d'entrer 1 ou 2." << endl;
   }
   return false; // uniquement pour le compilateur
}
