
std::string gen_code_mystere (bool nb_j_is_2);
std::string reaction (const std::string& reponce_joueur, const std::string& code_mystere);
bool code_pas_ok (const char code);


int mastermind (bool nb_joueurs_is_2 = false);

int mastermind (bool nb_joueurs_is_2) {

   std::string reponse_joueur;
   std::string code_mystere;
   std::string out;


      /* instructions */
   std::cout << std::endl << std::endl;
   std::cout << "----------------------------------" << std::endl;
   std::cout << "|  vous etes dans le mastermind  |" << std::endl;
   std::cout << "----------------------------------" << std::endl;
   std::cout << std::endl << std::endl;
   std::cout << "L'ordinateur va tirer un code de quatre chiffres au hasard entre 1 et 8 compris, et vous devrez le deviner." << std::endl << std::endl;
   std::cout << "Pour cela, vous proposerez un code et pour chaque chiffre, l'ordinateur vous anoncera :" << std::endl << std::endl;

   std::cout << " - une croix (x) qui signifiera que ce chiffre n'est pas dans le code mystere." << std::endl;
   std::cout << " - un tilde (~) qui signifiera que ce chiffre est present dans le code mystere, mais pas a cet emplacement." << std::endl;
   std::cout << " - un diese (#) qui signifiera que ce chiffre est present dans le code mystere, et a cet emplacement. Il pourra cependant etre egalement a un autre emplacement du code mystere." << std::endl << std::endl;

   code_mystere = gen_code_mystere (nb_joueurs_is_2);
   if (nb_joueurs_is_2)
      netoit_ecran ();

   int nb_coups (0);
   bool gagne (false);

   while (1) {

      // nouveau tour

      nb_coups++;

      std::cout << "vous en etes au coup numero " << nb_coups << ". " << std::endl; // on parle à l'utilisateur
      std::cout << "Proposez un code :" << std::endl; // on parle à l'utilisateur
      std::cout << ">> "; // on lui laisse le relai

      std::cin >> reponse_joueur; // on récupère les datas

      std::cout << std::endl; // on retourne à la ligne

      out = reaction (reponse_joueur, code_mystere); // on affiche la reponse du programe. Par exemple : x~##

      if (out == "   ####")
         return EXIT_SUCCESS;

      std::cout << out << std::endl << std::endl;
   }
}

std::string gen_code_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {

      std::cout << "choisisez le code que votre adversaire devra deviner :" << std::endl;

      std::string code ("0");

      while (code == "0") {

         std::cout << ">> ";

         std::cin >> code;

         if (code.size () != 4 ||  code_pas_ok (code [0]) ||  code_pas_ok (code [1]) ||  code_pas_ok (code [2]) ||  code_pas_ok (code [3])) {
            code = "0";
         }
         else {
            return code;
         }

         std::cout << "merci d'entrer un code de 4 chiffres compose de nombres entiers entre 1 et 8 :" << std::endl;
      }
   }

   std::string returned ("    ");
   int alea (0);

   std::default_random_engine rd {234}; // création du générateur

   for (std::size_t i = 0; i < 4; i++) {
      alea = rd () % 8 + 1;

      switch (alea) {
         case 1:
            returned [i] = '1';
        break;
         case 2:
            returned [i] = '2';
        break;
         case 3:
            returned [i] = '3';
        break;
         case 4:
            returned [i] = '4';
        break;
         case 5:
            returned [i] = '5';
        break;
         case 6:
            returned [i] = '6';
        break;
         case 7:
            returned [i] = '7';
        break;
         case 8:
            returned [i] = '8';
        break;
      }
   }

   return returned;
}

std::string reaction (const std::string& reponce_joueur, const std::string& code_mystere) {

   std::string returned ("   ");
   std::size_t j (0);
   bool is_tilde (false);

   for (std::size_t i = 0; i < 4; i++) {

      is_tilde = false;

      if (reponce_joueur [i] == code_mystere [i]) { // bon chiffre, bon endroit
         returned += "#";
      }
      else {
         for (j = 0; j < 4 && !is_tilde; j++) {
            if (reponce_joueur [i] == code_mystere [j]) { // bon chiffre, mauvais endroit
               returned += "~";
               is_tilde = true;
            }
         }
         if (!is_tilde) { // mauvais chiffre, mauvais endroit
            returned += "x";
         }
      }
   }

   if (returned == "   ####") // gagne, fin
      std::cout << "Bravo, vous avez trouve le code mystere : " << code_mystere << " !" << std::endl << std::endl;

   return returned;
}

bool code_pas_ok (const char code) {

   return (    code != '1'
               && code != '2'
               && code != '3'
               && code != '4'
               && code != '4'
               && code != '5'
               && code != '6'
               && code != '7'
               && code != '8'
          );
}
