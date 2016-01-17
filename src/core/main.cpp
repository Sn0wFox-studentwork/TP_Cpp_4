/*************************************************************************
							main  -  description
-------------------
début                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de <main> (fichier main.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "../commands/MoveCommand.h"

//------------------------------------------------------------- Constantes


//------------------------------------------------------------- Fonction principale

int main( int arcg, char** argv )
{
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
}