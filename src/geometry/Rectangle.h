/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if !defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Polygone.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public Polygone
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
    // Mode d'emploi :
    //
    // Contrat :
    //

	Rectangle* Clone() const
	{
		return new Rectangle(*this);
	}

    std::string getLabel ( )
    {
        return LABEL;
    }

//------------------------------------------------- Surcharge d'opérateurs
    Rectangle & operator= ( const Rectangle & unRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Rectangle ( const std::vector<Point> & _points );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Rectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Rectangle ( );
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

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
