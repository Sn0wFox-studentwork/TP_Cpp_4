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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int CommandManager::Do ( const ReversableCommand& cmd )
// Algorithme :	On vide la pile des commandes annulees si elle n'est pas vide,
//				puis on empile la commande cmd sur la pile des actions effectuees si cmd s'execute correctement,
//				et on ajoute 1 en tete de la liste numberToUndo pour se souvenir que lors d'un
//				Undo( ), une seule commande devra etre annulee.
//				On retourne la valeur retournee par l'execution de la commande.
{
	int returnCode = 0;
	if ( Redoable( ) )
	{
		clearRedoStack( );
	}
	if ( !( returnCode = cmd.Execute( ) ) )		// On ne push sur la pile que si la commande s'est deroulee normalement
	{
		undoStack.push( cmd.Clone( ) );
		numberToUndo.push_front(1);
	}
	return returnCode;
}	//----- Fin de Do

int CommandManager::Do( const vector<ReversableCommand*>& cmds )
// Algorithme :	On vide la pile des commandes annulees si elle n'est pas vide.
//				Pour chaque commande de cmds, on la clone et on tente de l'executer.
//					Si l'execution reussie, on incremente le compteur de commandes reussies,
//					et on empile la commande sur la pile des actions effectuees.
//					On ajoute le code de retour de l'execution a la valeur de retour de la methode.
//					Si un seule des commandes ne s'execute pas correctement, on annule toutes les modifications :
//					on appelle Undo( ) et efface les traces de son appel (depile redoStack
//					et suppression en tete de numberToRedo).
//				Si toutes les commandes se sont executees correctement, on ajoute en tete de la liste
//				numberToUndo le nombre total de commandes pour pouvoir eventuellement les annuler
//				d'un seul coup.
//				On retourne la somme des codes de retour de l'execution des commandes.
{
	int returnCode = 0;		// Code de retour de la methode
	int nbRetourOK = 0;		// Nombre de commandes s'etant executees correctement
	if ( Redoable( ) )
	{
		clearRedoStack( );
	}
	for ( nbRetourOK = 0; nbRetourOK < cmds.size( ); nbRetourOK++ )
	{
		ReversableCommand* cmdClone = cmds[nbRetourOK]->Clone( );
		if ( !cmds[nbRetourOK]->Execute( ) )		// On ne push sur la pile que si la commande s'est deroulee normalement
		{
			undoStack.push( cmdClone );
		}
		else
		{
			delete cmdClone;
			if ( nbRetourOK )	// Annulation des commandes deja executees
			{
				numberToUndo.push_front( nbRetourOK );
				Undo( );
				for ( int i = 0; i < nbRetourOK; i++ )
				{
					ReversableCommand* cmd = redoStack.top( );
					redoStack.pop( );
					delete cmd;
				}
				numberToRedo.pop_front( );
			}
			return -1;
		}
	}
	numberToUndo.push_front( cmds.size( ) );
	return 0;
}

int CommandManager::Undo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes effectuees (= derniere en date) undoStack
//				et on tente d'executer son inverse.
//				On ajoute le code de retour de l'execution a la valeur de retour de la methode.
//				On recommence ces operations autant de fois que le nombre a la tete de la liste numberToUndo,
//				qu'on fini par supprimer une fois toutes les iterations effectuees.
//				On ajoute en tete de la liste numberToRedo le nombre de total de commandes inverseees
//				pour pouvoir eventuellement les repeter d'un seul coup.
//				On retourne la somme des codes de retour de l'execution des commandes inverses.
{
	int returnCode = 0;		// Code de retour de la methode

	for ( int i = 0; i < *numberToUndo.begin( ); i++ )
	{
		ReversableCommand* c = undoStack.top( );	// Acces au premier element
		undoStack.pop( );							// Suppression du premier element
		ReversableCommand* cReverse = c->GetInversedCommand( );
		redoStack.push( c );
		returnCode += cReverse->Execute( );
		delete cReverse;							// On doit desallouer la commande inverse
	}
	numberToRedo.push_front( *numberToUndo.begin( ) );
	numberToUndo.pop_front( );
	return returnCode;
}	//----- Fin de Undo

int CommandManager::Redo ( )
// Algorithme :	On depile la commande au sommet de la pile des commandes annulees (= derniere annulee en date) redoStack
//				et on tente de l'executer.
//				On ajoute le code de retour de l'execution a la valeur de retour de la methode.
//				On recommence ces operations autant de fois que le nombre a la tete de la liste numberToRedo,
//				qu'on fini par supprimer une fois toutes les iterations effectuees.
//				On ajoute en tete de la liste numberToUndo le nombre de total de commandes
//				pour pouvoir eventuellement les repeter d'un seul coup.
//				On retourne la somme des codes de retour de l'execution des commandes inverses.
{
	int returnCode = 0;		// Code de retour de la methode

	for ( int i = 0; i < *numberToRedo.begin( ); i++ )
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
		clearRedoStack( );
		clearUndoStack( );
        undoStack = aCommandManager.undoStack;
        redoStack = aCommandManager.redoStack;
		numberToUndo = aCommandManager.numberToUndo;
		numberToRedo = aCommandManager.numberToRedo;
    }
    return *this;
}    //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CommandManager::CommandManager ( const CommandManager & aCommandManager ) :
        undoStack( aCommandManager.undoStack ), redoStack( aCommandManager.redoStack ),
		numberToUndo( aCommandManager.numberToUndo ), numberToRedo( aCommandManager.numberToRedo )
// Algorithme :	Utilisation du constructeurs de copie de CommandStack (std::stack<Command>) et list<int>.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CommandManager>" << endl;
#endif
}    //----- Fin de CommandManager (constructeur de copie)


CommandManager::CommandManager ( ) : undoStack( ), redoStack( ), numberToUndo( ), numberToRedo( )
// Algorithme :	Instanciation d'un objet par instanciation de deux piles de commandes vides et deux listes d'entiers vides.
{
#ifdef MAP
    cout << "Appel au constructeur de <CommandManager>" << endl;
#endif
}    //----- Fin de CommandManager


CommandManager::~CommandManager ( )
// Algorithme : Supression de l'objet et liberation de la memoire associee.
{
	clearRedoStack( );
	clearUndoStack( );
#ifdef MAP
    cout << "Appel au destructeur de <CommandManager>" << endl;
#endif
    // Pas d'allocation dynamique
}	//----- Fin de ~CommandManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CommandManager::clearRedoStack( )
// Algorithme :	On vide redoStack et on libere la memoire associee a chaque element.
{
	while ( !redoStack.empty( ) )
	{
		delete redoStack.top( );
		redoStack.pop( );
	}
	numberToRedo.clear( );
}	//----- Fin de clearRedoStack

void CommandManager::clearUndoStack( )
// Algorithme :	On vide undoStack et on libere la memoire associee a chaque element.
{
	while ( !undoStack.empty( ) )
	{
		delete undoStack.top( );
		undoStack.pop( );
	}
	numberToUndo.clear( );
}	//----- Fin de clearRedoStack
