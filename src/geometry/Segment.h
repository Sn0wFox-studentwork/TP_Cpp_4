/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier Segment.h) ------
#if !defined ( SEGMENT_H )
#define SEGMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "SingleObject.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Segment>
//
//
//------------------------------------------------------------------------ 

class Segment : public SingleObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contains ( const Point & point );
    // Mode d'emploi :
    //
    // Contrat :
    //

<<<<<<< HEAD
	void Print() const
	{
		std::cout << "S ";
		SingleObject::Print();
	}

=======
    std::string getLabel ( )
    {
        return LABEL;
    }
>>>>>>> origin/master

//------------------------------------------------- Surcharge d'opérateurs
    Segment & operator= ( const Segment & unSegment );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

<<<<<<< HEAD
    Segment ( Point p1, Point p2 );
=======
    Segment ( const std::vector<Point> & _points );
>>>>>>> origin/master
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Segment ( );
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
    const static int POINTS_MAX = 2;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Segment>

#endif // SEGMENT_H
