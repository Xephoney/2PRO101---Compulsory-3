#pragma once


//Variables and Definitions
#define Password_Grid_Colum_Size 4
#define Password_Grid_Row_Size 4
#define saveFileName "save.txt"

const int M = 6, N = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';

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
                if (!(y - 1 >= 0))
                {
                    continue;
                }
                y--;
                break;
            case 'a':
                if (!(x - 1 >= 0))
                {
                    continue;
                }
                x--;
                break;
            case 'd':
                if (!(x + 1 < Password_Grid_Colum_Size))
                {
                    continue;
                }
                x++;
                break;
            case 's':
                if (!(y + 1 < Password_Grid_Row_Size))
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
                if (!(y - 1 >= 0))
                {
                    continue;
                }
                y--;
                break;
            case 'a':
                if (!(x - 1 >= 0))
                {
                    continue;
                }
                x--;
                break;
            case 'd':
                if (!(x + 1 < Password_Grid_Colum_Size))
                {
                    continue;
                }
                x++;
                break;
            case 's':
                if (!(y + 1 < Password_Grid_Row_Size))
                {
                    continue;
                }
                y++;
                break;
            case 'g':
                //Confirm New Password
                break;
            default:
                continue;
                break;
            }

            previousLocationChar = passwordGrid[x][y];
            passwordGrid[x][y] = inputLocationChar;
            _pwInput.push_back(previousLocationChar);

            DisplayGrid();

        } while (true);


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
}login;



void Task1();
void MainMenu(); // Task 2

void Play(); //Battleships


//Helper Functions
int letterToNumber(char letter)
{
    return static_cast<int>(letter) - 65;
}
int randomRow()
{
    return rand() % M;
}
int randomColumn()
{
    return rand() % N;
}


