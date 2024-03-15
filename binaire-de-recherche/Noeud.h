#include <iostream>
using namespace std;

/*
* Classe pour utiliser dans un arbre binaire
*/
template <typename Type>
class Noeud {
  public:
    Type cle;
    Noeud* parent;
    Noeud* filsGauche;
    Noeud* filsDroite;

    Noeud(Type cle);
    Noeud(Type cle, Noeud* parent);
    bool estRacine();
    bool estFeuille();
    bool aFilsGauche();
    bool aFilsDroite();
    bool estFilsGauche();
    bool estFilsDroite();
    bool aDeuxEnfants();
};

template <typename Type>
Noeud<Type>::Noeud(Type cle) {
  this->cle = cle;
  this->parent = nullptr;
  this->filsGauche = nullptr;
  this->filsDroite = nullptr;
}

template <typename Type>
Noeud<Type>::Noeud(Type cle, Noeud* parent) {
  this->cle = cle;
  this->parent = parent;
  this->filsGauche = nullptr;
  this->filsDroite = nullptr;
}


template <typename Type>
bool Noeud<Type>::estRacine() {
  return this->parent == nullptr;
}

template <typename Type>
bool Noeud<Type>::estFeuille() {
  return (this->filsDroite == nullptr 
          && this->filsGauche == nullptr);
}

template <typename Type>
bool Noeud<Type>::aFilsGauche() {
  return this->filsGauche != nullptr;
}

template <typename Type>
bool Noeud<Type>::aFilsDroite() {
  return this->filsDroite != nullptr;
}

template <typename Type>
bool Noeud<Type>::estFilsGauche() {
  if (this->estRacine()) {
    return false;
  } else {
    return this->parent->filsGauche == this;
  }
}

template <typename Type>
bool Noeud<Type>::estFilsDroite() {
  if (this->estRacine()) {
    return false;
  } else {
    return this->parent->filsDroite == this;
  }
}

template <typename Type>
bool Noeud<Type>::aDeuxEnfants() {
  return (this->filsDroite != nullptr && this->filsGauche != nullptr);
}
