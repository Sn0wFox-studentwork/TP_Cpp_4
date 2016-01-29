/*************************************************************************
                           ReversableCommand  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <ReversableCommand> (fichier ReversableCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ReversableCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type ReversableCommand::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
ReversableCommand & ReversableCommand::operator = ( const ReversableCommand & aReversableCommand )
// Algorithme :	Si on n'est pas en train de faire aReversableCommand = aReversableCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aReversableCommand
{
	if ( this != &aReversableCommand )
	{
		params = aReversableCommand.params;
		figure = aReversableCommand.figure;
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ReversableCommand::ReversableCommand ( const ReversableCommand & aReversableCommand ) :
	Command( aReversableCommand ), figure( aReversableCommand.figure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ReversableCommand>" << endl;
#endif
} //----- Fin de ReversableCommand (constructeur de copie)


ReversableCommand::ReversableCommand ( const StringList& params, Figure* const f ) :
	Command( params ), figure( f )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ReversableCommand>" << endl;
#endif
} //----- Fin de ReversableCommand


ReversableCommand::~ReversableCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ReversableCommand>" << endl;
#endif
} //----- Fin de ~ReversableCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
