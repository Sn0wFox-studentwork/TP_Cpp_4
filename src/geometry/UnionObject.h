/*************************************************************************
                           UnionObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <UnionObject> (fichier UnionObject.h) ------
#if !defined ( UNION_OBJECT_H )
#define UNION_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "CompositeObject.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <UnionObject>
// Permet de manipuler un ensemble d'objets comme la reunion de tout
// ces objets.
//------------------------------------------------------------------------ 

class UnionObject : public CompositeObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
	// Mode d'emploi :	Retourne vrai si et seulement si le Point point est a l'interieur
	//					de l'objet courant, c'est a dire a l'interieur ou sur un bord ou un sommet
	//					d'au moins un des composants.

	inline std::string GetLabel ( ) const
	// Mode d'emploi :	Retourne une string decrivant la nature de l'objet courant.
	{
		return LABEL;
	}

	inline UnionObject* Clone ( ) const
	// Mode d'emploi :	Retourne un pointeur vers une copie de l'objet courant allouee dynamiquement.
	// Contrat :	La destruction du pointeur retourne est a la charge de l'utilisateur.
	{
		return new UnionObject( *this );
	}

//------------------------------------------------- Surcharge d'opérateurs
    UnionObject & operator= ( const UnionObject & unUnionObject );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unUnionObject.
	//					Libere la memoire des composants de l'objet courant,
	//					redimensionne components a une taille correcte et
	//					copie en profondeur les composants de unUnionObject


//-------------------------------------------- Constructeurs - destructeur
    UnionObject ( const UnionObject & unUnionObject );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unUnionObject.
	//											Les composants de unUnionObject seront copies en profondeur.

    UnionObject ( const Components& components );
	// Mode d'emploi :	Instancie un nouvel objet dont les composants seront des copies en profondeur de components.
	//					Les composants ne seront pas modifiables par la suite.

    UnionObject ( );
	// Mode d'emploi :	Instancie un nouvel objet compose d'aucun composants.
	//					Les composants ne seront pas modifiables par la suite.

    virtual ~UnionObject ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE

//----------------------------------------- Constantes de classe protégées
protected:
	const static std::string LABEL;

};

#endif // UNION_OBJECT_H
