/*************************************************************************
                           Application  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>
#include <string>

#include "../geometry/Object.h"
#include "../managers/FileManager.h"
#include "../managers/CommandManager.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// R�le de la classe <Application>
//
//
//------------------------------------------------------------------------ 

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	int Run( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
    Application & operator = ( const Application & unApplication );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Application ( const Application & unApplication );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Application ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Application ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es
	void takeParams( StringList& params, std::string& stringParams ) const;
	void execute( const Command& cmd ) const;
	void list( ) const;

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
	Figure figure;
	FileManager fileManager;
	CommandManager commandManager;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Application>

#endif // APPLICATION_H
