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
// Algorithme : On vérifie que le point se situe toujours du meme cote de chaque segment
// partant d'un point A à un point B consécutif du polygone.
{
    int x0, y0, x1, y1, x, y, res;
    int indB, indA;
	int xmin, xmax, ymin, ymax;
	bool positiv = false;
	bool negativ = false;
	bool oneCrossProductNotZero = false;	// Vrai si et seulement si un des produits vectoriel avait une norme non nulle

	// Supression des points consecutifs doubles et verification que point ne soit pas confondu avec un des points du polygone
	vector<Point> pts;
	for ( indA = 0; indA < points.size(); indA++ )
	{
		indB = (indA + 1) % points.size();				// Point suivant
		if (!(points[indA] == points[indB]))
		{
			pts.push_back(points[indA]);
		}
		if (point == points[indA])
		{
			return true;
		}
	}
	indB = 0;
	int nbPoints = pts.size();

	if (!nbPoints)
	{
		return false;			// Si le point avait ete confondu on s'en serait apercu au dessus
	}

	x = point.GetX();
	y = point.GetY();

	xmin = pts[0].GetX();
	xmax = pts[0].GetX();
	ymin = pts[0].GetY();
	ymax = pts[0].GetY();

    for ( indA = 0 ; indA < nbPoints ; indA++ )
    {
        indB = ( indA + 1 ) % nbPoints;

        // (y - y0) (x1 - x0) - (x - x0) (y1 - y0)
        x0 = pts.at( indA ).GetX( );
        y0 = pts.at( indA ).GetY( );
        x1 = pts.at( indB ).GetX( );
        y1 = pts.at( indB ).GetY( );

		xmin = x1 < xmin ? x1 : xmin;
		xmax = x1 > xmax ? x1 : xmax;
		ymin = y1 < ymin ? y1 : ymin;
		ymax = y1 > ymax ? y1 : ymax;

        res = ( y0 - y ) * ( x1 - x0 ) - ( x0 - x ) * ( y1 - y0 );

        if ( res > 0 )
        {
            positiv = true;
			oneCrossProductNotZero = true;
        }
		else if ( res < 0 )
		{
			negativ = true;
			oneCrossProductNotZero = true;
		}
		// Si res == 0, on ne peut rien dire

		if ( positiv && negativ )
		{
			return false;
		}
    }

	if ( oneCrossProductNotZero )
	{
		return true;
	}
	else		// On est dans le cas d'un polygone ligne
	{
		if (x >= xmin && x <= xmax && y >= ymin && y <= ymax)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}    //----- Fin de Contains

bool Polygone::IsConvex ( ) const
// Algorithme : On itère pour chaque trois points consécutifs de notre polygone
// (A->B->C), puis calcule le produit vectoriel ABxBC.
// Si tous les produits sont positifs ou négatifs, le polygone est convexe.
{
	// Signe du produit scalaire = sens de l'angle
    bool negative = false;
    bool positive = false;

	// Extremum atteint
	bool xminHit = false;
	bool xmaxHit = false;
	bool yminHit = false;
	bool ymaxHit = false;

	// Croissance des coordonnees
	bool xIncreasing = false;
	bool yIncreasing = false;

	// Extremums des points
	int xmin = points[0].GetX() < points[1].GetX() ? points[0].GetX() : points[1].GetX();
	int xmax = points[0].GetX() > points[1].GetX() ? points[0].GetX() : points[1].GetX();
	int ymin = points[0].GetY() < points[1].GetY() ? points[0].GetY() : points[1].GetY();
	int ymax = points[0].GetY() > points[1].GetY() ? points[0].GetY() : points[1].GetY();

	// Indices des points a manipuler
    int indA, indB, indC, BAx, BAy, BCx, BCy;
    

	// Valeur de la norme du produit vectoriel
	int crossProduct;

	// Supression des points consecutifs doubles
	vector<Point> pts;
	for (indA = 0; indA < points.size(); indA++)
	{
		indB = (indA + 1) % points.size();				// Point suivant
		if (!(points[indA] == points[indB]))
		{
			pts.push_back(points[indA]);
		}
	}
	indB = 0;
	int nbPoints = pts.size();
	
	if (nbPoints == 0 || nbPoints == 1 || nbPoints == 2)
	{
		return true;	// TODO : a voir
	}

    for ( indA = 0 ; indA < nbPoints - 2; indA++ )
    {
		// Prise des index des pts a manipuler
        indB = ( indA + 1 ) % nbPoints;				// Point suivant
        indC = ( indB + 1 ) % nbPoints;				// Point suivant le suivant

		if (pts[indA] == pts[indB] || pts[indB] == pts[indC])
		{
			continue;
		}

		if (!xminHit)
		{
			if (pts[indC].GetX() <= xmin)
			{
				xmin = pts[indC].GetX();
			}
			else if (pts[indA].GetX() >= pts[indB].GetX())
			{
				xminHit = true;
			}
		}
		else
		{
			if ( pts[indC].GetX() <= xmin )
			{
				return false;
			}
		}
		if (!xmaxHit)
		{
			if (pts[indC].GetX() >= xmax)
			{
				xmax = pts[indC].GetX();
			}
			else if (pts[indA].GetX() <= pts[indB].GetX())
			{
				xmaxHit = true;
			}
		}
		else
		{
			if (pts[indC].GetX() >= xmax)
			{
				return false;
			}
		}
		if (!yminHit)
		{
			if (pts[indC].GetY() <= ymin)
			{
				ymin = pts[indC].GetY();
			}
			else if (pts[indA].GetY() >= pts[indB].GetY())
			{
				yminHit = true;
			}
		}
		else
		{
			if (pts[indC].GetY() <= ymin)
			{
				return false;
			}
		}
		if (!ymaxHit)
		{
			if (pts[indC].GetY() >= ymax)
			{
				ymax = pts[indC].GetY();
			}
			else if (pts[indA].GetY() <= pts[indB].GetY())
			{
				ymaxHit = true;
			}
		}
		else
		{
			if (pts[indC].GetY() >= ymax)
			{
				return false;
			}
		}

        BAx = pts.at( indA ).GetX( ) - pts.at( indB ).GetX( );
        BAy = pts.at( indA ).GetY( ) - pts.at( indB ).GetY( );
        BCx = pts.at( indC ).GetX( ) - pts.at( indB ).GetX( );
        BCy = pts.at( indC ).GetY( ) - pts.at( indB ).GetY( );

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

	for (indA; indA < nbPoints; indA++)
	{
		indB = (indA + 1) % nbPoints;				// Point suivant
		indC = (indB + 1) % nbPoints;				// Point suivant le suivant

		BAx = pts.at(indA).GetX() - pts.at(indB).GetX();
		BAy = pts.at(indA).GetY() - pts.at(indB).GetY();
		BCx = pts.at(indC).GetX() - pts.at(indB).GetX();
		BCy = pts.at(indC).GetY() - pts.at(indB).GetY();

		crossProduct = (BAx * BCy - BAy * BCx);

		if (crossProduct < 0)
		{
			negative = true;
		}
		else if (crossProduct > 0)
		{
			positive = true;
		}
		if (negative && positive)
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
		points = unPolygone.points;
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
