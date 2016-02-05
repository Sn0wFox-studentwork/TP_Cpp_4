**************************************************
     Bienvenue dans l'application shapes B3134 !
   C'est un manipulateur de formes en lignes de
                    commandes.
Ceci n'est pas un format de README standard, mais
   vous y trouverez de precieuses informations.
**************************************************
**************************************************
						BUILD
**************************************************
Pour construire l'application B3134 :

Lancez simplement "make" dans le dossier de ce
README.

Quelques options :
make OS=win		Compile sous windows
make OS=unix		Compile sous unix
    =>Pensez a les utiliser pour cleen et mrproper!

make clean		Detruit les fichiers .o
make mrproper		clean + detruit l'executable

make DEBUG=yes		Compile en mode debug
make DEBUG=no		Compile en mode release

A NOTER :
	L'executable se trouvera dans le dossier racine
	Les .o dans bin/ et dans le dossier du meme
	nom que les .cpp.

**************************************************
				LANCEMENT DE B3134
**************************************************
Pour lancer l'application via ce dossier :
./B3134

Vous n'avez plus qu'a l'utiliser en vous reportant
a la documentation.

**************************************************
						TESTS
**************************************************
Pour lancer les tests : (sous linux uniquement)

cd ./tests
bash mktest.sh

Vous n'avez plus qu'a consulter les resultats des
tests.

A NOTER :
	Il arrive que les tests produisent des
	"faux-negatifs". Cela vient la plupart du
	temps de l'encodage des fins de lignes.

    =>	Avant de declarer l'application buguee,
	verifiez l'encodage des fins de ligne des
	fichiers contenus dans le dossier Tests.
	Notepad++ ou tout bon editeur vous
	permettra une conversion recursive des
	fins de ligne au format unix (LF).
**************************************************
**************************************************
			Bonne utilisation !
**************************************************