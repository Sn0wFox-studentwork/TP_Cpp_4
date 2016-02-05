/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <CompositeObject> (fichier CompositeObject.h) ------
#if !defined ( COMPOSITE_OBJECT_H )
#define COMPOSITE_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

#include "Object.h"

//------------------------------------------------------------------ Types
typedef std::vector<Object*> Components;

//------------------------------------------------------------------------ 
// Rôle de la classe <CompositeObject>
// Modelise une forme geometrique constituee d'un ensemble d'Objets.
// Permet la mise en place du composite pattern.
// L'ensemble d'objets servant a la construction d'un CompositeObject
// sera copie et le CompositeObject n'aura plus acces aux composants
// originaux.
//------------------------------------------------------------------------ 

class CompositeObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & point ) = 0;
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant.
	//					Plus de precisions dans les definitions presentes dans les classes heritant de CompositeObject.

	virtual Object* Clone ( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.

	virtual std::string GetLabel ( ) const = 0;
    // Mode d'emploi :	Retourne une string permettant d'identifier la nature de l'objet courant.

	void Move ( int dx, int dy );
	// Mode d'emploi :	Deplace l'objet courant selon le vecteur (dx, dy) : deplace tout ses composants
	//					selon le vecteur (dx, dy).
	//					La seule limite reste celle de l'overflow.

	virtual std::string ToString ( ) const;
	// Mode d'emploi :	Retourne une representation de l'objet courant sous forme de string.
	//					Il s'agit du label de l'objet suivit d'un espace et d'une accolade ouvrante,
	//					puis sur chaque nouvelle ligne la description d'un des composants donnee par
	//					leur methode ToString( ). Enfin une accolade fermante sur une derniere ligne.
	//					Les sauts de ligne se font par \n.
	//					Pas de saut de ligne final.

//------------------------------------------------- Surcharge d'opérateurs
    CompositeObject & operator= ( const CompositeObject & unCompositeObject );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unCompositeObject.
	//					Libere la memoire des composants de l'objet courant,
	//					redimensionne components a une taille correcte et
	//					copie en profondeur les composants de unCompositeObject.

//-------------------------------------------- Constructeurs - destructeur
    CompositeObject ( const CompositeObject & unCompositeObject );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unCompositeObject.
	//											Les composants de unCompositeObject seront copies en profondeur.

    CompositeObject ( const Components& components );
	// Mode d'emploi :	Instancie un nouvel objet dont les composants seront des copies en profondeur de components.
	//					Les composants ne seront pas modifiables par la suite.

    CompositeObject ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun composants.
	//					Les composants ne seront pas modifiables par la suite.

    virtual ~CompositeObject ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	Components components;      // Liste des composants de l'objet
								// Object etant une classe virtuelle,
								// nous somme obliges de passer par une liste de pointeurs
};

#endif // COMPOSITE_OBJECT_H
