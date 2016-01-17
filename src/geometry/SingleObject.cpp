/*************************************************************************
                           SingleObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <SingleObject> (fichier SingleObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "SingleObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
<<<<<<< HEAD
void SingleObject::Move( int dx, int dy )
// Algorithme :
{
	for ( Point p : points )
	{
		p.Move( dx, dy );
	}
}	//----- Fin de Méthode
=======
int SingleObject::Move ( int dx, int dy )
// Algorithme :
{
    for ( auto p = points.begin( ) ; p != points.end( ) ; ++p )
    {
        p->Move( dx, dy );
    }
    return 1;
}    //----- Fin de Méthode
>>>>>>> origin/master


//------------------------------------------------- Surcharge d'opérateurs
SingleObject & SingleObject::operator= ( const SingleObject & unSingleObject )
// Algorithme :	Si on n'est pas en train de faire unSingleObject = unSingleObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unSingleObject
{
    if ( this != &unSingleObject )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
SingleObject::SingleObject ( const SingleObject & unSingleObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SingleObject>" << endl;
#endif
} //----- Fin de SingleObject (constructeur de copie)

<<<<<<< HEAD

SingleObject::SingleObject ( ) : Object( ), points( )
=======
SingleObject::SingleObject ( )
>>>>>>> origin/master
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
} //----- Fin de SingleObject

SingleObject::SingleObject ( const std::vector<Point> & _points )
// Algorithme :
//
{
    // L'affectation n'est pas suffisante car elle ne transfère pas la taille (et capacité) du vecteur
    points.clear( );
    points.resize( _points.size( ));
    points = _points;
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
} //----- Fin de SingleObject


SingleObject::~SingleObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SingleObject>" << endl;
#endif
} //----- Fin de ~SingleObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
