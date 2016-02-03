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
// Permet de reinserer un Object ayant existe dans une figure.
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
	//								-1 si la figure contenait deja un objet sous le nom de params[0].
	//								-2 si deletedObjet etait un pointeur null.

    virtual ReversableCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur la commande annulant la commande courante.
	// A noter :	Les classes heritant de RestoreCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera RestoreCommand* par HeritedRestoreCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual RestoreCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    RestoreCommand & operator = ( const RestoreCommand & unRestoreCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unRestoreCommand.
	//					Les deux RestoreCommand auront toutes les deux un pointeur vers la meme Figure,
	//					mais le pointeur vers l'objet a supprimer sera copie en profondeur.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    RestoreCommand ( const RestoreCommand & unRestoreCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de RestoreCommand
	//											en tout points similaire a unRestoreCommand.
	//											deletedObject sera copie en profondeur.

    RestoreCommand ( const StringList& params, Figure* const f, Object* const delObject );
	// Mode d'emploi :	Cree une instance de RestoreCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant un copie de l'Object
	//					pointe par delObject sous le nom contenu dans params[0].
	// Contrat :	params[0] doit contenir le nom avec de l'objet a inserer dans la figure.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~RestoreCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	Object* deletedObject;		// L'objet a restaurer dans la figure

};

#endif // RESTORE_COMMAND_H
