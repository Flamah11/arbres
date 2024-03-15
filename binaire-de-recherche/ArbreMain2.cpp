#include "ArbreBinaireRecherche.h"
#include <iostream>

int main() {
  ArbreBinaireRecherche<int>* arbre = new ArbreBinaireRecherche<int>();

  arbre->inserer(30);
  arbre->inserer(20);
  arbre->inserer(25);
  arbre->inserer(10);
  arbre->inserer(50);
  arbre->inserer(40);
  arbre->inserer(60);

  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;

  arbre->supprimer(10);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(20);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(30);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(40);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(50);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(60);
  arbre->infixe();
  cout << "La racine est " << arbre->racine->cle << endl;
  
  arbre->supprimer(25);
  arbre->infixe();
  
  return 0;
}