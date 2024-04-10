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
 
    void prefixe();
 

    void infixe();
    
    void postfixe();

    Noeud<Type>* minimum();

    Noeud<Type>* maximum();
    
    Noeud<Type>* trouver(Type cle);

    int hauteur();
    
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
    racine->insererNoeud(this->racine, valeur);
  }
}


template <typename Type>
void ArbreBinaireRecherche<Type>::prefixe() {
    racine->Noeud<Type>::prefixeNoeud(this->racine);
    cout << endl;
}



template <typename Type>
void ArbreBinaireRecherche<Type>::postfixe() {
    this->racine->Noeud<Type>::postfixeNoeud(this->racine);
    cout << endl;
}

template <typename Type>
void ArbreBinaireRecherche<Type>::infixe() {
  if(!this->estVide()) {
    std::cout <<  "Arbre actuel en ordre infixe : ";
    this->racine->Noeud<Type>::infixeNoeud(this->racine);
    cout << endl;} 
    else {
    cout << "L'arbre est vide" << endl;
  }

}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::minimum() {
  return racine->Noeud<Type>::noeudMinimum(this->racine);
}



template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::maximum() {
  return racine->Noeud<Type>::noeudMaximum(this->racine);
}

template <typename Type>
Noeud<Type>* ArbreBinaireRecherche<Type>::trouver(Type cle) {
  return racine->Noeud<Type>::trouverNoeud(this->racine, cle);
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

      Noeud<Type>* successeur = racine->Noeud<Type>::noeudMinimum(noeudASupprimer->filsDroite);
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
   return this->racine->hauteurNoeud(this->racine);
}

/*
Voici un exemple d'utilisation d'une file pour parcourir l'arbre en largeur : 
	Ordre d'insertion : (0, 30, 20, 25, 10, 50, 40, 60, 5, 2, 11, 26, 1);
        
                 00
                   \
                    30
               /         \
              20          50
           /     \       /   \
         10       25    40    60
        /  \     /   \    \     
       5   11        26    51    
      /					            \
     2                       52
    /                         \
   1                           53

   Voici les étapes dans la file :

   Affiche rien
   etape #1 (0) 

  ()
   affiche zéro et le retire, ajoute 30
   etape #2 (30)

  ()
   affiche 30 et le retire, ajoute 20 et 50
   etape #3 (20, 50)

  (50)
   affiche 20 et le retire, ajoute 10 et 25
   etape #4 (50, 10, 25)

  (10, 25)  
   affiche 50 et le retire, ajoute 5 et 11 
   etape #5 (10, 25, 5, 11)

   (25, 5, 11)
   affiche 10 et le retire, ajoute 26 
   etape #6 (25, 5, 11, 26)


   affiche 25 et le retire, ajoute 2
   etape #7 (5, 11, 26, 2)


   affiche 5 et le retire, ajoute rien
   etape 8 (11, 26, 2)
   etc...

  affiche 11, ajoute rien, tu le retire 
  etape 9 (26, 2)

  affiche 26, ajoute rien, tu le retire
  etape 10 (2)

  
*/



