/*************************************************************************
                           AddSegmentCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <AddSegmentCommand> (fichier AddSegmentCommand.h) ------
#if ! defined ( ADD_SEGMENT_COMMAND_H )
#define ADD_SEGMENT_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <AddSegmentCommand>
// Permet d'ajouter un Segment a une figure existante.
//------------------------------------------------------------------------ 

class AddSegmentCommand : public AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute un segment a la figure,
	//					si aucun autre objet n'existe dans la figure avec le nom prevu pour le segment.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si un objet avec le nom params[0] existe deja dans la figure.

	virtual AddSegmentCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    AddSegmentCommand & operator = ( const AddSegmentCommand & unAddSegmentCommand );
	// Mode d'emploi :	Reaffecte la commande courante pour la rendre en tout
	//					points similaire a unAddSegmentCommand.
	// Contrat :	La desallocation de la figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    AddSegmentCommand ( const AddSegmentCommand & unAddSegmentCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de AddSegmentCommand
	//											en tout points similaire a unAddSegmentCommand.

    AddSegmentCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de AddRectangleCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant le segment
	//					decrit par params.
	// Contrat :	params[0] doit contenir le nom avec lequel inserer le plolygone dans la figure.
	//				Le reste de params doit contenir les points qui composeront le segment.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~AddSegmentCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

};

#endif // ADD_SEGMENT_COMMAND_H
