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
/*template <typename Type>
void Noeud<Type>::parcoursEnLargeur(Noeud<Type>* racine, bool infoBonus) {
    if (racine == nullptr) return;
    queue<Noeud<Type>*> file;
    file.push(racine);
    string representationSimple = "", representationBonus = "";
    int niveauActuel = 0, profondeurNoeud = 0;
    while (!file.empty()) {
        Noeud<Type>* noeudActuel = file.front();
        file.pop();
        //Calculons la profondeur du noeud actuel :
        profondeurNoeud = this->profondeur(noeudActuel);
        // Si la distance entre le noeud actuel et la racine est plus grande que la distance entre le niveau actuel et la racine,
        //alors cela signifie que le noeud actuel est sur le prochain niveau :
        if (profondeurNoeud == 0) {
            representationSimple += "\nAffichage de l'arbre binaire avec un parcours en largeur (representation simple) : \n";
            representationBonus += "\nAffichage de l'arbre binaire avec un parcours en largeur (representation avec des informations supplémentaires) : ";
            representationBonus +=  "\n\tNiveau " + to_string(profondeurNoeud) + " :\n"; 
        }
        else if (profondeurNoeud > niveauActuel) {
            representationBonus +=  "\n\n\tNiveau " + to_string(profondeurNoeud) + " :\n"; 
            representationSimple += "\n";
            //On actualise le niveauActuel avec celui du noeud actuel : 
            niveauActuel = profondeurNoeud;
        }
        else
            representationBonus += "\n";
        //Affichage :
        representationBonus += "\t\t[Clé : " + to_string(noeudActuel->clef_)  + ", Hauteur : " + to_string(noeudActuel->hauteur()) + ", Profondeur : " + to_string(profondeurNoeud) + "]";
        representationSimple += "\t" + to_string(noeudActuel->clef_);
        //On place le gauche et le fils droit dans la file pour les afficher ultérieurement :
        if (noeudActuel->filsGauche_ != nullptr) 
            file.push(noeudActuel->filsGauche_);
        if (noeudActuel->filsDroite_ != nullptr) 
            file.push(noeudActuel->filsDroite_);
    }

    representationSimple += "\n"; representationBonus += "\n";
    if (infoBonus)
        cout << representationBonus;
    else 
        cout << representationSimple;
}*/

template <typename Type>
void Noeud<Type>::parcoursEnLargeur(Noeud<Type>* noeud) {
   if (noeud == nullptr) return;
    std::queue<Noeud<Type>*> file;
    file.push(noeud);
    string vuebasique = "", vuebonus = ""; 
    int niveauActuel = 0, profondeurNoeud = 0;
    while (!file.empty()) {
        Noeud<Type>* noeudCourant = file.front();
        file.pop();
        profondeurNoeud = this->profondeur(niveauActuel);
    // Vérifier si nous sommes passés au niveau supérieur de l'arbre
    if (profondeurNoeud == 0) {
        vuebasique += "Vue simplifiée de l'arbre en parcours largeur : ";
        vuebonus += "Vue détaillée de l'arbre en parcours largeur avec infos supplémentaires : ";
        vuebonus += " Niveau " + to_string(profondeurNoeud) + " : "; 
    } else if (profondeurNoeud > niveauActuel) {
        vuebonus += "  Niveau " + to_string(profondeurNoeud) + " : "; 
        // Mise à jour du niveau actuel au niveau du noeud
        niveauActuel = profondeurNoeud;
    }
    // Construction de l'affichage des informations du noeud
    vueBasique += "  [Clé : " + to_string(noeudActuel->clef_) + ", Hauteur : " + to_string(noeudActuel->hauteur()) + ", Profondeur : " + to_string(profondeurNoeud) + "]";
   vuebasique += "  " + to_string(noeudActuel->clef_);
    // Ajout des noeuds enfants à la file d'attente pour le traitement ultérieur
    if (noeudActuel->filsGauche_ != nullptr) 
        file.push(noeudActuel->filsGauche_);
    if (noeudActuel->filsDroite_ != nullptr) 
        file.push(noeudActuel->filsDroite_);
}

// Choix de l'affichage en fonction de l'option supplémentaire
if (infoBonus)
    cout << representationBonus;
else 
    cout << vuebasique;

        std::cout << noeudCourant->cle << " ";
        if (noeudCourant->filsGauche != nullptr) file.push(noeudCourant->filsGauche);
        if (noeudCourant->filsDroite != nullptr) file.push(noeudCourant->filsDroite);
    }

// Exemples d'implémentations fictives pour hauteur et profondeur
  
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
//La hauteur de la racine équivaut toujours à  la hauteur maximal de l'arbre entier.
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
