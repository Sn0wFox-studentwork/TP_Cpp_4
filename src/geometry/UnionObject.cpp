/*************************************************************************
                           UnionObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 20116 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <UnionObject> (fichier UnionObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "UnionObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool UnionObject::Contains(Point point)
// Algorithme :
//
{
	return false;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
UnionObject & UnionObject::operator = ( const UnionObject & unUnionObject )
// Algorithme :	Si on n'est pas en train de faire unUnionObject = unUnionObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unUnionObject
{
	if (this != &unUnionObject)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
UnionObject::UnionObject ( const UnionObject & unUnionObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <UnionObject>" << endl;
#endif
} //----- Fin de UnionObject (constructeur de copie)


UnionObject::UnionObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UnionObject>" << endl;
#endif
} //----- Fin de UnionObject


UnionObject::~UnionObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UnionObject>" << endl;
#endif
} //----- Fin de ~UnionObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
