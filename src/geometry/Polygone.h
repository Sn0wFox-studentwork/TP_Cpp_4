/*************************************************************************
                           Polygone  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Polygone> (fichier Polygone.h) ------
#if !defined ( POLYGONE_H )
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "SingleObject.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <Polygone>
// Modelise un polygone.
// Ce polygone peut a priori etre quelconque (nul, ligne, convexe,
// concave, croise...).
// La classe fournie uniquement de quoi determiner si un polygone est
// convexe au sens large (voir IsConvexe( )), et si un point appartient
// au polygone courant s'il est convexe uniquement.
//------------------------------------------------------------------------ 

class Polygone : public SingleObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & point );
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, c'est a dire a l'interieur ou sur un bord ou un sommet
	//					du polygone.
    // Contrat :	Le polygone doit être convexe au sens defini par IsConvexe( ).

	inline Polygone* Clone( ) const
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.
	{
		return new Polygone( *this );
	}

    bool IsConvex ( ) const;
	// Mode d'emploi :	Determine si le polygone courant est convexe au sens large, c'est a dire :
	//						Si pour deux sommets quelconques du polygone,
	//						l'ensemble des points du segment reliant ces deux sommets est a l'interieur
	//						du polygone, OU sur un de ces bords.
	//					Ainsi, un polygone possedant :
	//						trois (ou plus) points alignes consecutifs pouvant etre entre deux autres
	//						ou plusieurs points consecutifs au meme endroit
	//					seront consideres comme convexes.
	//					En revanche, un polygone qui se superpose a lui-meme sera considere comme croise,
	//					et donc non convexe (sauf dans le cas ou seul le premier et le dernier point se chevauchent,
	//					puisqu'on retombe dans le cas de plusieurs points consecutifs se chevauchant).
	//					Retourne vrai si et seulement si le polygone courant est considere comme convexe,
	//					faUx sinon.

    inline std::string GetLabel ( ) const
	// Mode d'emploi :	Retourne une string decrivant la nature de l'objet courant.
	{
		return LABEL;
	}

//------------------------------------------------- Surcharge d'opérateurs
    Polygone & operator= ( const Polygone & unPolygone );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unPolygone.

//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unPolygone.

    Polygone ( const Sommets& tops );
	// Mode d'emploi :	Instancie un nouvel objet dont les points seront des copies des points de tops.
	//					Les points ne seront pas modifiables par la suite.

    Polygone ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun points.
	//					Les points ne seront pas modifiables par la suite.

    virtual ~Polygone ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------- Constantes de classe protégées
    const static std::string LABEL;

};

#endif // POLYGONE_H
