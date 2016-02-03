/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"
#include "RestoreCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int DeleteCommand::Execute( ) const
// Algorithme :	Si il existe un objet referencee dans la Figure pointee par figure
//				sous le nom contenu dans params[0], on libere la memoire associee
//				et on supprime cet objet de la figure. On retourne 0.
//				Sinon, on retourne -1.
{
	if( figure->count( params[0] ) == 1 )
	{
		delete (*figure)[params[0]];
		figure->erase( params[0] );
		return 0;
	}
	return -1;
}	//----- Fin de Execute

DeleteCommand* DeleteCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new DeleteCommand( *this );
}	//----- Fin de Clone

ReversableCommand* DeleteCommand::GetInversedCommand( ) const
// Algorithme :	Allocation dynamique d'une commande annulant la commande courante.
{
	return new RestoreCommand( params, figure, deletedObject );
}	//----- Fin de GetInversedCommand

//------------------------------------------------- Surcharge d'opérateurs
DeleteCommand & DeleteCommand::operator = ( const DeleteCommand & aDeleteCommand )
// Algorithme :	Si on n'est pas en train de faire aDeleteCommand = aDeleteCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aDeleteCommand.
//				Copie en profondeur de deletedObject sous peine d'avoir de gros ennuis.
{
	if ( this != &aDeleteCommand )
	{
		params = aDeleteCommand.params;
		figure = aDeleteCommand.figure;
		if ( aDeleteCommand.deletedObject )
		{
			deletedObject = aDeleteCommand.deletedObject->Clone( );
		}
		else
		{
			deletedObject = nullptr;
		}
	}
	return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
DeleteCommand::DeleteCommand ( const DeleteCommand & aDeleteCommand ) :
	ReversableCommand( aDeleteCommand ), deletedObject( nullptr )
// Algorithme :	Utilisation des constructeurs de copie de ReversableCommand et Objet* (copie de pointeur).
//				deletedObjet est initialise en tant que pointeur null. Il pointera vers un Object (une copie)
//				uniquement si cet objet existe dans la figure pointee par figure, et restera a nullptr sinon.
{
	if( aDeleteCommand.deletedObject )
	{
		deletedObject = aDeleteCommand.deletedObject->Clone( );
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <DeleteCommand>" << endl;
#endif
}	//----- Fin de DeleteCommand (constructeur de copie)


DeleteCommand::DeleteCommand( const StringList& params, Figure* const f ) :
	ReversableCommand( params, f ), deletedObject( nullptr )
// Algorithme :	Utilisation des constructeurs de ReversableCommand et Objet* (copie de pointeur).
//				deletedObjet est initialise en tant que pointeur null. Il pointera vers un Object (une copie)
//				uniquement si cet objet existe dans la figure pointee par f, et restera a nullptr sinon.
{
	if ( figure->count( params[0] ) == 1 )
	{
		deletedObject = (*figure)[params[0]]->Clone();
	}
#ifdef MAP
    cout << "Appel au constructeur de <DeleteCommand>" << endl;
#endif
}	//----- Fin de DeleteCommand


DeleteCommand::~DeleteCommand ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
	if ( deletedObject )	// pour ne pas tenter de desallouer un pointeur null
	{
		delete deletedObject;
	}
#ifdef MAP
    cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
}	//----- Fin de ~DeleteCommand
