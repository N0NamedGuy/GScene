CC=g++
GSCENE=../../gscene/
BIN=cubes
LDFLAGS=$(pgk-config --libs -cflags gl) -lglut -ggdb -lGLU -lm -I$(GSCENE) -I$(GSCENE)..

all: cubes.o
	$(CC) cubes.o node.o box.o viewer.o controller.o $(LDFLAGS) -o $(BIN) 

cubes.o: cubes.cpp node.o box.o viewer.o controller.o 
	$(CC) cubes.cpp node.o box.o viewer.o controller.o $(LDFLAGS) -c

node.o: $(GSCENE)node.h $(GSCENE)node.cpp
	$(CC) $(GSCENE)node.cpp $(LDFLAGS) -c

viewer.o: node.o $(GSCENE)viewer.h $(GSCENE)viewer.cpp
	$(CC) $(GSCENE)viewer.cpp $(LDFLAGS) -c

box.o: node.o $(GSCENE)shapes/box.h $(GSCENE)shapes/box.cpp
	$(CC) $(GSCENE)shapes/box.cpp $(LDFLAGS) -c

controller.o: $(GSCENE)controller.h $(GSCENE)controller.cpp
	$(CC) $(GSCENE)controller.cpp $(LDFLAGS) -c

clean:
	rm cubes.o node.o viewer.o box.o controller.o
