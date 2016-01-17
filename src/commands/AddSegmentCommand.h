/*************************************************************************
                           AddSegmentCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddSegmentCommand> (fichier AddSegmentCommand.h) ------
#if ! defined ( ADD_SEGMENT_COMMAND_H )
#define ADD_SEGMENT_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include "ReversableCommand.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <AddSegmentCommand>
//
//
//------------------------------------------------------------------------ 

class AddSegmentCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	// TODO :	Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    AddSegmentCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	On utilise une surcharge avec type de retour covariant.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	void print(){
		std::cout << "s " << params[0] << " " << params[1] << " " << params[2] << " " << params[3] << " " << params[4] << std::endl;
	}


//------------------------------------------------- Surcharge d'op�rateurs
    AddSegmentCommand & operator = ( const AddSegmentCommand & unAddSegmentCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AddSegmentCommand ( const AddSegmentCommand & unAddSegmentCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AddSegmentCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddSegmentCommand ( );
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

//----------------------------------------- Types d�pendants de <AddSegmentCommand>

#endif // ADD_SEGMENT_COMMAND_H
