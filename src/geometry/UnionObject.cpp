/*************************************************************************
                           UnionObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 20116 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <UnionObject> (fichier UnionObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UnionObject.h"

//------------------------------------------------------------- Constantes
const string UnionObject::LABEL = "OR";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool UnionObject::Contains ( const Point & point )
// Algorithme :	Retourne vrai des que Point appartient a un des composants.
//				Retourne faux sinon.
{
    for ( Object* o : components )
    {
        if ( o->Contains( point ) )
        {
            return true;
        }
    }
    return false;
}	//----- Fin de Contains


//------------------------------------------------- Surcharge d'opérateurs
UnionObject & UnionObject::operator= ( const UnionObject & unUnionObject )
// Algorithme :	Si on n'est pas en train de faire unUnionObject = unUnionObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unUnionObject.
//				On libere la memoire des anciens composants de l'objet courant,
//				puis on copie en profondeur ceux de unUnionObject.
{
    if ( this != &unUnionObject )
    {
		for ( Object * o : components )
		{
			delete o;
		}
		components.resize( 0 );
		for ( Object * o : unUnionObject.components )
		{
			components.push_back( o->Clone( ) );
		}
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
UnionObject::UnionObject ( const UnionObject & unUnionObject ) : CompositeObject( unUnionObject )
// Algorithme :	Utilisation du constructeur de copie de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <UnionObject>" << endl;
#endif
} //----- Fin de UnionObject (constructeur de copie)

UnionObject::UnionObject ( const Components& c ) : CompositeObject( c )
// Algorithme :	Utilisation du constructeur de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <UnionObject>" << endl;
#endif
}

UnionObject::UnionObject ( )
// Algorithme :	Utilisation du constructeur par defaut de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <UnionObject>" << endl;
#endif
}	//----- Fin de UnionObject


UnionObject::~UnionObject ( )
// Algorithme :	Liberation de la memoire associee (celle de chaque composant),
//				via le destructeur de CompositeObject appele automatiquement.
{
#ifdef MAP
    cout << "Appel au destructeur de <UnionObject>" << endl;
#endif
}	//----- Fin de ~UnionObject
