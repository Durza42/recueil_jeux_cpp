#ifndef JEU_NOMBRE_H
#define JEU_NOMBRE_H

bool continue_programe (const int reponse_joueur, const int nb_mystere);
bool a_gagne (const int reponse_joueur, const int nombre_mystere);
bool plus_petit (const int reponse_joueur, const int nombre_mystere);
bool plus_grand (const int reponse_joueur, const int nombre_mystere);
bool rejouer ();
int demander_max ();
int gen_nb_mystere (bool nb_j_is_2);

#endif
