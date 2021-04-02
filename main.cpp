//Author: Erica Carballo
//Project name: Tic Tac Toe
//Description: Program that allows two users to play tic tac toe.
//Last Changed: May 24, 2020

#include <iostream>
#include <string>
using namespace std;

const int ROW_SIZE = 3, COL_SIZE = 3;

void updatedBoard(int index1, int index2, char ticTac[][COL_SIZE], bool playerX);
//Input is the array.
//Will display the tic-tac-toe board.

void searchForPosition(const char ticTac[][COL_SIZE], int rowSize, char target, int& index1, int& index2);
//Input is the array and the char position.
//Will give the column and row of char position.

void checkWinner(char ticTac[][COL_SIZE], bool& isWinner, string& winner);
//Input is the array.
//Will return if there is winner and who the winner is.

void displayOutput(string winner);
//Input is the winner.
//Will display the winner.

int main()
{
    char ch, ticTac[ROW_SIZE][COL_SIZE], playerXPosition, playerOPosition;
    bool playerX, isWinner;
    int index1, index2;
    string winner;
    winner = " ";
    ch = '1';
    isWinner = false;

    cout << "This is the game of Tic-Tac-Toe.\n";

    updatedBoard(index1, index2, ticTac, playerX);

    while (!isWinner)
    {
        cout << endl;
        cout << "Please enter the position for player X. ";
        cin >> playerXPosition;
        playerX = true;


        //makes new board.
        searchForPosition(ticTac, ROW_SIZE, playerXPosition, index1, index2);
        updatedBoard(index1, index2, ticTac, playerX);

        checkWinner(ticTac, isWinner, winner);
        if (isWinner)
        {
            break;
        }

        cout << endl;
        cout << "Please enter the position for Player O. ";
        cin >> playerOPosition;
        playerX = false;


        searchForPosition(ticTac, ROW_SIZE, playerOPosition, index1, index2);
        updatedBoard(index1, index2, ticTac, playerX);

        checkWinner(ticTac, isWinner, winner);
    }

    cout << endl;
    displayOutput(winner);

    cout << endl;
    cout << "This is the end of the program.\n";

    return 0;
}

void updatedBoard(int index1, int index2, char ticTac[][COL_SIZE], bool playerX)
{
    char ch;
    ch = '1';
//Author: Erica Carballo
    if (playerX)
    {
        for (int rows = 0; rows < ROW_SIZE; rows++)
        {
            cout << endl;
            for (int cols = 0; cols < COL_SIZE; cols++)
            {
                if ((index1 == rows) && (index2 == cols))
                {
                    ticTac[rows][cols] = 'X';
                    ch = ch + 1;
                }
                else if ((ticTac[rows][cols] == 'O') || (ticTac[rows][cols] == 'X'))
                {
                    ch = ch + 1;
                }
                else
                {
                    ticTac[rows][cols] = ch++;
                }

                cout << ticTac[rows][cols] << " ";
            }
        }
    }
    else
    {
        for (int rows = 0; rows < ROW_SIZE; rows++)
        {
            cout << endl;
            for (int cols = 0; cols < COL_SIZE; cols++)
            {
                if ((index1 == rows) && (index2 == cols))
                {
                    ticTac[rows][cols] = 'O';
                    ch = ch + 1;
                }
                else if ((ticTac[rows][cols] == 'O') || (ticTac[rows][cols] == 'X'))
                {
                    ch = ch + 1;
                }
                else
                {
                    ticTac[rows][cols] = ch++;
                }

                cout << ticTac[rows][cols] << " ";
            }
        }
    }
}

void searchForPosition(const char ticTac[][COL_SIZE], int rowSize, char target, int& index1, int& index2)
{
    bool found;
    index1 = 0;
    index2 = 0;
    found = false;

    while ((!found) && (index2 < COL_SIZE))
    {
        if (index1 >= rowSize)
        {
            index1 = 0;
            index2++;
        }

        if (target == ticTac[index1][index2])
        {
            found = true;
        }
        else
        {
            index1++;
        }
    }

}

void checkWinner(char ticTac[][COL_SIZE], bool& isWinner, string& winner)
{
    int count;
    count = 0;

    if (((ticTac[0][0] == 'X') && (ticTac[1][1] == 'X') && (ticTac[2][2] == 'X')) || ((ticTac[0][2] == 'X') && (ticTac[1][1] == 'X') && (ticTac[2][0] == 'X')) || ((ticTac[0][0] == 'X') && (ticTac[1][0] == 'X') && (ticTac[2][0] == 'X')) || ((ticTac[0][1] == 'X') && (ticTac[1][1] == 'X') && (ticTac[2][1] == 'X')) || ((ticTac[0][2] == 'X') && (ticTac[1][2] == 'X') && (ticTac[2][2] == 'X')) || ((ticTac[0][0] == 'X') && (ticTac[0][1] == 'X') && (ticTac[0][2] == 'X'))||((ticTac[1][0] == 'X') && (ticTac[1][1] == 'X') && (ticTac[1][2] == 'X')) || ((ticTac[2][0] == 'X') && (ticTac[2][1] == 'X') && (ticTac[2][2] == 'X')))
    {
        winner = "Player X";
        isWinner = true;
    }
    else if (((ticTac[0][0] == 'O') && (ticTac[1][1] == 'O') && (ticTac[2][2] == 'O')) || ((ticTac[0][2] == 'O') && (ticTac[1][1] == 'O') && (ticTac[2][0] == 'O')) || ((ticTac[0][0] == 'O') && (ticTac[1][0] == 'O') && (ticTac[2][0] == 'O')) || ((ticTac[0][1] == 'O') && (ticTac[1][1] == 'O') && (ticTac[2][1] == 'O')) || ((ticTac[0][2] == 'O') && (ticTac[1][2] == 'O') && (ticTac[2][2] == 'O')) || ((ticTac[0][0] == 'O') && (ticTac[0][1] == 'O') && (ticTac[0][2] == 'O'))||((ticTac[1][0] == 'O') && (ticTac[1][1] == 'O') && (ticTac[1][2] == 'O')) || ((ticTac[2][0] == 'O') && (ticTac[2][1] == 'O') && (ticTac[2][2] == 'O')))
    {
        winner = "Player O";
        isWinner = true;
    }
    else
    {
        isWinner = false;
    }

    if (!isWinner)
    {
        char ch;
        for (int rows = 0; rows < ROW_SIZE; rows++)
        {
            for (int cols = 0; cols < COL_SIZE; cols++)
            {
                if ((ticTac[rows][cols] == 'X') || (ticTac[rows][cols] == 'O'))
                {
                    count = count + 1;
                }
            }
        }
    }

    if ((!isWinner) && (count == 9))
    {
        winner = "Neither";
        isWinner = true;
    }
    else if (!isWinner)
    {
        isWinner = false;
    }
}

void displayOutput(string winner)
{
    cout << "Winner is: " << winner << endl;
}

/*Sample Dialogue
This is the game of Tic-Tac-Toe.

1 2 3
4 5 6
7 8 9
Please enter the position for player X. 1

X 2 3
4 5 6
7 8 9
Please enter the position for Player O. 2

X O 3
4 5 6
7 8 9
Please enter the position for player X. 3

X O X
4 5 6
7 8 9
Please enter the position for Player O. 4

X O X
O 5 6
7 8 9
Please enter the position for player X. 5

X O X
O X 6
7 8 9
Please enter the position for Player O. 6

X O X
O X O
7 8 9
Please enter the position for player X. 7

X O X
O X O
X 8 9
Winner is: Player X

This is the end of the program.*/
