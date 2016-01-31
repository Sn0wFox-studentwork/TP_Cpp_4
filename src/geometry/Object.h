/*************************************************************************
                           Object  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Object> (fichier Object.h) ------
#if !defined ( OBJECT_H )
#define OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Object>
//
//
//------------------------------------------------------------------------ 

class Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & point ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual void Move(int dx, int dy) = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual void Print() const = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual Object* Clone() const = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

    virtual std::string getLabel ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Object & operator= ( const Object & unObject );
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
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    const static std::string LABEL;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Object>

#endif // OBJECT_H
