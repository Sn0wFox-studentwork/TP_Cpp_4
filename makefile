#Rappels elementaires-------------------------------------------
#
#	$@ : adresse de la cible
#	$< : premiere dependance
#	$^ : liste des dependances
#	$? : liste des dependances plus recentes que la cible
#	$* : le nom du fichier sans suffixe
#
#---------------------------------------------------------------

#Notes----------------------------------------------------------
#
#	Makefile bati dans le but de construire l'application shapes
#	resultat du tp de c++ numero 4, 01/2016.
#	Construit les binaires translatables dans le dossier
#	bin/xxx, a partir des sources presentes dans src/xxx.
#	L'executable final se trouvera a la racine de bin/.
#
#---------------------------------------------------------------

#Variables generales--------------------------------------------
OSUNIX = unix
OSWIN = win
OS = $(OSUNIX)
CD =
DEL =
DELOPT =
CC = g++
MAINFILE = main
OFILE = o
SRCFILE = cpp
HEADFILE = h
EXEFILE =

DEBUG = no

SRCPATH = src/
SRC = $(wildcard $(SRCPATH)*/*.$(SRCFILE))
OBJPATH = bin/
TEMPOBJ = $(SRC:.$(SRCFILE)=.$(OFILE))
OBJ = $(TEMPOBJ:$(SRCPATH)%=$(OBJPATH)%)

EXEPATH =
EXE1 = $(EXEPATH)B3134$(EXEFILE)
EXE2 =
EXECS = $(EXE1) $(EXE2)
#---------------------------------------------------------------

#Variables pour les options de compilation----------------------
W = -W
WA = -Wall
STDLIB = -std=c++11
GGDB = -ggdb

CFLAGS =
#---------------------------------------------------------------

#Compilation conditionnelle-------------------------------------
ifeq ($(OS),$(OSWIN))
	DEL += del
	DELOPT += /s
	CD = cd
else ifeq ($(OS),$(OSUNIX))
	DEL += rm
	DELOPT += -f
	CD = cd
else
	echo Unknown OS
	exit 1
endif

ifeq ($(DEBUG),yes)
	CFLAGS += $(W) $(WA) $(STDLIB) $(GGDB)
else
	CFLAGS = $(STDLIB)
endif

#---------------------------------------------------------------
	


#Variables pour les options d'edition des liens-----------------

LDFLAGS = $(STDLIB)
#---------------------------------------------------------------

#Dependances a reconstruire de maniere systematique-------------
.PHONY: clean mrproper print-%
#---------------------------------------------------------------
#Regles implicites a conserver----------------------------------
.SUFFIXES: #aucune
#---------------------------------------------------------------

#Regles de construction-----------------------------------------
all: $(EXECS)
ifeq ($(DEBUG),yes)
	@echo Projet compile en mode debug
else
	@echo Projet compile en mode release
endif

$(EXE1): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

#Dependances supplementaires
$(OBJPATH)commands/AddPolygonCommand.$(OFILE) : $(SRCPATH)geometry/Polygone.$(HEADFILE)
$(OBJPATH)commands/AddIntersectionCommand.$(OFILE) : $(SRCPATH)geometry/InterObject.$(HEADFILE)
$(OBJPATH)commands/AddRectangleCommand.$(OFILE) : $(SRCPATH)geometry/rectangle.$(HEADFILE)
$(OBJPATH)commands/AddSegmentCommand.$(OFILE) : $(SRCPATH)geometry/Segment.$(HEADFILE)
$(OBJPATH)commands/AddUnionCommand.$(OFILE) : $(SRCPATH)geometry/UnionObject.$(HEADFILE)
$(OBJPATH)commands/DeleteCommand.$(OFILE) : $(SRCPATH)commands/RestoreCommand.$(HEADFILE)
$(OBJPATH)commands/LoadCompositeCommand.$(OFILE) : $(SRCPATH)geometry/InterObject.$(HEADFILE) $(SRCPATH)geometry/UnionObject.$(HEADFILE)
$(OBJPATH)commands/RestoreCommand.$(OFILE) : $(SRCPATH)commands/DeleteCommand.$(HEADFILE)
$(OBJPATH)core/Application.$(OFILE) : $(SRCPATH)commands/MoveCommand.$(HEADFILE) $(SRCPATH)commands/AddSegmentCommand.$(HEADFILE) $(SRCPATH)commands/AddRectangleCommand.$(HEADFILE) $(SRCPATH)commands/AddPolygonCommand.$(HEADFILE) $(SRCPATH)commands/AddIntersectionCommand.$(HEADFILE) $(SRCPATH)commands/AddUnionCommand.$(HEADFILE) $(SRCPATH)commands/DeleteCommand.$(HEADFILE)
$(OBJPATH)managers/FileManager.$(OFILE) : $(SRCPATH)commands/LoadCompositeCommand.$(HEADFILE) $(SRCPATH)commands/AddSegmentCommand.$(HEADFILE) $(SRCPATH)commands/AddRectangleCommand.$(HEADFILE) $(SRCPATH)commands/AddPolygonCommand.$(HEADFILE) $(SRCPATH)geometry/Segment.$(HEADFILE) $(SRCPATH)geometry/Rectangle.$(HEADFILE) $(SRCPATH)geometry/Polygone.$(HEADFILE) $(SRCPATH)geometry/InterObject.$(HEADFILE) $(SRCPATH)geometry/UnionObject.$(HEADFILE)

#Recette particuliere pour le main
$(OBJPATH)core/$(MAINFILE).$(OFILE): $(SRCPATH)core/$(MAINFILE).$(SRCFILE) $(SRCPATH)core/Application.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
	
$(OBJPATH)core/%.$(OFILE) : $(SRCPATH)core/%.$(SRCFILE) $(SRCPATH)core/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)geometry/%.$(OFILE) : $(SRCPATH)geometry/%.$(SRCFILE) $(SRCPATH)geometry/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)commands/%.$(OFILE) : $(SRCPATH)commands/%.$(SRCFILE) $(SRCPATH)commands/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
$(OBJPATH)managers/%.$(OFILE) : $(SRCPATH)managers/%.$(SRCFILE) $(SRCPATH)managers/%.$(HEADFILE)
	$(CC) -o $@ -c $< $(CFLAGS)
#---------------------------------------------------------------

#Regles de nettoyage
clean:
ifeq ($(OS),$(OSUNIX))
	find . -name '*.$(OFILE)' -exec $(DEL) $(DELOPT) {} +
else
	$(CD) $(OBJPATH) && $(DEL) $(DELOPT) *.$(OFILE)
endif
	
mrproper: clean
ifeq ($(OS),$(OSUNIX))
	find . -name $(notdir $(EXECS)) -exec $(DEL) $(DELOPT) {} +
else
	$(DEL) $(DELOPT) $(notdir $(EXECS))
endif
	


#Regles de debuggage
print-% :
	@echo $* = $($*)




