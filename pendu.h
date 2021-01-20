#ifndef PENDU_H
#define PENDU_H

std::string gen_mot_mystere (bool nb_j_is_2);
bool a_gagne (const std::string& reponse_joueur, const std::string& mot_mystere);
bool reaction (char reponse_joueur, const std::string& mot_mystere, std::string mot_trouve);

#endif
