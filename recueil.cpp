
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <vector>


#include "recueil.h"
#include "pendu.h"
#include "nomber_game.h"
#include "melange_mot.h"
#include "mastermind.h"



int main () {

   print_welkolm ();

   std::string response_player;

   while (1) {

      getline (std::cin, reponce_joueur);

      if (response_player == "#quit" || response_player == "#QUIT") {
         exit (0);
      }
      else if (response_player == "1" || response_player == "jeu du pendu" || response_player == "pendu game") {
         clear_screen ();
         pendu (nb_p_is_2 ());
         print_menu ();
         getline (std::cin, response_player); // pour "vider le buffet"
      }
      else if (response_player == "2" || response_player == "jeu du nombre" || response_player == "number game") {
         clear_screen ();
         nomber_game (nb_p_is_2 ());
         print_menu ();
         getline (std::cin, response_player); // pour "vider le buffet"
      }
      else if (response_player == "3" || response_player == "melange mot") {
         clear_screen ();
         melange_mot (nb_p_is_2 ());
         print_menu ();
         getline (std::cin, response_player); // pour "vider le buffet"
      }
      else if (response_player == "4" || response_player == "mastermind") {
         clear_screen ();
         mastermind (nb_p_is_2 ());
         print_menu ();
         getline (std::cin, response_player); // pour "vider le buffet"
      }
      else { // la reponse ne correspond pas
         std::cout << std::endl << "Sory, I don't know this game... Entrez de nouveau :" << std::endl << ">> ";
      }
   }

   return EXIT_SUCCESS;
}

void print_menu () {

   using namespace std;

   std::cout << std::endl << std::endl;

   std::cout << "     ------------------------------" << std::endl;
   std::cout << "     |  welkolm back to the menu.  |" << std::endl;
   std::cout << "     ------------------------------" << std::endl << std::endl;

   std::cout << "Choose a game parmis ceux-ci :" << std::endl << std::endl;

   std::cout << "1) jeu du pendu" << std::endl;
   std::cout << "2) number game" << std::endl;
   std::cout << "3) melange mot" << std::endl;
   std::cout << "4) mastermind" << std::endl << std::endl;

   std::cout << "for choose a game, you can answer his numero or his name :" << std::endl << ">> ";
}

void print_welkolm () {

      /* instructions */
   std::cout << std::endl << std::endl;
   std::cout << "     ------------------------------------------------------------------" << std::endl;
   std::cout << "     |  Bienvenu dans le recueil de jeux opensources ecrits en C++ !  |" << std::endl;
   std::cout << "     ------------------------------------------------------------------" << std::endl;
   std::cout << std::endl << std::endl;
   std::cout << "Une fois dans ce menu, vous pouvez entrer #quit pour quitter." << std::endl << std::endl;

   std::cout << "choose a game parmis ceux-ci :" << std::endl << std::endl;

   std::cout << "1) jeu du pendu" << std::endl;
   std::cout << "2) number game" << std::endl;
   std::cout << "3) melange mot" << std::endl;
   std::cout << "4) mastermind" << std::endl << std::endl;

   std::cout << "for choose a game, you can answer his numero or his name :" << std::endl << ">> ";

}

void clear_screen () {
   for (std::size_t i = 0; i < 75; i++) {
      std::cout << std::endl;
   }
}

bool nb_p_is_2 () {

   std::cout << "combien de joueurs etes vous ? (1 ou 2)" << std::endl;

   std::string nb_p = "0";

   while (nb_j == "0") {

      std::cout << ">> ";

      std::cin >> nb_p;

      if (nb_p == "1")
         return false;
      else if (nb_p == "2")
         return true;
      else
         nb_p = "0";

      std::cout << std::endl << std::endl << "please answer 1 or 2." << std::endl;
   }
   return false;
}



