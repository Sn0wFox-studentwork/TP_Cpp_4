/*************************************************************************
                           InterObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <InterObject> (fichier InterObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "InterObject.h"

//------------------------------------------------------------- Constantes
const string InterObject::LABEL = "OI";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool InterObject::Contains ( const Point & point )
// Algorithme :	Retourne faux des que Point n'appartient pas a un des composants.
//				Retourne vrai sinon.
{
    for ( Object* o : components )
    {
        if ( !o->Contains( point ) )
        {
            return false;
        }
    }
    return true;
}	//----- Fin de Contains


//------------------------------------------------- Surcharge d'opérateurs
InterObject & InterObject::operator= ( const InterObject & unInterObject )
// Algorithme :	Si on n'est pas en train de faire unInterObject = unInterObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unInterObject.
//				On libere la memoire des anciens composants de l'objet courant,
//				puis on copie en profondeur ceux de unInterObject.
{
    if ( this != &unInterObject )
    {
		for ( Object * o : components )
		{
			delete o;
		}
		components.resize( 0 );
		for ( Object * o : unInterObject.components )
		{
			components.push_back( o->Clone( ) );
		}
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
InterObject::InterObject ( const InterObject & unInterObject ) : CompositeObject( unInterObject )
// Algorithme :	Utilisation du constructeur de copie de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <InterObject>" << endl;
#endif
}	//----- Fin de InterObject (constructeur de copie)

InterObject::InterObject ( const Components& c ) : CompositeObject( c )
// Algorithme :	Utilisation du constructeur de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <InterObject>" << endl;
#endif
}	//----- Fin de InterObject

InterObject::InterObject ( ) : CompositeObject( )
// Algorithme :	Utilisation du constructeur par defaut de CompositeObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <InterObject>" << endl;
#endif
}	//----- Fin de InterObject


InterObject::~InterObject ( )
// Algorithme :	Liberation de la memoire associee (celle de chaque composant),
//				via le destructeur de CompositeObject appele automatiquement.
{
#ifdef MAP
    cout << "Appel au destructeur de <InterObject>" << endl;
#endif
	// Pas d'allocation dynamique supplementaire
}	//----- Fin de ~InterObject
