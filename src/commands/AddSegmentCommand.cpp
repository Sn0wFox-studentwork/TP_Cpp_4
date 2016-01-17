/*************************************************************************
                           AddSegmentCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddSegmentCommand> (fichier AddSegmentCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "AddSegmentCommand.h"
#include "../geometry/Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type AddSegmentCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


int AddSegmentCommand::Execute( ) const
{
	cout << "In Execute :";
	for (int i = 0; i < this->GetParams().size(); i++)
	{
		cout << " " << this->GetParams()[i];
	}
	cout << endl;
	try
	{
		Object* o = figure->at( params[0] );
		return -1;
	}
	catch ( const out_of_range& e )
	{
		cout << stoi(params[1]) << endl;
		(*figure)[params[0]] = new Segment(	Point(stoi(params[1]), stoi(params[2])),
											Point(stoi(params[3]), stoi(params[4])) );
		(*figure)[params[0]]->Print();
	}
	return 0;
}

AddSegmentCommand * AddSegmentCommand::GetInversedCommand( ) const
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
	AddSegmentCommand* moveCmd = new AddSegmentCommand( sl, this->figure );
	return moveCmd;
}

//------------------------------------------------- Surcharge d'opérateurs
AddSegmentCommand & AddSegmentCommand::operator = ( const AddSegmentCommand & aAddSegmentCommand )
// Algorithme :	Si on n'est pas en train de faire aAddSegmentCommand = aAddSegmentCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddSegmentCommand
{
	if ( this != &aAddSegmentCommand )
	{
		params = aAddSegmentCommand.params;
		figure = aAddSegmentCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddSegmentCommand::AddSegmentCommand ( const AddSegmentCommand & aAddSegmentCommand ) : ReversableCommand ( aAddSegmentCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddSegmentCommand>" << endl;
#endif
} //----- Fin de AddSegmentCommand (constructeur de copie)


AddSegmentCommand::AddSegmentCommand ( const StringList& params, Figure* const f ) : ReversableCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddSegmentCommand>" << endl;
#endif
} //----- Fin de AddSegmentCommand


AddSegmentCommand::~AddSegmentCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddSegmentCommand>" << endl;
#endif
} //----- Fin de ~AddSegmentCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
