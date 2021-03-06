/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes
const string Segment::LABEL = "S";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Segment::Contains ( const Point & point )
// Algorithme : Trouver si C se situe sur le segment [AB]
//				AVEC --> A = a, B = b, C = point <--
//				On calcule le produit vectoriel AB*AC : s'il est nul, A, B, C sont alignés (bon signe)
//				On calcule ensuite les deux produits scalaires Kac = AB.AC, et Kab = AB.AB
//				Si 0 <= Kac <= Kab, C est contenu dans le segment [AB]
{
    Point & a = points.at( 0 );
    Point & b = points.at( 1 );

    // Vecteur AB
    int abx = b.GetX( ) - a.GetX( );
    int aby = b.GetY( ) - a.GetY( );
    // Vecteur AC
    int acx = point.GetX( ) - a.GetX( );
    int acy = point.GetY( ) - a.GetY( );
    // AB*AC
    int vec = ( abx * acy ) - ( aby * acx );
    // == 0 ?
    if ( vec == 0 )
        // A, B, C colinéaires
    {
        // AB.AC
        int kac = abx * acx + aby * acy;
        // AB.AB
        int kab = abx * abx + aby * aby;
        // O <= Kac <= Kab ?
        return kac <= kab && kac >= 0;
    }
    else
        // A,B,C non colinéaires
    {
        return false;
    }
}   //----- Fin de Contains

//------------------------------------------------- Surcharge d'opérateurs
Segment & Segment::operator= ( const Segment & unSegment )
// Algorithme :	Si on n'est pas en train de faire unSegment = unSegment, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unSegment
{
    if ( this != &unSegment )
    {
		points = unSegment.points;
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & unSegment ) : SingleObject( unSegment )
// Algorithme :	Utilisation du constructeur de copie de SingleObject.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
}	//----- Fin de Segment (constructeur de copie)

Segment::Segment ( const Point & p1, const Point & p2 ) : SingleObject( )
// Algorithme :	Utilisation du constructeur de SingleObject et ajout des points.
{
	points.push_back( p1 );
	points.push_back( p2 );
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif
}	//----- Fin de Segment

Segment::Segment ( ) : SingleObject( )
// Algorithme :	Utilisation du constructeur par defaut de SingleObject.
{
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif
}	//----- Fin de Segment

Segment::~Segment ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <Segment>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~Segment
