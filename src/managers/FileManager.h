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
// Permet de charger ou de sauvegarder une figure.
// Le format de fichier a charger doit etre celui ci :
//		<code> <nomObjet> <liste points>	, pour les objets simples
//		<code> <nomObjet> {
//		<code (du composant)> <liste points>
//		...
//		}									, pour les objets composites.
// Cette description est recursive.
//	<code>			: S ou R ou PC ou OI ou OR
//	<nom>			: le nom de l'objet
//	<liste points>	: la liste des points de l'objet au format : X Y
//------------------------------------------------------------------------ 

class FileManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Load ( const string& fileName, Figure* const figure, CommandManager& cmdManager ) const;
    // Mode d'emploi :	Tente de charger les objets decrits dans le fichier fileName dans la Figure pointee par figure.
	//					fileName peut etre le chemin vers le fichier.
    //					Retourne :	0 si la figure a pu etre remplie a partir de fileName.
	//								-1 si le fichier fileName n'existe pas.
	//								-2 si le nom d'un objet existe deja dans figure.
	//								-3 si un des noms d'objets du fichier apparait en double.
	//								-4 si le fichier contient une commande inconnue.
	//								-5 si un des descripteurs d'Objets n'est pas correct (mauvais nombre de coordonnees).
	//								Un nombre strictement positif si au moins une des commandes de creation s'est mal passe.
	//					NB : les cas pour lesquels il n'existe pas de code de retour ne seront pas geres.
    // Contrat :	L'utilisateur doit s'assurer que le fichier de nom fileName est coherent,
	//				et ne contient qu'eventuellement les erreurs pour lesquelles il existe un code de retour.

    int Save ( const string& fileName, const Figure& figure ) const;
    // Mode d'emploi :	Ecrit une description de la Figure figure dans le fichier fileName.
	//					Si le fichier n'existe pas, il sera cree.
	//					Si le fichier existe, il sera ecrase sans preavis.
	//					Si fileName specifie un chemin inexistant, l'ouverture echouera.
	//					Retourne :	0 si la figure a pu etre ecrite dans le fichier fileName.
	//								-1 si fileName n'a pas pu etre ouvert.
    // Contrat :	L'utilisateur doit s'assurer qui si le fichier existe, il peut etre ecrase.

//------------------------------------------------- Surcharge d'opérateurs
    FileManager & operator= ( const FileManager & unFileManager );
	// Mode d'emploi :	Reaffecte le FileManager courant pour le rendre en tout
	//					points similaire a unFileManager.

//-------------------------------------------- Constructeurs - destructeur
    FileManager ( const FileManager & unFileManager );
	// Mode d'emploi (constructeur de copie) :	Construit une nouvelle instance de FileManager
	//											en tout points similaire a unFileManager.

    FileManager ( );
    // Mode d'emploi :	Cree une instance de FileManager apte a etre utilisee.

    virtual ~FileManager ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	SingleObject* createSingleObject( const string& type, stringstream& sstream ) const;
	// Mode d'emploi :	Retourne un pointeur vers un Objet allouee dynamiquement d'apres les informations
	//					contenue dans type et sstream :
	//					Segment pour type = "S"
	//					Rectangle pour type = "R"
	//					Polygone pour type = "PC"
	// Contrat :	Il a ete verifier avant l'appel a cette fonction que type etait correct : S ou R ou PC.
	//				sstream doit contenir de quoi creer l'objet : son nom puis les coordonnees de ses points,
	//				separes sans exception par des espaces.
	//				Le desallocation du pointeur retourne est a la charge de l'utilisateur.

	CompositeObject* createCompositeObject( const string& type, ifstream& ifs ) const;
	// Mode d'emploi :	Retourne un pointeur vers un Objet allouee dynamiquement d'apres les informations
	//					contenue dans type et ifs.
	// Contrat :	Il a ete verifier avant l'appel a cette fonction que type etait correct : OI ou OR.
	//				ifs doit contenir de quoi creer l'objet : son nom puis les objets qui le composent
	//				separes par un saut de ligne. Les objets le composant doivent etre decrit de la meme maniere
	//				que pour la methode createSingleObject (si ce sont des objets simples) ou que pour cette methode
	//				(si ce sont des objets composites), prive de leur nom.
	//				Le desallocation du pointeur retourne est a la charge de l'utilisateur.

	void clearBeforeAbortLoading( vector<ReversableCommand*>& v ) const;
	// Mode d'emploi :	Desalloue les commandes du vecteur v.
	// Contrat :	Les commandes doivent etre aptes a etre desalouees.

	void clearBeforeAbortLoading( vector<Object*>& v ) const;
	// Mode d'emploi :	Desalloue les objets du vecteur v.
	// Contrat :	Les objets doivent etre aptes a etre desaloues.

};

#endif // FILE_MANAGER_H
