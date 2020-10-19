#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

#define gridColumSize 4
#define gridRowSize 4
#define saveFileName "save.txt"




void Task1();
void MainMenu(); // Task 2
void Play(); //Task 3

struct Login {
private :
    char passwordGird[gridColumSize][gridRowSize];
    std::string _pw = "ABC";

public :
    void DisplayGrid()
    {
        system("CLS");
        for (int y = 0; y < gridRowSize; y++)
        {
            for (int x = 0; x < gridColumSize; x++)
            {
                std::cout << "| " << passwordGird[x][y] << " ";
            }
            std::cout << "|\n";
        }

    }
    bool PasswordCheck()
    {
        std::string currentInput{ "A" };
        char currentlySelected = 'A';
        int x = 0, y = 0;

        do
        {
            DisplayGrid();
            std::cout << "X : " << x << " | Y : " << y << std::endl;
            switch (_getch())
            {
            // The last case 72 : is the code for the arrow keys. 
            case 'w' : case 'W' : case 72 : 
                if (y - 1 >= 0)
                {
                    y--;
                }
                break;
            case 'a' : case 'A' : case 75 :
                if (x - 1 >= 0)
                {
                    x--;
                }
                break;
            case 'd': case 'D' : case 77 :
                if (x + 1 < gridColumSize)
                {
                    x++;
                }
                break;
            case 's': case 'S': case 80 :
                if (y + 1 > gridRowSize)
                {
                    y++;
                }
                break;
            default:
                break;
            }
            currentlySelected = passwordGird[x][y];
            currentInput.push_back(currentlySelected);
            
        } while (currentInput.length() != _pw.length());

        if (currentInput == _pw)
            return true;
        else
            return false;
    }
    

    //The structs constructor. When a new Login variable is created it generates a new grid and stores it in passwordgrid with all 
    Login()
    {
        //ASCII code for the letter A
        int count = 65;
        //Filling the 2D array with letters using Ascii values. The counter keeps track of past as
        for (int y = 0; y < gridRowSize; y++)
        {
            for (int x = 0; x < gridColumSize; x++)
            {
                passwordGird[x][y] = (char)count++;
            }
        }


    }


};


int main()
{
    Task1();
}

void Task1()
{
    Login login;
    login.DisplayGrid();
    if (login.PasswordCheck())
    {
        std::cout << "Correct Password";
    }
    else
    {
        std::cout << "Wrong Password";
    }

}



void MainMenu()
{

}
