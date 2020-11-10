#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

//Variables and Definitions
#define Password_Grid_Colum_Size 4
#define Password_Grid_Row_Size 4
#define saveFileName "save.txt"

const int M = 6, N = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';

int letterToNumber(char letter);
int randomRow();
int randomColumn();

struct Login {
private:
    char passwordGrid[Password_Grid_Colum_Size][Password_Grid_Row_Size]{};
    std::string _pw;
    std::string _pwInput;

    void SetupPasswordGrid()
    {
        int count = 65;
        for (int y = 0; y < Password_Grid_Row_Size; y++)
        {
            for (int x = 0; x < Password_Grid_Colum_Size; x++)
            {
                passwordGrid[x][y] = (char)count++;
            }
        }
    }
    std::string FetchPassword()
    {
        std::fstream file(saveFileName);

        std::string temp;
        std::getline(file, temp);

        file.close();
        return temp;
    }
    void StorePassword(std::string new_pw)
    {
        std::fstream file;
        file.open(saveFileName);
        file.clear();

        file << new_pw;

        file.close();
    }

public:
    void DisplayGrid()
    {
        system("CLS");
        for (int y = 0; y < Password_Grid_Row_Size; y++)
        {
            for (int x = 0; x < Password_Grid_Colum_Size; x++)
            {
                std::cout << "| " << passwordGrid[x][y] << " ";
            }
            std::cout << "|\n";
        }
        //THIS IS FOR BUGTESTING - IGNORE - 
        //std::cout << "   Input\t |" << _pwInput << std::endl;
        //std::cout << "Password\t |"<< _pw << "|" << std::endl;
    }
    bool PasswordCheck()
    {
        char previousLocationChar = 'A';
        char inputLocationChar = '*';

        int x = 0, y = 0;
        passwordGrid[x][y] = inputLocationChar;
        _pwInput = "";
        _pwInput.push_back(previousLocationChar);

        DisplayGrid();

        do
        {
            //Gets input from keyboard and makes it lower case
            int inputKey = tolower(_getch());

            switch (inputKey)
            {
            case 'w':
                if (!(y - 1 >= 0) || passwordGrid[x][y - 1] == inputLocationChar)
                {
                    continue;
                }
                y--;
                break;
            case 'a':
                if (!(x - 1 >= 0) || passwordGrid[x - 1][y] == inputLocationChar)
                {
                    continue;
                }
                x--;
                break;
            case 'd':
                if (!(x + 1 < Password_Grid_Colum_Size) || passwordGrid[x + 1][y] == inputLocationChar)
                {
                    continue;
                }
                x++;
                break;
            case 's':
                if (!(y + 1 < Password_Grid_Row_Size) || passwordGrid[x][y + 1] == inputLocationChar)
                {
                    continue;
                }
                y++;
                break;
            default:
                continue;
                break;
            }

            previousLocationChar = passwordGrid[x][y];
            passwordGrid[x][y] = inputLocationChar;
            _pwInput.push_back(previousLocationChar);

            DisplayGrid();

        } while (_pwInput.length() != _pw.length());

        if (_pwInput == _pw)
            return true;
        else
            return false;
    }
    void ChangePassword()
    {
        SetupPasswordGrid();
        char previousLocationChar = 'A';
        char inputLocationChar = '*';

        int x = 0, y = 0;
        passwordGrid[x][y] = inputLocationChar;
        _pwInput = "";
        _pwInput.push_back(previousLocationChar);

        DisplayGrid();
        std::cout << "The password can be a max length of 10 and a minimum of 4.\n You can also press G to save the selected. \n";

        do
        {
            //Gets input from keyboard and makes it lower case
            int inputKey = tolower(_getch());

            switch (inputKey)
            {
            case 'w':
                if (!(y - 1 >= 0) || passwordGrid[x][y-1] == inputLocationChar)
                {
                    continue;
                }
                y--;
                break;
            case 'a':
                if (!(x - 1 >= 0) || passwordGrid[x-1][y] == inputLocationChar)
                {
                    continue;
                }
                x--;
                break;
            case 'd':
                if (!(x + 1 < Password_Grid_Colum_Size) || passwordGrid[x+1][y] == inputLocationChar)
                {
                    continue;
                }
                x++;
                break;
            case 's':
                if (!(y + 1 < Password_Grid_Row_Size) || passwordGrid[x][y+1] == inputLocationChar)
                {
                    continue;
                }
                y++;
                break;
            case 'g':
                if (_pwInput.length() >= 4)
                {
                    StorePassword(_pwInput);
                    return;
                }
                else
                {
                    std::cout << "Your password is not long enough! \n";
                    continue;
                }
                break;
            default:
                continue;
                break;
            }

            previousLocationChar = passwordGrid[x][y];
            passwordGrid[x][y] = inputLocationChar;
            _pwInput.push_back(previousLocationChar);

            DisplayGrid();
            std::cout << "The password can be a max length of 10 and a minimum of 4.\n You can also press G to save the selected. \n";
        } while (_pwInput.length() < 10);

        StorePassword(_pwInput);
    }
    void Setup()
    {
        SetupPasswordGrid();

        _pw = FetchPassword();
        //This if statement is just in the case where it can't find a file or it has been corrupted.
        //It just resets the password back to the default.
        if (_pw == "")
        {
            _pw = "ABCDHLPONM";
        }
    }
};

void Task1();
void MainMenu(); // Task 2
void Play(); //Battleships
void TestFunction();
class Battleship
{
    int numberOfHits;
    int CPUhits;

public:
	char board[M][N];
	char playerBoard[M][N];
	char computerBoard[M][N];

    int numberOfShots;
    int remainingShips;

    void makeEmptyBoard();
    void makeBoard(int numberOfShips);
    void printBoard();
    void printPlayerBoard();
    //0
    void printGameBoard();
    void writeLetters();
    void Shoot();
    void MakeBoardThree(char boardarr[][N], int numberOfShips);
    bool AttemptToPlaceShip(char boardarr[][N], int Column, int Row, int direction);

};
