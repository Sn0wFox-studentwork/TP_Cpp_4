/*************************************************************************
                           AddObjectCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <AddObjectCommand> (fichier AddObjectCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AddObjectCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
DeleteCommand* AddObjectCommand::GetInversedCommand( ) const
// Algorithme :	Allocation dynamique d'une commande annulant la commande courante.
{
	StringList sl;
	sl.push_back( params[0] );
	return new DeleteCommand( sl, figure );
}	//----- Fin de GetInversedCommand( )

//------------------------------------------------- Surcharge d'opérateurs
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
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AddObjectCommand::AddObjectCommand ( const AddObjectCommand & aAddObjectCommand ) :
	ReversableCommand( aAddObjectCommand )
// Algorithme :	Utilisation du constructeur de copie de ReversableCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AddObjectCommand>" << endl;
#endif
}	//----- Fin de AddObjectCommand (constructeur de copie)


AddObjectCommand::AddObjectCommand ( const StringList& params, Figure* const f ) :
	ReversableCommand( params, f )
// Algorithme :	Utilisation du constructeur de ReversableCommand.
{
#ifdef MAP
    cout << "Appel au constructeur de <AddObjectCommand>" << endl;
#endif
}	//----- Fin de AddObjectCommand


AddObjectCommand::~AddObjectCommand ( )
// Algorithme :	Libere la memoire associee a l'objet courant.
{
#ifdef MAP
    cout << "Appel au destructeur de <AddObjectCommand>" << endl;
#endif
	// Pas d'allocation dynamique
}	//----- Fin de ~AddObjectCommand
