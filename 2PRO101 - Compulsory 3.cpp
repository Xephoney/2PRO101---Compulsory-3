#include <time.h>
#include "Compulsory 3.h"


Login login;


int main()
{
    srand(time(NULL));
    Task1();
}

void Task1()
{
    login.Setup();
    //The login struct is at line 16 in the header
    if (login.PasswordCheck())
    {
		system("cls");
		std::cout << "Correct Password! \n\n";
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
    RETRY:
        //Since _getch here returns the ascii for that keyboard value, i've just made it check for those numbers; 49 = 1 on the keyboard etc.
        switch (_getch())
        {
        case 49 : 
            login.ChangePassword();
            break;
        case 50 :
            Player_VS_CPU();
            break;
        case 51 : 
            std::cout << "Exiting Application. Good Bye! \n\n\n";
            return;
            break;
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
    Battleship game;
    //Single Player (Single Boats
    game.makeEmptyBoard();
    game.makeBoard(11);
    game.printBoard();
    game.numberOfShots = 25;
    game.printPlayerBoard();

    do 
    {
		if (game.numberOfShots == 0)
		{
            std::cout << "We ran out of ammo! \n Lets retreat! \n\n GAME OVER\n";
			system("pause");
            system("CLS");
			MainMenu();
		}
        game.Shoot();
        game.printPlayerBoard();
        std::cout << game.numberOfShots;
    } while (game.remainingShips > 0);

    std::cout << "The location of the enemy ships! \n";
    game.printBoard();
    std::cout << "We got 'em Captain! We win! \n";

    system("pause");
    system("CLS");
    MainMenu();
}
void Player_VS_CPU()
{
    Battleship game;
    game.makeEmptyBoard();
    game.MakeBoardThree(4);

    game.printGameBoard();

    do 
    {
        game.Shoot();
        game.AIShoot();

        game.printGameBoard();
        
        if (game.remainingShips == 0)
        {
            std::cout << "OH NO!! They've sunk your battleships! \n --- [ GAME OVER ] ---";
            break;
        }
        else if (game.computerRemainingShips == 0)
        {
            std::cout << "YAY!! We sunk their battleships! \n --- [ YOU WIN ] ---\n\n";
            break;
        }
    } while (true);
    system("pause");
    system("CLS");
    return;
}
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
