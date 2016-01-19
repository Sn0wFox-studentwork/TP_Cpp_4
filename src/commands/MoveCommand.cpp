/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <MoveCommand> (fichier MoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type MoveCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


int MoveCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		(*figure)[params[0]]->Move( stoi( params[1] ), stoi( params[2] ) );
	}
	catch ( const out_of_range& e )
	{
		return -1;
	}
	return 0;
}	//----- Fin de M�thode

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
}	//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
