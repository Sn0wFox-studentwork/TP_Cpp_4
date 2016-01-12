/*************************************************************************
                           InterObject  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <InterObject> (fichier InterObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "InterObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool InterObject::Contains(Point point)
// Algorithme :
//
{
	return false;
} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
InterObject & InterObject::operator = ( const InterObject & unInterObject )
// Algorithme :	Si on n'est pas en train de faire unInterObject = unInterObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unInterObject
{
	if (this != &unInterObject)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
InterObject::InterObject ( const InterObject & unInterObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <InterObject>" << endl;
#endif
} //----- Fin de InterObject (constructeur de copie)


InterObject::InterObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <InterObject>" << endl;
#endif
} //----- Fin de InterObject


InterObject::~InterObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <InterObject>" << endl;
#endif
} //----- Fin de ~InterObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
