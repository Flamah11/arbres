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

    int hauteur();
    int hauteurNoeud(Noeud<Type>* noeud);

    int profondeur(Noeud<Type>* noeud);

    void supprimer(Type cle);

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
  if(!this->estVide()) {
    infixeNoeud(this->racine);
    cout << endl;
  } else {
    cout << "L'arbre est vide" << endl;
  }

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
  return trouverNoeud(this->racine, cle);
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::trouverNoeud(Noeud<Type>* noeud, Type cle) {
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

template <typename Type>
void ArbreBinaireRecherche<Type>::supprimer(Type cle) {
  Noeud<Type>* noeudASupprimer = trouver(cle);

  if (noeudASupprimer != nullptr) {
    if (noeudASupprimer->estFeuille()) {
      if (noeudASupprimer->estRacine()) {
        this->racine = nullptr;
      } else {
        if (noeudASupprimer->estFilsGauche()) {
          noeudASupprimer->parent->filsGauche = nullptr;
        } else {
          noeudASupprimer->parent->filsDroite = nullptr;
        }
      }
      delete noeudASupprimer;
    } else if (noeudASupprimer->aDeuxEnfants()) {

      Noeud<Type>* successeur = noeudMinimum(noeudASupprimer->filsDroite);
      Type cleSuccesseur = successeur->cle;
      supprimer(cleSuccesseur);
      noeudASupprimer->cle = cleSuccesseur;

    } else { // le noeud n'a qu'un enfant
      if (noeudASupprimer->estRacine()) {
        if (noeudASupprimer->aFilsGauche()) {
          noeudASupprimer->filsGauche->parent = nullptr;
          this->racine = noeudASupprimer->filsGauche;
        } else {
          noeudASupprimer->filsDroite->parent = nullptr;
          this->racine = noeudASupprimer->filsDroite;
        }
      } else {
        if (noeudASupprimer->estFilsGauche()) {
          if (noeudASupprimer->aFilsGauche()) {
            noeudASupprimer->parent->filsGauche = noeudASupprimer->filsGauche;
            noeudASupprimer->filsGauche->parent = noeudASupprimer->parent;
          } else {
            noeudASupprimer->parent->filsGauche = noeudASupprimer->filsDroite;
            noeudASupprimer->filsDroite->parent = noeudASupprimer->parent;
          }
        } else {
          if (noeudASupprimer->aFilsGauche()) {
            noeudASupprimer->parent->filsDroite = noeudASupprimer->filsGauche;
            noeudASupprimer->filsGauche->parent = noeudASupprimer->parent;
          } else {
            noeudASupprimer->parent->filsDroite = noeudASupprimer->filsDroite;
            noeudASupprimer->filsDroite->parent = noeudASupprimer->parent;
          }
        }
      }
      delete noeudASupprimer;
    }
  }
}

template <typename Type>
int ArbreBinaireRecherche<Type>::hauteur() {
   return hauteurNoeud(this->racine);
}


template <typename Type>
int ArbreBinaireRecherche<Type>::hauteurNoeud(Noeud<Type>* noeud) {
   if (noeud == nullptr) {
       return -1; // L'hauteur d'arbre vide est -1
   } else {
       int hauteurGauche = hauteurNoeud(noeud->filsGauche);
       int hauteurDroite = hauteurNoeud(noeud->filsDroite);
       return 1 + max(hauteurGauche, hauteurDroite);
   }
}

template <typename Type>
int ArbreBinaireRecherche<Type>::profondeur(Noeud<Type>* noeud) {
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
