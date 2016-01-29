/*************************************************************************
                           RestoreCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <RestoreCommand> (fichier RestoreCommand.h) ------
#if ! defined ( RESTORE_COMMAND_H )
#define RESTORE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "ReversableCommand.h"
#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// Rôle de la classe <RestoreCommand>
//
//
//------------------------------------------------------------------------ 

class RestoreCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de RestoreCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera RestoreCommand* par HeritedRestoreCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual RestoreCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.

//------------------------------------------------- Surcharge d'opérateurs
    RestoreCommand & operator = ( const RestoreCommand & unRestoreCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    RestoreCommand ( const RestoreCommand & unRestoreCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RestoreCommand ( const StringList& params, Figure* const f, Object* const delObject );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RestoreCommand ( );
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
	Object* deletedObject;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <RestoreCommand>

#endif // RESTORE_COMMAND_H
