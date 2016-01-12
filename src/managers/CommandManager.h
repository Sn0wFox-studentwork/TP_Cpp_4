/*************************************************************************
                           CommandManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <CommandManager> (fichier CommandManager.h) ------
#if ! defined ( COMMAND_MANAGER_H )
#define COMMAND_MANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "Command.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::stack<Command> CommandStack;

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandManager>
//
//
//------------------------------------------------------------------------ 

class CommandManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Do ( const Command& cmd );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Command Undo ( );
	// Mode d'emploi :
	//
	// Contrat :		La pile undoStack ne doit pas etre vide.
	//

	Command Redo ( );
	// Mode d'emploi :
	//
	// Contrat :		La pile redoStack ne doit pas etre vide.
	//

	bool Undoable ( ) const;
	// Mode d'emploi :	Renvoie false si et seulement si la pile undoStack est vide, true sinon.
	//
	// Contrat :
	//

	bool Redoable ( ) const;
	// Mode d'emploi :	Renvoie false si et seulement si la pile redoStack est vide, true sinon.
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
    CommandManager & operator = ( const CommandManager & unCommandManager );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CommandManager ( const CommandManager & unCommandManager );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CommandManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CommandManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	CommandStack undoStack;		// La pile des actions effectuees et annulables
	CommandStack redoStack;		// La pile des actions annulees (et donc refaisable)

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CommandManager>

#endif // COMMAND_MANAGER_H
