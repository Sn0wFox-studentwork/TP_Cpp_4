/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int MoveCommand::Execute( ) const
// Algorithme :	On verifie qu'il n'existe pas un objet referencee dans la Figure pointee par figure
//				sous le nom contenu dans params[0]
//				Sinon, on retourne -1.
//				On deplace l'objet de params[1] selon x et params[2] selon y.
//				On retourne 0.
{
	if ( figure->count( params[0] ) == 0 )
	{
		return -1;
	}
	else
	{
		(*figure)[params[0]]->Move( atoi( params[1].c_str( ) ), atoi( params[2].c_str( ) ) );
	}
	return 0;
}	//----- Fin de Execute( )

MoveCommand* MoveCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new MoveCommand( *this );
}	//----- Fin de Clone

MoveCommand * MoveCommand::GetInversedCommand( ) const
// Algorithme :	Allocation dynamique d'une commande annulant la commande courante.
//				Cette commande est calculee en inversant le signe des coordonnees
//				de deplacement.
//				On retourne un pointeur vers cette commande.
{
	StringList sl;
	sl.push_back( params[0] );	// Push du nom de l'objet
	for ( unsigned int i = 1; i < params.size( ); i++ )
	{
		if ( params[i].substr( 0, 1 ) == "-" )
		{
			sl.push_back( params[i].substr( 1, params[i].size( ) -1 ) );
		}
		else
		{
			sl.push_back( "-" + params[i] );
		}
	}
	MoveCommand* moveCmd = new MoveCommand( sl, this->figure );
	return moveCmd;
}	//----- Fin de GetInversedCommand( )

//------------------------------------------------- Surcharge d'opérateurs
MoveCommand & MoveCommand::operator = ( const MoveCommand & aMoveCommand )
// Algorithme :	Si on n'est pas en train de faire aMoveCommand = aMoveCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aMoveCommand
{
	if ( this != &aMoveCommand )
	{
		params = aMoveCommand.params;
		figure = aMoveCommand.figure;
	}
	return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
MoveCommand::MoveCommand ( const MoveCommand & aMoveCommand ) : ReversableCommand ( aMoveCommand )
// Algorithme :	Utilisation du constructeur de copie de ReversableCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MoveCommand>" << endl;
#endif
}	//----- Fin de MoveCommand (constructeur de copie)


MoveCommand::MoveCommand ( const StringList& params, Figure* const f ) : ReversableCommand( params, f )
// Algorithme :	Utilisation du constructeur de ReversableCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <MoveCommand>" << endl;
#endif
}	//----- Fin de MoveCommand


MoveCommand::~MoveCommand ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <MoveCommand>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~MoveCommand
