/*************************************************************************
                           AddObjectCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddObjectCommand> (fichier AddObjectCommand.h) ------
#if ! defined ( ADD_OBJECT_COMMAND_H )
#define ADD_OBJECT_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>

#include "ReversableCommand.h"
#include "DeleteCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------ 
// R�le de la classe <AddObjectCommand>
//
//
//------------------------------------------------------------------------ 

class AddObjectCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual DeleteCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de AddObjectCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera AddObjectCommand* par HeritedAddObjectCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.


//------------------------------------------------- Surcharge d'op�rateurs
    AddObjectCommand & operator = ( const AddObjectCommand & unAddObjectCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddObjectCommand ( const AddObjectCommand & unAddObjectCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddObjectCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddObjectCommand ( );
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

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <AddObjectCommand>

#endif // ADD_OBJECT_COMMAND_H
