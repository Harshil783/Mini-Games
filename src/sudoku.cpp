#include "sudoku.h"
// Implement the ReplaceCharacterFile Member Function from testing AI Codes

sudoku::sudoku()
{
}
void sudoku::printGrid(int (*grid)[9][9]) { // https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function/17569578#17569578
    for (int row = 0; row < 9; ++row) {
        // Print the top border of the grid
        for (int col = 0; col < 9; ++col) {
            cout << "+-------";
        }
        cout << "+" << endl;

        // Print the numbers with vertical borders
        for (int line = 0; line < 3; ++line) { // 3 lines per box
            for (int col = 0; col < 9; ++col) {
                if (line == 1) { // Center line for the number
                    //cout << "|   " << (grid[row][col] == 0 ? ' ' : grid[row][col] + '0') << "   ";
                } else {
                    cout << "|       ";
                }
            }
            cout << "|" << endl;
        }
    }

    // Print the bottom border of the grid
    for (int col = 0; col < 9; ++col) {
        cout << "+-------";
    }
    cout << "+" << endl;
}



/*int main() {
    // Example of a Sudoku grid (0 represents an empty cell)
    int sudokuGrid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Display the Sudoku grid
    printSudokuGrid(sudokuGrid);

    return 0;
}*/

void sudoku::mainMenu()
{
    clearScreen(); // clears the screen
    fileTextCenter("resources/sudokuMainTitle.txt"); // supply a pointer via the object instead and set the pointer using constructor instead
    leftPaddedText(100,"\n\n\n\n\n1.) Play \n2.)Rules 3.)Exit to Main Menu");
    //leftPaddedText(100,"\n\nLevels available:\n1.) Easy\n2.)Medium\n3.)Hard");

    cout<<"\n\n\n\n"<<endl;
    while(1)
    {

        leftPaddedTextNoNewLine(75, "Please Enter your choice: ");
        cin>>userChoice;

        switch(userChoice)
        {
            case 1:
                // before starting make sure you have user's desired difficulty
                start();
            case 2:
                rules();
            case 3:
                break;
            default:
                cout<<"Incorrect option message here!"<<endl; // use ascii art instead here!
        }
    }

//system("pause"); used this for debugging purposes and testing purposes
}

void sudoku::rules()
{
    //rules and how to play implementation here
}
void sudoku::start()
{
    // game logic here implementation here
}

sudoku::~sudoku()
{
    //dtor
}
