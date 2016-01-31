/*************************************************************************
                           FileManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <FileManager> (fichier FileManager.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "FileManager.h"
#include "../commands/LoadCompositeCommand.h"
#include "../commands/AddSegmentCommand.h"
#include "../commands/AddRectangleCommand.h"
#include "../commands/AddPolygonCommand.h"
#include "../geometry/Segment.h"
#include "../geometry/Rectangle.h"
#include "../geometry/InterObject.h"
#include "../geometry/UnionObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int FileManager::Load ( const string& fileName, Figure* const figure, CommandManager& cmdManager ) const
// Algorithme :
{
	ifstream ifs( fileName );
	if ( !ifs )
	{
		return -1;
	}
	vector<ReversableCommand*> cmds;	// La liste des commandes a effectuer pour charger le fichier
	StringList names;					// La liste des noms des objets a creer
	string cmdCode;						// Le code de la commande
	string paramLine;					// Les parametres de la commande sur une seule ligne
	string name;						// Nom de l'objet a creer	

	while ( getline( ifs, paramLine ) )	// TODO : probleme si on a atteint eof avant ou pas ?
	{
		StringList params;					// La liste des parametres de la commande
		stringstream sstream;				// Un flux pour manipuler plus facilement les strings
											// Il faut la reinitialiser a chaque tour de boucle
		sstream << paramLine;
		sstream >> cmdCode;
		sstream >> name;

		// Verification de l'unicite du nom de l'objet
		if ( figure->count( name ) != 0 )
		{
			clearBeforeAbortLoading( cmds );
			return -2;
		}
		for ( int i = 0; i < names.size( ); i++ )
		{
			if ( name == names[i] )
			{
				clearBeforeAbortLoading(cmds);
				return -3;
			}
		}

		// Creation de la commande de creation
		params.push_back( name );
		if ( cmdCode == "OI" || cmdCode == "OR" )
		{
			params.push_back( cmdCode );
			vector<Object*> comp;
			sstream.clear( );
			getline( ifs, paramLine );
			while ( paramLine != "}" && !ifs.eof( ) )	// Fonctionne uniquement car "}" sera obligatoirement en debut de ligne
			{
				stringstream sstreamcompo;
				sstreamcompo << paramLine;
				sstreamcompo >> cmdCode;
				
				// Cas ou le composant est un composant simple
				if ( cmdCode == "S" || cmdCode == "R" || cmdCode == "PC" )
				{
					SingleObject* sobj = createSingleObject( cmdCode, sstreamcompo );
					if ( sobj )
					{
						comp.push_back( sobj );
					}
					else
					{
						clearBeforeAbortLoading( comp );
						clearBeforeAbortLoading( cmds );
						return -5;
					}
					
				}
				else if ( cmdCode == "OI" || cmdCode == "OR" )
				{
					CompositeObject* cobj = createCompositeObject( cmdCode, ifs );
					if ( cobj )
					{
						comp.push_back( cobj );
					}
					else
					{
						clearBeforeAbortLoading( comp );
						clearBeforeAbortLoading( cmds );
						return -5;
					}
					
				}
				else	// mauvaise commande presente dans le fichier
				{
					clearBeforeAbortLoading( comp );
					clearBeforeAbortLoading( cmds );
					return -4;
				}

				getline( ifs, paramLine );
			}	//----- Fin de while ( paramLine != } && !eof )

			cmds.push_back( new LoadCompositeCommand( params, figure, comp ) );
		}	//----- Fin de if( cmdCode == OR || cmdCode == OI )
		else
		{
			while ( !sstream.eof( ) )
			{
				string coord;
				sstream >> coord;
				params.push_back(coord);
			}
			if ( cmdCode == "S" )
			{
				cmds.push_back( new AddSegmentCommand( params, figure ) );
			}
			else if ( cmdCode == "R" )
			{
				cmds.push_back( new AddRectangleCommand( params, figure ) );
			}
			else if ( cmdCode == "PC" )
			{
				cmds.push_back( new AddPolygonCommand( params, figure ) );
			}
			else	// mauvaise commande presente dans le fichier
			{
				clearBeforeAbortLoading(cmds);
				return -4;
			}
		}	//----- Fin de if( cmdCode == S || cmdCode == R || cmdCode == PC )

	}	//----- Fin de while( !ifs.eof( ) )

	// Execution du groupement de commandes
	cmdManager.Do( cmds );
	clearBeforeAbortLoading( cmds );
    return 0;

}	//----- Fin de Méthode

int FileManager::Save ( const string& fileName, const Figure& figure ) const
{
    return 0;
}

//------------------------------------------------- Surcharge d'opérateurs
FileManager & FileManager::operator= ( const FileManager & unFileManager )
// Algorithme :	Si on n'est pas en train de faire unFileManager = unFileManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unFileManager
{
    if ( this != &unFileManager )
    {
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FileManager::FileManager ( const FileManager & unFileManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FileManager>" << endl;
#endif
} //----- Fin de FileManager (constructeur de copie)


FileManager::FileManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FileManager>" << endl;
#endif
} //----- Fin de FileManager


FileManager::~FileManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FileManager>" << endl;
#endif
}	//----- Fin de ~FileManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
SingleObject* FileManager::createSingleObject( const string& type, stringstream& sstream ) const
// Algorithme :
{
	vector<Point> coords;
	while ( !sstream.eof( ) )
	{
		int coordx;
		int coordy;
		sstream >> coordx;
		sstream >> coordy;
		coords.push_back( Point( coordx, coordy ) );
	}
	if ( type == "S" )
	{
		if ( coords.size( ) == 2 )
		{
			return new Segment( coords[0], coords[1] );
		}
		else
		{
			return nullptr;
		}
	}
	else if ( type == "R" )
	{
		if ( coords.size( ) == 2 )
		{
			return new Rectangle( coords );
		}
		else
		{
			return nullptr;
		}
	}
	else if ( type == "PC" )
	{
		if ( coords.size( ) >= 2 )
		{
			return new Polygone( coords );
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}	//----- Fin de createSingleObject

CompositeObject* FileManager::createCompositeObject( const string& type, ifstream& ifs ) const
// Algorithme :
{
	string line;
	string lineWithoutTab;
	string cmdCode;
	vector<Object*> comp;
	while ( getline( ifs, line ) )
	{
		
		stringstream sstream;
		sstream << line;
		sstream >> cmdCode;
		if ( cmdCode == "}" )
		{
			break;	// Nous avons finis de traiter le compose composite
		}

		if ( cmdCode == "S" || cmdCode == "R" || cmdCode == "PC" )
		{
			SingleObject* sobj = createSingleObject( cmdCode, sstream );
			if ( sobj )
			{
				comp.push_back( sobj );
			}
			else
			{
				clearBeforeAbortLoading(comp);
				return nullptr;
			}
		}
		else if ( cmdCode == "OR" || cmdCode == "OI" )
		{
			CompositeObject* cobj = createCompositeObject( cmdCode, ifs );
			if ( cobj )
			{
				comp.push_back( cobj );
			}
			else
			{
				clearBeforeAbortLoading( comp );
				return nullptr;
			}
		}
		else
		{
			clearBeforeAbortLoading( comp );
			return nullptr;
		}	//----- Fin de if ( cmdCode est coherent )
	}	//----- Fin de while ( getline( ) && braceNumber )
	
	if ( type == "OR" )
	{
		return new InterObject( comp );
	}
	else
	{
		return new UnionObject( comp );
	}
}	//----- Fin de createCompositeObject

void FileManager::clearBeforeAbortLoading( vector<ReversableCommand*>& v ) const
{
	for ( int i = 0; i < v.size( ); i++ )
	{
		delete v[i];
	}
}

void FileManager::clearBeforeAbortLoading( vector<Object*>& v ) const
{
	for ( int i = 0; i < v.size( ); i++ )
	{
		delete v[i];
	}
}

//------------------------------------------------------- Méthodes privées
