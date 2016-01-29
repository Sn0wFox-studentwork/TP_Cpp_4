/*************************************************************************
                           ReversableCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <ReversableCommand> (fichier ReversableCommand.h) ------
#if ! defined ( REVERSABLE_COMMAND_H )
#define REVERSABLE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "Command.h"
#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::map<string, Object*> Figure;

//------------------------------------------------------------------------ 
// Rôle de la classe <ReversableCommand>
//
//
//------------------------------------------------------------------------ 

class ReversableCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual ReversableCommand* GetInversedCommand( ) const = 0;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de ReversableCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera ReversableCommand* par HeritedReversableCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual ReversableCommand* Clone( ) const = 0;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.


//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	Figure* figure;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <ReversableCommand>

#endif // REVERSABLE_COMMAND_H
