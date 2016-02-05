/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes
const string Rectangle::LABEL = "R";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Rectangle::Contains ( const Point & point )
// Algorithme : On vérifie que le point se trouve entre les deux coins du rectangle
//				NOTE : Cet algo marche uniquement avec les rectangles parallèles à l'axe x, y
{
    int xmax = points.at( 0 ).GetX( ); // Coin GAUCHE-HAUT
    int ymax = points.at( 0 ).GetY( );
    int xmin = points.at( 1 ).GetX( ); // Coin DROITE-BAS
    int ymin = points.at( 1 ).GetY( );
    int x = point.GetX( );
    int y = point.GetY( );

    return x >= xmin && x <= xmax && y >= ymin && y <= ymax;
}    //----- Fin de Contains

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & Rectangle::operator= ( const Rectangle & unRectangle )
// Algorithme :	Si on n'est pas en train de faire unRectangle = unRectangle, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unRectangle
{
    if ( this != &unRectangle )
    {
		points = unRectangle.points;
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ) : Polygone( )
// Algorithme :	Utilisation du constructeur de copie de Polygone.
{
    points = unRectangle.points;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
}	//----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( const Sommets& pts ) : Polygone( pts )
// Algorithme :	Utilisation du constructeur de Polygone.
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
}	//----- Fin de Rectangle

Rectangle::Rectangle ( ) : Polygone( )
// Algorithme :	Utilisation du constructeur par defaut de Polygone.
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
}	//----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~Rectangle
