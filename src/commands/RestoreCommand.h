/*************************************************************************
                           RestoreCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <RestoreCommand> (fichier RestoreCommand.h) ------
#if ! defined ( RESTORE_COMMAND_H )
#define RESTORE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "ReversableCommand.h"
#include "../geometry/Object.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <RestoreCommand>
//
//
//------------------------------------------------------------------------ 

class RestoreCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute une copie de l'objet pointe par
	//					deletedObjet a la figure pointe par figure.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si la figure contenanit deja un objet sous le nom de params[0].
	//								-2 si deletedObjet etait un pointeur null.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de RestoreCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera RestoreCommand* par HeritedRestoreCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual RestoreCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

//------------------------------------------------- Surcharge d'opérateurs
    RestoreCommand & operator = ( const RestoreCommand & unRestoreCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unRestoreCommand.
	//					Les deux RestoreCommand auront toutes les deux un pointeur vers la meme Figure,
	//					et un vers le meme objet supprime.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


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
//----------------------------------------------------- Attributs protégés
	Object* deletedObject;

};

#endif // RESTORE_COMMAND_H
