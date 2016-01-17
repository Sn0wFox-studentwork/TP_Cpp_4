/*************************************************************************
                           ReversableCommand  -  description
                             -------------------
    d�but                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <ReversableCommand> (fichier ReversableCommand.h) ------
#if ! defined ( REVERSABLE_COMMAND_H )
#define REVERSABLE_COMMAND_H

//--------------------------------------------------- Interfaces utilis�es
#include <map>

#include "Command.h"
#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::map<string, Object*> Figure;

//------------------------------------------------------------------------ 
// R�le de la classe <ReversableCommand>
//
//
//------------------------------------------------------------------------ 

class ReversableCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual ReversableCommand* GetInversedCommand( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de ReversableCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera ReversableCommand* par HeritedReversableCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.


//------------------------------------------------- Surcharge d'op�rateurs
    ReversableCommand & operator = ( const ReversableCommand & unReversableCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ReversableCommand ( const ReversableCommand & unReversableCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ReversableCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ReversableCommand ( );
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
	Figure* figure;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <ReversableCommand>

#endif // REVERSABLE_COMMAND_H
