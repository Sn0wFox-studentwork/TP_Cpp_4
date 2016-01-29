/*************************************************************************
                           RestoreCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <RestoreCommand> (fichier RestoreCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "RestoreCommand.h"
#include "DeleteCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int RestoreCommand::Execute( ) const
// Algorithme :
{
	if( figure->count( params[0] ) == 0 )
	{
		if ( deletedObject )
		{
			(*figure)[params[0]] = deletedObject->Clone( );
			return 0;
		}
	}
	return -1;
}	//----- Fin de Execute

ReversableCommand* RestoreCommand::GetInversedCommand( ) const
// Algorithme :
{
	return new DeleteCommand( params, figure );
}	//----- Fin de GetInversedCommand

RestoreCommand* RestoreCommand::Clone( ) const
// Algorithme :
{
	return new RestoreCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
RestoreCommand & RestoreCommand::operator = ( const RestoreCommand & aRestoreCommand )
// Algorithme :	Si on n'est pas en train de faire aRestoreCommand = aRestoreCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aRestoreCommand
{
	if ( this != &aRestoreCommand )
	{
		params = aRestoreCommand.params;
		figure = aRestoreCommand.figure;
		if ( aRestoreCommand.deletedObject )
		{
			deletedObject = aRestoreCommand.deletedObject->Clone();
		}
		else
		{
			deletedObject = nullptr;
		}
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
RestoreCommand::RestoreCommand ( const RestoreCommand & aRestoreCommand ) :
	ReversableCommand( aRestoreCommand ), deletedObject( nullptr )
// Algorithme :
//
{
	if( aRestoreCommand.deletedObject )
	{
		deletedObject = aRestoreCommand.deletedObject->Clone();
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <RestoreCommand>" << endl;
#endif
} //----- Fin de RestoreCommand (constructeur de copie)


RestoreCommand::RestoreCommand( const StringList& params, Figure* const f, Object* const delObject ) :
	ReversableCommand( params, f ), deletedObject( nullptr )
	// Algorithme :
	//
{
	if ( delObject )
	{
		deletedObject = delObject->Clone( );
	}
#ifdef MAP
    cout << "Appel au constructeur de <RestoreCommand>" << endl;
#endif
} //----- Fin de RestoreCommand


RestoreCommand::~RestoreCommand ( )
// Algorithme :
//
{
	if ( deletedObject )	// pour ne pas tenter de desallouer un pointeur null
	{
		delete deletedObject;
	}
#ifdef MAP
    cout << "Appel au destructeur de <RestoreCommand>" << endl;
#endif
} //----- Fin de ~RestoreCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
