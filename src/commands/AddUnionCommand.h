/*************************************************************************
                           AddUnionCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddUnionCommand> (fichier AddUnionCommand.h) ------
#if ! defined ( ADD_UNION_COMMAND_H )
#define ADD_UNION_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <AddUnionCommand>
// Permet d'ajouter un UnionObject a une figure existante.
//------------------------------------------------------------------------ 

class AddUnionCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute une union a la figure,
	//					si aucun autre objet n'existe dans la figure avec le nom prevu pour l'union,
	//					et si tout les composants existent.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si un objet avec le nom params[0] existe deja dans la figure.
	//								-2 si un des composants n'a pas pu etre trouve dans la figure.

	virtual AddUnionCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    AddUnionCommand & operator = ( const AddUnionCommand & unAddUnionCommand );
	// Mode d'emploi :	Reaffecte la commande courante pour la rendre en tout
	//					points similaire a unAddUnionCommand.
	// Contrat :	La desallocation de la figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    AddUnionCommand ( const AddUnionCommand & unAddUnionCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de AddUnionCommand
	//											en tout points similaire a unAddUnionCommand.

    AddUnionCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de AddUnionCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant l'UnionObject
	//					decrit par params.
	// Contrat :	params[0] doit contenir le nom avec lequel inserer l'union dans la figure.
	//				Le reste de params doit contenir des pointeurs vers les objets qui composeront l'union.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~AddUnionCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

};

#endif // ADD_UNION_COMMAND_H
