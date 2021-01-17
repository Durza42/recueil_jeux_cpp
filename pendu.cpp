
using namespace std;

string gen_mot_mystere (bool nb_j_is_2);
bool a_gagne (const string& reponse_joueur, const string& mot_mystere);
bool reaction (char reponse_joueur, const string& mot_mystere, string mot_trouve);


int pendu (bool nb_joueurs_is_2 = false);

int pendu (bool nb_joueurs_is_2) {

   bool gagne (false);

   char reponse_joueur;
   string mot_mystere (""), mot_trouve ("");


      /* instructions */
   cout << endl << endl;
   cout << "------------------------------------" << endl;
   cout << "|  vous etes dans le jeu du pendu  |" << endl;
   cout << "------------------------------------" << endl;
   cout << endl << endl;
   cout << "L'ordinateur va tirer un mot au hasard, et vous devrez le deviner." << endl << endl;
   cout << "Pour ce faire, vous proposerez une lettre, puis l'ordinateur vous indiquera les lettres du mot qui correspondent a la lettre que vous venez de proposer. Il vous reafichera enduite le mot avec les lettres que vous avez deja trouvees de devoilees. Vous avez gagne lorsque vous avez devoile toutes les lettres du mot, car vous aurez alors trouve le mot en entier." << endl << endl;

   mot_mystere = gen_mot_mystere (nb_joueurs_is_2);
   for (unsigned int i = 0; i < mot_mystere.size (); i += 1) {
      mot_trouve.push_back ('_');
   }
   if (nb_joueurs_is_2)
      netoit_ecran ();

   int nb_coups (0);

   while (!gagne) {

      // nouveau tour

      cout << "vous en etes au coup numero " << nb_coups << ". " << endl; // on parle à l'utilisateur
      cout << "Voici le mot mystere : " << mot_trouve << " Proposez une lettre de ce mot :" << endl; // on parle à l'utilisateur
      cout << ">> "; // on lui laisse le relai

      cin >> reponse_joueur; // on récupère les datas

      cout << endl; // on retourne à la ligne

      if (reaction (reponse_joueur, mot_mystere, mot_trouve)) {
         for (unsigned int i = 0 ; i < mot_mystere.size () ; i += 1) {
            if (reponse_joueur == mot_mystere [i]) {
               mot_trouve [i] = mot_mystere [i];
            }
         }
      }
      else {
         nb_coups += 1;
      }

      gagne = a_gagne (mot_trouve, mot_mystere);
   }

   cout << "Bravo, vous avez bien devine le mot mystere : " << mot_mystere << " !" << endl << endl;

   return 0;
}

string gen_mot_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {
      cout << endl << "entrez le mot que votre adversaire devra deviner (merci d'entrer uniquement des majuscules) :" << endl << ">> ";

      string reponce ("");

      cin >> reponce;

      return reponce;
   }

   ifstream dico ("dico.txt"); // mode lecture

   default_random_engine rd {234}; // création du générateur

   dico.seekg (rd () % 3940127, ios::beg);

   char caractere_act (' ');

   while (caractere_act != '\n')
      dico.get (caractere_act);

   string mot_genere;

   dico >> mot_genere;

   dico.close ();

   cout << endl;
   return mot_genere;
}

bool a_gagne (const string& mot_trouve, const string& mot_mystere) {
   return mot_trouve == mot_mystere;
}

bool reaction (char reponse_joueur, const string& mot_mystere, string mot_trouve) {

   for (unsigned int i = 0 ; i < mot_mystere.size () ; i += 1) {
      if (reponse_joueur == mot_mystere [i]) {
         cout << "bravo, il y a bien " << reponse_joueur << " dans le mot !" << endl << endl << endl << endl << endl;
         return true;
      }
   }

   cout << "Eh non, il n'y a pas de \"" << reponse_joueur << "\" dans le mot !" << endl << endl << endl << endl << endl;
   return false;
}
