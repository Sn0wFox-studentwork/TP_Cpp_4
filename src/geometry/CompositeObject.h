/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <CompositeObject> (fichier CompositeObject.h) ------
#if ! defined ( COMPOSITE_OBJECT_H )
#define COMPOSITE_OBJECT_H

//--------------------------------------------------- Interfaces utilis�es
#include <list>

#include "Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <CompositeObject>
//
//
//------------------------------------------------------------------------ 

class CompositeObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual bool Contains( Point point ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	int Move( int dx, int dy );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
	std::list<Object*> components;		// Object etant une classe virtuelle,
										// nous somme obliges de passer par une liste de pointeurs

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <CompositeObject>

#endif // COMPOSITE_OBJECT_H
