CXXFLAGS = --std=c++17

all: modulo modulo2

rebuild: clean modulo modulo2

modulo: main.o *.h
	$(CXX) $(CXXFLAGS) -o modulo main.o 

modulo2: main2.o *.h
	$(CXX) $(CXXFLAGS) -o modulo2 main2.o 

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp

clean: 
	-rm -f *.o *.gch *~ 