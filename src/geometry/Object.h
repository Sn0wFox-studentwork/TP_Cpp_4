/*************************************************************************
                           Object  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Object> (fichier Object.h) ------
#if !defined ( OBJECT_H )
#define OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include "Point.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <Object>
// Permet de modeliser une forme geometrique.
// Cette forme pourra etre quelconque, simple ou composees de plusieurs
// autre formes.
// Classe abstraite permettant la mise en place du composite pattern.
// Elle definit egalement l'ensemble des methodes communes a toutes
// les sortes de formes geometriques.
//------------------------------------------------------------------------ 

class Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & point ) = 0;
    // Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, ou sur un de ces bords ou sommets.

	virtual void Move ( int dx, int dy ) = 0;
	// Mode d'emploi :	Deplace l'objet courant selon le vecteur (dx, dy).
	//					La seule limite reste celle de l'overflow.

    virtual std::string ToString ( ) const = 0;
	// Mode d'emploi :	Retourne une representation de l'objet courant sous forme de string.

	virtual Object* Clone ( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.

    virtual std::string GetLabel ( ) const = 0;
    // Mode d'emploi :	Retourne une string permettant d'identifier la nature de l'objet courant.

//------------------------------------------------- Surcharge d'opérateurs
    Object & operator= ( const Object & unObject );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unObject.

//-------------------------------------------- Constructeurs - destructeur
    Object ( const Object & unObject );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unObject.

    Object ( );
    // Mode d'emploi :	Instancie un nouvel objet.
	//					Definit les composants de base d'un Object.

    virtual ~Object ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
    const static std::string LABEL;

};

#endif // OBJECT_H
