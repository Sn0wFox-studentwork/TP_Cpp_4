/*************************************************************************
                           CommandManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <CommandManager> (fichier CommandManager.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "CommandManager.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int CommandManager::Do ( ReversableCommand* const cmd )
// Algorithme :	On vide la pile des commandes annulees si elle n'est pas vide,
//				puis on empile la commande cmd sur la pile des actions effectuees.
{
	if ( Redoable( ) )
	{
		clearRedoStack( );
	}
	if ( !cmd->Execute( ) )		// On ne push sur la pile que si la commande s'est deroulee normalement
	{
		undoStack.push( cmd );
		numberToUndo.push_front(1);
		return 0;
	}
	return -1;
}	//----- Fin de Do

int CommandManager::Do( const vector<ReversableCommand*>& cmds )
// Algorithme :
// TODO :	Se servir de la methode au dessus !
{
	int ret = 0;
	if ( Redoable( ) )
	{
		clearRedoStack();
	}
	for ( int i = 0; i < cmds.size( ); i++ )
	{
		undoStack.push( cmds[i] );
		ret += cmds[i]->Execute( );
	}
	if( cmds.size( ) != 0 )
	{
		numberToUndo.push_front( cmds.size( ) );
	}
	return ret;
}

int CommandManager::Undo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes effectuees (= derniere en date)
//				et on l'empile sur la pile des commandes annulees.
//				Retourne l'inverse de la commande depilee.
// TODO :	Et si la commande inverse se passe mal ?
{
	int returnCode = 0;
	for ( int i = 0; i < *numberToUndo.begin( ); i++ )
	{
		ReversableCommand* c = undoStack.top( );	// Acces au premier element
		undoStack.pop( );							// Suppression du premier element
		redoStack.push( c );
		ReversableCommand* cReverse = c->GetInversedCommand( );
		returnCode += cReverse->Execute( );
		delete cReverse;							// On doit desallouer la commande inverse !
	}
	numberToRedo.push_front( *numberToUndo.begin( ) );
	numberToUndo.pop_front( );
	return returnCode;
}	//----- Fin de Undo

int CommandManager::Redo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes annulees (= derniere annulee en date)
//				et on l'empile sur la pile des commandes effectuees.
//				Retour de cette meme commande.
// TODO :	Et si la commande se passe mal ?
{
	int nbToRedo = 0;
	int returnCode = 0;
	if ( !numberToRedo.empty( ) )
	{
		nbToRedo = *numberToRedo.begin( );
	}
	for ( int i = 0; i < nbToRedo; i++ )
	{
		ReversableCommand* c = redoStack.top( );	// Acces au premier element
		redoStack.pop( );							// Suppression du premier element
		undoStack.push( c );
		returnCode += c->Execute( );
	}
	numberToUndo.push_front( *numberToRedo.begin( ) );
	numberToRedo.pop_front( );
	return returnCode;
}	//----- Fin de Redo

bool CommandManager::Undoable ( ) const
// Algorithme :	Retourne vrai si la pile des commandes effectuees n'est pas vide, faux sinon.
{
    return !undoStack.empty( );
}    //----- Fin de Undoable

bool CommandManager::Redoable ( ) const
// Algorithme :	Retourne vrai si la pile des commandes annulees n'est pas vide, faux sinon.
{
    return !redoStack.empty( );
}    //----- Fin de Redoable


//------------------------------------------------- Surcharge d'opérateurs
CommandManager & CommandManager::operator= ( const CommandManager & aCommandManager )
// Algorithme :	Si on n'est pas en train de faire aCommandManager = aCommandManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aCommandManager.
{
    if ( this != &aCommandManager )
    {
        undoStack = aCommandManager.undoStack;
        redoStack = aCommandManager.redoStack;
		numberToUndo = aCommandManager.numberToUndo;	// TODO : suffisant ?
    }
    return *this;
}    //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandManager::CommandManager ( const CommandManager & aCommandManager ) :
        undoStack( aCommandManager.undoStack ), redoStack( aCommandManager.redoStack ),
		numberToUndo( aCommandManager.numberToUndo )
// Algorithme :	Utilisation du constructeurs de copie de CommandStack (std::stack<Command>).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandManager>" << endl;
#endif
}    //----- Fin de CommandManager (constructeur de copie)


CommandManager::CommandManager ( ) : undoStack( ), redoStack( ), numberToUndo( )
// Algorithme :	Instanciation d'un objet par instanciation de deux piles de commandes vides.
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandManager>" << endl;
#endif
}    //----- Fin de CommandManager


CommandManager::~CommandManager ( )
// Algorithme : Supression de l'objet et liberation de la memoire associee.
{
#ifdef MAP
    cout << "Appel au destructeur de <CommandManager>" << endl;
#endif
    // Pas d'allocation dynamique
}    //----- Fin de ~CommandManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CommandManager::clearRedoStack( )
// Algorithme :	Nettoyage de la pile redoStack par reaffectation d'une pile vide.
{
	redoStack = CommandStack();		// Pour le moment, l'application conserve les pointeurs des commandes crees,
									// et les detruit avec elle ; il n'y a donc pas de probleme.
	numberToRedo.clear( );
}	//----- Fin de clearRedoStack

//------------------------------------------------------- Méthodes privées
