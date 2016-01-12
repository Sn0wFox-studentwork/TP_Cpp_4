/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes
const string ERR_STRING = "ERR";
const string OK_STRING = "OK";

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int Application::Run( )
// Algorithme :
// TODO : tronche des fins de ligne ?
// TODO : il y a de la redondance, il faudrait la supprimer
{
	// Variables de traitement des commandes
	string stringCode;
	CommandCode code;
	string params;
	StringList paramsList;
	Command* cmd = nullptr;

	// Prise du premier code commande
	cin >> stringCode;

	// Prise des parametres, traitement et attente du prochain code commande
	while ( stringCode != "EXIT" )
	{
		params = "";
		// Traitement du code de commande (NB : switch impossible avec std::string)
		if ( stringCode == "S" )
		{
			code = CommandCode::S;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "R" )
		{
			code = CommandCode::R;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "PC" )
		{
			code = CommandCode::PC;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "OR" )
		{
			code = CommandCode::OR;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do( *cmd );
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "OI" )
		{
			code = CommandCode::OI;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "HIT" )
		{
			code = CommandCode::HIT;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "MOVE" )
		{
			code = CommandCode::MOVE;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "DELETE" )
		{
			code = CommandCode::DELETE;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "CLEAR" )
		{
			code = CommandCode::CLEAR;
			takeParams( paramsList, params );
			cmd = new Command( code, paramsList );
			commandManager.Do(*cmd);
			// Appelle methode adequate
			delete cmd;
		}
		else if ( stringCode == "LIST" )
		{
			code = CommandCode::UNSAVEABLE;
			list();
		}
		else if ( stringCode == "UNDO" )
		{
			code = CommandCode::UNSAVEABLE;
			cmd = new Command( commandManager.Undo( ) );
			execute( *cmd );
			delete cmd;
		}
		else if ( stringCode == "REDO" )
		{
			code = CommandCode::UNSAVEABLE;
			cmd = new Command( commandManager.Redo( ) );
			execute( *cmd );
			delete cmd;
		}
		else if ( stringCode == "LOAD" )
		{
			code = CommandCode::UNSAVEABLE;
			cin >> params;
			fileManager.Load( params );
			// TODO : que fait-on si on charge un modele en plein millieu de l'edition d'un autre ?
		}
		else if ( stringCode == "SAVE" )
		{
			code = CommandCode::UNSAVEABLE;
			cin >> params;
			fileManager.Save( params, figure );
		}
		else
		{
			cout << ERR_STRING << endl << "#Unknown command" << endl;
		}
		// NB : cas du "EXIT" traite par le while


		// Attente du prochain code de commande
		cin >> stringCode;

	}	//----- Fin de while(stringCode != "EXIT")

	return 0;
}	//----- Fin de Run

//------------------------------------------------- Surcharge d'opérateurs
Application & Application::operator = ( const Application & uneApplication )
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


Application::Application( ) : figure()
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
} //----- Fin de ~Application

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Application::takeParams( StringList & params, std::string & stringParams ) const
{
	getline( cin, stringParams );
	while ( !stringParams.empty( ) )
	{
		// TODO : pas tout a fait non, mais l'idee est la
		size_t lim = stringParams.find( " " );
		if ( lim == string::npos ) lim = 0;
		params.push_back( stringParams.substr( 0, lim ) );
		stringParams = stringParams.substr( lim, stringParams.size( ) - lim );
	}
}

void Application::execute( const Command & cmd ) const
{
	// TODO : implementer cette methode (switch + appelle bonne fonction)
}

void Application::list( ) const
{
	// TODO : implementer cette methode
}


//------------------------------------------------------- Méthodes privées
