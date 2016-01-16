/*************************************************************************
                           Polygone  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Polygone> (fichier Polygone.h) ------
#if ! defined ( POLYGONE_H )
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "SingleObject.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polygone>
//
//
//------------------------------------------------------------------------ 

class Polygone : public SingleObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual bool Contains( Point point );
	// Mode d'emploi :
	//
	// Contrat :
	//


//------------------------------------------------- Surcharge d'opérateurs
    Polygone & operator = ( const Polygone & unPolygone );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polygone ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polygone ( );
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

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polygone>

#endif // POLYGONE_H
