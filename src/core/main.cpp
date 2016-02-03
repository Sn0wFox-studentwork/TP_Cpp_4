/*************************************************************************
							main  -  description
-------------------
début                : 11/01/2016
copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de <main> (fichier main.cpp) --

//----------------------------------------------- Constantes préprocesseur
//#define VLD	// Vld est un outil propre a Visual Studio qui a un fonctionnement similaire a Valgrind.
				// Enlever le commentaire devant la ligne precedente aura pour effet de l'activer.
				// (si vous possedez Vld)

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

//------------------------------------------------------------- Fonction principale

int main ( int arcg, char ** argv )
// Algorithme :	Point d'entree du programme.
//				Instancie une application, et retourne la valeur retournee par Run().
{
	Application app;
	return app.Run( );
}	//----- Fin de main