/*************************************************************************
Command  -  description
-------------------
d�but                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H )
#define COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <Command>
//
//
//------------------------------------------------------------------------ 

class Command
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
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

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	CommandCode cmdCode;
	StringList params;

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Command>

#endif // COMMAND_H
