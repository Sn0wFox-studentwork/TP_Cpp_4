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
	// Signe du produit scalaire = sens de l'angle
    bool negative = false;
    bool positive = false;

	// Extremums des points
	int xmin = points[0].GetX() < points[1].GetX() ? points[0].GetX() : points[1].GetX();
	int xmax = points[0].GetX() > points[1].GetX() ? points[0].GetX() : points[1].GetX();
	int ymin = points[0].GetY() < points[1].GetY() ? points[0].GetY() : points[1].GetY();
	int ymax = points[0].GetY() > points[1].GetY() ? points[0].GetY() : points[1].GetY();

	// Extremum atteint
	bool xminHit = false;
	bool xmaxHit = false;
	bool yminHit = false;
	bool ymaxHit = false;

	// Indices des points a manipuler
    int indB, indC, BAx, BAy, BCx, BCy;
    int nbPoints = points.size( );

	// Valeur de la norme du produit vectoriel
	int crossProduct;

    for ( int indA = 0 ; indA < nbPoints - 2; indA++ )
    {
		// Prise des index des points a manipuler
        indB = ( indA + 1 ) % nbPoints;				// Point suivant
        indC = ( indB + 1 ) % nbPoints;				// Point suivant le suivant

		if (points[indA] == points[indB] || points[indB] == points[indC])
		{
			continue;
		}

		if (!xminHit)
		{
			if (points[indC].GetX() <= xmin)
			{
				xmin = points[indC].GetX();
			}
			else
			{
				xminHit = true;
			}
		}
		else
		{
			if ( points[indC].GetX() <= xmin )
			{
				return false;
			}
		}
		if (!xmaxHit)
		{
			if (points[indC].GetX() >= xmax)
			{
				xmax = points[indC].GetX();
			}
			else
			{
				xmaxHit = true;
			}
		}
		else
		{
			if (points[indC].GetX() >= xmax)
			{
				return false;
			}
		}
		if (!yminHit)
		{
			if (points[indC].GetY() <= ymin)
			{
				ymin = points[indC].GetY();
			}
			else
			{
				yminHit = true;
			}
		}
		else
		{
			if (points[indC].GetY() <= ymin)
			{
				return false;
			}
		}
		if (!ymaxHit)
		{
			if (points[indC].GetY() >= ymax)
			{
				ymax = points[indC].GetY();
			}
			else
			{
				ymaxHit = true;
			}
		}
		else
		{
			if (points[indC].GetY() >= ymax)
			{
				return false;
			}
		}

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
