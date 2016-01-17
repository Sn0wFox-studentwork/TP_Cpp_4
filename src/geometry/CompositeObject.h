/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <CompositeObject> (fichier CompositeObject.h) ------
#if ! defined ( COMPOSITE_OBJECT_H )
#define COMPOSITE_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <list>

#include "Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CompositeObject>
//
//
//------------------------------------------------------------------------ 

class CompositeObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual bool Contains( Point point ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Move( int dx, int dy );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void Print() const
	{
		for (Object* o : components)
		{
			o->Print();
		}
	}


//------------------------------------------------- Surcharge d'opérateurs
    CompositeObject & operator = ( const CompositeObject & unCompositeObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CompositeObject ( const CompositeObject & unCompositeObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CompositeObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CompositeObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	std::list<Object*> components;		// Object etant une classe virtuelle,
										// nous somme obliges de passer par une liste de pointeurs

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CompositeObject>

#endif // COMPOSITE_OBJECT_H
