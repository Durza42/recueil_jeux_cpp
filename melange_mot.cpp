
using namespace std;

string mm_gen_mot_mystere (bool nb_j_is_2);
string melange_mot_mystere (string mot_mystere);
bool mm_a_gagne (const string& reponse_joueur, const string& mot_mystere);


int melange_mot (bool nb_joueurs_is_2 = false);

int melange_mot (bool nb_joueurs_is_2) {

   cout << "entrez \"#quit\" pour quitter ou #perdu pour donner votre langue au chat. Ne mettez pas d'espaces lors de vos reponces, cela vous coutera un coup suplementaire ! Vous devez egalement entrer le mot en majuscule, sinon il ne sera pas detecte !" << endl;

   string mot_mystere (""), mot_mystere_melange ("");

   mot_mystere = mm_gen_mot_mystere (nb_joueurs_is_2);
   if (nb_joueurs_is_2)
      netoit_ecran ();
   mot_mystere_melange = melange_mot_mystere (mot_mystere);


   bool gagne (false);
   int nb_coups (0);
   string reponse_joueur ("");

   while (!gagne) {

      // nouveau tour

      nb_coups += 1;

      cout << "vous en etes au coup numero " << nb_coups << ". " << endl; // on parle à l'utilisateur
      cout << "Voici un mot dont les lettres ont ete melangees : " << mot_mystere_melange << " Retrouvez le mot d'origine :" << endl; // on parle à l'utilisateur
      cout << ">> "; // on lui laisse le relai

      getline (cin, reponse_joueur); // on récupère les datas

      cout << endl; // on retourne à la ligne

      if (reponse_joueur == "#QUIT" || reponse_joueur == "#quit") // commande #quit --> on quitte
         return 0;

      if (reponse_joueur == "#PERDU" || reponse_joueur == "#perdu") { // commande #quit --> on quitte
         cout << "voici le mot que vous deviez trouver : " << mot_mystere << ". Dommage..." << endl << endl;
         return 0;
      }

      gagne = mm_a_gagne (reponse_joueur, mot_mystere);

      if (!gagne)
         cout << "et non, ce n'etait pas " << reponse_joueur << "." << endl << endl;
   }

   cout << "Bravo, vous avez bien devine le mot mystere : " << reponse_joueur << " !" << endl << endl;

   return 0;
}

string mm_gen_mot_mystere (bool nb_j_is_2) {

   if (nb_j_is_2) {
      cout << endl << "entrez le mot que votre adversaire devra deviner (merci d'entrer uniquement des majuscules) :" << endl << ">> ";

      string reponce ("");

      cin >> reponce;

      return reponce;
   }

   ifstream dico ("dico.txt"); // mode lecture

   dico.seekg (rd () % 3940127, ios::beg); // 3940127 : nombre de caractères du fichier en enlevant le dernier mot

   char caractere_act (' ');

   while (caractere_act != '\n')
      dico.get (caractere_act);

   string mot_genere;

   dico >> mot_genere;

   dico.close ();

   cout << endl;

   return mot_genere;
}

string melange_mot_mystere (string mot_mystere) {

   string mot_mystere_melange;
   int indice_char_copie (0);

   while (mot_mystere.size () > 1) {

      indice_char_copie = clock () % mot_mystere.size ();
      mot_mystere_melange += mot_mystere [indice_char_copie];
      mot_mystere.erase (indice_char_copie, 1);

   }

   mot_mystere_melange += mot_mystere;

   return mot_mystere_melange;
}

bool mm_a_gagne (const string& reponse_joueur, const string& mot_mystere) {
   return (reponse_joueur == mot_mystere);
}
