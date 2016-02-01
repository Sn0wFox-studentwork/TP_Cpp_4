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

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes
const std::string Rectangle::LABEL = "R";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Rectangle::Contains ( const Point & point )
// Algorithme : On vérifie que le point se trouve entre les deux coins du rectangle
// NOTE : Cet algo marche uniquement avec les rectangles parallèles à l'axe x, y
{
    int xmax = points.at( 0 ).GetX( ); // Coin GAUCHE-HAUT
    int ymax = points.at( 0 ).GetY( );
    int xmin = points.at( 1 ).GetX( ); // Coin DROITE-BAS
    int ymin = points.at( 1 ).GetY( );
    int x = point.GetX( );
    int y = point.GetY( );

    return x > xmin && x < xmax && y > ymin && y < ymax;
}    //----- Fin de Contains

//------------------------------------------------- Surcharge d'opérateurs
Rectangle & Rectangle::operator= ( const Rectangle & unRectangle )
// Algorithme :	Si on n'est pas en train de faire unRectangle = unRectangle, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unRectangle
{
    if ( this != &unRectangle )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle )
// Algorithme :
//
{
    points = unRectangle.points;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( const std::vector<Point> & _points ) : Polygone( _points )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
