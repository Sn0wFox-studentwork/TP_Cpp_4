/*************************************************************************
                           Polygone  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Polygone> (fichier Polygone.h) ------
#if !defined ( POLYGONE_H )
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "SingleObject.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polygone>
//
//
//------------------------------------------------------------------------ 

class Polygone : public SingleObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains ( const Point & point );
    // Mode d'emploi :
    //
    // Contrat :
    //

	Polygone* Clone() const
	{
		return new Polygone(*this);
	}

    std::string getLabel ( )
    {
        return LABEL;
    }

//------------------------------------------------- Surcharge d'opérateurs
    Polygone & operator= ( const Polygone & unPolygone );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polygone ( const std::vector<Point> & _points );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Polygone ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polygone ( );
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
    const static int POINTS_MIN = 3;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polygone>

#endif // POLYGONE_H
