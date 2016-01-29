/*************************************************************************
                           RestoreCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <RestoreCommand> (fichier RestoreCommand.h) ------
#if ! defined ( RESTORE_COMMAND_H )
#define RESTORE_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>

#include "ReversableCommand.h"
#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// R�le de la classe <RestoreCommand>
//
//
//------------------------------------------------------------------------ 

class RestoreCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de RestoreCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera RestoreCommand* par HeritedRestoreCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
	Object* deletedObject;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <RestoreCommand>

#endif // RESTORE_COMMAND_H
