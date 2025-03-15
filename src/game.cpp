//#include "game.h"
//
//game::game()
//{
//    // for getting command prompt to full screen
//    //std::system("mode 650"); this one does half the job
//    //::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); // This will put you in a literal full screen, could possibly confuse the average user
//
//    clearScreen();
//    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // this one does the required job! using this
//    consoleWidthAndHeight(); // WARNING: DO NOT TOUCH THIS! NECESSARY FOR TEXT POSITIONING
//}
//
//game::~game()
//{
//    //dtor
//}
//
//void game::clearScreen()
//{
//    system("cls"); // clear the screen
//}
//void game::consoleWidthAndHeight()
//{
//    // code taken from stackoverflow
//    // https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//}
//
//void game::fileTextCenter(const string& filePath) {
//    // Open the file using the provided file path
//    std::ifstream file(filePath);
//    if (!file.is_open()) {
//        std::cerr << "Failed to open file: " << filePath << endl;
//        return;
//    }
//
//    string line; // To read each line from the file
//    while (std::getline(file, line)) {
//        int lineLength = line.length();
//        if (lineLength < consoleWidth) {
//            int padding = (consoleWidth - lineLength) / 2; // Calculate spaces for centering
//            cout << string(padding, ' ') << line << endl;
//        } else {
//            cout << line << endl; // Print as-is if the line is too wide
//        }
//    }
//
//    file.close(); // Close the file after use
//}
//
//
//void game::textCenter(const string& input) {
//
//    // Use a stringstream to process the string line by line
//    std::istringstream stream(input);
//    string line;
//
//    while (std::getline(stream, line)) {
//        int lineLength = line.length();
//        if (lineLength < consoleWidth) {
//            int padding = (consoleWidth - lineLength) / 2; // Calculate spaces for centering
//            cout << string(padding, ' ') << line << endl;
//        } else {
//            cout << line << endl; // Print as-is if line is too wide
//        }
//    }
//}
//
//void game::leftPaddedText(int padLength,const string& lineToPrint){
//    // Use a stringstream to process the string line by line
//    std::istringstream stream(lineToPrint);
//    string line;
//
//    while (std::getline(stream, line)) {
//        // Add padding spaces and then print the line
//        cout << string(padLength, ' ') << line << endl;
//    }
//}
//
//void game::leftPaddedTextNoNewLine(int padLength, const string& lineToPrint)
//{
//    std::istringstream stream(lineToPrint);
//    string line;
//    while (std::getline(stream, line)) {
//        // Add padding spaces and then print the line
//        cout << string(padLength, ' ') << line;
//    }
//}
//
//void game::mainMenu(){
//    /*
//    greet the user and present the available games - Harshil
//    */
//    // Main menu title message
//    // call the necessary function here
//    string welcomeMessageFilePath = "resources/welcomeMessage.txt";
//    string mainMenuGameOptions = "The following games are available:\n1.) Sudoku\n2.) Rock Paper Scissors\n3.) Hangman\n4.) Guess the number\n5.) Tic Tac Toe\n6.) Exit the game";
//    fileTextCenter(welcomeMessageFilePath);
//    leftPaddedText(100, mainMenuGameOptions);
//
//
//        /*cout<<"The following games are available:";
//        cout<<"\n1.) Sudoku";
//        cout<<"\n2.) Rock Paper Scissors";
//        cout<<"\n3.) Hangman";
//        cout<<"\n4.) Guess the number";
//        cout<<"\n5.) Tic Tac Toe";
//        cout<<"\n6.) Exit the game";*/
//    while(1){
//        int userChoice; // Default=No game selected
//        string enterOptionText = "\n\nPlease enter your choice: ";
//        leftPaddedTextNoNewLine(100, enterOptionText);
//        cin>>userChoice;
//
//
//        //Context: THinking of logic on deciding the gameflow for selecting the game as the games need to also have the double player and single player option
//        // The double player is gonna be turn based so i need to think of the logic for that part
//        // single player is gonna need a random generator function to generate a guess and it needs to be close to the solution so I am gonna need to have already solved puzzles and their answers as well as known combinations for some of the games.
//        if(userChoice>=1&&userChoice<=5){
//            gameChoice=userChoice;
//            goto loopExit;
//        }
//        else if(userChoice==6){
//            std::exit(0);
//        }
//        else{
//            cout<<"Wrong choice!"<<endl;
//        }
//        loopExit:
//        {break;}
//}}
//
//
//
///*void game::fileMessageDisplay(string filePath){
//
//    std::ifstream file(filePath);
//    if (!file.is_open()) {
//        std::cerr << "Error opening file" << endl;
//        std::exit(0);
//    }
//
//    // Manipulate this to get centered text, call a function to calculate the EOF position and calculate the centered text instead
//    char ch;
//    while (file.get(ch)) {
//        cout << ch;
//    }
//    cout<<endl;
//
//    file.close();
//
//}
//*/ //To de comment use Ctrl+Shift+X


#include "game.h"

game::game()
{
    clearScreen();
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // Maximize the console window
    consoleWidthAndHeight(); // Necessary for text positioning
}

game::~game()
{
    // Destructor
}

// I am getting a replacement for this one
 void game::replaceCharacterInFile(const string& filename, int position, char newChar){
    // Open the file in read mode
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Read the file content into a string
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Ensure position is valid
    if (position < 0 || position >= content.size()) {
        cerr << "Error: Position out of bounds." << endl;
        return;
    }

    // Replace the character at the specified position
    content[position] = newChar;

    // Display the modified content on the terminal
    cout << content << endl;
}

void game::clearScreen()
{
    system("cls"); // Clear the screen
}
void game::setColor(const string& color)
{
    cout << color;
}

void game::consoleWidthAndHeight()
{
    // Get the console's width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void game::fileTextCenter(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        int lineLength = line.length();
        if (lineLength < consoleWidth) {
            int padding = (consoleWidth - lineLength) / 2;
            cout << string(padding, ' ') << line << endl;
        } else {
            cout << line << endl;
        }
    }

    file.close();
}

void game::textCenter(const string& input)
{
    istringstream stream(input);
    string line;

    while (getline(stream, line)) {
        int lineLength = line.length();
        if (lineLength < consoleWidth) {
            int padding = (consoleWidth - lineLength) / 2;
            cout << string(padding, ' ') << line << endl;
        } else {
            cout << line << endl;
        }
    }
}

void game::leftPaddedText(int padLength, const string& lineToPrint)
{
    cout << string(padLength, ' ') << lineToPrint << endl;
}

void game::leftPaddedTextNoNewLine(int padLength, const string& lineToPrint)
{
    cout << string(padLength, ' ') << lineToPrint;
}

void game::mainMenu()
{
    string welcomeMessageFilePath = "resources/welcomeMessage.txt";
    string mainMenuGameOption1 = "The following games are available:";
    string mainMenuGameOption2 = "1.) Sudoku";
    string mainMenuGameOption3 = "2.) Tic Tac Toe";
    string mainMenuGameOption4 = "3.) Rock Paper Scissors";
    string mainMenuGameOption5 = "4.) Exit to main Menu";

    // Display the welcome message and the main menu options
    fileTextCenter(welcomeMessageFilePath);
    //leftPaddedText(100, mainMenuGameOptions);

    int selectedOption = 0; // Start with the first option selected
    const int totalOptions = 4; // There are 6 options in the menu

    while (true) {
        // Highlight the selected option
        clearScreen();  // Clear the screen to refresh the menu
        setColor(RESET_COLOR);  // Reset to normal color
        fileTextCenter(welcomeMessageFilePath);
        //leftPaddedText(100, mainMenuGameOptions);

        //cout << "\n\n\n\n\n\n\n\n"; // A dirty fix for maintaining space
        leftPaddedText(75, mainMenuGameOption1);


        for (int i = 0; i < totalOptions; ++i) {
            if (i == selectedOption) {
                // Highlight the selected option
                setColor(GREEN);  // Use green for highlighting
                cout<<"     ";
            } else {
                setColor(RESET_COLOR);  // Reset to normal color
                cout << "  ";
            }
            // Print the option
            if (i == 0) leftPaddedText(100, mainMenuGameOption2);
            else if (i == 1) leftPaddedText(100, mainMenuGameOption3);
            else if (i == 2) leftPaddedText(100, mainMenuGameOption4);
            else if (i == 3) leftPaddedText(100, mainMenuGameOption5);
        }

        // Wait for user input (W, S for navigation, Enter for selection)
        char userInput = _getch(); // Capture a keypress

        if (userInput == 'w' || userInput == 'W') {
            // Move up
            selectedOption = (selectedOption - 1 + totalOptions) % totalOptions;
        } else if (userInput == 's' || userInput == 'S') {
            // Move down
            selectedOption = (selectedOption + 1) % totalOptions; // Fix the logic here!
        } else if (userInput == 13) { // Enter key is pressed (ASCII 13)
            // Execute the selected option
            if (selectedOption == 3) {
                // Exit the game
                cout << "Exiting game..." << endl;
                exit(0);
            } else {
                gameChoice = selectedOption + 1; // Set the chosen game
                break; // Exit the loop and start the selected game
            }
        }
    }
}

