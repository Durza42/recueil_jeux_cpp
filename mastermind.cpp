
using namespace std;


string gen_code_mystere (bool nb_j_is_2);
string reaction (string reponce_joueur, string code_mystere);
bool code_pas_ok (const char code);


int mastermind (bool nb_joueurs_is_2 = false);

int mastermind (bool nb_joueurs_is_2) {

   srand (time (0)); // pour la generation de nombres aléatoires

   int nb_joueurs (1), nb_coups (0);

   bool gagne (false);

   string reponse_joueur;
   string code_mystere;
   string out;


      /* instructions */
   cout << endl << endl;
   cout << "----------------------------------" << endl;
   cout << "|  vous etes dans le mastermind  |" << endl;
   cout << "----------------------------------" << endl;
   cout << endl << endl;
   cout << "L'ordinateur va tirer un code de quatre chiffres au hasard entre 1 et 8 compris, et vous devrez le deviner." << endl << endl;
   cout << "Pour cela, vous proposerez un code et pour chaque chiffre, l'ordinateur vous anoncera :" << endl << endl;

   cout << " - une croix (x) qui signifiera que ce chiffre n'est pas dans le code mystere." << endl;
   cout << " - un tilde (~) qui signifiera que ce chiffre est present dans le code mystere, mais pas a cet emplacement." << endl;
   cout << " - un diese (#) qui signifiera que ce chiffre est present dans le code mystere, et a cet emplacement. Il pourra cependant etre egalement a un autre emplacement du code mystere." << endl << endl;

   code_mystere = gen_code_mystere (nb_joueurs_is_2);
   if (nb_joueurs_is_2)
      netoit_ecran ();

   while (1) {

      // nouveau tour

      nb_coups += 1;

      cout << "vous en etes au coup numero " << nb_coups << ". " << endl; // on parle à l'utilisateur
      cout << "Proposez un code :" << endl; // on parle à l'utilisateur
      cout << ">> "; // on lui laisse le relai

      cin >> reponse_joueur; // on récupère les datas

      cout << endl; // on retourne à la ligne

      out = reaction (reponse_joueur, code_mystere); // on affiche la reponse du programe. Par exemple : _~##

      if (out == "   ####")
         return EXIT_SUCCESS;

      cout << out << endl << endl;
   }
}





string gen_code_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {

      string code ("0");

      cout << "choisisez le code que votre adversaire devra deviner :" << endl;

      while (code == "0") {

         cout << ">> ";

         cin >> code;

         if (     code.size () != 4
              ||  code_pas_ok (code [0])
              ||  code_pas_ok (code [1])
              ||  code_pas_ok (code [2])
              ||  code_pas_ok (code [3])
            ) {
            code = "0";
         }
         else {
            return code;
         }

         cout << "merci d'entrer un code de 4 chiffres compose de nombres entiers entre 1 et 8 :" << endl;
      }
   }

   string returned ("    ");
   int alea (0);

   for (unsigned int i = 0; i < 4; i += 1) {
         /* rand risque de donner des résultats trop proches, tels que 8678 ou 1221 */
      alea = clock () % 8 + 1;

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


string reaction (string reponce_joueur, string code_mystere) {

   string returned ("   ");
   unsigned short int j (0);
   bool is_tilde (false);

   for (unsigned short int i = 0; i < 4; i += 1) {

      is_tilde = false;

      if (reponce_joueur [i] == code_mystere [i]) { // bon chiffre, bon endroit
         returned += "#";
      }
      else {
         for (j = 0; j < 4 && !is_tilde; j += 1) {
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
      cout << "Bravo, vous avez trouve le code mystere : " << code_mystere << " !" << endl << endl;

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









