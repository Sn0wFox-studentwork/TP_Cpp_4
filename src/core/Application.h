/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>

#include "../geometry/Object.h"
#include "../managers/FileManager.h"
#include "../managers/CommandManager.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// Rôle de la classe <Application>
//
//
//------------------------------------------------------------------------ 

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	int Run( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées
	void takeParams( StringList& params, std::string& stringParams ) const;
	void execute( const Command& cmd ) const;
	void list( ) const;

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Figure figure;
	FileManager fileManager;
	CommandManager commandManager;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Application>

#endif // APPLICATION_H
