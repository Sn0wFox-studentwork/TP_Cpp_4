/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Segment::Contains( Point point )
// Algorithme :
//
{
	return false;
}	//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Segment & Segment::operator = ( const Segment & unSegment )
// Algorithme :	Si on n'est pas en train de faire unSegment = unSegment, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unSegment
{
	if (this != &unSegment)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & unSegment )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- Fin de Segment (constructeur de copie)


Segment::Segment ( Point p1, Point p2 ) : SingleObject( )
// Algorithme :
//
{
	cout << p1.GetX() << endl;
	points.push_back( p1 );
	points.push_back( p2 );
	cout << points[0].GetX() << endl;
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif
} //----- Fin de Segment


Segment::~Segment ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Segment>" << endl;
#endif
} //----- Fin de ~Segment


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
