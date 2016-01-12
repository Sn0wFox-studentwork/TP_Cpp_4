/*************************************************************************
                           SingleObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <SingleObject> (fichier SingleObject.h) ------
#if ! defined ( SINGLE_OBJECT_H )
#define SINGLE_OBJECT_H

//--------------------------------------------------- Interfaces utilis�es
#include <list>

#include "Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <SingleObject>
//
//
//------------------------------------------------------------------------ 

class SingleObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual bool Contains( Point p ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual int Move( int dx, int dy );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'op�rateurs
    SingleObject & operator = ( const SingleObject & unSingleObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    SingleObject ( const SingleObject & unSingleObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SingleObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SingleObject ( );
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
	std::list<Point> points;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <SingleObject>

#endif // SINGLE_OBJECT_H
