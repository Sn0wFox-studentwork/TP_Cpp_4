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

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::vector<std::string> StringList;

//------------------------------------------------------------------------ 
// Rôle de la classe <Command>
//
//
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
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.

	//------------------------------------------------- Surcharge d'opérateurs
	Command & operator = ( const Command & aCommand );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout point semblable a aCommand.
	//					Retourne l'objet modifie par reference.

	//-------------------------------------------- Constructeurs - destructeur
	Command( const Command & aCommand );
	// Mode d'emploi (constructeur de copie) :	Construit un objet en tout points similaire a aCommand.

	Command( const StringList& params );
	// Mode d'emploi :	Construit une instance de Command.
	//					La commande cree aura comme liste de parametres params (copie).
	// Contrat :	La liste de parametres doit etre complete, car elle ne sera pas modifiable par la suite.

	virtual ~Command( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
	StringList params;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Command>

#endif // COMMAND_H
