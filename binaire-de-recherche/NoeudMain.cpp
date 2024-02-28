#include "Noeud.h"
#include <iostream>

int main() {
  Noeud<int>* noeud1 = new Noeud(50);
  Noeud<int>* noeud2 = new Noeud(35);
  Noeud<int>* noeud3 = new Noeud(87);

  noeud1->filsGauche = noeud2;
  noeud2->parent = noeud1;

  noeud1->filsDroite = noeud3;
  noeud3->parent = noeud1;

  if (noeud1->estRacine()) {
    cout << "Je suis la racine : noeud1 " << endl;
  }

  if (noeud1->aFilsGauche()) {
    cout << "Oui, j'en ai un fils a gauche" << endl;
  }

  if (noeud2->estFilsGauche()){
    cout << "Oui" << endl;
  }

  return 0;
}