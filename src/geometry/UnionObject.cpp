/*************************************************************************
                           UnionObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 20116 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <UnionObject> (fichier UnionObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UnionObject.h"

//------------------------------------------------------------- Constantes
const std::string UnionObject::LABEL = "UO";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool UnionObject::Contains ( const Point & point )
// Algorithme :
//
{
    for (Object* o : components)
    {
        if (o->Contains(point))
        {
            return true;
        }
    }
    return false;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
UnionObject & UnionObject::operator= ( const UnionObject & unUnionObject )
// Algorithme :	Si on n'est pas en train de faire unUnionObject = unUnionObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unUnionObject
{
    if ( this != &unUnionObject )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
UnionObject::UnionObject ( const UnionObject & unUnionObject ) : CompositeObject::CompositeObject( unUnionObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <UnionObject>" << endl;
#endif
} //----- Fin de UnionObject (constructeur de copie)

UnionObject::UnionObject ( const std::vector<Object *> & _components ) : CompositeObject( _components )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UnionObject>" << endl;
#endif
}

UnionObject::UnionObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UnionObject>" << endl;
#endif
} //----- Fin de UnionObject


UnionObject::~UnionObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UnionObject>" << endl;
#endif
} //----- Fin de ~UnionObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
