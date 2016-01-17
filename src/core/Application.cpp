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
	CommandCode code;
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
			cout << "Tentative ajout segment" << endl;
			takeParams( paramsList );
			cout << "params pris :";
			for (int i = 0; i < paramsList.size(); i++)
			{
				cout << " " << paramsList[i];
			}
			cout << endl;
			cmd = new AddSegmentCommand( paramsList, &figure );
			for (int i = 0; i < cmd->GetParams().size(); i++)
			{
				cout << " " << cmd->GetParams()[i];
			}
			cout << "commande cree" << endl;
			commandManager.Do(cmd);
			cout << "commande executee" << endl;
			history.push_back(cmd);
			cout << "commande stockee" << endl;
			
		}
		/*else if ( stringCode == "R" )
		{
			code = CommandCode::R;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "PC" )
		{
			code = CommandCode::PC;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "OR" )
		{
			code = CommandCode::OR;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "OI" )
		{
			code = CommandCode::OI;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			takeParams( paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "HIT" )
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
			commandManager.Do(cmd);
			history.push_back(cmd);
		}
		/*else if ( stringCode == "DELETE" )
		{
			code = CommandCode::DELETE;
			takeParams( paramsList );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "CLEAR" )
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
		}
		// NB : cas du "EXIT" traite par le while


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
{
	string stringParams;
	getline( cin, stringParams );
	stringParams = stringParams.substr(1, stringParams.size());
	while ( !stringParams.empty( ) )
	{
		// TODO : pas tout a fait non, mais l'idee est la
		size_t lim = stringParams.find( " " );
		if ( lim == string::npos )
		{
			cout << "pas trouve" << endl;
			params.push_back(stringParams);
			break;
		}
		cout << "lim : " << lim << ends;
		cout << "on va push : " << "--" << stringParams.substr(0, lim) << "--" << endl;
		params.push_back( stringParams.substr( 0, lim ) );
		cout << "la string va valoir : " << stringParams.substr(lim+1, stringParams.size() - lim-1) << endl;
		stringParams = stringParams.substr( lim + 1, stringParams.size( ) - lim - 1 );
	}
	cout << "TOTAL PARAMS :";
	for (int i = 0; i < params.size(); i++)
	{
		cout << " " << params[i];
	}
	cout << endl;
}

void Application::execute ( const Command & cmd ) const
{
    // TODO : implementer cette methode (switch + appelle bonne fonction)
}

void Application::list ( ) const
{
	for (ConstFigureIterator fi = figure.begin(); fi != figure.end(); fi++)
	{
		cout << fi->first << " : ";
		fi->second->Print( );
	}
}


//------------------------------------------------------- Méthodes privées
