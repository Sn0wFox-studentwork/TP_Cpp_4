/*************************************************************************
                           Object  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Object> (fichier Object.h) ------
#if ! defined ( OBJECT_H )
#define OBJECT_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Object>
//
//
//------------------------------------------------------------------------ 

class Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual bool Contains( Point point ) = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual int Move(int dx, int dy) = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'op�rateurs
    Object & operator = ( const Object & unObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Object ( const Object & unObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Object ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Object ( );
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

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Object>

#endif // OBJECT_H
