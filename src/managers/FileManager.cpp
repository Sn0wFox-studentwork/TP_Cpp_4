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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int FileManager::Load ( const string& fileName, Figure* const figure, CommandManager& cmdManager ) const
// Algorithme :	On verifie qu'il est possible d'ouvrir le fichier fileName en lecture.
//				Sinon, on retourne -1.
//				Tant qu'on arrive a lire une ligne du fichier (= on n'est pas a la fin du fichier) :
//					On extrait le code de l'objet a creer et le nom de l'objet a creer.
//					On verifie qu'aucun objet avec ce nom n'existe deja dans la figure.
//					Sinon, on retourne -2.
//					On verifie qu'aucun objet deja cree a partir du fichier ne porte ce nom.
//					Sinon, on retourne -3.
//					Si le code de la commande est celui d'un composite (OI ou OR),
//						Tant qu'on arrive a lire une ligne correctement,
//							on cree les objets composant le composite.
//						On ajoute la commande permettant de creer le composite a la liste des commandes a effectuer.
//					Sinon, on cree une commande permettant de creer l'objet et on l'ajoute a la liste des
//					commandes a effecteur.
//					A tout moment, si on echour a creer un des objets, on retourne -5.
//					Si un autre probleme a lieu, on retourne -4.
//				On execute la liste des commandes via cmdManager.
//				On retourne le code de retour de cmdManager passe en positif.
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

	while ( getline( ifs, paramLine ) )
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
			clearBeforeAbortLoading( comp );
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
	int returnCode = cmdManager.Do( cmds );
	clearBeforeAbortLoading( cmds );
    return -returnCode;

}	//----- Fin de Load

int FileManager::Save ( const string& fileName, const Figure& figure ) const
// Algorithme :	On tente d'ouvrir le fichier fileName.
//				Si on echoue, on retourne -1.
//				Sinon, on ecrit dans ce fichier la description de chaque objet present dans figure
//				qui nous est donnee par Object::ToString(), en y inserant le nom sous lequel est connu
//				l'objet dans la figure apres le code representant l'objet.
//				On retourne 0.
{
	ofstream file( fileName, ios::binary | ios::out );
	if ( file )
	{
		for ( ConstFigureIterator cfi = figure.begin( ); cfi != figure.end( ); cfi++ )
		{
			string strTamp = cfi->second->ToString( );
			size_t spacePlace = strTamp.find( " " );
			string strToPrint = strTamp.substr( 0, spacePlace + 1 ) + cfi->first + " " + strTamp.substr( spacePlace + 1 );
			file << strToPrint << endl;
		}
		return 0;
	}
	return -1;
}

//------------------------------------------------- Surcharge d'opérateurs
FileManager & FileManager::operator= ( const FileManager & unFileManager )
// Algorithme :	Si on n'est pas en train de faire unFileManager = unFileManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unFileManager
{
    if ( this != &unFileManager )
    {
		// Rien a faire
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FileManager::FileManager ( const FileManager & unFileManager )
// Algorithme :	Aucun attribut a initialiser.
{
	// Nothing to do
#ifdef MAP
    cout << "Appel au constructeur de copie de <FileManager>" << endl;
#endif
}	//----- Fin de FileManager (constructeur de copie)


FileManager::FileManager ( )
// Algorithme :	Aucun attribut a initialiser.
{
#ifdef MAP
    cout << "Appel au constructeur de <FileManager>" << endl;
#endif
}	//----- Fin de FileManager


FileManager::~FileManager ( )
// Algorithme :	Liberation de la memoire occupee par l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <FileManager>" << endl;
#endif
	// Pas d'allocation dynamique
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
	
	CompositeObject* o = nullptr;
	if ( type == "OR" )
	{
		o = new UnionObject( comp );
	}
	else
	{
		o = new InterObject( comp );
	}
	clearBeforeAbortLoading( comp );
	return o;

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
