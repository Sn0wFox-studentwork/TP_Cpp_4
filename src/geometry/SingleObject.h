/*************************************************************************
                           SingleObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <SingleObject> (fichier SingleObject.h) ------
#if !defined ( SINGLE_OBJECT_H )
#define SINGLE_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>
#include <string>

#include "Object.h"

//------------------------------------------------------------------ Types
typedef std::vector<Point> Sommets;

//------------------------------------------------------------------------ 
// Rôle de la classe <SingleObject>
// Permet de modeliser des objets (ici des formes geometriques) dits
// elementaires, c'est-a-dire constitues uniquement de points.
// Permet la mise en place du composite pattern.
//------------------------------------------------------------------------ 

class SingleObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & p ) = 0;
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, c'est a dire a l'interieur ou sur un bord ou un sommet
	//					de l'objet courant.

	virtual Object* Clone ( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.

	virtual std::string GetLabel ( ) const = 0;
    // Mode d'emploi :	Retourne une string permettant d'identifier la nature de l'objet courant.

	virtual void Move ( int dx, int dy );
	// Mode d'emploi :	Deplace l'objet courant selon le vecteur (dx, dy) : deplace tout ses points
	//					selon le vecteur (dx, dy).
	//					La seule limite reste celle de l'overflow.

	virtual std::string ToString ( ) const;
	// Mode d'emploi :	Retourne une representation de l'objet courant sous forme de string.
	//					Il s'agit Il s'agit du label de l'objet suivit des coordonnees
	//					de chacun des points au format : " x y".
	//					Pas de saut de ligne final.

//------------------------------------------------- Surcharge d'opérateurs
    SingleObject & operator= ( const SingleObject & unSingleObject );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unSingleObject.
	//					Les points seront tous copies.


//-------------------------------------------- Constructeurs - destructeur
    SingleObject ( const SingleObject & unSingleObject );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unSingleObject.
	//											Les points seront tous copies.

    SingleObject ( const Sommets& tops );
	// Mode d'emploi :	Instancie un nouvel objet dont les points seront des copies des points de tops.
	//					Les points ne seront pas modifiables par la suite.

    SingleObject ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun points.
	//					Les points ne seront pas modifiables par la suite.

    virtual ~SingleObject ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	Sommets points;		// L'ensemble des sommets de l'objet

};

#endif // SINGLE_OBJECT_H
