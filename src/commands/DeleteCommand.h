/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) ------
#if ! defined ( DELETE_COMMAND_H )
#define DELETE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "ReversableCommand.h"
#include "DeleteCommand.h"
#include "../geometry/Object.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <DeleteCommand>
//
//
//------------------------------------------------------------------------ 

class DeleteCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si l'objet a supprimer n'existait pas dans la figure.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de DeleteCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera DeleteCommand* par HeritedDeleteCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual DeleteCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

//------------------------------------------------- Surcharge d'opérateurs
    DeleteCommand & operator = ( const DeleteCommand & unDeleteCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unDeleteCommand.
	//					Les deux DeleteCommand auront toutes les deux un pointeur vers la meme Figure,
	//					et un vers le meme objet supprime.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


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
//----------------------------------------------------- Attributs protégés
	Object* deletedObject;	// Pointeur vers une copie de l'objet a supprimer

};

#endif // DELETE_COMMAND_H
