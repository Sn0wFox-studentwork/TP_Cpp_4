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
// Algorithme :
//
{
    return false;
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
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( const std::vector<Point> & _points ) : Polygone( _points )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
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
