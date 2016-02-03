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
// Algorithme :	On verifie que la figure ne contient pas deja un objet avec le nom prevu pour l'union.
//				Sinon, on retourne -1;
//				On verifie que tout les composants existent dans la figure.
//				Sinon, on retourne -2.
//				On instancie dynamiquement un UnionObject et on l'ajoute a la figure.
//				On retourne 0.
{
	if ( figure->count( params[0] ) != 0 )
	{
		return -1;
	}
	else
	{
		vector<Object*> vec;
		for ( int i = 1; i < params.size( ); i++ )
		{
			if (figure->count( params[i] ) != 0 )
			{
				vec.push_back( (*figure)[params[i]] );
			}
			else
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
