/*************************************************************************
                           SingleObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <SingleObject> (fichier SingleObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "SingleObject.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void SingleObject::Move( int dx, int dy )
// Algorithme :	Utilisation la methode Move sur chacun des points.
{
	for ( Point& p : points )
	{
		p.Move( dx, dy );
	}
}	//----- Fin de Move

string SingleObject::ToString( ) const
// Algorithme :	Utilisation d'un stringstream pour plus de praticite.
//				On insere dans le flux le label de l'object courant suivant des coordonnees
//				de tout chacun de ses points au format : " x y".
//				Pas de retour a la ligne final.
{
	ostringstream os;
	os << GetLabel( );
	for ( Point p : points )
	{
		os << " " << p.GetX( ) << " " << p.GetY( );
	}
	return os.str( );
}	//----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs
SingleObject & SingleObject::operator= ( const SingleObject & unSingleObject )
// Algorithme :	Si on n'est pas en train de faire unSingleObject = unSingleObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unSingleObject.
{
    if ( this != &unSingleObject )
    {
		points = unSingleObject.points;
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
SingleObject::SingleObject ( const SingleObject & unSingleObject ) : Object( ), points( unSingleObject.points )
// Algorithme :	Utilisation des constructeurs de copie de Object et de vector<Point>.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SingleObject>" << endl;
#endif
}	//----- Fin de SingleObject (constructeur de copie)

SingleObject::SingleObject ( ) : Object( ), points( )
// Algorithme :	Utilisation des constructeurs par defaut de Object et de vector<Point>.
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
}	//----- Fin de SingleObject

SingleObject::SingleObject ( const Sommets& pts ) : Object( ), points( pts )
// Algorithme :	Utilisation des constructeurs de Object et de vector<Point>.
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
}	//----- Fin de SingleObject


SingleObject::~SingleObject ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <SingleObject>" << endl;
#endif
	// Pas d'allocation dynamique.
}	//----- Fin de ~SingleObject
