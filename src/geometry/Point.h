/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if !defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Move( int dx, int dy );
	// Mode d'emploi :
	//
	// Contrat :
	//

	int GetX( )
	{
		return x;
	}

	int GetY( )
	{
		return y;
	}


//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetX ( ) const
    {
        return x;
    }

    int GetY ( ) const
    {
        return y;
    }


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point ( int ax, int ay );	// Notes Mehdi : les noms commencant par "_" sont generalement reserves system ;)
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
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
    int x;
    int y;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
