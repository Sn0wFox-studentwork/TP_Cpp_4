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
// Permet de supprimer un Object existant dans une figure.
//------------------------------------------------------------------------ 

class DeleteCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : supprime l'objet avec le nom donne de la figure,
	//					s'il existe.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si l'objet a supprimer avec le nom params[0] n'existe pas dans la figure.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de DeleteCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera DeleteCommand* par HeritedDeleteCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual DeleteCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    DeleteCommand & operator = ( const DeleteCommand & unDeleteCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unDeleteCommand.
	//					Les deux DeleteCommand auront toutes les deux un pointeur vers la meme Figure,
	//					mais le pointeur vers l'objet a supprimer sera copie en profondeur.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    DeleteCommand ( const DeleteCommand & unDeleteCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de DeleteCommand
	//											en tout points similaire a unDeleteCommand.
	//											deletedObject sera copie en profondeur.

    DeleteCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de DeleteCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y supprimant l'Object
	//					decrit par params.
	// Contrat :	params[0] doit contenir le nom avec de l'objet a supprimer de la figure.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~DeleteCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	Object* deletedObject;		// Pointeur vers une copie de l'objet a supprimer

};

#endif // DELETE_COMMAND_H
