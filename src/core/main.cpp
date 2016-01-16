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

//------------------------------------------------------------- Constantes


//------------------------------------------------------------- Fonction principale

int main( int arcg, char** argv )
{
	cout << "Hello world !" << endl;
	StringList sl;
	sl.push_back("name");
	sl.push_back("5");
	sl.push_back("-3");
	Command c( CommandCode::MOVE, sl );
	cout << c << endl;
	cout << c.GetInversedCommand() << endl;

	StringList sl2;
	sl2.push_back("name");
	sl2.push_back("5");
	sl2.push_back("5");
	sl2.push_back("0");
	sl2.push_back("-3");
	Command c2(CommandCode::S, sl2);
	cout << c2 << endl;
	cout << c2.GetInversedCommand() << endl;

	return 0;
}