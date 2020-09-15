CXXFLAGS = --std=c++17

all: match

rebuild: clean match

match: main.o board.o tile.o *.h
	$(CXX) $(CXXFLAGS) -o match main.o board.o tile.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp
tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp

clean: 
	-rm -f *.o *.gch *~ 