/*************************************************************************
                           AddObjectCommand  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <AddObjectCommand> (fichier AddObjectCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AddObjectCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type AddObjectCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


DeleteCommand * AddObjectCommand::GetInversedCommand( ) const
{
	StringList sl;
	sl.push_back( params[0] );
	return new DeleteCommand( sl, figure );
}

//------------------------------------------------- Surcharge d'op�rateurs
AddObjectCommand & AddObjectCommand::operator = ( const AddObjectCommand & aAddObjectCommand )
// Algorithme :	Si on n'est pas en train de faire aAddObjectCommand = aAddObjectCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aAddObjectCommand
{
	if ( this != &aAddObjectCommand )
	{
		params = aAddObjectCommand.params;
		figure = aAddObjectCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddObjectCommand::AddObjectCommand ( const AddObjectCommand & aAddObjectCommand ) :
	ReversableCommand( aAddObjectCommand )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddObjectCommand>" << endl;
#endif
} //----- Fin de AddObjectCommand (constructeur de copie)


AddObjectCommand::AddObjectCommand ( const StringList& params, Figure* const f ) :
	ReversableCommand( params, f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AddObjectCommand>" << endl;
#endif
} //----- Fin de AddObjectCommand


AddObjectCommand::~AddObjectCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AddObjectCommand>" << endl;
#endif
} //----- Fin de ~AddObjectCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
