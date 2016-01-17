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
//-------- Execution générale
	void takeParams( StringList& params ) const;
	// Mode d'emploi :	Ajoute les parametres rentres sur l'entree standard dans la liste
	//					de parametres params (ajout par la fin).

	void execute( const Command& cmd ) const;
	// Mode d'emploi :	Execute la commande cmd.

	void list( ) const;
	// Mode d'emploi :	Affiche toutes les formes géometrique de la Figure figure.

//-------- Actions spécifiques
	void addSegment( std::string name, Point p1, Point p2 );
	void addRectangle( std::string name, Point p1, Point p2 );
	void addPolygone( std::string name, StringList points );
	void addUnion( std::string name, StringList componentsNames );
	void addIntersection( std::string name, StringList componentsNames );
	void hit( std::string name, Point p );
	void move( std::string name, Point p );
	void deleteObjects( StringList componentsNames );

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
