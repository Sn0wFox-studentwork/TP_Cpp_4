/*************************************************************************
                           AddRectangleCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddRectangleCommand> (fichier AddRectangleCommand.h) ------
#if ! defined ( ADD_RECTANGLE_COMMAND_H )
#define ADD_RECTANGLE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AddRectangleCommand>
//
//
//------------------------------------------------------------------------ 

class AddRectangleCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

	virtual AddRectangleCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.

//------------------------------------------------- Surcharge d'opérateurs
    AddRectangleCommand & operator = ( const AddRectangleCommand & unAddRectangleCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddRectangleCommand ( const AddRectangleCommand & unAddRectangleCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddRectangleCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddRectangleCommand ( );
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

//----------------------------------------- Types dépendants de <AddRectangleCommand>

#endif // ADD_RECTANGLE_COMMAND_H
