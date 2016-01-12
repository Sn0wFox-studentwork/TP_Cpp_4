/*************************************************************************
                           UnionObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <UnionObject> (fichier UnionObject.h) ------
#if ! defined ( UNION_OBJECT_H )
#define UNION_OBJECT_H

//--------------------------------------------------- Interfaces utilis�es
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <UnionObject>
//
//
//------------------------------------------------------------------------ 

class UnionObject : public CompositeObject
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

//----------------------------------------- Types d�pendants de <UnionObject>

#endif // UNION_OBJECT_H
