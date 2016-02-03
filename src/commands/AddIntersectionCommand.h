/*************************************************************************
                           AddIntersectionCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddIntersectionCommand> (fichier AddIntersectionCommand.h) ------
#if ! defined ( ADD_INTERSECTION_COMMAND_H )
#define ADD_INTERSECTION_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <AddIntersectionCommand>
// Permet d'ajouter un InterObject a une figure existante.
//------------------------------------------------------------------------ 

class AddIntersectionCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute une intersection a la figure,
	//					si aucun autre objet n'existe dans la figure avec le nom prevu pour l'intersection,
	//					et si tout les composants existent.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si un objet avec le nom params[0] existe deja dans la figure.
	//								-2 si un des composants n'a pas pu etre trouve dans la figure.

	virtual AddIntersectionCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    AddIntersectionCommand & operator = ( const AddIntersectionCommand & unAddIntersectionCommand );
    // Mode d'emploi :	Reaffecte la commande courante pour la rendre en tout
	//					points similaire a unAddIntersectionCommand.
	// Contrat :	La desallocation de la figure reste a la charge de l'appelant.

//-------------------------------------------- Constructeurs - destructeur
    AddIntersectionCommand ( const AddIntersectionCommand & unAddIntersectionCommand );
    // Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de AddIntersectionCommand
	//											en tout points similaire a unAddIntersectionCommand.

    AddIntersectionCommand ( const StringList& params, Figure* const f );
    // Mode d'emploi :	Cree une instance de AddIntersectionCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant l'InterObject
	//					decrit par params.
    // Contrat :	params[0] doit contenir le nom avec lequel inserer l'intersection dans la figure.
    //				Le reste de params doit contenir des pointeurs vers les objets qui composeront l'intersection.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~AddIntersectionCommand ( );
    // Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

};

#endif // ADD_INTERSECTION_COMMAND_H
