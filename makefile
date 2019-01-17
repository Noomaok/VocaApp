CPP = g++
CPPFLAGS = -pedantic -Wall -g -DMAP
INT = Lesson.h
REAL = $(INT:.h=.cpp) App.cpp
EXE = VocaApp.exe
ECHO = @echo
RM = del

all:
	$(ECHO) "- all     : display this message"
	$(ECHO) "- debug   : build the debug version"
	$(ECHO) "- release : build the release version"
	$(ECHO) "- clean   : delete generate files"

debug: 
	$(ECHO) "Compilation version debug de <$(EXE)>"
	$(CPP) $(CPPFLAGS) -o $(EXE) $(INT) $(REAL)

release: 
	$(ECHO) "Compilation version release de <$(EXE)>"
	$(CPP) -o $(EXE) $(INT) $(REAL)

clean:
	$(RM) $(EXE)