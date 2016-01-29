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

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <LoadCompositeCommand>
//
//
//------------------------------------------------------------------------ 

class LoadCompositeCommand : public	AddObjectCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual int Execute( ) const;
	// Mode d'emploi :	Execute la commande courante.
	//					Retourne :	0 si tout s'est bien passe.
	//								-1 si le nom de l'objet present dans params[1] existe deja dans la figure.
	//								-2 si params[1] ne contient ni "OR" ni "OI".
	// TODO :	Mettre dans les specif generales cette histoire d'unicite du nom.

	virtual LoadCompositeCommand* Clone( ) const;
	// Mode d'emploi :	Alloue dynamiquement une commande et retourne un pointeur vers l'instance ainsi creee.


//------------------------------------------------- Surcharge d'opérateurs
    LoadCompositeCommand & operator = ( const LoadCompositeCommand & unLoadCompositeCommand );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LoadCompositeCommand ( const LoadCompositeCommand & unLoadCompositeCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LoadCompositeCommand ( const StringList& params, Figure* const f, const vector<Object*>& obj );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LoadCompositeCommand ( );
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
	vector<Object*> components;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <LoadCompositeCommand>

#endif // LOAD_COMPOSITE_COMMAND_H
