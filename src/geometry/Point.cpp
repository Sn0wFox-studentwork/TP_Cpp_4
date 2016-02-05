/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) --

//---------------------------------------------------------------- INCLUDE
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Point::Move( int dx, int dy )
// Algorithme :	Ajout de dx et dy a x et y.
{
	x += dx;
	y += dy;
}	//----- Fin de Move

//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & unPoint )
// Algorithme :	Si on n'est pas en train de faire unPoint = unPoint, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unPoint
{
	if (this != &unPoint)
	{
		x = unPoint.x;
		y = unPoint.y;
	}
	return *this;
}

bool Point::operator== ( const Point & unPoint ) const
// Algorithme : Retourne vrai si les points ont les meme corrdonnees.
{
	return x == unPoint.x && y == unPoint.y;
}	//----- Fin de Contains


//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint ) : x( unPoint.x ), y( unPoint.y )
// Algorithme :	Utilisation des constructeurs de copie des entiers.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
}	//----- Fin de Point (constructeur de copie)


Point::Point ( int ax, int ay ) : x(ax), y(ay)
// Algorithme :	Utilisation des constructeurs des entiers.
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
}	//----- Fin de Point

Point::Point ( ) : x( 0 ), y( 0 )
// Algorithme :	Utilisation des constructeurs de copie des entiers en initialisant a 0 les coordonnees.
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
}	//----- Fin de Point

Point::~Point ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~Point
