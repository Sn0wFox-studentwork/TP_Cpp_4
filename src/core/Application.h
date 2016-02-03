/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if !defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <list>

#include "../geometry/Object.h"
#include "../managers/FileManager.h"
#include "../managers/CommandManager.h"

//------------------------------------------------------------------ Types
typedef std::list<ReversableCommand*> ListCommand;
typedef ListCommand::iterator ListCmdIterator;
typedef ListCommand::const_iterator ConstListCmdIterator;

//------------------------------------------------------------------------ 
// Rôle de la classe <Application>
// Application est la plus haute couche de notre programme.
// C'est elle qui possede la figure qui contiendra les differents objets
// geometriques Objects, qui seront regroupes dans une Figure.
// C'est elle qui lira les commandes entrees par l'utilisateur et qui
// les transformera en commandes Commands executables. Elle utilisera
// par la suite son CommandManager pour executer ces commandes,
// et son FileManager pour sauvegarder ou charger un figure au format txt.
//------------------------------------------------------------------------ 

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    int Run ( );
    // Mode d'emploi :	Methode principale.
	//					Lit l'entree standard et transforme les caracteres saisis en commandes,
	//					puis tente de les faire executer.
	//					Reussir une commande autre que UNDO ou REDO apres une commande UNDO empechera l'utilisation de
	//					REDO jusqu'a une nouvelle commande UNDO reussie.
	//					Retourne 0 lorsque l'utilisateur lui passe la chaine "EXIT". Tourne en boucle sinon.
    // Contrat :	La saisie des coordonnees des points doit se faire sous la forme de nombre entiers,
	//				positifs ou negatifs.
	//				Toutes les commandes doivent etre rentrees en majuscules, a l'exception des noms des objets.
	//				Le nom des objets doivent uniquement etre des caracteres alphanumeriques.
    //				Un seul objet portant le meme nom pourra etre cree a la fois. Tenter de creer un objet du meme nom
	//				generera une erreur. Pour remplacer un objet, il faut donc utiliser une commande DELETE
	//				suivie d'une commande d'ajout d'objet.
	//				Toutes autres interrogations sur le format de saisie trouveront reponses dans le cahier des charges.
	

//------------------------------------------------- Surcharge d'opérateurs
    Application & operator= ( const Application & unApplication );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unApplication.
	//					La figure sera d'abord desallouee puis remplacee par une copie en
	//					profondeur de celle de unApplication.

//-------------------------------------------- Constructeurs - destructeur
    Application ( const Application & unApplication );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unApplication.
	//											La figure sera copiee en profondeur a partir de celle de unApplication.
    Application ( );
	// Mode d'emploi :	Instancie un nouvel objet dont les la figure sera vide,
	//					de meme que fileManager et commandManager.

    virtual ~Application ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	void takeParams( StringList& params ) const;
	// Mode d'emploi :	Ajoute les parametres rentres sur une ligne de l'entree standard dans la liste
	//					de parametres params (ajout par la fin). Chaque suite de caracteres separee des autres
	//					par un espace sera ajoutee en tant que parametre a la fin.

	void list( ) const;
	// Mode d'emploi :	Affiche toutes les formes géometrique de la Figure figure selon la norme definie
	//					par leur descripteur ToString(). Seul le nom sous lequel est connu chaque objet
	//					dans la figure sera insere, entre le code de l'objet et son nom :
	//					<code> <nom> <reste de la description>.
	//					Le reste de la description pourra tenir sur plusieurs lignes s'il s'agit d'un
	//					objet composite.

protected:
//----------------------------------------------------- Attributs protégés
	Figure figure;					// L'ensemble des formes geometriques
	FileManager fileManager;		// Permet de sauvegarder/charger une figure
	CommandManager commandManager;	// Permet la mise en place de annuler/repeter et d'executer les commandes.

};

#endif // APPLICATION_H
