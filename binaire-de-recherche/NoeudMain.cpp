#include "ArbreBinaireRecherche.h"
#include "Noeud.h"

#include <iostream>

int main() {
  //Test main #1 :
  Noeud<int>* noeud1 = new Noeud<int>(50);
  Noeud<int>* noeud2 = new Noeud<int>(35);
  Noeud<int>* noeud3 = new Noeud<int>(87);

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
    cout << "Oui, je suis un fils gauche" << endl;
  }





    cout << "\n\n\n" << endl;
  //Test main #2 :
  ArbreBinaireRecherche<int>* arbre50 = new ArbreBinaireRecherche<int>();

  arbre50->inserer(8);
  arbre50->inserer(5);
  arbre50->inserer(3);
  arbre50->inserer(7);
  arbre50->inserer(9);

  arbre50->prefixe();

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

  Noeud<int>* noeudRecherche = arbre2->trouver(47);

  cout << "La  valeur : " << noeudRecherche->cle << " est presente.";


  



    cout << "\n\nVoici les tests de suppression des noeuds dans l'arbre : " <<  "\n\t";
  //Test main #3 :
  ArbreBinaireRecherche<int>* arbre = new ArbreBinaireRecherche<int>();

  arbre->inserer(30);
  arbre->inserer(20);
  arbre->inserer(25);
  arbre->inserer(10);
  arbre->inserer(50);
  arbre->inserer(40);
  arbre->inserer(60);

  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";

  arbre->supprimer(10);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle << "\n\t";
  
  arbre->supprimer(20);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";
  
  arbre->supprimer(30);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";
  
  arbre->supprimer(40);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";
  
  arbre->supprimer(50);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";
  
  arbre->supprimer(60);
  arbre->infixe();
  cout << "\t\tLa racine est " << arbre->racine->cle <<  "\n\t";

  arbre->supprimer(25);
  arbre->infixe();

  cout << " neyou" << endl;
  
  noeud1->parcoursEnLargeur(arbre50->racine);

  cout << " neyou" << endl;
  return 0;
}