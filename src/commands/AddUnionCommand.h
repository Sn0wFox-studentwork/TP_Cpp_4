/*************************************************************************
                           AddUnionCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddUnionCommand> (fichier AddUnionCommand.h) ------
#if ! defined ( ADD_UNION_COMMAND_H )
#define ADD_UNION_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include "AddObjectCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <AddUnionCommand>
//
//
//------------------------------------------------------------------------ 

class AddUnionCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

//------------------------------------------------- Surcharge d'op�rateurs
    AddUnionCommand & operator = ( const AddUnionCommand & unAddUnionCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddUnionCommand ( const AddUnionCommand & unAddUnionCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddUnionCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddUnionCommand ( );
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

//----------------------------------------- Types d�pendants de <AddUnionCommand>

#endif // ADD_UNION_COMMAND_H
