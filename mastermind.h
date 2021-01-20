#ifndef MASTERMIND_H
#define MASTERMIND_H

std::string gen_code_mystere (bool nb_j_is_2);
std::string reaction (const std::string& reponce_joueur, const std::string& code_mystere);
bool code_pas_ok (const char code);

#endif
