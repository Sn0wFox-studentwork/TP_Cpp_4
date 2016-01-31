/*************************************************************************
                           Polygone  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Polygone> (fichier Polygone.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polygone.h"

//------------------------------------------------------------- Constantes
const std::string Polygone::LABEL = "PC";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Polygone::Contains ( const Point & point )
// Algorithme : On vérifie que le point se situe à droite de chaque segment
// partant d'un point A à un point B consécutif du polygone.
{
    int x0, y0, x1, y1, x, y, res;
    int indB;
    int nbPoints = points.size( );

    for ( int indA = 0 ; indA < nbPoints ; indA++ )
    {
        indB = ( indA + 1 ) % nbPoints;

        // (y - y0) (x1 - x0) - (x - x0) (y1 - y0)
        x0 = points.at( indA ).GetX( );
        y0 = points.at( indA ).GetY( );
        x1 = points.at( indB ).GetX( );
        y1 = points.at( indB ).GetY( );
        x = point.GetX( );
        y = point.GetY( );

        res = ( y - y0 ) * ( x1 - x0 ) - ( x - x0 ) * ( y1 - y0 );

        if ( res > 0 )
        {
            return false;
        }
    }

    return true;
}    //----- Fin de Contains

bool Polygone::IsConvex ( ) const
// Algorithme : On itère pour chaque trois points consécutifs de notre polygone
// (A->B->C), puis calcule le produit vectoriel ABxBC.
// Si tous les produits sont positifs ou négatifs, le polygone est convexe.
{
    bool negative = false;
    bool positive = false;
    int indB, indC, BAx, BAy, BCx, BCy, crossProduct;
    int nbPoints = points.size( );

    for ( int indA = 0 ; indA < nbPoints ; indA++ )
    {
        indB = ( indA + 1 ) % nbPoints;
        indC = ( indB + 1 ) % nbPoints;

        BAx = points.at( indA ).GetX( ) - points.at( indB ).GetX( );
        BAy = points.at( indA ).GetY( ) - points.at( indB ).GetY( );
        BCx = points.at( indC ).GetX( ) - points.at( indB ).GetX( );
        BCy = points.at( indC ).GetY( ) - points.at( indB ).GetY( );
        crossProduct = ( BAx * BCy - BAy * BCx );

        if ( crossProduct < 0 )
        {
            negative = true;
        }
        else if ( crossProduct > 0 )
        {
            positive = true;
        }
        if ( negative && positive )
        {
            return false;
        }
    }

    return true;
}    //----- Fin de IsConvex

//------------------------------------------------- Surcharge d'opérateurs
Polygone & Polygone::operator= ( const Polygone & unPolygone )
// Algorithme :	Si on n'est pas en train de faire unPolygone = unPolygone, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unPolygone
{
    if ( this != &unPolygone )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Polygone::Polygone ( const Polygone & unPolygone )
// Algorithme :
//
{
    points = unPolygone.points;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polygone>" << endl;
#endif
} //----- Fin de Polygone (constructeur de copie)

Polygone::Polygone ( const std::vector<Point> & _points ) : SingleObject( _points )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygone>" << endl;
#endif
} //----- Fin de Polygone

Polygone::Polygone ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygone>" << endl;
#endif
} //----- Fin de Polygone

Polygone::~Polygone ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polygone>" << endl;
#endif
} //----- Fin de ~Polygone


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
