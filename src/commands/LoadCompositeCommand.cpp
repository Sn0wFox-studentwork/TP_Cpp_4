/*************************************************************************
                    LoadCompositeCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <LoadCompositeCommand> (fichier LoadCompositeCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "LoadCompositeCommand.h"
#include "../geometry/InterObject.h"
#include "../geometry/UnionObject.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int LoadCompositeCommand::Execute( ) const
// Algorithme :
{
	if( figure->count( params[0] ) == 0 )
	{
		if ( params[1] == "OI" )
		{
			(*figure)[params[0]] = new InterObject( components );
		}
		else if ( params[1] == "OR" )
		{
			(*figure)[params[0]] = new UnionObject( components );
		}
		else
		{
			return -2;
		}
		return 0;
	}
	return -1;
}	//----- Fin de Execute

LoadCompositeCommand* LoadCompositeCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new LoadCompositeCommand( *this );
}	//----- Fin de Clone


//------------------------------------------------- Surcharge d'opérateurs
LoadCompositeCommand & LoadCompositeCommand::operator = ( const LoadCompositeCommand & unLoadCompositeCommand )
// Algorithme :	Si on n'est pas en train de faire unLoadCompositeCommand = unLoadCompositeCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unLoadCompositeCommand
{
	if ( this != &unLoadCompositeCommand )
	{
		params = unLoadCompositeCommand.params;
		figure = unLoadCompositeCommand.figure;
		components = unLoadCompositeCommand.components;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LoadCompositeCommand::LoadCompositeCommand ( const LoadCompositeCommand & unLoadCompositeCommand ) :
	AddObjectCommand( unLoadCompositeCommand ), components( )
// Algorithme :
{
	for ( Object* o : unLoadCompositeCommand.components )
	{
		components.push_back( o->Clone( ) );
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <LoadCompositeCommand>" << endl;
#endif
} //----- Fin de LoadCompositeCommand (constructeur de copie)


LoadCompositeCommand::LoadCompositeCommand ( const StringList& params, Figure* const f, const vector<Object*>& obj ) :
	AddObjectCommand( params, f ), components( )
// Algorithme :
{
	for ( Object* o : obj )
	{
		components.push_back( o->Clone( ) );
	}
#ifdef MAP
    cout << "Appel au constructeur de <LoadCompositeCommand>" << endl;
#endif
} //----- Fin de LoadCompositeCommand


LoadCompositeCommand::~LoadCompositeCommand ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
	for ( int i = 0; i < components.size( ); i++ )
	{
		delete components[i];
	}
#ifdef MAP
    cout << "Appel au destructeur de <LoadCompositeCommand>" << endl;
#endif
}	//----- Fin de ~LoadCompositeCommand
