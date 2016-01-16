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
	// Mode d'emploi :	Empile la commande cmd sur undoStack.
	//					Vide la pile des commandes annulees redoStack si elle n'est pas vide.

	Command Undo ( );
	// Mode d'emploi :	Depile undoStack et empile la commande sur redoStack.
	//					Retourne l'inverse de la commande depilee.
	// Contrat :		La pile undoStack ne doit pas etre vide.

	Command Redo ( );
	// Mode d'emploi :	Depile redoStack et empile la commande sur undoStack.
	//					Retourne la commande depilee.
	// Contrat :		La pile redoStack ne doit pas etre vide.

	bool Undoable ( ) const;
	// Mode d'emploi :	Renvoie false si et seulement si la pile undoStack est vide, true sinon.

	bool Redoable ( ) const;
	// Mode d'emploi :	Renvoie false si et seulement si la pile redoStack est vide, true sinon.

//------------------------------------------------- Surcharge d'opérateurs
    CommandManager & operator = ( const CommandManager & aCommandManager );
    // Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a aCommandManager.

//-------------------------------------------- Constructeurs - destructeur
    CommandManager ( const CommandManager & aCommandManager );
    // Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a aCommandManager.

    CommandManager ( );
    // Mode d'emploi :	Instancie un nouvel objet dont les piles de commandes sont vides.

    virtual ~CommandManager ( );
    // Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	void clearRedoStack();
	// Mode d'emploi :	Vide la pile des commandes annulees redoStack.

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	CommandStack undoStack;		// La pile des commandes effectuees et annulables
	CommandStack redoStack;		// La pile des commandes annulees (et donc refaisables)

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CommandManager>

#endif // COMMAND_MANAGER_H
