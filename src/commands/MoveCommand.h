/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <MoveCommand> (fichier MoveCommand.h) ------
#if ! defined ( MOVE_COMMAND_H )
#define MOVE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "ReversableCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <MoveCommand>
// Permet de deplacer un objet present dans une figure.
//------------------------------------------------------------------------ 

class MoveCommand : public ReversableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si l'objet a deplacer n'existait pas dans la figure.

    MoveCommand* GetInversedCommand( ) const;
	// Mode d'emploi :	Retourne un pointeur sur une commande annulant la commande courante.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'utilisateur.

	virtual MoveCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    MoveCommand & operator = ( const MoveCommand & unMoveCommand );
    // Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unMoveCommand.
	//					Les deux MoveCommand auront toutes les deux un pointeur vers la meme Figure.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    MoveCommand ( const MoveCommand & unMoveCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de MoveCommand
	//											en tout points similaire a unMoveCommand.

    MoveCommand ( const StringList& params, Figure* const f );
	// Mode d'emploi :	Cree une instance de MoveCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en deplacant l'objet
	//					connu sous le nom contenu dans params[0] par f. Le deplacement se fera de params[1]
	//					selon x et de params[2] selon y.
	// Contrat :	params[0] doit contenir le nom avec de l'objet a inserer dans la figure.
	//				params[1] et params[2] doivent contenir respectivement les coordonnees du vecteur deplacement
	//				selon x et selon y.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~MoveCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

};

#endif // MOVE_COMMAND_H
