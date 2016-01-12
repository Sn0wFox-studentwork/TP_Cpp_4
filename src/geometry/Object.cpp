/*************************************************************************
                           Object  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <Object> (fichier Object.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Object.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs
Object & Object::operator = ( const Object & unObject )
// Algorithme :	Si on n'est pas en train de faire unObject = unObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unObject
{
	if (this != &unObject)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Object::Object ( const Object & unObject )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Object>" << endl;
#endif
} //----- Fin de Object (constructeur de copie)


Object::Object ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Object>" << endl;
#endif
} //----- Fin de Object


Object::~Object ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Object>" << endl;
#endif
} //----- Fin de ~Object


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
