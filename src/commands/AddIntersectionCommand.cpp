/*************************************************************************
                           AddIntersectionCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <AddIntersectionCommand> (fichier AddIntersectionCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "AddIntersectionCommand.h"
#include "../geometry/InterObject.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type AddIntersectionCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


int AddIntersectionCommand::Execute( ) const
// Algorithme :
{
	try
	{
		Object* o = figure->at( params[0] );
		return -1;
	}
	catch ( const out_of_range& e )
	{
		vector<Object*> vec;
		for (int i = 1; i < params.size(); i++)
		{
			try
			{
				Object* o = figure->at(params[i]);
				return -1;
			}
			catch ( const out_of_range& e )
			{
				vec.push_back( (*figure)[params[i]] );
			}
		}
		(*figure)[params[0]] = new InterObject(	vec );
	}
	return 0;
}	//----- Fin de Execute

//------------------------------------------------- Surcharge d'op�rateurs
AddIntersectionCommand & AddIntersectionCommand::operator = ( const AddIntersectionCommand & aAddIntersectionCommand )
// Algorithme :	Si on n'est pas en train de faire aAddIntersectionCommand = aAddIntersectionCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddIntersectionCommand
{
	if ( this != &aAddIntersectionCommand )
	{
		params = aAddIntersectionCommand.params;
		figure = aAddIntersectionCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddIntersectionCommand::AddIntersectionCommand ( const AddIntersectionCommand & aAddIntersectionCommand ) :
	AddObjectCommand ( aAddIntersectionCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de AddIntersectionCommand (constructeur de copie)


AddIntersectionCommand::AddIntersectionCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de AddIntersectionCommand


AddIntersectionCommand::~AddIntersectionCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddIntersectionCommand>" << endl;
#endif
} //----- Fin de ~AddIntersectionCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
