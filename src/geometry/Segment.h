/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier Segment.h) ------
#if !defined ( SEGMENT_H )
#define SEGMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "SingleObject.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <Segment>
// Permet de modeliser un segment.
// Ce segment peut etre quelconque, et en particulier nul.
//------------------------------------------------------------------------ 

class Segment : public SingleObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, c'est a dire a sur le segment.
	//					Une extremite est une partie du segment.

	Segment* Clone ( ) const
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.
	{
		return new Segment( *this );
	}

    inline std::string GetLabel ( ) const
	// Mode d'emploi :	Retourne une string decrivant la nature de l'objet courant.
	{
		return LABEL;
	}

//------------------------------------------------- Surcharge d'opérateurs
    Segment & operator= ( const Segment & unSegment );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unSegment.


//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unSegment.

    Segment ( const Point & p1, const Point & p2 );
	// Mode d'emploi :	Instancie un nouvel objet dont les points seront des copies des points p1 et p2.
	//					Le segment aura pour extremites les copies de p1 et p2.
	//					Les points ne seront pas modifiables par la suite.

    Segment ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun points.
	//					Les points ne seront pas modifiables par la suite.

    virtual ~Segment ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------- Constantes de classe protégées
	const static std::string LABEL;

};

#endif // SEGMENT_H
