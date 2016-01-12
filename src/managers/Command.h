/*************************************************************************
Command  -  description
-------------------
début                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H )
#define COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef enum CommandCode
// Cette enumeration liste toutes les commandes inversibles possibles
{
	UNSAVEABLE, S, R, PC, OR, OI, HIT, DELETE, CLEAR, MOVE
} CommandCode;

typedef std::list<std::string> StringList;

//------------------------------------------------------------------------ 
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------ 

class Command
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	Command GetInversedCommand( ) const;
	// Mode d'emploi : retourne la commande annulant la commande courante.
	//
	// Contrat :
	//

	CommandCode GetCmdCode( ) const
	{
		return cmdCode;
	}

	StringList GetParams( ) const
	{
		return params;
	}

	//------------------------------------------------- Surcharge d'opérateurs
	Command & operator = ( const Command & unCommand );
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Command( const Command & unCommand );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Command( const CommandCode& cmdCode, const StringList& params );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Command();
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
	CommandCode cmdCode;
	StringList params;

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Command>

#endif // COMMAND_H
