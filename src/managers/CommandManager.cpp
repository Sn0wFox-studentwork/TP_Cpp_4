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
// Algorithme :	On vide la pile des commandes annulees si elle n'est pas vide,
//				puis on empile la commande cmd sur la pile des actions effectuees.
{
	if ( Redoable( ) )
	{
		clearRedoStack( );
	}
	undoStack.push( cmd );
}	//----- Fin de Do

Command CommandManager::Undo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes effectuees (= derniere en date)
//				et on l'empile sur la pile des commandes annulees.
//				Retourne l'inverse de la commande depilee.
{
	Command c = undoStack.top( );	// Acces au premier element
	undoStack.pop( );				// Suppression du premier element
	redoStack.push( c );
	return c.GetInversedCommand( );
}	//----- Fin de Undo

Command CommandManager::Redo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes annulees (= derniere annulee en date)
//				et on l'empile sur la pile des commandes effectuees.
//				Retour de cette meme commande.
{
	Command c = redoStack.top( );	// Acces au premier element
	undoStack.pop( );				// Suppression du premier element
	undoStack.push( c );
	return c;
}	//----- Fin de Redo

bool CommandManager::Undoable ( ) const
// Algorithme :	Retourne vrai si la pile des commandes effectuees est vide, faux sinon.
{
	return undoStack.empty( );
}	//----- Fin de Undoable

bool CommandManager::Redoable ( ) const
// Algorithme :	Retourne vrai si la pile des commandes annulees est vide, faux sinon.
{
	return redoStack.empty( );
}	//----- Fin de Redoable


//------------------------------------------------- Surcharge d'opérateurs
CommandManager & CommandManager::operator = ( const CommandManager & aCommandManager )
// Algorithme :	Si on n'est pas en train de faire aCommandManager = aCommandManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aCommandManager.
{
	if ( this != &aCommandManager )
	{
		undoStack = aCommandManager.undoStack;
		redoStack = aCommandManager.redoStack;
	}
	return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandManager::CommandManager ( const CommandManager & aCommandManager ) :
	undoStack( aCommandManager.undoStack ), redoStack( aCommandManager.redoStack )
// Algorithme :	Utilisation du constructeurs de copie de CommandStack (std::stack<Command>).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandManager>" << endl;
#endif
}	//----- Fin de CommandManager (constructeur de copie)


CommandManager::CommandManager ( ) : undoStack(), redoStack()
// Algorithme :	Instanciation d'un objet par instanciation de deux piles de commandes vides.
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandManager>" << endl;
#endif
}	//----- Fin de CommandManager


CommandManager::~CommandManager ( )
// Algorithme : Supression de l'objet et liberation de la memoire associee.
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandManager>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~CommandManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CommandManager::clearRedoStack( )
// Algorithme :	Vidage de la pile des actions a refaire par reaffectation d'une pile vide.
{
	redoStack = CommandStack( );
}	//----- Fin de clearRedoStack

//------------------------------------------------------- Méthodes privées
