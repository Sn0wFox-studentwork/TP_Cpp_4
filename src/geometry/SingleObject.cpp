/*************************************************************************
                           SingleObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <SingleObject> (fichier SingleObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "SingleObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int SingleObject::Move( int dx, int dy )
// Algorithme :
{
	return 0;
}	//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
SingleObject & SingleObject::operator = ( const SingleObject & unSingleObject )
// Algorithme :	Si on n'est pas en train de faire unSingleObject = unSingleObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unSingleObject
{
	if (this != &unSingleObject)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
SingleObject::SingleObject ( const SingleObject & unSingleObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SingleObject>" << endl;
#endif
} //----- Fin de SingleObject (constructeur de copie)


SingleObject::SingleObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleObject>" << endl;
#endif
} //----- Fin de SingleObject


SingleObject::~SingleObject ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SingleObject>" << endl;
#endif
} //----- Fin de ~SingleObject


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
