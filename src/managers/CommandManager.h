/*************************************************************************
                           CommandManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <CommandManager> (fichier CommandManager.h) ------
#if !defined ( COMMAND_MANAGER_H )
#define COMMAND_MANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>
#include <list>

#include "../commands/Command.h"
#include "../commands/ReversableCommand.h"

//------------------------------------------------------------------ Types
typedef std::stack<ReversableCommand*> CommandStack;

//------------------------------------------------------------------------ 
// Rôle de la classe <CommandManager>
// CommandManager permet d'executer les commandes qu'on lui donne.
// Elles peuvent lui etre passee une par une ou par paquets.
// CommandManager possede l'historique des commandes, et permet egalement
// d'annuler les commandes effectuees, ou au contraire de repeter les
// commandes annulees. Les commandes passees dans le meme paquet seront
// annulees et repetees en tant qu'une seule action.
// Si une commande est executee apres une annulation, alors la/les
// commande(s) annulee(s) ne seront plus repetables.
// Il n'y a pas de limite sur le nombre de commandes annulables.
//------------------------------------------------------------------------ 

class CommandManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	int Do ( const ReversableCommand& cmd );
	// Mode d'emploi :	Empile la commande cmd sur undoStack.
	//					Vide la pile des commandes annulees redoStack si elle n'est pas vide.
	//					Execute la commande cmd.
	//					Retourne :	0 si tout c'est bien passe.
	//								le code d'erreur retourne par l'execution de la commande sinon, qui sera negatif.

	int Do ( const vector<ReversableCommand*>& cmds );
	// Mode d'emploi :	Tente d'executer toutes les commandes de cmds.
	//					Vide la pile des commandes annulees redoStack si elle n'est pas vide.
	//					Si cmds est vide, ne fait rien.
	//					Si cmds ne contient qu'une commande, est equivalent a l'appel de Do(ReversableCommand*).
	//					Empile les commandes de cmds sur redoStack uniquement si toutes ont pu s'executer correctement.
	//					Sinon, aucun des changements ne sera pris en compte.
	//					Retourne :	0 si toutes les commandes ont etes effectuees avec succes.
	//								-1 sinon.
	// Contrat :	La desallocation eventuelle des commandes de cmds reste a la charge de l'utilisateur.
	//				L'integrite de la figure manipulee par les commandes ne doit pas avoir ete compromise.

	int Undo ( );
	// Mode d'emploi :	Depile undoStack autant de fois que l'entier contenu a la tete de numberToUndo,
	//					et tente d'executer l'inverse de chaque commande depilee.
	//					Empile les commandes non inverseees sur redoStack.
	//					Retourne la somme des retours de l'execution des commandes inversees. Comme ces retours sont negatifs
	//					ou nuls, cela correspond a :
	//						0 si toutes les commandes inverses ont etes effectuees avec succes.
	//						Un entier negatif sinon, somme des codes de retour de l'execution des commandes inversees.
	// Contrat :	La pile undoStack ne doit pas etre vide.
	//				L'integrite de la figure manipulee par les commandes ne doit pas avoir ete compromise.

	int Redo ( );
	// Mode d'emploi :	Depile redoStack autant de fois que l'entier contenu a la tete de numberToRedo,
	//					et tente d'executer la commande depilee.
	//					Empile les commandes sur undoStack.
	//					Retourne la somme des retours de l'execution des commandes. Comme ces retours sont negatifs
	//					ou nuls, cela correspond a :
	//						0 si toutes les commandes inverses ont etes effectuees avec succes.
	//						Un entier negatif sinon, somme des codes de retour de l'execution des commandes inversees.
	// Contrat :		La pile redoStack ne doit pas etre vide.

    bool Undoable ( ) const;
    // Mode d'emploi :	Renvoie false si et seulement si la pile undoStack est vide, true sinon.

    bool Redoable ( ) const;
    // Mode d'emploi :	Renvoie false si et seulement si la pile redoStack est vide, true sinon.

//------------------------------------------------- Surcharge d'opérateurs
    CommandManager & operator= ( const CommandManager & aCommandManager );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a aCommandManager. Tout les attributs seront copies.

//-------------------------------------------- Constructeurs - destructeur
    CommandManager ( const CommandManager & aCommandManager );
    // Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
    //											a aCommandManager. Tout les attributs seront copies.

    CommandManager ( );
    // Mode d'emploi :	Instancie un nouvel objet dont les piles de commandes et les listes d'entiers sont vides.

    virtual ~CommandManager ( );
    // Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
    //					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	void clearRedoStack( );
	// Mode d'emploi :	Vide la pile des commandes annulees redoStack.
	//					Ne fait rien si la pile etait vide.
	//					Nettoie la memoire associee.

	void clearUndoStack( );
	// Mode d'emploi :	Vide la pile des commandes effeectuees undoStack.
	//					Ne fait rien si la pile etait vide.
	//					Nettoie la memoire associee.

protected:
//----------------------------------------------------- Attributs protégés
	CommandStack undoStack;			// La pile des commandes effectuees et annulables
    CommandStack redoStack;			// La pile des commandes annulees (et donc refaisables)
	list<int> numberToUndo;			// Liste le nombre de commandes a annuler d'un seul coup. Part du debut de la pile undoStask
	list<int> numberToRedo;			// Liste le nombre de commandes a repeter d'un seul coup. Part du debut de la pile redoStack

};

#endif // COMMAND_MANAGER_H
