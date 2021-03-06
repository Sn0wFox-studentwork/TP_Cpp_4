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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AddIntersectionCommand::Execute( ) const
// Algorithme :	On verifie que la figure ne contient pas deja un objet avec le nom prevu pour l'intersection.
//				Sinon, on retourne -1;
//				On verifie que tout les composants existent dans la figure.
//				Sinon, on retourne -2.
//				On instancie dynamiquement un InterObject et on l'ajoute a la figure.
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
			if ( figure->count( params[i] ) != 0 )
			{
				vec.push_back( (*figure)[params[i]] );
			}
			else
			{
				return -2;
			}
		}
		(*figure)[params[0]] = new InterObject(	vec );
	}
	return 0;
}	//----- Fin de Execute

AddIntersectionCommand* AddIntersectionCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
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
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddIntersectionCommand::AddIntersectionCommand ( const AddIntersectionCommand & aAddIntersectionCommand ) :
	AddObjectCommand ( aAddIntersectionCommand )
// Algorithme :	Utilisation du constructeur de copie de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddIntersectionCommand>" << endl;
#endif
}	//----- Fin de AddIntersectionCommand (constructeur de copie)


AddIntersectionCommand::AddIntersectionCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :	Utilisation du constructeur de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <AddIntersectionCommand>" << endl;
#endif
}	//----- Fin de AddIntersectionCommand


AddIntersectionCommand::~AddIntersectionCommand ( )
// Algorithme :	Libere la memoire asociee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <AddIntersectionCommand>" << endl;
#endif
	// Pas d'allocation dynamique.
}	//----- Fin de ~AddIntersectionCommand
