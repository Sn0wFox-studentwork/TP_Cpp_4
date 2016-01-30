/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdexcept>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int MoveCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		(*figure)[params[0]]->Move( atoi( params[1].c_str( ) ), atoi( params[2].c_str( ) ) );
	}
	catch ( const out_of_range& e )
	{
		return -1;
	}
	return 0;
}	//----- Fin de Execute( )

MoveCommand* MoveCommand::Clone( ) const
// Algorithme :
{
	return new MoveCommand( *this );
}	//----- Fin de Clone

MoveCommand * MoveCommand::GetInversedCommand( ) const
// Algorithme :
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
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
MoveCommand::MoveCommand ( const MoveCommand & aMoveCommand ) : ReversableCommand ( aMoveCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MoveCommand>" << endl;
#endif
} //----- Fin de MoveCommand (constructeur de copie)


MoveCommand::MoveCommand ( const StringList& params, Figure* const f ) : ReversableCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de MoveCommand


MoveCommand::~MoveCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de ~MoveCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
