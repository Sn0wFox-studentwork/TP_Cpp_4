/*************************************************************************
						Command  -  description
						   -------------------
	début                : 11/01/2016
	copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if !defined ( COMMAND_H )
#define COMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <iostream>

//------------------------------------------------------------------ Types
typedef std::vector<std::string> StringList;

//------------------------------------------------------------------------ 
// Rôle de la classe <Command>
// Classe abstraite decrivant une commande.
// Une commande est un objet qui pourra en modifier un autre lorsqu'on
// fait appel a sa methode Execute( ).
// Permet d'implementer un command pattern pour gerer plus facilement
// la manipulation des commandes de l'application.
//------------------------------------------------------------------------ 

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	virtual int Execute( ) const = 0;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne 0 si tout s'est bien passe, une autre valeur sinon.
	//					Ces autres valeurs seront a preciser dans les surcharges de cette methode.

	inline StringList GetParams( ) const
	// Mode d'emploi :	Retourne la liste des parametres de la commande courante.
	{
		return params;
	}

	virtual Command* Clone( ) const = 0;
	// Mode d'emploi :	Alloue dynamiquement une copie de la commande courante
	//					et retourne un pointeur vers l'instance ainsi creee.
	// Contrat :	La desallocation du pointeur retourne est a la charge de l'appelant.

	//------------------------------------------------- Surcharge d'opérateurs
	Command & operator = ( const Command & aCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point similaire a aCommand.

	//-------------------------------------------- Constructeurs - destructeur
	Command( const Command & aCommand );
	// Mode d'emploi (constructeur de copie) :	Construit un objet en tout points similaire a aCommand.

	Command( const StringList& params );
	// Mode d'emploi :	Construit une instance de Command.
	//					La commande cree aura comme liste de parametres params (copie).
	// Contrat :	La liste de parametres doit etre complete, car elle ne sera pas modifiable par la suite.
	//				Valable pour toutes les classes heritant de Command.

	virtual ~Command( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
	StringList params;		// La liste des parametres de la commande.

};

#endif // COMMAND_H
