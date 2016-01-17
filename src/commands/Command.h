/*************************************************************************
						Command  -  description
						   -------------------
	début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if !defined ( COMMAND_H )
#define COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <iostream>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef enum CommandCode
// Cette enumeration liste toutes les commandes inversibles possibles
{
<<<<<<< HEAD:src/commands/Command.h
	NULLCMD, S, R, PC, OR, OI, HIT, DELETE, MOVE, LIST, UNDO, REDO, LOAD, SAVE, CLEAR
=======
		UNSAVEABLE, S, R, PC, OR, OI, HIT, DELETE, CLEAR, LOAD, MOVE
>>>>>>> origin/master:src/managers/Command.h
} CommandCode;

typedef std::vector<std::string> StringList;

//------------------------------------------------------------------------ 
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------ 

class Command
{
		//----------------------------------------------------------------- PUBLIC

public:
<<<<<<< HEAD:src/commands/Command.h
	//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

	inline StringList GetParams( ) const
	// Mode d'emploi :	Retourne la liste des parametres de la commande courante.
	{
		return params;
	}

	//------------------------------------------------- Surcharge d'opérateurs
	Command & operator = ( const Command & aCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point semblable a aCommand.
	//					Retourne l'objet modifie par reference.

	//-------------------------------------------- Constructeurs - destructeur
	Command( const Command & aCommand );
	// Mode d'emploi (constructeur de copie) :	Construit un objet en tout points similaire a aCommand.

	Command( const StringList& params );
	// Mode d'emploi :	Construit une instance de Command.
	//					La commande cree aura comme liste de parametres params (copie).
	// Contrat :	La liste de parametres doit etre complete, car elle ne sera pas modifiable par la suite.

	virtual ~Command( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.
=======
		//----------------------------------------------------- Méthodes publiques
		Command GetInversedCommand ( ) const;
		// Mode d'emploi :	Retourne la commande annulant la commande courante.
		//					Retourne une commande de code UNSAVEABLE avec une liste de parametres
		//					vide de le cas d'une commande non-annulable.

		inline CommandCode GetCmdCode ( ) const
		// Mode d'emploi :	Retourne le code de la commande courante.
		{
			return cmdCode;
		}

		inline StringList GetParams ( ) const
		// Mode d'emploi :	Retourne la liste des parametres de la commande courante.
		{
			return params;
		}

		//------------------------------------------------- Surcharge d'opérateurs
		Command & operator= ( const Command & aCommand );
		// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point semblable a aCommand.
		//					Retourne l'objet modifie par reference.

		friend ostream & operator<< ( ostream & s, Command c );
		// Mode d'emploi :	Insere une representation de l'objet courant sous forme de chaine de caracteres
		//					dans le flux de sortie s.
		//					Retourne le fux ainsi modifie par reference.

		//-------------------------------------------- Constructeurs - destructeur
		Command ( const Command & aCommand );
		// Mode d'emploi (constructeur de copie) :	Construit un objet en tout points similaire a aCommand.

		Command ( const CommandCode & cmdCode, const StringList & params );
		// Mode d'emploi :	Construit une instance de Command.
		//					La commande cree aura pour code de commande cmdCode et comme liste de parametres params (copies).
		// Contrat :	La liste de parametres doit etre complete, car elle ne sera pas modifiable par la suite.
		//				Le code de commande cmdCode doit etre un membre de l'enumeration CommandCode.

		virtual ~Command ( );
		// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
		//					Appele automatiquement.
>>>>>>> origin/master:src/managers/Command.h

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
<<<<<<< HEAD:src/commands/Command.h
	StringList params;
=======
		CommandCode cmdCode;
		StringList params;
>>>>>>> origin/master:src/managers/Command.h

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Command>

#endif // COMMAND_H
