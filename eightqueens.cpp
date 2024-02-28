/*
Eight Queens Puzzle
 - Challenges one to place eight queens on an 8x8 chessboard
 - Enter in one coordinate and the rest of the queens will be
    filled so that no two queens threaten each other
 - Incorporates recursion to check for previous Queens and if another one can be placed on the current row or not
 - Uses a 2D array to display the board
*/

/*
Prompt:
1) g++ eightqueens.cpp
2) ./a.out
3) Queen coordinate ("2 7")
*/

#include <iostream>
using namespace std;

// Initializing constants for the board
const int rowSize = 8;
const int colSize = 8;

// Displaying board
void printQueenBoard(char board[rowSize][colSize])
{
    cout << " ";

    // Setting the numbers for the rows
    for (int i = 1; i < colSize + 1; i++)
    {
        cout << " " << i << " ";
    }
    cout << endl;

    // Setting the first element in the 2D array to blank
    for (int i = 0; i < colSize; i++)
    {
        // Setting the numbers for the columns
        cout << i + 1;
        for (int j = 0; j < rowSize; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Checking to see if a queen can be placed in such a position
bool canPlaceQueen(char board[rowSize][colSize], int row, int col)
{
    // Check for the row
    for (int i = 0; i < colSize; i++)
    {
        if (board[row][i] == 'Q' || i == colSize)
        {
            return false;
        }
    }
    // Checking for the column
    for (int i = 0; i < rowSize; i++)
    {
        if (board[i][col] == 'Q' || i == rowSize)
        {
            return false;
        }
    }
    // Checking for top right diagonal
    for (int r = row - 1, c = col + 1; r >= 0 && c < colSize; r--, c++)
    {
        if (board[r][c] == 'Q' || row < 0 || col > colSize)
        {
            return false;
        }
    }
    // Checking for bottom left diagonal
    for (int r = row + 1, c = col - 1; r < rowSize && c >= 0; r++, c--)
    {
        if (board[r][c] == 'Q' || row > rowSize || col < 0)
        {
            return false;
        }
    }
    // Checking for top left diagonal
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 'Q' || row < 0 || col < 0)
        {
            return false;
        }
    }
    // Checking for bottom right diagonal
    for (int r = row + 1, c = col + 1; r < rowSize && c < colSize; r++, c++)
    {
        if (board[r][c] == 'Q' || row > rowSize || col > colSize)
        {
            return false;
        }
    }
    return true;
}

// Recursive function to solve if a Q is placed in such a position
bool solveQueen(char board[rowSize][colSize], int row, int initialRow)
{
    // Skipping the row if there is a Q founded
    if (initialRow == row)
    {
        row = row + 1;
    }
    // Checks if all queens are placed onto the board
    if (row >= rowSize)
    {
        return true;
    }

    for (int i = 0; i < colSize; i++)
    {
        // If you hit the initial Q placed, skipped passed it
        if (board[row][i] == 'Q')
        {
            continue;
        }
        // Place the queen in the spot that it was able to be placed
        if (canPlaceQueen(board, row, i))
        {
            board[row][i] = 'Q';
            // Recursive function to go to the next row to place a Q
            if (solveQueen(board, row + 1, initialRow))
            {
                return true;
            }
            else
            {
                // Set if it is invalid to place a Q
                board[row][i] = '-';
            }
        }
    }
    return false;
}

// Function to go back a row if a Q can not be placed in a specific row
bool initialQ(int initialRow, int initialCol)
{
    // Initialize the 2D array
    char board[rowSize][colSize];

    // For loop to place the - throughout the 2D array
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            board[i][j] = '-';
        }
    }
    // Decrement to match the indexes on the array
    initialRow--;
    initialCol--;

    // Set the initial position with Q
    board[initialRow][initialCol] = 'Q';

    if (!solveQueen(board, 0, initialRow))
    {
        return false;
    }

    // Call print function
    printQueenBoard(board);

    return true;
}

int main()
{
    int userRow;
    int userColumn;

    cout << "Enter initial coordinates of the first queen: ";
    cin >> userRow >> userColumn;
    cout << endl;

    // Call initialQ function with the user inputs
    initialQ(userRow, userColumn);

    return 0;
}