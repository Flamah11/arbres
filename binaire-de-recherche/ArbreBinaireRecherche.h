#ifndef ARBREBINAIRERECHERCHE_H
#define ARBREBINAIRERECHERCHE_H

#include "Noeud.h"
#include <iostream>
using namespace std;

template <typename Type>
class ArbreBinaireRecherche {
  public:
    Noeud<Type>* racine;

    ArbreBinaireRecherche();
    bool estVide();
    void inserer(Type valeur);
    void insererNoeud(Noeud<Type>* noeud, Type valeur);

    void prefixe();
    void prefixeNoeud(Noeud<Type>* noeud);

    void infixe();
    void infixeNoeud(Noeud<Type>* noeud);

    void postfixe();
    void postfixeNoeud(Noeud<Type>* noeud);

    Noeud<Type>* minimum();
    Noeud<Type>* noeudMinimum(Noeud<Type>* noeud);

    Noeud<Type>* maximum();
    Noeud<Type>* noeudMaximum(Noeud<Type>* noeud);

    Noeud<Type>* trouver(Type cle);
    Noeud<Type>* trouverNoeud(Noeud<Type>* noeud, Type cle);

};

#endif

template <typename Type>
ArbreBinaireRecherche<Type>::ArbreBinaireRecherche() {
  this->racine = nullptr;
}

template <typename Type>
bool ArbreBinaireRecherche<Type>::estVide() {
  return this->racine == nullptr;
}

template <typename Type>
void ArbreBinaireRecherche<Type>::inserer(Type valeur) {
  if (this->estVide()) {
    this->racine = new Noeud<Type>(valeur);
  } else {
    insererNoeud(this->racine, valeur);
  }
}

template <typename Type>
void ArbreBinaireRecherche<Type>::insererNoeud(Noeud<Type>* noeud, Type valeur) {
  if (valeur < noeud->cle) {
    if (noeud->aFilsGauche()) {      
      insererNoeud(noeud->filsGauche, valeur);

    } else {
      noeud->filsGauche = new Noeud<Type>(valeur);
      noeud->filsGauche->parent = noeud;
    }
  } else {
    if (noeud->aFilsDroite()) {
      insererNoeud(noeud->filsDroite, valeur);

    } else {
      noeud->filsDroite = new Noeud<Type>(valeur);
      noeud->filsDroite->parent = noeud;
    }
  }
}

template <typename Type>
void ArbreBinaireRecherche<Type>::prefixe() {
    prefixeNoeud(this->racine);
    cout << endl;
}

template <typename Type>
void ArbreBinaireRecherche<Type>::prefixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    cout << noeud->cle << " ";
    prefixeNoeud(noeud->filsGauche);
    prefixeNoeud(noeud->filsDroite);
  }
}

template <typename Type>
void ArbreBinaireRecherche<Type>::postfixe() {
    postfixeNoeud(this->racine);
    cout << endl;
}

template <typename Type>
void ArbreBinaireRecherche<Type>::postfixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    postfixeNoeud(noeud->filsGauche);
    postfixeNoeud(noeud->filsDroite);
    cout << noeud->cle << " ";
  }
}

template <typename Type>
void ArbreBinaireRecherche<Type>::infixe() {
    infixeNoeud(this->racine);
    cout << endl;
}

template <typename Type>
void ArbreBinaireRecherche<Type>::infixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    infixeNoeud(noeud->filsGauche);
    cout << noeud->cle << " ";
    infixeNoeud(noeud->filsDroite);
  }
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::minimum() {
  return noeudMinimum(this->racine);
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::noeudMinimum(Noeud<Type>* noeud) {
  while (noeud != nullptr && noeud->aFilsGauche()) {
    noeud = noeud->filsGauche;
  }

  return noeud;
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::maximum() {
  return noeudMaximum(this->racine);
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::noeudMaximum(Noeud<Type>* noeud) {
  while (noeud != nullptr && noeud->aFilsDroite()) {
    noeud = noeud->filsDroite;
  }

  return noeud;
}
template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::trouver(Type cle) {
  return trouverNoeud(this->racine);
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::trouverNoeud(Noeud<Type>* noeud, Type cle) {
  if (noeud != nullptr) {
    if (cle > noeud->cle) {
      return trouverNoeud(noeud->filsDroite, cle);
    }

    if (cle < noeud->cle) {
      return trouverNoeud(noeud->filsGauche, cle);
    } 
    return noeud;
  }
  return noeud;
}
