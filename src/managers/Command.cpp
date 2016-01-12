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
Command Command::GetInversedCommand( ) const
// Algorithme :
//
{
	// TODO : implementer cette methode
	return Command(CommandCode::DELETE, StringList());
}	//----- Fin de GetInversedCommand


//------------------------------------------------- Surcharge d'opérateurs
Command & Command::operator = ( const Command & unCommand )
// Algorithme :	Si on n'est pas en train de faire unCommand = unCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unCommand
{
	if ( this != &unCommand )
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Command::Command ( const Command & unCommand )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Command>" << endl;
#endif
} //----- Fin de Command (constructeur de copie)


Command::Command ( const CommandCode& c, const StringList& p ) : cmdCode(c), params(p)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- Fin de Command


Command::~Command ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- Fin de ~Command


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
