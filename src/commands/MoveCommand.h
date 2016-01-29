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

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

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
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    MoveCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	On utilise une surcharge avec type de retour covariant.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual MoveCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.

	void print(){
		std::cout << "MOVE " << params[0] << " " << params[1] << " " << params[2] << std::endl;
	}


//------------------------------------------------- Surcharge d'opérateurs
    MoveCommand & operator = ( const MoveCommand & unMoveCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


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

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <MoveCommand>

#endif // MOVE_COMMAND_H
