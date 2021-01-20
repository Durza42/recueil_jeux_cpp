#include "recueil.h"
#include "pendu.h"
#include "nomber_game.h"
#include "melange_mot.h"
#include "mastermind.h"


int melange_mot (bool nb_joueurs_is_2 = false);

int melange_mot (bool nb_joueurs_is_2) {

   std::cout << "entrez \"#quit\" pour quitter ou #perdu pour donner votre langue au chat. Ne mettez pas d'espaces lors de vos reponces, cela vous std::coutera un coup suplementaire ! Vous devez egalement entrer le mot en majuscule, sinon il ne sera pas detecte !" << std::endl;

   std::string mot_mystere, mot_mystere_melange;

   mot_mystere = mm_gen_mot_mystere (nb_joueurs_is_2);
   if (nb_joueurs_is_2)
      netoit_ecran ();
   mot_mystere_melange = melange_mot_mystere (mot_mystere);


   bool gagne = false;
   int nb_coups = 0;
   std::string reponse_joueur;

   while (!gagne) {

      // nouveau tour

      nb_coups++;

      std::cout << "vous en etes au coup numero " << nb_coups << ". " << std::endl; // on parle à l'utilisateur
      std::cout << "Voici un mot dont les lettres ont ete melangees : " << mot_mystere_melange << " Retrouvez le mot d'origine :" << std::endl; // on parle à l'utilisateur
      std::cout << ">> "; // on lui laisse le relai

      getline (std::cin, reponse_joueur); // on récupère les datas

      std::cout << std::endl; // on retourne à la ligne

      if (reponse_joueur == "#QUIT" || reponse_joueur == "#quit") // commande #quit --> on quitte
         return 0;

      if (reponse_joueur == "#PERDU" || reponse_joueur == "#perdu") { // commande #quit --> on quitte
         std::cout << "voici le mot que vous deviez trouver : " << mot_mystere << ". Dommage..." << std::endl << std::endl;
         return 0;
      }

      gagne = mm_a_gagne (reponse_joueur, mot_mystere);

      if (!gagne)
         std::cout << "et non, ce n'etait pas " << reponse_joueur << "." << std::endl << std::endl;
   }

   std::cout << "Bravo, vous avez bien devine le mot mystere : " << reponse_joueur << " !" << std::endl << std::endl;

   return 0;
}

std::string mm_gen_mot_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {
      std::cout << std::endl << "entrez le mot que votre adversaire devra deviner (merci d'entrer uniquement des majuscules) :" << std::endl << ">> ";

      std::string reponce;

      std::cin >> reponce;

      return reponce;
   }

   std::ifstream dico ("dico.txt"); // mode lecture

   std::default_random_engine rd {234}; // création du générateur

   dico.seekg (rd () % 3940127, std::ios::beg); // 3940127 : nombre de caractères du fichier en enlevant le dernier mot

   char caractere_act = ' ';

   while (caractere_act != '\n')
      dico.get (caractere_act);

   std::string mot_genere;

   dico >> mot_genere;

   dico.close ();

   std::cout << std::endl;

   return mot_genere;
}

std::string melange_mot_mystere (std::string mot_mystere) {

   std::string mot_mystere_melange;
   int indice_char_copie = 0;

   while (mot_mystere.size () > 1) {

      indice_char_copie = clock () % mot_mystere.size ();
      mot_mystere_melange += mot_mystere [indice_char_copie];
      mot_mystere.erase (indice_char_copie, 1);

   }

   mot_mystere_melange += mot_mystere;

   return mot_mystere_melange;
}

bool mm_a_gagne (const std::string& reponse_joueur, const std::string& mot_mystere) {
   return (reponse_joueur == mot_mystere);
}
