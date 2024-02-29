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
