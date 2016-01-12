/*************************************************************************
                           CommandManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <CommandManager> (fichier CommandManager.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandManager.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void CommandManager::Do ( const Command& cmd )
// Algorithme :
{
	undoStack.push( cmd );
}	//----- Fin de Do

Command CommandManager::Undo ( )
// Algorithme :
// TODO : passage par reference dans le push ?
{
	Command c = undoStack.top();	// Acces au premier element
	undoStack.pop();				// Suppression du premier element
	redoStack.push(c);
	return c.GetInversedCommand();
}	//----- Fin de Undo

Command CommandManager::Redo ( )
// Algorithme :
{
	Command c = redoStack.top();	// Acces au premier element
	undoStack.pop();				// Suppression du premier element
	undoStack.push(c);
	return c;
}	//----- Fin de Redo

bool CommandManager::Undoable ( ) const
// Algorithme :
{
	return undoStack.empty();
}	//----- Fin de Undoable

bool CommandManager::Redoable ( ) const
// Algorithme :
{
	return redoStack.empty();
}	//----- Fin de Redoable


//------------------------------------------------- Surcharge d'opérateurs
CommandManager & CommandManager::operator = ( const CommandManager & unCommandManager )
// Algorithme :	Si on n'est pas en train de faire unCommandManager = unCommandManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unCommandManager
{
	if ( this != &unCommandManager )
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandManager::CommandManager ( const CommandManager & unCommandManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandManager>" << endl;
#endif
} //----- Fin de CommandManager (constructeur de copie)


CommandManager::CommandManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandManager>" << endl;
#endif
} //----- Fin de CommandManager


CommandManager::~CommandManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandManager>" << endl;
#endif
} //----- Fin de ~CommandManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
