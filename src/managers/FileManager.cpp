/*************************************************************************
                           FileManager  -  description
                             -------------------
    d�but                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- R�alisation de la classe <FileManager> (fichier FileManager.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FileManager.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type FileManager::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode



Figure FileManager::Load( string fileName )
{
	return Figure( );
}

int FileManager::Save( string fileName, Figure figure )
{
	return 0;
}

//------------------------------------------------- Surcharge d'op�rateurs
FileManager & FileManager::operator = ( const FileManager & unFileManager )
// Algorithme :	Si on n'est pas en train de faire unFileManager = unFileManager, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unFileManager
{
	if (this != &unFileManager)
	{
	}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FileManager::FileManager ( const FileManager & unFileManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FileManager>" << endl;
#endif
} //----- Fin de FileManager (constructeur de copie)


FileManager::FileManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FileManager>" << endl;
#endif
} //----- Fin de FileManager


FileManager::~FileManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FileManager>" << endl;
#endif
} //----- Fin de ~FileManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
