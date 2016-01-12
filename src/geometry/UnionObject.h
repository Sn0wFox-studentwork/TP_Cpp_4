/*************************************************************************
                           UnionObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <UnionObject> (fichier UnionObject.h) ------
#if ! defined ( UNION_OBJECT_H )
#define UNION_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <UnionObject>
//
//
//------------------------------------------------------------------------ 

class UnionObject : public CompositeObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains( Point point );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    UnionObject & operator = ( const UnionObject & unUnionObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    UnionObject ( const UnionObject & unUnionObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    UnionObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~UnionObject ( );
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

//----------------------------------------- Types dépendants de <UnionObject>

#endif // UNION_OBJECT_H
