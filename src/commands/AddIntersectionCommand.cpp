/*************************************************************************
                           AddIntersectionCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddIntersectionCommand> (fichier AddIntersectionCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdexcept>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AddIntersectionCommand.h"
#include "../geometry/InterObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int AddIntersectionCommand::Execute( ) const
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
				Object* o = figure->at(params[i]);
				vec.push_back( (*figure)[params[i]] );
			}
			catch ( const out_of_range& e )
			{
				return -2;
			}
		}
		(*figure)[params[0]] = new InterObject(	vec );
	}
	return 0;
}	//----- Fin de Execute

AddIntersectionCommand* AddIntersectionCommand::Clone( ) const
// Algorithme :
{
	return new AddIntersectionCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
AddIntersectionCommand & AddIntersectionCommand::operator = ( const AddIntersectionCommand & aAddIntersectionCommand )
// Algorithme :	Si on n'est pas en train de faire aAddIntersectionCommand = aAddIntersectionCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddIntersectionCommand
{
	if ( this != &aAddIntersectionCommand )
	{
		params = aAddIntersectionCommand.params;
		figure = aAddIntersectionCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddIntersectionCommand::AddIntersectionCommand ( const AddIntersectionCommand & aAddIntersectionCommand ) :
	AddObjectCommand ( aAddIntersectionCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de AddIntersectionCommand (constructeur de copie)


AddIntersectionCommand::AddIntersectionCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de AddIntersectionCommand


AddIntersectionCommand::~AddIntersectionCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de ~AddIntersectionCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
