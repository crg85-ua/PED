.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcomplejo.o tvectorcom.o tabbcom.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

TABBCom:    src/TABBCom.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/TABBCom.cpp $(OBJ) -o TABBCom

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<


clean:
	rm -f $(OBJ) 