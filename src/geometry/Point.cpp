/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Point::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

<<<<<<< HEAD

void Point::Move( int dx, int dy )
{
	x += dx;
	y += dy;
}

//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & unPoint )
// Algorithme :	Si on n'est pas en train de faire unPoint = unPoint, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unPoint
=======
int Point::Move ( int dx, int dy )
// Algorithme :
>>>>>>> origin/master
{
    x += dx;
    y += dy;

    return 1;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


<<<<<<< HEAD
Point::Point ( int ax, int ay ) : x(ax), y(ay)
=======
Point::Point ( int _x, int _y ) : x( _x ), y( _y )
>>>>>>> origin/master
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point

Point::Point ( ) : x( 0 ), y( 0 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point

Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
