/*************************************************************************
                           AddPolygonCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <AddPolygonCommand> (fichier AddPolygonCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "AddPolygonCommand.h"
#include "../geometry/Polygone.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type AddPolygonCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


int AddPolygonCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		return -1;
	}
	catch ( const out_of_range& e )
	{
		vector<Point> vec;
		for ( int i = 1; i+1 < params.size(); i+=2 )
		{
			vec.push_back( Point( stoi( params[i] ), stoi( params[i + 1] ) ) );
		}

		(*figure)[params[0]] = new Polygone( vec );
	}
	return 0;
}	//----- Fin de Execute

//------------------------------------------------- Surcharge d'op�rateurs
AddPolygonCommand & AddPolygonCommand::operator = ( const AddPolygonCommand & aAddPolygonCommand )
// Algorithme :	Si on n'est pas en train de faire aAddPolygonCommand = aAddPolygonCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddPolygonCommand
{
	if ( this != &aAddPolygonCommand )
	{
		params = aAddPolygonCommand.params;
		figure = aAddPolygonCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddPolygonCommand::AddPolygonCommand ( const AddPolygonCommand & aAddPolygonCommand ) :
	AddObjectCommand ( aAddPolygonCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddPolygonCommand>" << endl;
#endif
} //----- Fin de AddPolygonCommand (constructeur de copie)


AddPolygonCommand::AddPolygonCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddPolygonCommand>" << endl;
#endif
} //----- Fin de AddPolygonCommand


AddPolygonCommand::~AddPolygonCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddPolygonCommand>" << endl;
#endif
} //----- Fin de ~AddPolygonCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
