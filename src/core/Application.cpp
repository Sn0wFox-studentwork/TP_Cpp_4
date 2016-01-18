/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "../commands/MoveCommand.h"
#include "../commands/AddSegmentCommand.h"
#include "../commands/AddRectangleCommand.h"
#include "../commands/AddPolygonCommand.h"
#include "../commands/AddIntersectionCommand.h"
#include "../commands/AddUnionCommand.h"
#include "../commands/DeleteCommand.h"

//------------------------------------------------------------- Constantes
const string ERR_STRING = "ERR";
const string OK_STRING = "OK";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int Application::Run ( )
// Algorithme :
// TODO : tronche des fins de ligne ?
// TODO : il y a de la redondance, il faudrait la supprimer
{
	// Variables de traitement des commandes
	string stringCode;
	int returnCode;
	string params;
	StringList paramsList;
	ReversableCommand* cmd = nullptr;

    // Prise du premier code commande
    cin >> stringCode;

	// Prise des parametres, traitement et attente du prochain code commande
	while ( stringCode != "EXIT" )
	{
		paramsList = StringList();
		params = "";
		// Traitement du code de commande (NB : switch impossible avec std::string)
		if ( stringCode == "S" )
		{
			takeParams( paramsList );
			cmd = new AddSegmentCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );			
		}
		else if ( stringCode == "R" )
		{
			takeParams( paramsList );
			cmd = new AddRectangleCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );
		}
		else if ( stringCode == "PC" )
		{
			takeParams( paramsList );
			cmd = new AddPolygonCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );
		}
		else if ( stringCode == "OR" )
		{
			takeParams( paramsList );
			cmd = new AddUnionCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );
		}
		else if ( stringCode == "OI" )
		{
			takeParams( paramsList );
			cmd = new AddIntersectionCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );
		}
		/*else if ( stringCode == "HIT" )
		{
			code = CommandCode::HIT;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}*/
		else if ( stringCode == "MOVE" )
		{
			takeParams( paramsList );
			cmd = new MoveCommand( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			history.push_back( cmd );
		}
		else if ( stringCode == "DELETE" )
		{
			takeParams( paramsList );
			int i = 0;						// Nombre de commandes delete qui se sont correctement deroulees
			for ( string& s : paramsList )
			{
				StringList sl;
				sl.push_back(s);
				cmd = new DeleteCommand( sl, &figure );
				returnCode = commandManager.Do( cmd );
				history.push_back( cmd );
				if ( returnCode )
				{
					break;	// Si une seul des commandes de supression se passe mal, on arrete
				}
				i++;
			}
			// Si une seule des commande de supression s'est mal passe, on annule la supression
			if ( returnCode )
			{
				for ( int j = 0; j < i; j++ )
				{
					commandManager.Undo( );
				}
				cout << ERR_STRING << endl << "#Parameter " << paramsList[i] << " doesn't exist as Object" << endl;
			}
		}
		/*else if ( stringCode == "CLEAR" )
		{
			code = CommandCode::CLEAR;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "LOAD" )
		{
			code = CommandCode::LOAD;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}*/
		else if ( stringCode == "LIST" )
		{
			list();
			returnCode = 0;
		}
		/*else if ( stringCode == "UNDO" )
		{
			code = CommandCode::UNDO;
			cmd = new Command( commandManager.Undo( ) );
			execute( *cmd );
			delete cmd;
		}
		else if ( stringCode == "REDO" )
		{
			code = CommandCode::REDO;
			cmd = new Command( commandManager.Redo( ) );
			execute( *cmd );
			delete cmd;
		}
		else if ( stringCode == "LOAD" )
		{
			code = CommandCode::LOAD;
			cin >> params;
			fileManager.Load( params );
			// TODO : que fait-on si on charge un modele en plein millieu de l'edition d'un autre ?
		}
		else if ( stringCode == "SAVE" )
		{
			code = CommandCode::SAVE;
			cin >> params;
			fileManager.Save( params, figure );
		}*/
		else
		{
			cout << ERR_STRING << endl << "#Unknown command" << endl;
			returnCode = -1;
		}
		// NB : cas du "EXIT" traite par le while

		// TODO : afficher les bons messages
		if ( !returnCode && returnCode != -1 )
		{
			cout << OK_STRING << endl;
		}

		// Attente du prochain code de commande
		cout << "Attente new commande" << endl;
		cin >> stringCode;
	
	}	//----- Fin de while(stringCode != "EXIT")
	
	return 0;
}	//----- Fin de Run

//------------------------------------------------- Surcharge d'opérateurs
Application & Application::operator= ( const Application & uneApplication )
// Algorithme :	Si on n'est pas en train de faire uneApplication = uneApplication, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneApplication
{
    if ( this != &uneApplication )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & unApplication )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
} //----- Fin de Application (constructeur de copie)


Application::Application ( ) : figure( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
} //----- Fin de Application


Application::~Application ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
	for (ConstListCmdIterator cli = history.begin(); cli != history.end(); cli++)
	{
		delete *cli;
	}
} //----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Application::takeParams( StringList & params ) const
// Algorithme :
{
	string stringParams;
	getline( cin, stringParams );
	stringParams = stringParams.substr(1, stringParams.size());
	while ( !stringParams.empty( ) )
	{
		size_t lim = stringParams.find( " " );
		if ( lim == string::npos )
		{
			params.push_back(stringParams);
			break;
		}
		params.push_back( stringParams.substr( 0, lim ) );
		stringParams = stringParams.substr( lim + 1, stringParams.size( ) - lim - 1 );
	}
}

void Application::list ( ) const
// Algorithme :
{
	for ( ConstFigureIterator fi = figure.begin(); fi != figure.end(); fi++ )
	{
		cout << fi->first << " : ";
		fi->second->Print( );
	}
}


//------------------------------------------------------- Méthodes privées
