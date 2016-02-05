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

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
// Modelise un point en 2D de coordonnees x et y.
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Move( int dx, int dy );
	// Mode d'emploi :	Deplace x et y selon dx et dy respectivement.
	//					La seule limite est l'overflow.

	inline int GetX( ) const
	// Mode d'emploi :	Retourne une copie de la coordonnee selon x du point courant.
	{
		return x;
	}

	inline int GetY( ) const
	// Mode d'emploi :	Retourne une copie de la coordonnee selon x du point courant.
	{
		return y;
	}

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
	// Mode d'emploi :	Reaffecte l'objet courant pour le rendre en tout
	//					points similaire a unPoint.

	bool operator== ( const Point& unPoint ) const;
	// Mode d'emploi :	Retourne vrai si et seulement si le point courant et unPoint ont les meme coordonnees.
	//					Retourne faux sinon.

//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
	// Mode d'emploi (constructeur de copie) :	Instancie un nouvel objet pour le rendre en tout point similaire
	//											a unPoint.

    Point ( int ax, int ay );
	// Mode d'emploi :	Instancie un nouvel objet dont les coordonnees x et y seront repectivement ax et ay.

    Point ( );
	// Mode d'emploi :	Instancie un nouvel objet dont les coordonnees x et y seront 0 et 0.

    virtual ~Point ( );
	// Mode d'emploi :	Detruit l'objet courant et libere la memoire associee.
	//					Appele automatiquement.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Attributs protégés
    int x;		// Cordonees selon x
    int y;		// Cordonees selon y

};

#endif // POINT_H
