/*************************************************************************
                           AddSegmentCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddSegmentCommand> (fichier AddSegmentCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AddSegmentCommand.h"
#include "../geometry/Segment.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AddSegmentCommand::Execute( ) const
// Algorithme :	On verifie que la figure ne contient pas deja un objet avec le nom prevu pour le rectangle.
//				Sinon, on retourne -1;
//				On alloue dynamiquement un segment qu'on ajoute a la figure via un pointeur.
//				On retourne 0.
{
	if ( figure->count( params[0] ) != 0 )
	{
		return -1;
	}
	else
	{
		(*figure)[params[0]] = new Segment(	Point( atoi(params[1].c_str( ) ), atoi( params[2].c_str( ) ) ),
											Point( atoi(params[3].c_str( ) ), atoi( params[4].c_str( ) ) ) );
	}
	return 0;
}	//----- Fin de Execute

AddSegmentCommand* AddSegmentCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
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
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddSegmentCommand::AddSegmentCommand ( const AddSegmentCommand & aAddSegmentCommand ) :
	AddObjectCommand ( aAddSegmentCommand )
// Algorithme :	Utilisation du constructeur de copie de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddSegmentCommand>" << endl;
#endif
}	//----- Fin de AddSegmentCommand (constructeur de copie)


AddSegmentCommand::AddSegmentCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :	Utilisation du constructeur de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <AddSegmentCommand>" << endl;
#endif
}	//----- Fin de AddSegmentCommand


AddSegmentCommand::~AddSegmentCommand ( )
// Algorithme :	Libere la memoire asociee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <AddSegmentCommand>" << endl;
#endif
	// Pas d'allocation dynamique.
}	//----- Fin de ~AddSegmentCommand
