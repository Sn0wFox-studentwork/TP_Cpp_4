/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <MoveCommand> (fichier MoveCommand.h) ------
#if ! defined ( MOVE_COMMAND_H )
#define MOVE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "ReversableCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <MoveCommand>
//
//
//------------------------------------------------------------------------ 

class MoveCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si l'objet a deplacer n'existait pas dans la figure.

    MoveCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual MoveCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.

//------------------------------------------------- Surcharge d'opérateurs
    MoveCommand & operator = ( const MoveCommand & unMoveCommand );
    // Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unMoveCommand.
	//					Les deux MoveCommand auront toutes les deux un pointeur vers la meme Figure.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    MoveCommand ( const MoveCommand & unMoveCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MoveCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MoveCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

};

#endif // MOVE_COMMAND_H
