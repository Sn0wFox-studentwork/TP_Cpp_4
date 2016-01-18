/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"
#include "RestoreCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type DeleteCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


int DeleteCommand::Execute( ) const
// Algorithme :
{
	if( figure->count( params[0] ) == 1 )
	{
		delete (*figure)[params[0]];
		figure->erase( params[0] );
		return 0;
	}
	return -1;
}	//----- Fin de Execute

ReversableCommand* DeleteCommand::GetInversedCommand( ) const
// Algorithme :
{
	return new RestoreCommand( params, figure, deletedObject );
}	//----- Fin de GetInversedCommand

//------------------------------------------------- Surcharge d'opérateurs
DeleteCommand & DeleteCommand::operator = ( const DeleteCommand & aDeleteCommand )
// Algorithme :	Si on n'est pas en train de faire aDeleteCommand = aDeleteCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aDeleteCommand
{
	if ( this != &aDeleteCommand )
	{
		params = aDeleteCommand.params;
		figure = aDeleteCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
DeleteCommand::DeleteCommand ( const DeleteCommand & aDeleteCommand ) :
	ReversableCommand( aDeleteCommand ), isComplete( aDeleteCommand.isComplete ), deletedObject( nullptr )
// Algorithme :
//
{
	if( aDeleteCommand.deletedObject )
	{
		deletedObject = aDeleteCommand.deletedObject->Clone();
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <DeleteCommand>" << endl;
#endif
} //----- Fin de DeleteCommand (constructeur de copie)


DeleteCommand::DeleteCommand( const StringList& params, Figure* const f ) :
	ReversableCommand( params, f ), isComplete( true ), deletedObject( nullptr )
// Algorithme :
//
{
	if ( figure->count( params[0] ) == 1 )
	{
		deletedObject = (*figure)[params[0]]->Clone();
	}
	else
	{
		isComplete = false;
	}
#ifdef MAP
    cout << "Appel au constructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de DeleteCommand


DeleteCommand::~DeleteCommand ( )
// Algorithme :
//
{
	if ( deletedObject )	// pour ne pas tenter de desallouer un pointeur null
	{
		delete deletedObject;
	}
#ifdef MAP
    cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de ~DeleteCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
