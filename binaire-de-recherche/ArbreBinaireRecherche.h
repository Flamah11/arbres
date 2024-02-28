#ifndef ARBREBINAIRERECHERCHE_H
#define ARBREBINAIRERECHERCHE_H

#include "Noeud.h"

template <typename Type>
class ArbreBinaireRecherche {
  public:
    Noeud<Type>* racine;

    ArbreBinaireRecherche();
    bool estVide();
    void inserer(Type valeur);
    void insererNoeude(Noeud<Type> noeud, Type valeur);
};

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
    insererNoeude(this->racine, valeur);
  }
}

template <typename Type>
void ArbreBinaireRecherche<Type>::insererNoeude(Noeud<Type> noeud, Type valeur) {
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

#endif