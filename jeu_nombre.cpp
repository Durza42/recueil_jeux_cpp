#include "recueil.h"
#include "pendu.h"
#include "nomber_game.h"
#include "melange_mot.h"
#include "mastermind.h"


int jeu_nombre (bool nb_joueurs_is_2 = false);

int jeu_nombre (bool nb_joueurs_is_2) {

      /* instructions */
   std::cout << std::endl << std::endl;
   std::cout << "--------------------------------------" << std::endl;
   std::cout << "|  vous etes dans le jeu du nombre.  |" << std::endl;
   std::cout << "--------------------------------------" << std::endl;
   std::cout << std::endl << std::endl;
   std::cout << "L'ordinateur va tirer un nombre entre 1 et le nombre que vous alez entrer ci-dessous, et vous devrez le deviner." << std::endl;
   std::cout << "Pour cela, vous proposerez un nombre, puis l'ordinateur vous répondra, selon le cas :" << std::endl;
   std::cout << " - bravo, vous avez gagne !" << std::endl;
   std::cout << " - plus grand" << std::endl;
   std::cout << " - plus petit" << std::endl << std::endl << std::endl << std::endl;


   bool jouer (true), gagne (false);
   int nb_mystere (0), reponse_joueur (0);
   int compteur_de_coups (0);

   while (jouer) {

         // tirage du nombre mystere
      nb_mystere = gen_nb_mystere (nb_joueurs_is_2);
      if (nb_joueurs_is_2)
         netoit_ecran ();

      while (!gagne) {
         compteur_de_coups++;

         std::cout << "coup " << compteur_de_coups << ". proposez un nombre :" << std::endl << ">> ";

         std::cin >> reponse_joueur;

         gagne = !continue_programe (reponse_joueur, nb_mystere); // si on doit s'arêter là (le joueur a trouvé le nombre)
      }

      jouer = rejouer ();
      gagne = false;
      std::cout << std::endl;
      compteur_de_coups = 0;
   }

   return EXIT_SUCCESS;
}

bool continue_programe (const int reponse_joueur, const int nb_mystere) {
   if (a_gagne (reponse_joueur, nb_mystere)) {
      std::cout << std::endl << "bravo, vous avez gagne !" << std::endl << std::endl << std::endl;
      return false;
   }
   else if (plus_petit (reponse_joueur, nb_mystere)) {
      std::cout << "   plus petit." << std::endl << std::endl;
      return true;
   }
   else if (plus_grand (reponse_joueur, nb_mystere)) {
      std::cout << "   plus grand." << std::endl << std::endl;
      return true;
   }
   else {
      std::cout << "fatal error : votre nombre n'est ni trop petit, ni trop grand, ni egal. Je rapelle de ne pas rentrer de lettre." << std::endl;
      exit (EXIT_FAILURE);
   }
   return true;
}

bool a_gagne (const int reponse_joueur, const int nombre_mystere) {
   return (reponse_joueur == nombre_mystere);
}

bool plus_grand (const int reponse_joueur, const int nombre_mystere) {
   return (nombre_mystere > reponse_joueur);
}

bool plus_petit (const int reponse_joueur, const int nombre_mystere) {
   return (nombre_mystere < reponse_joueur);
}

bool rejouer () {
   std::cout << "voulez-vous rejouer ? Tapez o pour oui ou n pour non :" << std::endl;
   std::cout << ">> ";

   std::string reponse ("n");
   std::cin >> reponse;
   
   if (reponse == "o")
      return true;
   else
      return false;
}

int demander_max () {
   std::cout << "entrez le nombre maximal que pourra vous donner l'ordinateur :" << std::endl << ">> ";

   int reponse (0);
   std::cin >> reponse;

   return reponse;
}

int gen_nb_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {

      int nb (0);

      std::cout << "choisisez le nombre que votre adversaire devra deviner :" << std::endl;

      while (nb == 0) {

         std::cout << ">> ";

         std::cin >> nb;

         if (nb % 1 != 0 || nb == 0)
            nb = 0;
         else
            return nb;

         std::cout << "merci d'entrer un nombre entier superieur a 0 :" << std::endl;
      }
   }

   std::default_random_engine rd {234}; // création du générateur
      // retour par defaut
   return rd () % demander_max ();
}

