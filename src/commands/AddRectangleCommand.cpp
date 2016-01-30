/*************************************************************************
                           AddRectangleCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddRectangleCommand> (fichier AddRectangleCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdexcept>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "AddRectangleCommand.h"
#include "../geometry/Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int AddRectangleCommand::Execute( ) const
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
		vec.push_back(Point(atoi(params[1].c_str()), atoi(params[2].c_str())));
		vec.push_back(Point(atoi(params[3].c_str( )), atoi(params[4].c_str( ))));
		(*figure)[params[0]] = new Rectangle( vec );
	}
	return 0;
}	//----- Fin de Execute

AddRectangleCommand* AddRectangleCommand::Clone( ) const
// Algorithme :
{
	return new AddRectangleCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
AddRectangleCommand & AddRectangleCommand::operator = ( const AddRectangleCommand & aAddRectangleCommand )
// Algorithme :	Si on n'est pas en train de faire aAddRectangleCommand = aAddRectangleCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddRectangleCommand
{
	if ( this != &aAddRectangleCommand )
	{
		params = aAddRectangleCommand.params;
		figure = aAddRectangleCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddRectangleCommand::AddRectangleCommand ( const AddRectangleCommand & aAddRectangleCommand ) :
	AddObjectCommand ( aAddRectangleCommand )
// Algorithme :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddRectangleCommand>" << endl;
#endif
} //----- Fin de AddRectangleCommand (constructeur de copie)


AddRectangleCommand::AddRectangleCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddRectangleCommand>" << endl;
#endif
} //----- Fin de AddRectangleCommand


AddRectangleCommand::~AddRectangleCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddRectangleCommand>" << endl;
#endif
} //----- Fin de ~AddRectangleCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées