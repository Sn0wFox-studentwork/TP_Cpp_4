/*************************************************************************
                           AddObjectCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddObjectCommand> (fichier AddObjectCommand.h) ------
#if ! defined ( ADD_OBJECT_COMMAND_H )
#define ADD_OBJECT_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "ReversableCommand.h"
#include "DeleteCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <AddObjectCommand>
// Classe abstraite permettant d'ajouter un Object a une figure existante.
// Factorise le code de GetInversedCommand.
//------------------------------------------------------------------------ 

class AddObjectCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

    virtual DeleteCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur une commande annulant la commande courante.
	// A noter :	Les classes heritant de AddObjectCommand pourront utiliser une surcharge par
	//				type de retour covariant : on remplacera AddObjectCommand* par HeritedAddObjectCommand*.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual AddObjectCommand* Clone( ) const = 0;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    AddObjectCommand & operator = ( const AddObjectCommand & unAddObjectCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unAddObjectCommand.
	//					Les deux AddObjectCommand auront toutes les deux un pointeur vers la meme Figure.
    // Contrat :	La desallocation de cette figure reste a la charge de l'appelant.

//-------------------------------------------- Constructeurs - destructeur
    AddObjectCommand ( const AddObjectCommand & unAddObjectCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de AddObjectCommand
	//											en tout points similaire a unAddObjectCommand.

    AddObjectCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de AddObjectCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant l'objet
	//					decrit par params.
	// Contrat :	params[0] doit contenir le nom avec lequel inserer l'objet dans la figure.
	//				Le reste de params doit contenir de quoi construire l'objet. Voir les constructeurs
	//				des classes heritant de AddObjectCommand pour plus de details.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~AddObjectCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

};

#endif // ADD_OBJECT_COMMAND_H
