
#include <iostream>
#include <fstream> // permet la gestion des flux vers et depuis les fichiers
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath>
#include <random> // nombres aléatoires



void affiche_menu ();
void affiche_bienvenu ();
void netoit_ecran ();
bool nb_j_is_2 ();


#include "pendu.cpp"
#include "jeu_nombre.cpp"
#include "melange_mot.cpp"
#include "mastermind.cpp"



int main () {

   affiche_bienvenu ();

   std::string reponce_joueur;

   while (1) {

      getline (std::cin, reponce_joueur);

      if (reponce_joueur == "#quit" || reponce_joueur == "#QUIT") {
         exit (0);
      }
      else if (reponce_joueur == "1" || reponce_joueur == "jeu du pendu") {
         netoit_ecran ();
         pendu (nb_j_is_2 ());
         affiche_menu ();
         getline (std::cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "2" || reponce_joueur == "jeu du nombre") {
         netoit_ecran ();
         jeu_nombre (nb_j_is_2 ());
         affiche_menu ();
         getline (std::cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "3" || reponce_joueur == "melange mot") {
         netoit_ecran ();
         melange_mot (nb_j_is_2 ());
         affiche_menu ();
         getline (std::cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "4" || reponce_joueur == "mastermind") {
         netoit_ecran ();
         mastermind (nb_j_is_2 ());
         affiche_menu ();
         getline (std::cin, reponce_joueur); // pour "vider le buffet"
      }
      else { // la reponse ne correspond pas
         std::cout << std::endl << "Desole, je ne connais pas ce jeu... Entrez de nouveau :" << std::endl << ">> ";
      }
   }

   return EXIT_SUCCESS;
}

void affiche_menu () {

   using namespace std;

   std::cout << std::endl << std::endl;

   std::cout << "     ---------------------------------------" << std::endl;
   std::cout << "     |  Vous etes de retour dans le menu.  |" << std::endl;
   std::cout << "     ---------------------------------------" << std::endl << std::endl;

   std::cout << "Choisissez un jeu parmis ceux-ci :" << std::endl << std::endl;

   std::cout << "1) jeu du pendu" << std::endl;
   std::cout << "2) jeu du nombre" << std::endl;
   std::cout << "3) melange mot" << std::endl;
   std::cout << "4) mastermind" << std::endl << std::endl;

   std::cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << std::endl << ">> ";
}

void affiche_bienvenu () {

   using namespace std;

      /* instructions */
   std::cout << std::endl << std::endl;
   std::cout << "     ------------------------------------------------------------------" << std::endl;
   std::cout << "     |  Bienvenu dans le recueil de jeux opensources ecrits en C++ !  |" << std::endl;
   std::cout << "     ------------------------------------------------------------------" << std::endl;
   std::cout << std::endl << std::endl;
   std::cout << "Une fois dans ce menu, vous pouvez entrer #quit pour quitter." << std::endl << std::endl;

   std::cout << "Choisissez un jeu parmis ceux-ci :" << std::endl << std::endl;

   std::cout << "1) jeu du pendu" << std::endl;
   std::cout << "2) jeu du nombre" << std::endl;
   std::cout << "3) melange mot" << std::endl;
   std::cout << "4) mastermind" << std::endl << std::endl;

   std::cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << std::endl << ">> ";

}

void netoit_ecran () {
   for (std::size_t i = 0; i < 75; i++) {
      std::cout << std::endl;
   }
}

bool nb_j_is_2 () {

   std::cout << "combien de joueurs etes vous ? (1 ou 2)" << std::endl;

   std::string nb_j = "0";

   while (nb_j == "0") {

      std::cout << ">> ";

      std::cin >> nb_j;

      if (nb_j == "1")
         return false;
      else if (nb_j == "2")
         return true;
      else
         nb_j = "0";

      std::cout << std::endl << std::endl << "merci d'entrer 1 ou 2." << std::endl;
   }
   return false; // uniquement pour le compilateur
}
