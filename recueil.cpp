
#include <iostream>
#include <fstream> // permet la gestion des flux vers et depuis les fichiers
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath>



using namespace std;




void affiche_menu ();
void netoit_ecran ();
void show_sources  ();
bool nb_j_is_2 ();



string gen_mot_mystere (bool nb_j_is_2);
bool a_gagne (string& reponse_joueur, string& mot_mystere);
bool reaction (char reponse_joueur, string& mot_mystere, string mot_trouve);


int pendu (bool nb_joueurs_is_2 = false);

string mm_gen_mot_mystere (bool nb_j_is_2);
string melange_mot_mystere (string mot_mystere);
bool mm_a_gagne (string& reponse_joueur, string& mot_mystere);


int melange_mot (bool nb_joueurs_is_2 = false);

string gen_code_mystere (bool nb_j_is_2);
string reaction (string reponce_joueur, string code_mystere);
bool code_pas_ok (const char code);


int mastermind (bool nb_joueurs_is_2 = false);



bool continue_programe (int& reponse_joueur, int& nb_mystere);
bool a_gagne (const int reponse_joueur, const int nombre_mystere);
bool plus_petit (const int reponse_joueur, const int nombre_mystere);
bool plus_grand (const int reponse_joueur, const int nombre_mystere);
bool rejouer ();
int demander_max ();
int gen_nb_mystere (bool nb_j_is_2);



int jeu_nombre (bool nb_joueurs_is_2 = false);

int main () {

      /* instructions */
   cout << endl << endl;
   cout << "     ------------------------------------------------------------------" << endl;
   cout << "     |  Bienvenu dans le recueil de jeux opensources ecrits en C++ !  |" << endl;
   cout << "     ------------------------------------------------------------------" << endl;
   cout << endl << endl;
   cout << "Une fois dans ce menu, vous pouvez entrer #quit pour quitter ou #sources pour voir les codes sources." << endl << endl;

   cout << "Choisissez un jeu parmis ceux-ci :" << endl << endl;

   cout << "1) jeu du pendu" << endl;
   cout << "2) jeu du nombre" << endl;
   cout << "3) melange mot" << endl;
   cout << "4) mastermind" << endl << endl;

   cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << endl << ">> ";

   string reponce_joueur ("");

   while (1) {

      getline (cin, reponce_joueur);

      if (reponce_joueur == "#quit" || reponce_joueur == "#QUIT") {
         exit (0);
      }
      else if (reponce_joueur == "#sources" || reponce_joueur == "#SOURCES") {
         show_sources ();
      }
      else if (reponce_joueur == "1" || reponce_joueur == "jeu du pendu") {
         netoit_ecran ();
         pendu (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "2" || reponce_joueur == "jeu du nombre") {
         netoit_ecran ();
         jeu_nombre (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "3" || reponce_joueur == "melange mot") {
         netoit_ecran ();
         melange_mot (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else if (reponce_joueur == "4" || reponce_joueur == "mastermind") {
         netoit_ecran ();
         mastermind (nb_j_is_2 ());
         affiche_menu ();
         getline (cin, reponce_joueur); // pour "vider le buffet"
      }
      else { // la reponse ne correspond pas
         cout << endl << "Desole, je ne connais pas ce jeu... Entrez de nouveau :" << endl << ">> ";
      }
   }

   return EXIT_SUCCESS;
}





void show_sources  () {
   Compiler error (generated); // Ici afficher les codes sources.
}



void affiche_menu () {

   cout << endl << endl;

   cout << "     ---------------------------------------" << endl;
   cout << "     |  Vous etes de retour dans le menu.  |" << endl;
   cout << "     ---------------------------------------" << endl << endl;

   cout << "Choisissez un jeu parmis ceux-ci :" << endl << endl;

   cout << "1) jeu du pendu" << endl;
   cout << "2) jeu du nombre" << endl;
   cout << "3) melange mot" << endl;
   cout << "4) mastermind" << endl << endl;

   cout << "Pour choisir un jeu, vous pouvez soit entrer son numero soit entrer son nom :" << endl << ">> ";
}



void netoit_ecran () {
   for (unsigned int i = 0; i < 75; i += 1) {
      cout << endl;
   }
}

bool nb_j_is_2 () {

   string nb_j ("0");

   cout << "combien de joueurs etes vous ? (1 ou 2)" << endl;

   while (nb_j == "0") {

      cout << ">> ";

      cin >> nb_j;

      if (nb_j == "1")
         return false;
      else if (nb_j == "2")
         return true;
      else
         nb_j = "0";

      cout << endl << endl << "merci d'entrer 1 ou 2." << endl;
   }
   return false; // uniquement pour le compilateur
}


/*  */





int pendu (bool nb_joueurs_is_2) {

   srand (time (0)); // pour la generation de nombres aléatoires

   int nb_joueurs (1), nb_coups (0);

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

   dico.seekg (rand () % 3940127, ios::beg);

   char caractere_act (' ');

   while (caractere_act != '\n')
      dico.get (caractere_act);

   string mot_genere;

   dico >> mot_genere;

   dico.close ();

   cout << endl;
   return mot_genere;
}




bool a_gagne (string& mot_trouve, string& mot_mystere) {
   return mot_trouve == mot_mystere;
}



bool reaction (char reponse_joueur, string& mot_mystere, string mot_trouve) {

   for (unsigned int i = 0 ; i < mot_mystere.size () ; i += 1) {
      if (reponse_joueur == mot_mystere [i]) {
         cout << "bravo, il y a bien " << reponse_joueur << " dans le mot !" << endl << endl << endl << endl << endl;
         return true;
      }
   }

   cout << "Eh non, il n'y a pas de \"" << reponse_joueur << "\" dans le mot !" << endl << endl << endl << endl << endl;
   return false;
}



/*  */




int melange_mot (bool nb_joueurs_is_2) {

   srand (time (0)); // pour la generation de nombres aléatoires

   int nb_joueurs (1), nb_coups (0);

   bool gagne (false);

   string reponse_joueur ("");
   string mot_mystere (""), mot_mystere_melange ("");

   cout << "entrez \"#quit\" pour quitter ou #perdu pour donner votre langue au chat. Ne mettez pas d'espaces lors de vos reponces, cela vous coutera un coup suplementaire ! Vous devez egalement entrer le mot en majuscule, sinon il ne sera pas detecte !" << endl;

   mot_mystere = mm_gen_mot_mystere (nb_joueurs_is_2);
   if (nb_joueurs_is_2)
      netoit_ecran ();
   mot_mystere_melange = melange_mot_mystere (mot_mystere);

   while (!gagne) {

      // nouveau tour

      nb_coups += 1;

      cout << "vous en etes au coup numero " << nb_coups << ". " << endl; // on parle à l'utilisateur
      cout << "Voici un mot dont les lettres ont ete melangees : " << mot_mystere_melange << " Retrouvez le mot d'origine :" << endl; // on parle à l'utilisateur
      cout << ">> "; // on lui laisse le relai

      getline (cin, reponse_joueur); // on récupère les datas

      cout << endl; // on retourne à la ligne

      if (reponse_joueur == "#QUIT" || reponse_joueur == "#quit") { // commande #quit --> on quitte
         return 0;
      }
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

   dico.seekg (rand () % 3940127, ios::beg); // 3940127 : nombre de caractères du fichier en enlevant le dernier mot

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




bool mm_a_gagne (string& reponse_joueur, string& mot_mystere) {
   return (reponse_joueur == mot_mystere);
}


/* */






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


/*  */


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



















