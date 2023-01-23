#include "Sudoku.h"
using namespace std;


int main(){
    int userInput;
    string userInput2;
    Sudoku game;

    cout << "What difficulty would you like to choose from 1-10? " << endl;
    cin >> userInput;
    while(userInput < 1 & userInput > 11){
        cout << "Try again" << endl;
        cout << "What difficulty would you like to choose from 1-10? " << endl;
        cin >> userInput;
    }
    game.setDifficulty(userInput);
    game.displayPuzzle();

    cout << "Would you like to solve? y/n" << endl;
    cin >> userInput2; 
    while(userInput2 != "y" && userInput2 != "n"){
        cout << "Try again" << endl;
        cout << "would you like to solve? y/n" << endl;
        cin >> userInput2;
    }
    if(userInput2 == "y"){        
        game.solveBoard(true);
        game.displayPuzzle();
    }
    else{
        cout<< "Thanks, bye" << endl;
        exit(0);
    }


    return 0;
}