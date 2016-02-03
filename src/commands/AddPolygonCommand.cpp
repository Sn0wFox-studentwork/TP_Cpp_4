/*************************************************************************
                           AddPolygonCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddPolygonCommand> (fichier AddPolygonCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AddPolygonCommand.h"
#include "../geometry/Polygone.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AddPolygonCommand::Execute( ) const
// Algorithme :	On verifie que la figure ne contient pas deja un objet avec le nom prevu pour le polygone.
//				Sinon, on retourne -1;
//				On instancie dynamiquement le polygone et on verifie qu'il est bien convexe.
//				Sinon, on libere la memoire de ce polygone et on retourne -2.
//				On ajoute a la figure le polygone.
//				On retourne 0.
{
	if ( figure->count( params[0] ) != 0 )
	{
		return -1;
	}
	else
	{
		vector<Point> vec;
		for ( int i = 1; i+1 < params.size(); i+=2 )
		{
			vec.push_back( Point( atoi( params[i].c_str( ) ), atoi( params[i + 1].c_str( ) ) ) );
		}

		Polygone * p = new Polygone( vec );
		if ( p->IsConvex( ))
		{
			( *figure )[params[0]] = p;
		}
		else
		{
			delete p;
			return -2;
		}
	}
	return 0;
}	//----- Fin de Execute

AddPolygonCommand* AddPolygonCommand::Clone( ) const
// Algorithme :	Retour d'un pointeur vers une copie de l'objet courant allouee dynamiquement.
{
	return new AddPolygonCommand( *this );
}	//----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs
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
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddPolygonCommand::AddPolygonCommand ( const AddPolygonCommand & aAddPolygonCommand ) :
	AddObjectCommand ( aAddPolygonCommand )
// Algorithme :	Utilisation du constructeur de copie de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddPolygonCommand>" << endl;
#endif
}	//----- Fin de AddPolygonCommand (constructeur de copie)


AddPolygonCommand::AddPolygonCommand ( const StringList& params, Figure* const f ) :
	AddObjectCommand( params, f )
// Algorithme :	Utilisation du constructeur de AddObjectCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <AddPolygonCommand>" << endl;
#endif
}	//----- Fin de AddPolygonCommand


AddPolygonCommand::~AddPolygonCommand ( )
// Algorithme :	Libere la memoire asociee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <AddPolygonCommand>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~AddPolygonCommand
