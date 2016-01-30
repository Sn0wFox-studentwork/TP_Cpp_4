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

using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "../commands/MoveCommand.h"
#include "../commands/AddSegmentCommand.h"
#include "../commands/AddRectangleCommand.h"
#include "../commands/AddPolygonCommand.h"
#include "../commands/AddIntersectionCommand.h"
#include "../commands/AddUnionCommand.h"

//------------------------------------------------------------- Constantes
const string ERR_STRING = "ERR";
const string OK_STRING = "OK";
const string YES_STRING = "YES";
const string NO_STRING = "NO";

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
			AddSegmentCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
		}
		else if ( stringCode == "R" )
		{
			takeParams( paramsList );
			AddRectangleCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
		}
		else if ( stringCode == "PC" )
		{
			takeParams( paramsList );
			AddPolygonCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
			if ( returnCode == -2 )
			{
				cout << ERR_STRING << endl << "#Polygon is not convex" << endl;
			}
		}
		else if ( stringCode == "OR" )
		{
			takeParams( paramsList );
			AddUnionCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
		}
		else if ( stringCode == "OI" )
		{
			takeParams( paramsList );
			AddIntersectionCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
		}
		else if ( stringCode == "HIT" )
		{
			takeParams( paramsList );
			if ( figure.count( paramsList[0] ) == 1 )
			{
				if (	figure[paramsList[0]]->Contains(
						Point( atoi( paramsList[1].c_str( ) ), atoi( paramsList[2].c_str( ) ) ) ) )
				{
					returnCode = 1;
					cout << YES_STRING << endl;
				}
				else
				{
					cout << NO_STRING << endl;
				}
			}
			else
			{
				cout << ERR_STRING << endl << "#" << paramsList[0] << " doesn't exist as Object" << endl;
			}
		}
		else if ( stringCode == "MOVE" )
		{
			takeParams( paramsList );
			MoveCommand cmd( paramsList, &figure );
			returnCode = commandManager.Do( cmd );
		}
		else if ( stringCode == "DELETE" )
		{
			// TODO : optimiser ca
			takeParams( paramsList );
			vector<ReversableCommand*> vec;
			for ( string& s : paramsList )
			{
				StringList sl;
				sl.push_back(s);
				ReversableCommand* cmd = new DeleteCommand( sl, &figure );
				vec.push_back( cmd );
			}
			returnCode = commandManager.Do( vec );
			// Si une seule des commandes de supression s'est mal passe, on annule la supression
			if ( returnCode )
			{
				commandManager.Undo( );
				cout << ERR_STRING << endl << "#A parameter doesn't exist as Object" << endl;
			}
			for ( ReversableCommand* cmd : vec )
			{
				delete cmd;
			}
		}
		else if ( stringCode == "CLEAR" )
		{
			vector<ReversableCommand*> vec;
			for ( ConstFigureIterator cfi = figure.begin( ); cfi != figure.end( ); cfi++ )
			{
				StringList sl;
				sl.push_back( cfi->first );
				ReversableCommand* cmd = new DeleteCommand( sl, &figure );
				vec.push_back( cmd );
			}
			returnCode = commandManager.Do( vec );
			for ( ReversableCommand* cmd : vec )
			{
				delete cmd;
			}
		}
		else if ( stringCode == "LIST" )
		{
			list( );
			returnCode = 0;
		}
		else if ( stringCode == "UNDO" )
		{
			if ( commandManager.Undoable( ) )
			{
				commandManager.Undo( );
				returnCode = 0;
			}
			else
			{
				cout << ERR_STRING << endl << "#No action to undo" << endl;
				returnCode = -1;
			}
		}
		else if ( stringCode == "REDO" )
		{
			if ( commandManager.Redoable( ) )
			{
				commandManager.Redo( );
				returnCode = 0;
			}
			else
			{
				cout << ERR_STRING << endl << "#No action to redo" << endl;
				returnCode = -1;
			}
		}
		else if ( stringCode == "LOAD" )
		{
			string s;
			cin >> s;
			returnCode = fileManager.Load(s, &figure, commandManager);
		}
		/*else if ( stringCode == "SAVE" )
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
		if ( !returnCode && returnCode != 1 )
		{
			cout << OK_STRING << endl;
		}

		// Attente du prochain code de commande
		cin >> stringCode;
	
	}	//----- Fin de while(stringCode != "EXIT")
	
	return 0;
}	//----- Fin de Run

//------------------------------------------------- Surcharge d'opérateurs
Application & Application::operator= ( const Application & uneApplication )
// Algorithme :	Si on n'est pas en train de faire uneApplication = uneApplication, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de uneApplication
{
	for ( ConstFigureIterator cfi = figure.begin( ); cfi != figure.end( ); cfi++ )
	{
		delete cfi->second;
	}
	figure = uneApplication.figure;
	fileManager = uneApplication.fileManager;
	commandManager = uneApplication.commandManager;

    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & unApplication ) :
	figure( unApplication.figure ), fileManager( unApplication.fileManager ), commandManager( unApplication.commandManager )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
}	//----- Fin de Application (constructeur de copie)


Application::Application ( ) : figure( ), fileManager( ), commandManager( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
}	//----- Fin de Application


Application::~Application ( )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
	for ( ConstFigureIterator cfi = figure.begin( ); cfi != figure.end( ); cfi++ )
	{
		delete cfi->second;
	}
}	//----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Application::takeParams( StringList & params ) const
// Algorithme :
{
	string stringParams;
	getline( cin, stringParams );
	stringParams = stringParams.substr( 1, stringParams.size( ) );
	while ( !stringParams.empty( ) )
	{
		size_t lim = stringParams.find( " " );
		if ( lim == string::npos )
		{
			params.push_back( stringParams );
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
		cout << endl;
	}
}

//------------------------------------------------------- Méthodes privées
