CXX = g++
CXXFLAGS = -Wall -std=c++11


main: main.cpp Sudoku.o 
	$(CXX) $(CXXFLAGS) main.cpp Sudoku.o -o main

Sudoku.o: Sudoku.h Sudoku.cpp
	$(CXX) $(CXXFLAGS)  -c Sudoku.cpp

run:
	./main

clean:
	rm *.o*
	rm *~
	


