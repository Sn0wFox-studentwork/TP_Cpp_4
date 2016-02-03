/*************************************************************************
                           AddPolygonCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddPolygonCommand> (fichier AddPolygonCommand.h) ------
#if ! defined ( ADD_POLYGON_COMMAND_H )
#define ADD_POLYGON_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <AddPolygonCommand>
// Permet d'ajouter un Polygone a une figure existante.
//------------------------------------------------------------------------ 

class AddPolygonCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute un polygone a la figure,
	//					si aucun autre objet n'existe dans la figure avec le nom prevu pour le polygone.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si un objet avec le nom params[0] existe deja dans la figure.

	virtual AddPolygonCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    AddPolygonCommand & operator = ( const AddPolygonCommand & unAddPolygonCommand );
	// Mode d'emploi :	Reaffecte la commande courante pour la rendre en tout
	//					points similaire a unAddPolygonCommand.
	// Contrat :	La desallocation de la figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    AddPolygonCommand ( const AddPolygonCommand & unAddPolygonCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de AddPolygonCommand
	//											en tout points similaire a unAddPolygonCommand.

    AddPolygonCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de AddPolygonCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant le polygone
	//					decrit par params.
	// Contrat :	params[0] doit contenir le nom avec lequel inserer le plolygone dans la figure.
	//				Le reste de params doit contenir les points qui composeront le polygone.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~AddPolygonCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

};

#endif // ADD_POLYGON_COMMAND_H
