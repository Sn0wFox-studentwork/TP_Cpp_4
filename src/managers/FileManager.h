/*************************************************************************
                           FileManager  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <FileManager> (fichier FileManager.h) ------
#if !defined ( FILE_MANAGER_H )
#define FILE_MANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>

#include "../geometry/Object.h"
#include "../geometry/SingleObject.h"
#include "../geometry/CompositeObject.h"
#include "CommandManager.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::map<string, Object*> Figure;
typedef Figure::iterator FigureIterator;
typedef Figure::const_iterator ConstFigureIterator;

//------------------------------------------------------------------------ 
// Rôle de la classe <FileManager>
//
//
//------------------------------------------------------------------------ 

class FileManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Load ( const string& fileName, Figure* const figure, CommandManager& cmdManager ) const;
    // Mode d'emploi :	Cas non geres :
	//						Mauvais nombre d'accolades.
	//						Fichier incomplet.
	//						Accolade ne constituant pas expressement une fin de ligne (ajout de caracteres hors \r et \n).			
    //					Retourne :	0 si la figure a pu etre remplie a partir de filename.
	//								-1 si le fichier fileName n'existe pas.
	//								-2 si le nom d'un objet existe deja dans figure.
	//								-3 si un des noms d'objets du fichier apparait en double.
	//								-4 si le fichier contient une commande inconnue.
	//								-5 si un des descripteurs d'Objets n'est pas correct (mauvais nombre de coordonnees).
	//					NB : les cas pour lesquels il n'existent pas de code de retour ne seront pas geres.
    // Contrat :	L'utilisateur doit s'assurer que le fichier de nom fileName est coherent,
	//				et ne contient qu'eventuellement les erreurs pour lesquelles il existe un code de retour.

    int Save ( const string& fileName, const Figure& figure ) const;
    // Mode d'emploi :	Ecrit une description de la figure figure dans le fichier fileName.
	//					Si le fichier n'existe pas, il sera cree.
	//					Si le fichier existe, il sera ecrase sans preavis.
	//					Retourne :	0 si la figure a pu etre ecrite dans le fichier fileName.
	//								-1 si fileName n'a pas pu etre ouvert.
    // Contrat :	L'utilisateur doit s'assurer qui si le fichier existe, il peut etre ecrase.




//------------------------------------------------- Surcharge d'opérateurs
    FileManager & operator= ( const FileManager & unFileManager );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FileManager ( const FileManager & unFileManager );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FileManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FileManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	SingleObject* createSingleObject( const string& type, stringstream& sstream ) const;
	// Mode d'emploi :	
	// Contrat :	Il a ete verifier avant l'appel a cette fonction que type etait correct.
	CompositeObject* createCompositeObject( const string& type, ifstream& ifs ) const;
	// Mode d'emploi :	
	// Contrat :	Il a ete verifier avant l'appel a cette fonction que type etait correct.
	void clearBeforeAbortLoading( vector<ReversableCommand*>& v ) const;
	void clearBeforeAbortLoading( vector<Object*>& v ) const;

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <FileManager>

#endif // FILE_MANAGER_H
