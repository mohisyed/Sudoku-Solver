#include "Sudoku.h"



Sudoku::Sudoku(){
    generatePuzzle();
    // displayPuzzle();
    // solveBoard(true);
    // displayPuzzle();

}

void Sudoku::displayPuzzle()
{
    cout << endl;
    cout << "      0  1  2   3  4  5   6  7  8 " << endl;
    cout << endl;
    for(unsigned int i = 0; i < PUZZLE_SIZE; i++){    
        if ( i == 3 || i == 6)
           cout << "      --------+---------+---------" << endl;
        for(unsigned int x = 0; x < PUZZLE_SIZE; x++){
            if(x == 0)
                cout << i  << "    " ;
            else if ( x == 3 || x == 6)
                cout << "|";
            cout << " " <<  board[i][x] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

bool Sudoku::canEnter(int row, int col, int value){
    for (int i = 0; i < PUZZLE_SIZE; i++){
        if (board[row][i] == value)
            return false;
    }

    for (int i = 0; i < PUZZLE_SIZE; i++){
        if (board[i][col] == value)
            return false;
    }

    int beginColumn =  col - col % 3;
    int beginRow = row - row % 3;

    for (int i = beginRow; i < beginRow + 3; i++){
        for (int x = beginColumn; x < beginColumn + 3; x++){
            if (board[i][x] == value)
                return false;
        }
    }
    return true;
}

bool Sudoku::hasEmptyCell(){
    for (int i = 0; i < PUZZLE_SIZE; i++){
        for (int x = 0; x < PUZZLE_SIZE; x++){
            if (board[i][x] == EMPTY_VALUE)
                return true;
        }
    }
    return false;
}

bool Sudoku::fillPuzzle(){
    int row, col;
    for (int i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++){
        row = i / PUZZLE_SIZE;
        col = i % PUZZLE_SIZE;
        if (board[row][col] == EMPTY_VALUE){
        
            unsigned seed = time(NULL);
            shuffle(values.begin(), values.end(), default_random_engine(seed));
            for (int j = 0; j < PUZZLE_SIZE; j++){
                if (canEnter(row, col, values[j])){
                    board[row][col] = values[j];
                    if (!hasEmptyCell() || fillPuzzle()){
                        return true;
                    }
                }
            }
            break;
        }
    }
    board[row][col] = EMPTY_VALUE;
    return false;
}

bool Sudoku::solveBoard(bool forward){
    int row, col;
    for (int i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++){
        row = i / PUZZLE_SIZE, col = i % PUZZLE_SIZE;
        if (board[row][col] == EMPTY_VALUE){
            for (int value = 1; value <= PUZZLE_SIZE; value++){
                if (canEnter(row, col, value)){
                    board[row][col] = value;
                    if(forward == true){
                        sleep(1);
                        displayPuzzle();
                    }
                    if (!hasEmptyCell()){
                        numberOfSolutions += 1;
                        if(forward == true)
                            return true;
                        break;
                    }
                    else if (solveBoard(forward)){
                        return true;
                    }
                }
            }
            break;
        }
    }
    board[row][col] = EMPTY_VALUE;
    return false;
}

void Sudoku::generatePuzzle(){
    for (int i = 0; i < PUZZLE_SIZE; i++){
        for (int j = 0; j < PUZZLE_SIZE; j++){
            board[i][j] = EMPTY_VALUE;
        }
    }

    fillPuzzle();
    srand(time(NULL));
    int attempt = difficulty;

    while(attempt > 0){
        int row = rand() % PUZZLE_SIZE;
        int col = rand() % PUZZLE_SIZE;

       while (board[row][col] == EMPTY_VALUE){
            row = rand() % PUZZLE_SIZE;
            col = rand() % PUZZLE_SIZE;
        }
        int holderValue = board[row][col];
        board[row][col] = EMPTY_VALUE;
        numberOfSolutions = 0;
        solveBoard();
        if(numberOfSolutions != 1){
            board[row][col] = holderValue;
            attempt--;
        }
    }
}
