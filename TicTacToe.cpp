#include <iostream>
using namespace std;

int main()
{
    char board[3][3];
    int menuChoice;
    char playAgain = 'y';

    int scoreX = 0, scoreO = 0, draw = 0;

    do
    {
        cout << "\n========== TIC TAC TOE ==========\n";
        cout << "1. Start Game\n";
        cout << "2. View Rules\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        if (menuChoice == 2)
        {
            cout << "\nRules of Tic Tac Toe:\n";
            cout << "1. This is a 2 player game.\n";
            cout << "2. Player 1 uses X and Player 2 uses O.\n";
            cout << "3. Enter a number from 1 to 9 to mark your position.\n";
            cout << "4. First player to complete a row, column or diagonal wins.\n";
            cout << "5. If all boxes are filled and no one wins, the game is a draw.\n";
        }
        else if (menuChoice == 1)
        {
            do
            {
                char value = '1';
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        board[i][j] = value;
                        value++;
                    }
                }

                char player = 'X';
                int choice, row, col;
                int moves = 0;
                bool win = false;

                while (win == false && moves < 9)
                {
                    cout << "\nCurrent Board:\n\n";

                    for (int i = 0; i < 3; i++)
                    {
                        cout << " ";
                        for (int j = 0; j < 3; j++)
                        {
                            cout << board[i][j];
                            if (j < 2)
                                cout << " | ";
                        }
                        cout << endl;

                        if (i < 2)
                            cout << "---|---|---" << endl;
                    }

                    cout << "\nPlayer " << player << ", enter box number: ";
                    cin >> choice;

                    if (choice < 1 || choice > 9)
                    {
                        cout << "Invalid choice. Enter a number from 1 to 9.\n";
                        continue;
                    }

                    row = (choice - 1) / 3;
                    col = (choice - 1) % 3;

                    if (board[row][col] == 'X' || board[row][col] == 'O')
                    {
                        cout << "Box already filled. Try again.\n";
                        continue;
                    }

                    board[row][col] = player;
                    moves++;

                    for (int i = 0; i < 3; i++)
                    {
                        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                            win = true;
                    }

                    for (int j = 0; j < 3; j++)
                    {
                        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                            win = true;
                    }

                    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
                        win = true;

                    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
                        win = true;

                    if (win == false)
                    {
                        if (player == 'X')
                            player = 'O';
                        else
                            player = 'X';
                    }
                }

                cout << "\nFinal Board:\n\n";

                for (int i = 0; i < 3; i++)
                {
                    cout << " ";
                    for (int j = 0; j < 3; j++)
                    {
                        cout << board[i][j];
                        if (j < 2)
                            cout << " | ";
                    }
                    cout << endl;

                    if (i < 2)
                        cout << "---|---|---" << endl;
                }

                if (win == true)
                {
                    cout << "\nPlayer " << player << " wins the game!\n";
                    if (player == 'X')
                        scoreX++;
                    else
                        scoreO++;
                }
                else
                {
                    cout << "\nGame is a draw!\n";
                    draw++;
                }

                cout << "\nScoreboard:\n";
                cout << "Player X Wins: " << scoreX << endl;
                cout << "Player O Wins: " << scoreO << endl;
                cout << "Draws: " << draw << endl;

                cout << "\nDo you want to play again? (y/n): ";
                cin >> playAgain;
            } while (playAgain == 'y' || playAgain == 'Y');
        }
        else if (menuChoice == 3)
        {
            cout << "\nExiting game. Thank you!\n";
        }
        else
        {
            cout << "\nInvalid menu choice.\n";
        }

    } while (menuChoice != 3);

    return 0;
}