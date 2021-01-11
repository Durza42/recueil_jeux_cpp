using namespace std;


bool continue_programe (int& reponse_joueur, int& nb_mystere);
bool a_gagne (const int reponse_joueur, const int nombre_mystere);
bool plus_petit (const int reponse_joueur, const int nombre_mystere);
bool plus_grand (const int reponse_joueur, const int nombre_mystere);
bool rejouer ();
int demander_max ();
int gen_nb_mystere (bool nb_j_is_2);



int jeu_nombre (bool nb_joueurs_is_2 = false);

int jeu_nombre (bool nb_joueurs_is_2) {

   srand (time (0));

   int nb_mystere (0);
   int reponse_joueur (0);

   int compteur_de_coups (0);

      /* instructions */
   cout << endl << endl;
   cout << "--------------------------------------" << endl;
   cout << "|  vous etes dans le jeu du nombre.  |" << endl;
   cout << "--------------------------------------" << endl;
   cout << endl << endl;
   cout << "L'ordinateur va tirer un nombre entre 1 et le nombre que vous alez entrer ci-dessous, et vous devrez le deviner." << endl;
   cout << "Pour cela, vous proposerez un nombre, puis l'ordinateur vous répondra, selon le cas :" << endl;
   cout << " - bravo, vous avez gagne !" << endl;
   cout << " - plus grand" << endl;
   cout << " - plus petit" << endl << endl << endl << endl;


   bool jouer (true), gagne (false);

   while (jouer) {

         // tirage du nombre mystere
      nb_mystere = gen_nb_mystere (nb_joueurs_is_2);
      if (nb_joueurs_is_2)
         netoit_ecran ();

      while (!gagne) {
         compteur_de_coups += 1;

         cout << "coup " << compteur_de_coups << ". proposez un nombre :" << endl << ">> ";

         cin >> reponse_joueur;

         gagne = !continue_programe (reponse_joueur, nb_mystere); // si on doit s'arêter là (le joueur a trouvé le nombre)
      }
      jouer = rejouer ();
      gagne = false;
      cout << endl;
      compteur_de_coups = 0;
   }

   return EXIT_SUCCESS;
}


bool continue_programe (int& reponse_joueur, int& nb_mystere) {
   if (a_gagne (reponse_joueur, nb_mystere)) {
      cout << endl << "bravo, vous avez gagne !" << endl << endl << endl;
      return false;
   }
   else if (plus_petit (reponse_joueur, nb_mystere)) {
      cout << "   plus petit." << endl << endl;
      return true;
   }
   else if (plus_grand (reponse_joueur, nb_mystere)) {
      cout << "   plus grand." << endl << endl;
      return true;
   }
   else {
      cout << "fatal error : votre nombre n'est ni trop petit, ni trop grand, ni egal. Je rapelle de ne pas rentrer de lettre." << endl;
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
   cout << "voulez-vous rejouer ? Tapez o pour oui ou n pour non :" << endl;
   cout << ">> ";

   string reponse ("n");
   cin >> reponse;
   
   if (reponse == "o")
      return true;
   else
      return false;
}


int demander_max () {
   cout << "entrez le nombre maximal que pourra vous donner l'ordinateur :" << endl << ">> ";

   int reponse (0);
   cin >> reponse;

   return reponse;
}


int gen_nb_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {

      int nb (0);

      cout << "choisisez le nombre que votre adversaire devra deviner :" << endl;

      while (nb == 0) {

         cout << ">> ";

         cin >> nb;

         if (nb % 1 != 0 || nb == 0)
            nb = 0;
         else
            return nb;

         cout << "merci d'entrer un nombre entier superieur a 0 :" << endl;
      }
   }
      // retour par defaut
   return rand () % demander_max ();
}





