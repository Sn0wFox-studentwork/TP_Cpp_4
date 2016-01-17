/*************************************************************************
							main  -  description
-------------------
début                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de <main> (fichier main.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "../commands/MoveCommand.h"

//------------------------------------------------------------- Constantes


//------------------------------------------------------------- Fonction principale

int main ( int arcg, char ** argv )
{
<<<<<<< HEAD
	cout << "Hello world !" << endl;
	StringList sl;
	Figure f;
	sl.push_back("name");
	sl.push_back("5");
	sl.push_back("-3");
	MoveCommand c( sl, &f );
	CommandManager cm;
	MoveCommand* c2 = c.GetInversedCommand( );
	c.print();
	c2->print();


	Application app;

	return app.Run( );
=======
    cout << "Hello world !" << endl;
    StringList sl;
    sl.push_back( "name" );
    sl.push_back( "5" );
    sl.push_back( "-3" );
    Command c( CommandCode::MOVE, sl );
    cout << c << endl;
    cout << c.GetInversedCommand( ) << endl;

    StringList sl2;
    sl2.push_back( "name" );
    sl2.push_back( "5" );
    sl2.push_back( "5" );
    sl2.push_back( "0" );
    sl2.push_back( "-3" );
    Command c2( CommandCode::S, sl2 );
    cout << c2 << endl;
    cout << c2.GetInversedCommand( ) << endl;

    /* Point a1 = Point(0,0);
    Point b1 = Point(4,2);
    Point c = Point(2,1);

    std::vector<Point> points (10);
    points[0] = a1;
    points[1] = b1;

    Segment s(points);

    cout << "RESULT :" << s.Contains(c) << endl; */

    return 0;
>>>>>>> origin/master
}