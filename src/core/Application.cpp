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
#include <algorithm>

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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Application::Run ( )
// Algorithme :	Prise du premier mot (=suite de caracteres avant un espace ou un retour a la ligne).
//				Il est range dans la variable qui contiendra toujours le premier mot d'une ligne,
//				et qui correspond a un code de commande (connu ou nom, c'est ainsi qu'il sera interprete).
//				Tant que l'utilisateur ne rentre pas la chaine "EXIT" :
//					On lit le reste de la ligne rentree et on la convertie en StringList via takeParams.
//					Suivant la valeur du code de la commande :
//					S'il est connu, on cree la commande ou le groupement de commandes associe et on tente
//					de l'executer. Si l'execution est positive, on affiche "OK".
//					Sinon, on affiche "ERR" suivi d'une autre ligne commencant par un #. Cette ligne donne quelques
//					informations sur la nature du probleme rencontre.
//				On retourne 0.
{
	// Variables de traitement des commandes
	string stringCode = "";
	int returnCode;
	StringList paramsList;

    // Prise du premier code commande
    cin >> stringCode;

	// Prise des parametres, traitement et attente du prochain code commande
	while ( stringCode != "EXIT" )
	{
		paramsList = StringList( );
		takeParams( paramsList );
		// Traitement du code de commande (NB : switch impossible avec std::string)
		if ( stringCode == "S" )
		{
			if ( paramsList.size( ) != 5 )
			{
				cout << ERR_STRING << endl << "#Must have 5 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				AddSegmentCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " already exists" << endl;
				}
			}
		}
		else if ( stringCode == "R" )
		{
			if ( paramsList.size( ) != 5 )
			{
				cout << ERR_STRING << endl << "#Must have 5 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				AddRectangleCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode == -1 )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " already exists" << endl;
				}
				else if ( returnCode == -2 )
				{
					cout << ERR_STRING << endl << "#" << "Rectangle not well constructed" << endl;
				}
			}
		}
		else if ( stringCode == "PC" )
		{
			if ( paramsList.size( ) < 7 || paramsList.size( )%2 != 1)
			{
				cout << ERR_STRING << endl << "#Must have an odd number of at least 7 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				AddPolygonCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode == -2 )
				{
					cout << ERR_STRING << endl << "#Polygon is not convex" << endl;
				}
				else if ( returnCode == -1 )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " already exists" << endl;
				}
			}
		}
		else if ( stringCode == "OR" )
		{
			if ( paramsList.size( ) < 2 )
			{
				cout << ERR_STRING << endl << "#Must have at least 2 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				AddUnionCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode == -2 )
				{
					cout << ERR_STRING << endl << "#Object(s) not part of the figure" << endl;
				}
				else if ( returnCode == -1 )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " already exists" << endl;
				}
			}
		}
		else if ( stringCode == "OI" )
		{
			if ( paramsList.size( ) < 2 )
			{
				cout << ERR_STRING << endl << "#Must have at least 2 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				AddIntersectionCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode == -2 )
				{
					cout << ERR_STRING << endl << "#Object(s) not part of the figure" << endl;
				}
				else if ( returnCode == -1 )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " already exists" << endl;
				}
			}

		}
		else if ( stringCode == "HIT" )
		{
			if ( figure.count( paramsList[0] ) == 1 )
			{
				if (	figure[paramsList[0]]->Contains(
						Point( atoi( paramsList[1].c_str( ) ), atoi( paramsList[2].c_str( ) ) ) ) )
				{
					cout << YES_STRING << endl;
				}
				else
				{
					cout << NO_STRING << endl;
				}
				returnCode = 1;		// Pour ne pas afficher OK_STRING
			}
			else
			{
				cout << ERR_STRING << endl << "#" << paramsList[0] << " not part of the figure" << endl;
				returnCode = -1;
			}
		}
		else if ( stringCode == "MOVE" )
		{
			if ( paramsList.size( ) != 3 )
			{
				cout << ERR_STRING << endl << "#Must have 3 parameters" << endl;
				returnCode = -1;
			}
			else
			{
				MoveCommand cmd( paramsList, &figure );
				returnCode = commandManager.Do( cmd );
				if ( returnCode )
				{
					cout << ERR_STRING << endl << "#" << paramsList[0] << " not part of the figure" << endl;
				}
			}
		}
		else if ( stringCode == "DELETE" )
		{
			if ( !paramsList.size( ) )
			{
				cout << ERR_STRING << endl << "#Must have at least 1 parameter" << endl;
				returnCode = -1;
			}
			else
			{
				vector<ReversableCommand*> vec;
				for ( string& s : paramsList )
				{
					StringList sl;
					sl.push_back( s );
					ReversableCommand* cmd = new DeleteCommand( sl, &figure );
					vec.push_back( cmd );
				}
				returnCode = commandManager.Do( vec );
				if ( returnCode )
				{
					cout << ERR_STRING << endl << "#Object(s) not part of the figure" << endl;
				}
				for ( ReversableCommand* cmd : vec )
				{
					delete cmd;
				}
			}
		}
		else if ( stringCode == "CLEAR" )
		{
			if ( paramsList.size( ) )
			{
				cout << ERR_STRING << endl << "#Must not have any parameters" << endl;
				returnCode = -1;
			}
			else
			{
				vector<ReversableCommand*> vec;
				for ( ConstFigureIterator cfi = figure.begin(); cfi != figure.end(); cfi++ )
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
				if ( returnCode )
				{
					commandManager.Undo();
					cout << ERR_STRING << endl << "#Error while clearing the figure" << endl;
				}
			}
		}
		else if ( stringCode == "LIST" )
		{
			if ( paramsList.size( ) )
			{
				cout << ERR_STRING << endl << "#Must not have any parameters" << endl;
				returnCode = -1;
			}
			else
			{
				list( );
				returnCode = 1;
			}
		}
		else if ( stringCode == "UNDO" )
		{
			if ( paramsList.size( ) )
			{
				cout << ERR_STRING << endl << "#Must not have any parameters" << endl;
				returnCode = -1;
			}
			else
			{
				if ( commandManager.Undoable( ) )
				{
					returnCode = commandManager.Undo( );
					if ( returnCode )
					{
						cout << ERR_STRING << endl << "#Error when trying to undo" << endl;
					}
				}
				else
				{
					cout << ERR_STRING << endl << "#No action to undo" << endl;
					returnCode = -1;
				}
			}
		}
		else if ( stringCode == "REDO" )
		{
			if ( paramsList.size( ) )
			{
				cout << ERR_STRING << endl << "#Must not have any parameters" << endl;
				returnCode = -1;
			}
			else
			{
				if ( commandManager.Redoable( ) )
				{
					returnCode = commandManager.Redo( );
					if ( returnCode )
					{
						cout << ERR_STRING << endl << "#Error when trying to redo" << endl;
					}
				}
				else
				{
					cout << ERR_STRING << endl << "#No action to redo" << endl;
					returnCode = -1;
				}
			}
		}
		else if ( stringCode == "LOAD" )
		{
			if ( paramsList.size( ) != 1 )
			{
				cout << ERR_STRING << endl << "#Must have only 1 parameter" << endl;
				returnCode = -1;
			}
			else
			{
				returnCode = fileManager.Load( paramsList[0], &figure, commandManager );
				if ( returnCode )
				{
					cout << ERR_STRING << endl << "#Error while trying to read " << paramsList[0] << endl;
				}
			}
		}
		else if ( stringCode == "SAVE" )
		{
			if ( paramsList.size( ) != 1 )
			{
				cout << ERR_STRING << endl << "#Must have only 1 parameter" << endl;
				returnCode = -1;
			}
			else
			{
				returnCode = fileManager.Save( paramsList[0], figure );
				if ( returnCode )
				{
					cout << ERR_STRING << endl << "#Error while trying to save the figure" << endl;
				}
			}
		}
		else
		{
			cout << ERR_STRING << endl << "#Unknown command" << endl;
			returnCode = -1;
		}
		// NB : cas du "EXIT" traite par le while

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
//				on les modifie pour qu'ils soient comme ceux de uneApplication.
//				Copie en profondeur de la figure, sous peine d'avoir de gros problemes.
{
	if ( this != &uneApplication )
	{
		for ( ConstFigureIterator cfi = figure.begin( ); cfi != figure.end( ); cfi++ )
		{
			delete cfi->second;
			figure.erase( cfi->first );
		}
		for ( ConstFigureIterator cfi = uneApplication.figure.begin( ); cfi != uneApplication.figure.end( ); cfi++ )
		{
			if ( cfi->second )
			{
				figure[cfi->first] = cfi->second->Clone( );
			}
			else
			{
				figure[cfi->first] = nullptr;
			}
		}
		fileManager = uneApplication.fileManager;
		commandManager = uneApplication.commandManager;
	}
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Application::Application( const Application & unApplication ) :
	figure( ), fileManager( unApplication.fileManager ), commandManager( unApplication.commandManager )
// Algorithme :	Utilisation des constructeurs de copie de FileManager et CommandManager.
//				Copie en profondeur de la figure, sous peine d'avoir de gros problemes.
{
	for ( ConstFigureIterator cfi = unApplication.figure.begin( ); cfi != unApplication.figure.end( ); cfi++ )
	{
		if ( cfi->second )
		{
			figure[cfi->first] = cfi->second->Clone( );
		}
		else
		{
			figure[cfi->first] = nullptr;
		}
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
}	//----- Fin de Application (constructeur de copie)


Application::Application ( ) : figure( ), fileManager( ), commandManager( )
// Algorithme :	Utilisation des constructeurs par defaut de Figure, FileManager et CommandManager.
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
}	//----- Fin de Application


Application::~Application ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
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
// Algorithme :	Lit la ligne courante sur l'entree standard et la stocke dans une string.
//				Si cette string est vide, la fonction s'arrete.
//				Sinon, cette ligne est parsee pour faire en sorte que chaque groupement de caracteres
//				entre deux espaces (ou espace et fin de ligne pour le dernier groupe) soit ajoute a params.
//				La fonction s'arrete lorsqu'elle a ajoute le dernier groupement.
{
	string stringParams;
	getline( cin, stringParams );
	if ( stringParams.empty( ) )
	{
		return;
	}
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
}	//----- Fin de takeParams

void Application::list ( ) const
// Algorithme :	Affiche chaque element de la figure sur la sortie standard,
//				en utilisant la methode print pour chaque objet. On insere
//				avant cela le nom sous lequel est connu l'objet entre son code
//				et le reste de sa description.
{
	for ( ConstFigureIterator fi = figure.begin( ); fi != figure.end( ); fi++ )
	{
		string strTamp = fi->second->ToString( );
		size_t spacePlace = strTamp.find( " " );
		string strToShow = strTamp.substr( 0, spacePlace+1 ) + fi->first + " " + strTamp.substr( spacePlace + 1 );
		//replace( strToShow.begin( ), strToShow.end( ), '\n', ' ');	// Pour afficher sur une seule ligne
		cout << strToShow << endl;
	}
}	//----- Fin de list
