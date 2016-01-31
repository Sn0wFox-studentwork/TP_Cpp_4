/*************************************************************************
                           AddUnionCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddUnionCommand> (fichier AddUnionCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdexcept>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AddUnionCommand.h"
#include "../geometry/UnionObject.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AddUnionCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		return -1;
	}
	catch ( const out_of_range& e )
	{
		vector<Object*> vec;
		for ( int i = 1; i < params.size( ); i++ )
		{
			try
			{
				Object* o = figure->at( params[i] );
				vec.push_back( (*figure)[params[i]] );
			}
			catch ( const out_of_range& e )
			{
				return -2;
			}
		}
		(*figure)[params[0]] = new UnionObject(	vec );
	}
	return 0;
}	//----- Fin de Execute

AddUnionCommand* AddUnionCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new AddUnionCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
AddUnionCommand & AddUnionCommand::operator = ( const AddUnionCommand & aAddUnionCommand )
// Algorithme :	Si on n'est pas en train de faire aAddUnionCommand = aAddUnionCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddUnionCommand
{
	if ( this != &aAddUnionCommand )
	{
		params = aAddUnionCommand.params;
		figure = aAddUnionCommand.figure;
	}
	return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddUnionCommand::AddUnionCommand ( const AddUnionCommand & aAddUnionCommand ) :
	AddObjectCommand ( aAddUnionCommand )
// Algorithme :	Utilisation du constructeur de copie de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddUnionCommand>" << endl;
#endif
}	//----- Fin de AddUnionCommand (constructeur de copie)


AddUnionCommand::AddUnionCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :	Utilisation du constructeur de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <AddUnionCommand>" << endl;
#endif
}	//----- Fin de AddUnionCommand


AddUnionCommand::~AddUnionCommand ( )
// Algorithme :	Libere la memoire asociee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <AddUnionCommand>" << endl;
#endif
	// Pas d'allocation dynamique.
}	//----- Fin de ~AddUnionCommand
