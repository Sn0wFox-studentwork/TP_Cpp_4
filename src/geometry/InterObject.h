/*************************************************************************
                           InterObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <InterObject> (fichier InterObject.h) ------
#if ! defined ( INTER_OBJECT_H )
#define INTER_OBJECT_H

//--------------------------------------------------- Interfaces utilis�es
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <InterObject>
//
//
//------------------------------------------------------------------------ 

class InterObject : public CompositeObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	bool Contains( Point point );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'op�rateurs
    InterObject & operator = ( const InterObject & unInterObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    InterObject ( const InterObject & unInterObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    InterObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~InterObject ( );
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

//----------------------------------------- Types d�pendants de <InterObject>

#endif // INTER_OBJECT_H
