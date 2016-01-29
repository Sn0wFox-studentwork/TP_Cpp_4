/*************************************************************************
                           AddPolygonCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddPolygonCommand> (fichier AddPolygonCommand.h) ------
#if ! defined ( ADD_POLYGON_COMMAND_H )
#define ADD_POLYGON_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include "AddObjectCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <AddPolygonCommand>
//
//
//------------------------------------------------------------------------ 

class AddPolygonCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

//------------------------------------------------- Surcharge d'op�rateurs
    AddPolygonCommand & operator = ( const AddPolygonCommand & unAddPolygonCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddPolygonCommand ( const AddPolygonCommand & unAddPolygonCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddPolygonCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddPolygonCommand ( );
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

//----------------------------------------- Types d�pendants de <AddPolygonCommand>

#endif // ADD_POLYGON_COMMAND_H
