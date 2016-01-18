/*************************************************************************
                           AddIntersectionCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddIntersectionCommand> (fichier AddIntersectionCommand.h) ------
#if ! defined ( ADD_INTERSECTION_COMMAND_H )
#define ADD_INTERSECTION_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AddIntersectionCommand>
//
//
//------------------------------------------------------------------------ 

class AddIntersectionCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

//------------------------------------------------- Surcharge d'opérateurs
    AddIntersectionCommand & operator = ( const AddIntersectionCommand & unAddIntersectionCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddIntersectionCommand ( const AddIntersectionCommand & unAddIntersectionCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddIntersectionCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddIntersectionCommand ( );
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

//----------------------------------------- Types dépendants de <AddIntersectionCommand>

#endif // ADD_INTERSECTION_COMMAND_H
