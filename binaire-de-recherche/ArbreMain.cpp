#include "ArbreBinaireRecherche.h"
#include <iostream>

int main() {
  ArbreBinaireRecherche<int>* arbre = new ArbreBinaireRecherche<int>();

  arbre->inserer(30);
  arbre->inserer(40);
  arbre->inserer(20);

  return 0;
}