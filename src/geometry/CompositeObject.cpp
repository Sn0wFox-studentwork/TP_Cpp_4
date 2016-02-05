/*************************************************************************
                           CompositeObject  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <CompositeObject> (fichier CompositeObject.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "CompositeObject.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void CompositeObject::Move( int dx, int dy )
// Algorithme :	Utilisation la methode Move sur chacun des composants.
//				On peut donc faire des appels a Move d'un CompositeObject sans probleme.
{
	for ( Object* o : components )
	{
		o->Move( dx, dy );
	}
}	//----- Fin de Move

std::string CompositeObject::ToString( ) const
// Algorithme :	Utilisation d'un stringstream pour plus de praticite.
//				On insere dans le flux le label de l'object courant, suivi d'une
//				accollade ouvrante et d'un retour a la ligne sous la forme d'un \n.
//				On appelle ensuite ToString sur chacun des composants et on insere la string retourne dans le flux,
//				en retournant a la ligne via un \n a chaque fois.
//				On peut donc faire des appels a ToString d'un CompositeObject sans probleme.
//				On termine par inserer sur une nouvelle ligne une accolade fermante,
//				et on retourne le flux transforme en string.
//				Pas de retour a la ligne final.
{
	ostringstream os;
	os << GetLabel() << " {" << "\n";
	for ( Object* o : components )
	{
		os << o->ToString( ) << "\n";
	}
	os << "}";

	return os.str( );
}	//----- Fin de ToString


//------------------------------------------------- Surcharge d'opérateurs
CompositeObject & CompositeObject::operator= ( const CompositeObject & unCompositeObject )
// Algorithme :	Si on n'est pas en train de faire unCompositeObject = unCompositeObject, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de unCompositeObject.
//				On libere la memoire des anciens composants de l'objet courant,
//				puis on copie en profondeur ceux de unCompositeObject.
{
    if ( this != &unCompositeObject )
    {
		for ( Object * o : components )
		{
			delete o;
		}
		components.resize( 0 );
		for ( Object * o : unCompositeObject.components )
		{
			components.push_back( o->Clone( ) );
		}
    }
    return *this;
}	//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CompositeObject::CompositeObject ( const CompositeObject & unCompositeObject ) : Object ( )
// Algorithme :	On copie en profondeur chaque composant via Clone.
//				On peut donc tout a fait appeler le Clone d'un CompositeObject.
{
	for ( Object * o : unCompositeObject.components )
	{
		components.push_back( o->Clone( ) );
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <CompositeObject>" << endl;
#endif
}	//----- Fin de CompositeObject (constructeur de copie)


CompositeObject::CompositeObject ( const Components& c ) : Object( )
// Algorithme :	Pour chaque pointeurs de c, on realise une copie en profondeur via Clone et on stocke
//				le pointeur a la fin de components.
{
	for ( Object * o : c )
	{
		components.push_back( o->Clone( ) );
	}
#ifdef MAP
    cout << "Appel au constructeur de <CompositeObject>" << endl;
#endif
}	//----- Fin de CompositeObject

CompositeObject::CompositeObject ( ) : Object( ), components( )
// Algorithme :	Utilisation des constructeurs par defaut de Object et vector<Object*>.
{
#ifdef MAP
    cout << "Appel au constructeur de <CompositeObject>" << endl;
#endif
}	//----- Fin de CompositeObject


CompositeObject::~CompositeObject ( )
// Algorithme :	Liberation de la memoire associee a l'objet courant (celle de chaque composant).
{
	for ( Object * o : components )
	{
		delete o;
	}
#ifdef MAP
    cout << "Appel au destructeur de <CompositeObject>" << endl;
#endif
}	//----- Fin de ~CompositeObject
