CPP = @g++
CPPFLAGS = -pedantic -Wall -g -DMAP
REAL = $(wildcard src/*.cpp)
EXE = bin/VocaApp
ECHO = @echo
MKDIR = @mkdir
RM = rm

all:
	$(ECHO) "- all     : display this message"
	$(ECHO) "- debug   : build the debug version"
	$(ECHO) "- release : build the release version"
	$(ECHO) "- clean   : delete generate files"

debug:
	$(MKDIR) -p bin
	$(ECHO) "Compilation version debug de <$(EXE)>"
	$(CPP) $(CPPFLAGS) -o $(EXE) $(REAL)

release: 
	$(MKDIR) -p bin
	$(ECHO) "Compilation version release de <$(EXE)>"
	$(CPP) -o $(EXE) $(REAL)

clean:
	$(RM) $(EXE)
