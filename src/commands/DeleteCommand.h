/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) ------
#if ! defined ( DELETE_COMMAND_H )
#define DELETE_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>

#include "ReversableCommand.h"
#include "DeleteCommand.h"
#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// R�le de la classe <DeleteCommand>
//
//
//------------------------------------------------------------------------ 

class DeleteCommand : public ReversableCommand
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
	// A noter :	Les classes heritant de DeleteCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera DeleteCommand* par HeritedDeleteCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.


//------------------------------------------------- Surcharge d'op�rateurs
    DeleteCommand & operator = ( const DeleteCommand & unDeleteCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DeleteCommand ( const DeleteCommand & unDeleteCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DeleteCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DeleteCommand ( );
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
	bool isComplete;
	Object* deletedObject;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <DeleteCommand>

#endif // DELETE_COMMAND_H
