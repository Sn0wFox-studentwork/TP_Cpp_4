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

using namespace std;

//------------------------------------------------------ Include personnel
#include "Polygone.h"

//------------------------------------------------------------- Constantes
const string Polygone::LABEL = "PC";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Polygone::Contains ( const Point & point )
// Algorithme : On cree un nouveau tableau de points qui supprime les points consecutifs doubles.
//				Si un des sommets est au meme endroit que le Point point, on retourne vrai.
//				S'il ne reste qu'un seul point, c'est qu'il est a l'exetrieur, on retroune donc faux.
//				Pour chaque point du polygone,
//					On determine si une de composante est un extremum du polygone.
//					si le signe de la composante selon z du produit vectoriel entre les vecteurs formes
//					par :	le point courant et le point a etudier
//							le point courant et le point suivant (le premier pour le dernier)
//					est invariant on continue.
//					Sinon, on retourne faux.
//				Si au moins un des produits vectoriels n'était pas nul, c'est que le point etait a l'interieur
//				du polygone. On retourne donc vrai.
//				Sinon, c'est qu'on est dans le cas d'un polygone sous forme de ligne.
//				Si le point a etudier possede des composantes comprises entre les extremums,
//				C'est qu'il est sur la ligne et on retourne vrai.
//				Sinon, on retourne faux.
{
    int x0, y0, x1, y1, x, y, res;
    int indB, indA;
	int xmin, xmax, ymin, ymax;
	bool positiv = false;
	bool negativ = false;
	bool oneCrossProductNotZero = false;	// Vrai si et seulement si un des produits vectoriel avait une norme non nulle

	// Supression des points consecutifs doubles et verification que point ne soit pas confondu avec un des points du polygone
	vector<Point> pts;
	for ( indA = 0; indA < points.size( ); indA++ )
	{
		indB = ( indA + 1 ) % points.size( );				// Point suivant
		if ( !( points[indA] == points[indB] ) )
		{
			pts.push_back( points[indA] );
		}
		if ( point == points[indA] )
		{
			return true;
		}
	}
	indB = 0;
	int nbPoints = pts.size( );

	if ( !nbPoints )
	{
		return false;			// Si le point avait ete confondu on s'en serait apercu au dessus
	}

	x = point.GetX( );
	y = point.GetY( );

	xmin = pts[0].GetX( );
	xmax = pts[0].GetX( );
	ymin = pts[0].GetY( );
	ymax = pts[0].GetY( );

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
// Algorithme : On cree un nouveau tableau de points qui supprime les points consecutifs doubles.
//				S'il reste trois points ou moins, le pylogone est forcement convexe : on retourne vrai.
//				On itere pour chaque trois points consecutifs du tableau precedent (A->B->C) :
//					On determine si une des coordonnees des points est un extremum (il faut croitre dans un sens puis
//					decroitre pour determiner une extremum).
//					Si une des coordonnees des points depassent un des extremum, on retourne faux.
//					On calcule le produit vectoriel ABxBC (sa composante selon z).
//					S'il change de signe, le polygone n'est pas convexe, et on retourne faux.
//				Si tous les produits sont positifs ou négatifs, le polygone est convexe, et on retourne vrai.
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
	int xmin = points[0].GetX( ) < points[1].GetX( ) ? points[0].GetX( ) : points[1].GetX( );
	int xmax = points[0].GetX( ) > points[1].GetX( ) ? points[0].GetX( ) : points[1].GetX( );
	int ymin = points[0].GetY( ) < points[1].GetY( ) ? points[0].GetY( ) : points[1].GetY( );
	int ymax = points[0].GetY( ) > points[1].GetY( ) ? points[0].GetY( ) : points[1].GetY( );

	// Indices des points a manipuler
    int indA, indB, indC, BAx, BAy, BCx, BCy;
    

	// Valeur de la norme du produit vectoriel
	int crossProduct;

	// Supression des points consecutifs doubles
	Sommets pts;
	for ( indA = 0; indA < points.size( ); indA++ )
	{
		indB = ( indA + 1 ) % points.size( );				// Point suivant
		if ( !( points[indA] == points[indB] ) )
		{
			pts.push_back( points[indA] );
		}
	}
	indB = 0;
	int nbPoints = pts.size( );
	
	if ( nbPoints <= 2 )
	{
		return true;
	}

    for ( indA = 0 ; indA < nbPoints - 2; indA++ )
    {
		// Prise des index des pts a manipuler
        indB = ( indA + 1 ) % nbPoints;				// Point suivant
        indC = ( indB + 1 ) % nbPoints;				// Point suivant le suivant

		// Prise des extremums et verifications
		if (!xminHit)
		{
			if ( pts[indC].GetX( ) <= xmin )
			{
				xmin = pts[indC].GetX( );
			}
			else if ( pts[indA].GetX( ) >= pts[indB].GetX( ) )
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
		if ( !xmaxHit )
		{
			if ( pts[indC].GetX( ) >= xmax )
			{
				xmax = pts[indC].GetX( );
			}
			else if ( pts[indA].GetX( ) <= pts[indB].GetX( ) )
			{
				xmaxHit = true;
			}
		}
		else
		{
			if ( pts[indC].GetX( ) >= xmax )
			{
				return false;
			}
		}
		if (!yminHit)
		{
			if ( pts[indC].GetY() <= ymin )
			{
				ymin = pts[indC].GetY( );
			}
			else if ( pts[indA].GetY( ) >= pts[indB].GetY( ) )
			{
				yminHit = true;
			}
		}
		else
		{
			if ( pts[indC].GetY() <= ymin )
			{
				return false;
			}
		}
		if ( !ymaxHit )
		{
			if ( pts[indC].GetY() >= ymax )
			{
				ymax = pts[indC].GetY( );
			}
			else if ( pts[indA].GetY( ) <= pts[indB].GetY( ) )
			{
				ymaxHit = true;
			}
		}
		else
		{
			if ( pts[indC].GetY( ) >= ymax )
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

	// Tout les extremums ont deja ete verifies
	for ( indA; indA < nbPoints; indA++ )
	{
		indB = ( indA + 1 ) % nbPoints;				// Point suivant
		indC = ( indB + 1 ) % nbPoints;				// Point suivant le suivant

		BAx = pts.at( indA ).GetX( ) - pts.at(indB).GetX( );
		BAy = pts.at( indA ).GetY( ) - pts.at(indB).GetY( );
		BCx = pts.at( indC ).GetX( ) - pts.at(indB).GetX( );
		BCy = pts.at( indC ).GetY( ) - pts.at(indB).GetY( );

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
		points = unPolygone.points;
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Polygone::Polygone ( const Polygone & unPolygone ) : SingleObject( )
// Algorithme :	Utilisation du constructeur de copie de SingleObject.
{
	points = unPolygone.points;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polygone>" << endl;
#endif
}	//----- Fin de Polygone (constructeur de copie)

Polygone::Polygone ( const Sommets& pts ) : SingleObject( pts )
// Algorithme :	Utilisation du constructeur de SingleObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygone>" << endl;
#endif
}	//----- Fin de Polygone

Polygone::Polygone ( )
// Algorithme :	Utilisation du constructeur par defaut de SingleObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygone>" << endl;
#endif
}	//----- Fin de Polygone

Polygone::~Polygone ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <Polygone>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~Polygone
