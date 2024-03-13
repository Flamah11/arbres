#include "ArbreBinaireRecherche.h"
#include <iostream>

int main() {
  ArbreBinaireRecherche<int>* arbre = new ArbreBinaireRecherche<int>();

  arbre->inserer(8);
  arbre->inserer(5);
  arbre->inserer(3);
  arbre->inserer(7);
  arbre->inserer(9);

  arbre->prefixe();

  ArbreBinaireRecherche<int>* arbre2 = new ArbreBinaireRecherche<int>();
  arbre2->inserer(31);
  arbre2->inserer(10);
  arbre2->inserer(60);
  arbre2->inserer(47);
  arbre2->inserer(3);
  arbre2->inserer(15);
  arbre2->inserer(17);

  arbre2->postfixe();

  Noeud<int>* minimum = arbre2->minimum();

  cout << "Le minimum d'arbre2 est : " << minimum->cle << endl;

  Noeud<int>* maximum = arbre2->maximum();

  cout << "Le maximum d'arbre2 est : " << maximum->cle << endl;

  return 0;
}