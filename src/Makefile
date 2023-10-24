LIBS = -lglut -lGLU -lGL

all: run

run : main.o
	g++ -o run main.o $(LIBS) 

main : main.cpp
	g++ -c main.cpp

clean:
	rm -f run main.o