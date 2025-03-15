#pragma once

class Resource
{
    private:
        char[100] titleFile; // title file for game
        char[100] mainMenuFile; // mainMenu File where all the options of any game are located
        char[100] rulesFile;
        // Common IO Statements here



    public:
        Resource();
        ~Resource();
};
