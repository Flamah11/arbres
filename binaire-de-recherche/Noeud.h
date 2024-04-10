#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath> 
#include <optional>
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

    void insererNoeud(Noeud<Type>* noeud, Type valeur);


    void prefixeNoeud(Noeud<Type>* noeud);


    void infixeNoeud(Noeud<Type>* noeud);

    void parcoursEnLargeur(Noeud<Type>* noeud);

    void postfixeNoeud(Noeud<Type>* noeud);

    Noeud<Type>* noeudMinimum(Noeud<Type>* noeud);

    Noeud<Type>* noeudMaximum(Noeud<Type>* noeud);

    Noeud<Type>* trouverNoeud(Noeud<Type>* noeud, Type cle);

    int hauteurNoeud(Noeud<Type>* noeud);

    int profondeur(Noeud<Type>* noeud);
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
void Noeud<Type>::insererNoeud(Noeud<Type>* noeud, Type valeur) {
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
void Noeud<Type>::postfixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    postfixeNoeud(noeud->filsGauche);
    postfixeNoeud(noeud->filsDroite);
    cout << noeud->cle << " ";
  }
}

template <typename Type>
void Noeud<Type>::prefixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    cout << noeud->cle << " ";
    prefixeNoeud(noeud->filsGauche);
    prefixeNoeud(noeud->filsDroite);
  }
}



template <typename Type>
void Noeud<Type>::infixeNoeud(Noeud<Type>* noeud) {
  if(noeud != nullptr) {
    infixeNoeud(noeud->filsGauche);
    cout << noeud->cle << " ";
    infixeNoeud(noeud->filsDroite);
  }
}


template <typename Type>
void Noeud<Type>::parcoursEnLargeur(Noeud<Type>* noeud) {
   if (noeud == nullptr) return;
    std::queue<Noeud<Type>*> file;
    file.push(noeud);
    while (!file.empty()) {
        Noeud<Type>* noeudCourant = file.front();
        file.pop();
        std::cout << noeudCourant->valeur << " ";
        if (noeudCourant->gauche != nullptr) file.push(noeudCourant->gauche);
        if (noeudCourant->droit != nullptr) file.push(noeeudCourant->droit);
    }
}

// Exemples d'implémentations fictives pour hauteur et profondeur
template <typename Type>
int Noeud<Type>::hauteur(Noeud<Type>* noeud) {
    return 0; // À implémenter
}

template <typename Type>
int Noeud<Type>::calculerProfondeur(Noeud<Type>* noeud) {
    return 0; // À implémenter
}
      
  }
}

template <typename Type>
Noeud<Type>* Noeud<Type>::noeudMinimum(Noeud<Type>* noeud) {
  while (noeud != nullptr && noeud->aFilsGauche()) {
    noeud = noeud->filsGauche;
  }

  return noeud;
}

template <typename Type>
Noeud<Type>* Noeud<Type>::noeudMaximum(Noeud<Type>* noeud) {
  while (noeud != nullptr && noeud->aFilsDroite()) {
    noeud = noeud->filsDroite;
  }

  return noeud;
}


template <typename Type>
Noeud<Type>* Noeud<Type>::trouverNoeud(Noeud<Type>* noeud, Type cle) {
  if (noeud == nullptr)
    return nullptr;
  
  if (cle > noeud->cle) {
    return trouverNoeud(noeud->filsDroite, cle);
  }

  if (cle < noeud->cle) {
    return trouverNoeud(noeud->filsGauche, cle);
  } 
  return noeud;

}

//déclaration de la methode "hauteurNoeud" de la classe "Noeud" :
//int hauteurNoeud(Noeud<Type>* noeud);

//Définition de la methode "hauteurNoeud" de la classe "Noeud" :
//Méthode qui donne la distance maximal entre le noeud actuel et une feuille.
//Les feuilles ont une hauteur de "zéro" pour le calcul.
//La hauteur de la racine équivaut toujours à la hauteur maximal de l'arbre entier.
template<class Type>
int Noeud<Type>::hauteurNoeud(Noeud<Type>* noeud) {
   if (noeud == nullptr) {
       return -1; // L'hauteur d'arbre vide est -1
   } else {
       int hauteurGauche = hauteurNoeud(noeud->filsGauche);
       int hauteurDroite = hauteurNoeud(noeud->filsDroite);
       return 1 + max(hauteurGauche, hauteurDroite);
   }
}

//Méthode qui donne la distance entre la racine et le noeud actuel.
//Le noeud en argument a une profondeur de zéro pour le calcul.
//Si le noeud en argument est la racine, alors la racine vaut zéro.
template <typename Type>
int Noeud<Type>::profondeur(Noeud<Type>* noeud) {
   int profondeur = 0;
   Noeud<Type>* noeudActuel = this->racine;
   while (noeudActuel != nullptr && noeudActuel->cle != noeud->cle) {
       profondeur++;
       if (noeud->cle < noeudActuel->cle) {
           noeudActuel = noeudActuel->filsGauche;
       } else {
           noeudActuel = noeudActuel->filsDroite;
       }
   }
   return noeudActuel == nullptr ? -1 : profondeur;
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
