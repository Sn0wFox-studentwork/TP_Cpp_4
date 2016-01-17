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

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
typedef std::map<string, Object *> Figure;

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
    Figure Load ( string fileName );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Save ( string fileName, Figure figure );
    // Mode d'emploi :
    //
    // Contrat :
    //




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
