/*************************************************************************
                           InterObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <InterObject> (fichier InterObject.h) ------
#if !defined ( INTER_OBJECT_H )
#define INTER_OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "CompositeObject.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <InterObject>
//
//
//------------------------------------------------------------------------ 

class InterObject : public CompositeObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string getLabel ( ) const
    {
        return LABEL;
    }

	InterObject* Clone() const
	{
		return new InterObject(*this);
	}

//------------------------------------------------- Surcharge d'opérateurs
    InterObject & operator= ( const InterObject & unInterObject );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    InterObject ( const InterObject & unInterObject );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    InterObject ( const std::vector<Object *> & _components );
    // Mode d'emploi :
    //
    // Contrat :
    //

    InterObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~InterObject ( );
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
    const static std::string LABEL;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <InterObject>

#endif // INTER_OBJECT_H
