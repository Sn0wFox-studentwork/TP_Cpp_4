/*************************************************************************
                           FileManager  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <FileManager> (fichier FileManager.h) ------
#if ! defined ( FILE_MANAGER_H )
#define FILE_MANAGER_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <map>

#include "../geometry/Object.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::map<string, Object*> Figure;

//------------------------------------------------------------------------ 
// R�le de la classe <FileManager>
//
//
//------------------------------------------------------------------------ 

class FileManager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	Figure Load(string fileName);
    // Mode d'emploi :
    //
    // Contrat :
    //

	int Save(string fileName, Figure figure);
	// Mode d'emploi :
	//
	// Contrat :
	//




//------------------------------------------------- Surcharge d'op�rateurs
    FileManager & operator = ( const FileManager & unFileManager );
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <FileManager>

#endif // FILE_MANAGER_H
