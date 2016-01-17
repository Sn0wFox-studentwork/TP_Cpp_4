/*************************************************************************
                           SingleObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <SingleObject> (fichier SingleObject.h) ------
#if !defined ( SINGLE_OBJECT_H )
#define SINGLE_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>

#include "Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <SingleObject>
//
//
//------------------------------------------------------------------------ 

class SingleObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & p ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual int Move ( int dx, int dy );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    SingleObject & operator= ( const SingleObject & unSingleObject );
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

    SingleObject ( const std::vector<Point> & _points );
    // Mode d'emploi :
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
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    const static std::string LABEL;
    std::vector<Point> points;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SingleObject>

#endif // SINGLE_OBJECT_H
