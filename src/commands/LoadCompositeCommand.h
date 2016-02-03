/*************************************************************************
                      LoadCompositeCommand  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <LoadCompositeCommand> (fichier LoadCompositeCommand.h) ------
#if ! defined ( LOAD_COMPOSITE_COMMAND_H )
#define LOAD_COMPOSITE_COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "AddObjectCommand.h"

//------------------------------------------------------------------------ 
// Rôle de la classe <LoadCompositeCommand>
// Permet de charger un CompositeObject dans une figure sans avoir besoin
// que les composes existent deja dans la figure.
//------------------------------------------------------------------------ 

class LoadCompositeCommand : public	AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante : ajoute un CompositeObject a la figure
	//					(InterObject ou UnionObject suivant la valeur de params[1] : meme convention que pour Application::Run()).
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si le nom de l'objet present dans params[1] existe deja dans la figure.
	//								-2 si params[1] ne contient ni "OR" ni "OI".

	virtual LoadCompositeCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

//------------------------------------------------- Surcharge d'opérateurs
    LoadCompositeCommand & operator = ( const LoadCompositeCommand & unLoadCompositeCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a unRestoreCommand.
	//					Les deux RestoreCommand auront toutes les deux un pointeur vers la meme Figure,
	//					mais les pointeurs du vecteur de composants seront copies en profondeur.
	// Contrat :	La desallocation de cette figure reste a la charge de l'appelant.


//-------------------------------------------- Constructeurs - destructeur
    LoadCompositeCommand ( const LoadCompositeCommand & unLoadCompositeCommand );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de RestoreCommand
	//											en tout points similaire a unRestoreCommand.
	//											components et ses pointeurs seront copies en profondeur.

    LoadCompositeCommand ( const StringList& params, Figure* const f, const vector<Object*>& obj );
	// Mode d'emploi :	Cree une instance de LoadCompositeCommand qui modifiera la figure pointee
	//					par f via la liste de parametres params lors de son execution en y ajoutant un
	//					CompositeObject definie par obj sous le nom contenu dans params[0].
	// Contrat :	params[0] doit contenir le nom avec de l'objet a inserer dans la figure.
	//				L'utilisateur ne devra pas executer cette commande s'il detruit la figure pointee par f.

    virtual ~LoadCompositeCommand ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	vector<Object*> components;		// Liste de pointeurs d'objets permettant de creer un CopositeObject

};

#endif // LOAD_COMPOSITE_COMMAND_H
