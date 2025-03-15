#include <game.h>
#include <sudoku.h>

int main()
{
    game Game;
    sudoku SudokuSinglePlayer;



    while(1)
    {
        Game.mainMenu(); // calls the main menu
        switch(Game.gameChoice)
            {
                case 1:
                    SudokuSinglePlayer.mainMenu();

            }
    }

    return 0;
}
