
std::string gen_mot_mystere (bool nb_j_is_2);
bool a_gagne (const std::string& reponse_joueur, const std::string& mot_mystere);
bool reaction (char reponse_joueur, const std::string& mot_mystere, std::string mot_trouve);


int pendu (bool nb_joueurs_is_2 = false);

int pendu (bool nb_joueurs_is_2) {

   bool gagne (false);

   char reponse_joueur;
   std::string mot_mystere (""), mot_trouve ("");


   mot_mystere = gen_mot_mystere (nb_joueurs_is_2);
   for (std::size_t i = 0; i < mot_mystere.size (); i++) {
      mot_trouve.push_back ('_');
   }
   if (nb_joueurs_is_2)
      netoit_ecran ();

   int nb_coups (0);

   while (!gagne) {

      // nouveau tour

      std::cout << "vous en etes au coup numero " << nb_coups << ". " << std::endl; // on parle à l'utilisateur
      std::cout << "Voici le mot mystere : " << mot_trouve << " Proposez une lettre de ce mot :" << std::endl; // on parle à l'utilisateur
      std::cout << ">> "; // on lui laisse le relai

      std::cin >> reponse_joueur; // on récupère les datas

      std::cout << std::endl; // on retourne à la ligne

      if (reaction (reponse_joueur, mot_mystere, mot_trouve)) {
         for (std::size_t i = 0 ; i < mot_mystere.size () ; i++) {
            if (reponse_joueur == mot_mystere [i]) {
               mot_trouve [i] = mot_mystere [i];
            }
         }
      }
      else {
         nb_coups++;
      }

      gagne = a_gagne (mot_trouve, mot_mystere);
   }

   std::cout << "Bravo, vous avez bien devine le mot mystere : " << mot_mystere << " !" << std::endl << std::endl;

   return 0;
}

void affiche_instructions () {

   using namespace std;

      /* instructions */
   cout << endl << endl;
   cout << "------------------------------------" << endl;
   cout << "|  vous etes dans le jeu du pendu  |" << endl;
   cout << "------------------------------------" << endl;
   cout << endl << endl;
   cout << "L'ordinateur va tirer un mot au hasard, et vous devrez le deviner." << endl << endl;
   cout << "Pour ce faire, vous proposerez une lettre, puis l'ordinateur vous indiquera les lettres du mot qui correspondent a la lettre que vous venez de proposer. Il vous reafichera enduite le mot avec les lettres que vous avez deja trouvees de devoilees. Vous avez gagne lorsque vous avez devoile toutes les lettres du mot, car vous aurez alors trouve le mot en entier." << endl << endl;
}

std::string gen_mot_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {
      std::cout << std::endl << "entrez le mot que votre adversaire devra deviner (merci d'entrer uniquement des majuscules) :" << std::endl << ">> ";

      std::string reponce;

      std::cin >> reponce;

      return reponce;
   }

   std::ifstream dico ("dico.txt"); // mode lecture

   std::default_random_engine rd {234}; // création du générateur

   dico.seekg (rd () % 3940127, std::ios::beg);

   char caractere_act = ' ';

   while (caractere_act != '\n')
      dico.get (caractere_act);

   std::string mot_genere;

   dico >> mot_genere;

   dico.close ();

   std::cout << std::endl;
   return mot_genere;
}

bool a_gagne (const std::string& mot_trouve, const std::string& mot_mystere) {
   return mot_trouve == mot_mystere;
}

bool reaction (char reponse_joueur, const std::string& mot_mystere, std::string mot_trouve) {

   for (std::size_t i = 0 ; i < mot_mystere.size () ; i++) {
      if (reponse_joueur == mot_mystere [i]) {
         std::cout << "bravo, il y a bien " << reponse_joueur << " dans le mot !" << std::endl << std::endl << std::endl << std::endl << std::endl;
         return true;
      }
   }

   std::cout << "Eh non, il n'y a pas de \"" << reponse_joueur << "\" dans le mot !" << std::endl << std::endl << std::endl << std::endl << std::endl;
   return false;
}

