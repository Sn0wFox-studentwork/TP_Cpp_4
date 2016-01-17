/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <CompositeObject> (fichier CompositeObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int CompositeObject::Move ( int dx, int dy )
// Algorithme :
{
    for ( auto obj = components.begin( ) ; obj != components.end( ) ; ++obj )
    {
        ( *obj )->Move( dx, dy );
    }
    return 1;
}    //----- Fin de Move


//------------------------------------------------- Surcharge d'opérateurs
CompositeObject & CompositeObject::operator= ( const CompositeObject & unCompositeObject )
// Algorithme :	Si on n'est pas en train de faire unCompositeObject = unCompositeObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unCompositeObject
{
    if ( this != &unCompositeObject )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CompositeObject::CompositeObject ( const CompositeObject & unCompositeObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CompositeObject>" << endl;
#endif
} //----- Fin de CompositeObject (constructeur de copie)


CompositeObject::CompositeObject ( const std::vector<Object *> & _components ) : components( _components )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CompositeObject>" << endl;
#endif
} //----- Fin de CompositeObject

CompositeObject::CompositeObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CompositeObject>" << endl;
#endif
} //----- Fin de CompositeObject


CompositeObject::~CompositeObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CompositeObject>" << endl;
#endif
} //----- Fin de ~CompositeObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
