/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 11/01/2016
    copyright            : (C) 2016 par Baha & Pericas-Moya
*************************************************************************/

//---------- Réalisation de la classe <Command> (fichier Command.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Command.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Command Command::GetInversedCommand ( ) const
// Algorithme :	switch sut le code de la commande courante cmdCode.
//				Retourne l'a commande qui aura l'effet oppose de la commande courante.
{
    StringList sl;

    switch ( cmdCode )
    {
        // Cas de la creation d'un objet : commande inverse = delete
        case S:
        case R:
        case PC:
        case OR:
        case OI:
            sl.push_back( params[0] );
            return Command( CommandCode::DELETE, sl );
            // Cas du deplacement
        case MOVE:
            sl.push_back( params[0] );    // Push du nom de l'objet
            for ( unsigned int i = 1 ; i < params.size( ) ; i++ )
            {
                if ( params[i].substr( 0, 1 ) == "-" )
                {
                    sl.push_back( params[i].substr( 1, params[i].size( ) - 1 ));
                }
                else
                {
                    sl.push_back( "-" + params[i] );
                }
            }
            return Command( CommandCode::MOVE, sl );
            // Cas du load
        case LOAD:
            break;
            // Cas des commandes dont l'inverse sera geree via la pile des commandes annulees
        case DELETE:
        case HIT:
        case CLEAR:
        case UNSAVEABLE:
            break;
        default:
            break;
    }
    return Command( CommandCode::UNSAVEABLE, StringList( ));
}    //----- Fin de GetInversedCommand


//------------------------------------------------- Surcharge d'opérateurs
Command & Command::operator= ( const Command & aCommand )
// Algorithme :	Si on n'est pas en train de faire aCommand = aCommand, on "copie" tout les champs :
//				on les modifie pour qu'ils soient comme ceux de aCommand
{
    if ( this != &aCommand )
    {
        cmdCode = aCommand.cmdCode;
        params = aCommand.params;
    }
    return *this;
}    //----- Fin de operator =


ostream & operator<< ( ostream & s, Command c )
// Algorithme :	On insere dans le flux de sortie s la representation du code de la commande c
//				sous forme de string, suivie d'un espace.
//				On insere ensuite la liste des parametres de c (qui sont deja des strings)
//				en separant les parametres par un espace.
//				On retourne le flux s ainsi modifie par reference.
{
    switch ( c.cmdCode )
    {
        case S:
            s << "S ";
            break;
        case R:
            s << "R ";
            break;
        case PC:
            s << "PC ";
            break;
        case OR:
            s << "OR ";
            break;
        case OI:
            s << "OI ";
            break;
        case HIT:
            s << "HIT ";
            break;
        case DELETE:
            s << "DELETE ";
            break;
        case CLEAR:
            s << "CLEAR ";
            break;
        case MOVE:
            s << "MOVE ";
            break;
        default:
            break;
    }

    for ( unsigned int i = 0 ; i < c.params.size( ) ; i++ )
    {
        s << c.params[i] << " ";
    }
    return s;

}    //----- Fin de operator<<

//-------------------------------------------- Constructeurs - destructeur
Command::Command ( const Command & aCommand ) : cmdCode( aCommand.cmdCode ), params( aCommand.params )
// Algorithme : utilisation des constructeurs de copie de CommandCode (int) et StringList (std::vector<string>).
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Command>" << endl;
#endif
} //----- Fin de Command (constructeur de copie)


Command::Command ( const CommandCode & c, const StringList & p ) : cmdCode( c ), params( p )
// Algorithme :	Utilisation des constructeurs de copie de CommandCode (int) et StringList (std::vector<string>).
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- Fin de Command


Command::~Command ( )
// Algorithme :	Liberation de la memoire.
{
#ifdef MAP
    cout << "Appel au destructeur de <Command>" << endl;
#endif
    // Pas d'allocation dynamique.
} //----- Fin de ~Command


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
