/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if !defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <list>

#include "../geometry/Object.h"
#include "../managers/FileManager.h"
#include "../managers/CommandManager.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::list<ReversableCommand*> ListCommand;
typedef ListCommand::iterator ListCmdIterator;
typedef ListCommand::const_iterator ConstListCmdIterator;

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

    int Run ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Application & operator= ( const Application & unApplication );
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
private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Figure figure;					// L'ensemble des formes geometriques
	FileManager fileManager;		// Permet de sauvegarder/charger une figure
	CommandManager commandManager;	// Permet la mise en place de annuler/repeter
	ListCommand history;			// L'historique des commandes utilisees

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Application>

#endif // APPLICATION_H
