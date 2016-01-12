/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <CompositeObject> (fichier CompositeObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
int CompositeObject::Move( int dx, int dy )
// Algorithme :
{
	return 0;
}	//----- Fin de Move


//------------------------------------------------- Surcharge d'op�rateurs
CompositeObject & CompositeObject::operator = ( const CompositeObject & unCompositeObject )
// Algorithme :	Si on n'est pas en train de faire unCompositeObject = unCompositeObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unCompositeObject
{
	if ( this != &unCompositeObject )
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CompositeObject::CompositeObject ( const CompositeObject & unCompositeObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CompositeObject>" << endl;
#endif
} //----- Fin de CompositeObject (constructeur de copie)


CompositeObject::CompositeObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CompositeObject>" << endl;
#endif
} //----- Fin de CompositeObject


CompositeObject::~CompositeObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CompositeObject>" << endl;
#endif
} //----- Fin de ~CompositeObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
