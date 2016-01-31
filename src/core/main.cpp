/*************************************************************************
							main  -  description
-------------------
début                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de <main> (fichier main.cpp) --

//----------------------------------------------- Constantes préprocesseur
//#define VLD

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#ifdef VLD
	#include <vld.h>
#endif

using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "../geometry/Segment.h"
#include "../geometry/Rectangle.h"
#include "../geometry/UnionObject.h"
#include "../geometry/InterObject.h"

//------------------------------------------------------------- Constantes


//------------------------------------------------------------- Fonction principale

int main ( int arcg, char ** argv )
{
	Application app;

	Object * o1 = new Segment( Point( 0, 0 ), Point( 1, 1 ));
	//o1->Print();
	vector<Point> vec1 = { Point( 0, 2 ), Point( 2, 0 ) };
	Object * o2 = new Rectangle( vec1 );
	//o2->Print();
	vector<Object *> vecs = { o1, o2 };
	Object * o3 = new UnionObject( vecs );
	o3->Print( );
	Object * o4 = new InterObject( vecs );
	o4->Print( );
	vector<Object *> vecs2 = { o3, o4 };
	cout << "Réunion de Composites" << endl;
	Object * o5 = new UnionObject( vecs2 );
	o5->Print( );
	return app.Run( );
}