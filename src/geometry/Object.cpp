/*************************************************************************
                           Object  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Object> (fichier Object.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Object.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Object & Object::operator= ( const Object & unObject )
// Algorithme :	Si on n'est pas en train de faire unObject = unObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unObject
{
    if ( this != &unObject )
    {
		// Rien a faire ici
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Object::Object ( const Object & unObject )
// Algorithme :	Rien a faire ici.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Object>" << endl;
#endif
}	//----- Fin de Object (constructeur de copie)


Object::Object ( )
// Algorithme :	Rien a faire ici.
{
#ifdef MAP
    cout << "Appel au constructeur de <Object>" << endl;
#endif
}	//----- Fin de Object


Object::~Object ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <Object>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~Object


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées