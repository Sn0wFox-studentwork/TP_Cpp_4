/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if !defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Polygone.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
// Permet de modeliser un rectangle.
// Ce rectangle peut etre quelconque (nul, ligne, ...).
//------------------------------------------------------------------------ 

class Rectangle : public Polygone
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, c'est a dire a l'interieur ou sur un bord ou un sommet
	//					du rectangle.
	// Contrat :	Le rectangle doit avoir des bords paralleles aux axes x et y.

	inline Rectangle* Clone ( ) const
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.
	{
		return new Rectangle( *this );
	}

	inline std::string GetLabel ( ) const
	// Mode d'emploi :	Retourne une string decrivant la nature de l'objet courant.
	{
		return LABEL;
	}

//------------------------------------------------- Surcharge d'opérateurs
    Rectangle & operator= ( const Rectangle & unRectangle );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unRectangle.

//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unRectangle.

    Rectangle ( const Sommets& tops );
	// Mode d'emploi :	Instancie un nouvel objet dont les points seront des copies des points de tops.
	//					Le rectangle aura pour coin haut droit le premier point de top, et comme coin bas gauche le second.
	//					Les points ne seront pas modifiables par la suite.

    Rectangle ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun points.
	//					Les points ne seront pas modifiables par la suite.

    virtual ~Rectangle ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------- Constantes de classe protégées
	const static std::string LABEL;

};

#endif // RECTANGLE_H
