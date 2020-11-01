#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <time.h>
//This includes a Login Struct that takes care of the login functions
#include "Compulsory 3.h"




int main()
{
    srand(time(NULL));
    //Task1();
    Play();
}

void Task1()
{
    login.Setup();
    //The login struct is at line 16 in the header
    if (login.PasswordCheck())
    {
        std::cout << "Correct Password\n\n";
        MainMenu();
    }
    else
    {
        std::cout << "Wrong Password. Exiting application \n ";
    }
}

void MainMenu()
{
    do
    {
        std::cout << " --- [ Main Menu ] --- \n";
        std::cout << " 1. Change Password \n";
        std::cout << " 2. Play Battleship \n";
        std::cout << " 3. Quit Application \n";
        std::cout << "Please select one of the options above : ";
        
        int answer;
    RETRY:
        std::cin >> answer;

        switch (answer)
        {
        case 1 : 
            login.ChangePassword();
            break;
        case 2 :
            Play();
            break;
        case 3 : 
            std::cout << "Exiting Application. Good Bye! \n\n\n";
            return;
        default:
            std::cin.clear();
            std::cin.ignore(8000, '\n');
            std::cout << "Invalid Input! Please retry : ";
            goto RETRY;
            break;
        }
    } while (true);

}

struct BattleShip
{
    char board[M][N];
    char playerBoard[M][N];
    int numberOfHits;
    int numberOfShots;
    void makeEmptyBoard()
    {
        for (int y = 0; y < M; y++)
        {
            for (int x = 0; x < N; x++)
            {
                board[x][y] = BLANK;
            }
        }

        for (int y = 0; y < M; y++)
        {
            for (int x = 0; x < N; x++)
            {
                playerBoard[x][y] = BLANK;
            }
        }
        

        /*
        int** Board;
        Board = new int*[M];
        for (int i = 0; i < M; i++)
        {
            Board[i] = new int[N];
        }
        */
    }
    void makeBoard(int numberOfShips)
    {
        int x;
        int y;
        for (int i = 0; i < numberOfShips; i++)
        {
        Retry:
            y = randomRow();
            x = randomColumn();
            if (board[x][y] == SHIP)
            {
                goto Retry;
            }
            board[x][y] = SHIP;
        }
    }

    void printBoard()
    {
        system("CLS");
        for (int y = 0; y < M; y++)
        {
            std::cout << y + 1 << " ";
            for (int x = 0; x < N; x++)
            {
                std::cout << "|" << board[x][y];
            }
            std::cout << "|\n";
        }
        writeLetters();
    }
    void printPlayerBoard()
    {
        system("CLS");
        
        for (int y = 0; y < M; y++)
        {
            std::cout << y + 1 << " ";
            for (int x = 0; x < N; x++)
            {
                std::cout << "|" << playerBoard[x][y];
            }
            std::cout << "|\n";
        }
        writeLetters();
    }
    void writeLetters()
    {
        std::cout << "  -------------\n";
        std::cout << "  ";

        for (int i = 0; i < N; i++)
        {
            std::cout << "|" << (char)(65 + i) ;
        }
        std::cout << "|\n";
    }
    void Shoot()
    {

    }

};

void Play()
{
    //Single Player
    BattleShip game;
    game.makeEmptyBoard();
    game.makeBoard(11);
    //game.printBoard();
    game.printPlayerBoard();

    
}


