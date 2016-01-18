/*************************************************************************
                           AddRectangleCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <AddRectangleCommand> (fichier AddRectangleCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "AddRectangleCommand.h"
#include "../geometry/Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type AddRectangleCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


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
		vec.push_back(Point(stoi(params[1]), stoi(params[2])));
		vec.push_back(Point(stoi(params[3]), stoi(params[4])));
		(*figure)[params[0]] = new Rectangle( vec );
	}
	return 0;
}	//----- Fin de Execute

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
