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
    std::string vueBasique = "", vueBonus = ""; 
    int niveauActuel = 0, profondeurNoeud = 0;
    while (!file.empty()) {
        Noeud<Type>* noeudCourant = file.front();
        file.pop();
        if (noeudCourant->filsGauche != nullptr) file.push(noeudCourant->filsGauche);
        if (noeudCourant->filsDroite != nullptr) file.push(noeudCourant->filsDroite);

        profondeurNoeud = this->profondeur(noeudCourant);
        if (profondeurNoeud == 0) {
            vueBasique += "Vue simplifiée de l'arbre en parcours largeur : ";
            vueBonus += "Vue détaillée de l'arbre en parcours largeur avec infos supplémentaires : ";
            vueBonus += " Niveau " + std::to_string(profondeurNoeud) + " : "; 
        } else if (profondeurNoeud > niveauActuel) {
            vueBonus += "  Niveau " + std::to_string(profondeurNoeud) + " : "; 
            niveauActuel = profondeurNoeud;
        }
        vueBasique += "  [clé : " + std::to_string(noeudCourant->cle) + ", Hauteur : " + std::to_string(this->hauteurNoeud(noeudCourant)) + ", Profondeur : " + std::to_string(profondeurNoeud) + "]";
        vueBasique += "  " + std::to_string(noeudCourant->cle) + " ";
    }

    // Choix de l'affichage en fonction de l'option supplémentaire
    bool infoBonus = true; // ou déterminé par une condition externe
    if (infoBonus)
        std::cout << vueBonus;
    else 
        std::cout << vueBasique;
}

//Méthode qui donne la distance entre la racine et le noeud actuel.
//Le noeud en argument a une profondeur de zéro pour le calcul.
//Si le noeud en argument est la racine, alors la racine vaut zéro.
// Définition de la méthode profondeur à l'extérieur de la classe mais toujours dans le fichier d'en-tête
template<typename Type>
int Noeud<Type>::profondeur(Noeud<Type>* noeud) {
    int profondeur = 0;
    Noeud<Type>* noeudActuel = this;  // Correct, on suppose que 'this' est le noeud racine

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
