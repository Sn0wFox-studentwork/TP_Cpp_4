/*************************************************************************
                           RestoreCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <RestoreCommand> (fichier RestoreCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "RestoreCommand.h"
#include "DeleteCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int RestoreCommand::Execute( ) const
// Algorithme :	On verifie qu'il n'existe pas un objet referencee dans la Figure pointee par figure
//				sous le nom contenu dans params[0]
//				Sinon, on retourne -1.
//				On verifie que le pointeur vers l'objet a inserer n'est pas null.
//				Sinon, on retourne -2.
//				On insere dans la figure une copie de deletedObject allouee dynamiquement.
//				On retourne 0.
{
	if( figure->count( params[0] ) == 0 )
	{
		if ( deletedObject )
		{
			(*figure)[params[0]] = deletedObject->Clone( );
			return 0;
		}
		return -2;
	}
	return -1;
}	//----- Fin de Execute

ReversableCommand* RestoreCommand::GetInversedCommand( ) const
// Algorithme :	Allocation dynamique d'une commande annulant la commande courante.
{
	return new DeleteCommand( params, figure );
}	//----- Fin de GetInversedCommand

RestoreCommand* RestoreCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new RestoreCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
RestoreCommand & RestoreCommand::operator = ( const RestoreCommand & aRestoreCommand )
// Algorithme :	Si on n'est pas en train de faire aRestoreCommand = aRestoreCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aRestoreCommand.
//				Copie en profondeur de deletedObject sous peine d'avoir de gros ennuis.
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
// Algorithme :	Utilisation des constructeurs de copie de ReversableCommand et Objet* (copie de pointeur).
//				deletedObjet est initialise en tant que pointeur null. Il pointera vers un Object (une copie)
//				uniquement si cet objet existe dans aRestoreCommand, et restera a nullptr sinon.
{
	if( aRestoreCommand.deletedObject )
	{
		deletedObject = aRestoreCommand.deletedObject->Clone( );
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <RestoreCommand>" << endl;
#endif
}	//----- Fin de RestoreCommand (constructeur de copie)


RestoreCommand::RestoreCommand( const StringList& params, Figure* const f, Object* const delObject ) :
	ReversableCommand( params, f ), deletedObject( nullptr )
// Algorithme :	Utilisation des constructeurs de ReversableCommand et Objet* (copie de pointeur).
//				deletedObjet est initialise en tant que pointeur null. Il pointera vers un delObject (une copie)
//				uniquement si cet objet existe, et restera a nullptr sinon.
{
	if ( delObject )
	{
		deletedObject = delObject->Clone( );
	}
#ifdef MAP
    cout << "Appel au constructeur de <RestoreCommand>" << endl;
#endif
}	//----- Fin de RestoreCommand


RestoreCommand::~RestoreCommand ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
	if ( deletedObject )	// pour ne pas tenter de desallouer un pointeur null
	{
		delete deletedObject;
	}
#ifdef MAP
    cout << "Appel au destructeur de <RestoreCommand>" << endl;
#endif
}	//----- Fin de ~RestoreCommand
