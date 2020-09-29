CXXFLAGS = --std=c++17

all: main

main: main.o *.h
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean: 
	-rm -f *.o *.gch *~