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
int AddSegmentCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		return -1;
	}
	catch ( const out_of_range& e )
	{
		(*figure)[params[0]] = new Segment(	Point(stoi(params[1]), stoi(params[2])),
											Point(stoi(params[3]), stoi(params[4])) );
	}
	return 0;
}	//----- Fin de Clone

AddSegmentCommand* AddSegmentCommand::Clone( ) const
// Algorithme :
{
	return new AddSegmentCommand( *this );
}	//----- Fin de Clone

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
AddSegmentCommand::AddSegmentCommand ( const AddSegmentCommand & aAddSegmentCommand ) :
	AddObjectCommand ( aAddSegmentCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddSegmentCommand>" << endl;
#endif
} //----- Fin de AddSegmentCommand (constructeur de copie)


AddSegmentCommand::AddSegmentCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
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
