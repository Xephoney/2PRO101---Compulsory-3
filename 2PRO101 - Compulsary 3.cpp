#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

//This includes a Login Struct that takes care of the login functions
#include "Compulsory 3.h"



int main()
{
    
    //Task1();
    MainMenu();
}

void Task1()
{
    login.Setup();
    //The login struct is at line 146 in the header
    if (login.PasswordCheck())
    {
        std::cout << "Correct Password";
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

void Play()
{

}