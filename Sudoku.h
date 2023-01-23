#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <vector>

using namespace std;

const int PUZZLE_SIZE = 9;
const int EMPTY_VALUE = 0;
//vector <int> values = {1,2,3,4,5,6,7,8,9};

class Sudoku{
    public:
        Sudoku();
        void displayPuzzle();
        bool canEnter(int row, int col, int value);
        bool hasEmptyCell();
        bool fillPuzzle();
        void generatePuzzle();
        void setDifficulty(int diff){difficulty = diff;}
        void printdiff(){cout << difficulty;}
        bool solveBoard(bool forward = false);
    protected:
        int board[PUZZLE_SIZE][PUZZLE_SIZE];
        int difficulty = 1;
        int numberOfSolutions;
        vector <int> values = {1,2,3,4,5,6,7,8,9};
};


#endif