/*************************************************************************
                           ReversableCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <ReversableCommand> (fichier ReversableCommand.h) ------
#if ! defined ( REVERSABLE_COMMAND_H )
#define REVERSABLE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "Command.h"
#include "../geometry/Object.h"

//------------------------------------------------------------------ Types
typedef std::map<string, Object*> Figure;

//------------------------------------------------------------------------ 
// Rôle de la classe <ReversableCommand>
// Classe abstraite decrivant une commande dont l'execution peut etre
// inversee.
// Permet de mettre en place un comportement de annuler/repeter.
//------------------------------------------------------------------------ 

class ReversableCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual ReversableCommand* GetInversedCommand( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de ReversableCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera ReversableCommand* par HeritedReversableCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual ReversableCommand* Clone( ) const = 0;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    ReversableCommand & operator = ( const ReversableCommand & unReversableCommand );
    // Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unReversableCommand.
	//					Les deux ReversableCommand auront toutes les deux un pointeur vers la meme Figure.
    // Contrat :	La desallocation de cette figure reste a la charge de l'appelant.

//-------------------------------------------- Constructeurs - destructeur
    ReversableCommand ( const ReversableCommand & unReversableCommand );
    // Mode d'emploi (constructeur de copie) :	Construit une reversableCommand a partir de unReversableCommand.
	//											Les deux ReversableCommand auront toutes les deux un pointeur
	//											vers la meme Figure.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.

    ReversableCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :	Construit une reversableCommand a partir des parametres donnes.
	//					La Figure manipulee par la ReversableCommand est celle pointee par f.
	//					Le constructeur ne fera donc qu'un copie de pointeur.
    // Contrat :	La desallocation de f reste a la charge de l'appelant.

    virtual ~ReversableCommand ( );
    // Mode d'emploi :	Detruit l'objet courant et libere la memoire.
	//					Appele automatiquement.
	// Contrat :	La desallocation de figure reste a la charge de l'appelant.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	Figure* figure;		// La figure qui sera manipulee par la commande

};

#endif // REVERSABLE_COMMAND_H
