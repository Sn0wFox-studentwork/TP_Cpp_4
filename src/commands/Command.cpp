/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Command> (fichier Command.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Command.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
Command & Command::operator = ( const Command & aCommand )
// Algorithme :	Si on n'est pas en train de faire aCommand = aCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aCommand
{
	if ( this != &aCommand )
	{
		params = aCommand.params;
	}
	return *this;
}	//----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Command::Command ( const Command & aCommand ) : params( aCommand.params )
// Algorithme : utilisation des constructeurs de copie de CommandCode (int) et StringList (std::vector<string>).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Command>" << endl;
#endif
} //----- Fin de Command (constructeur de copie)


Command::Command ( const StringList& p ) : params( p )
// Algorithme :	Utilisation des constructeurs de copie de CommandCode (int) et StringList (std::vector<string>).
{
#ifdef MAP
    cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- Fin de Command


Command::~Command ( )
// Algorithme :	Liberation de la memoire.
{
#ifdef MAP
    cout << "Appel au destructeur de <Command>" << endl;
#endif
	// Pas d'allocation dynamique.
} //----- Fin de ~Command


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
