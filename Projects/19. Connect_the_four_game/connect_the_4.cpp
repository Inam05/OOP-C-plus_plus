#include <iostream>
using namespace std;

const int rows = 6;
const int cols = 7;

char board[rows * cols];
// Initialize the game board
void initialize_board()
{
    // Set each cell to an empty space (' ')
    for (int i = 0; i < rows * cols; ++i)
    {
        board[i] = ' '; // fill each cell with an empty space
    }
}

// Print the current state of the game board
void print_board()
{
    // Display the board with row and column numbers
    cout << "-----------------------------\n";
    for (int i = 0; i < rows; ++i) // use for new line (outer loop)
    {
        for (int j = 0; j < cols; ++j) // use for display the status
        {
            cout << "| " << board[i * cols + j] << " ";
            // It retrieves cell values ​​from the line board array and displays it on the console. Each cell has a border(|) next to it.
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    for (int j = 0; j < cols; ++j)
    {
        // This line displays the column number with a space.
        cout << "  " << j << " ";
    }
    cout << "\n";
}

// Check if a move is valid
bool the_move_is_valid_or_not(int col)
{
    // Check if the column is within bounds and the top cell in the column is empty
    return col >= 0 && col < cols && board[col] == ' ';
    // when the all conditions have been true , its mean that the player choose a valid move
}

// Drop a player's piece into the specified column
int drop_piece(int col, char player_piece)
{
    // Loop through the column from bottom to top and place the piece in the first empty cell
    for (int i = rows - 1; i >= 0; --i)
    {
        if (board[i * cols + col] == ' ')
        {
            board[i * cols + col] = player_piece;
            return i; // Return the row where the piece is placed
        }
    }
    return -1; // Column is full
    // So, this function basically traverses a column from bottom to top and places the player's piece on the first open space.
}

// Check for a win in a specific direction
bool check_win_direction(int starting_row, int starting_column, int changing_row, int changing_col, char player_piece)
{
    // Loop through four consecutive cells in the specified direction
    for (int i = 0; i < 4; ++i)
    {
        int r = starting_row + i * changing_row;    // its check that 4 pieces are present in a row
        int c = starting_column + i * changing_col; // its check that 4 pieces are present in a column
        if (board[r * cols + c] != player_piece)
        // This is a condition checks that the cells in the current row and column do not contain player packets
        {
            return false; // Not a win in this direction
        }
    }
    // So, this function simply checks the 4 concrete cells running in a specified direction to see if they are filled with player packets.
    return true; // Win in this direction
}

// Check for a win in any direction
bool check_win(int row, int col, char player_piece)
{
    // Check horizontally
    for (int i = 0; i <= cols - 4; ++i)
    {
        if (check_win_direction(row, i, 0, 1, player_piece))
        {
            // The CheckOneDirection function is called in each iteration. This indicates that the main row or I (column) is passed,
            // or 0 or 1 indicates that horixontally have to be checked.
            return true;
        }
    }

    // Check vertically
    for (int i = 0; i <= rows - 4; ++i)
    {
        if (check_win_direction(i, col, 1, 0, player_piece))
        {
            // In this main (row) or col is passed, either to 1 or 0 points indicates that vertices have to be checked.
            return true;
        }
    }

    // Check diagonally (positive slope)
    for (int i = 0; i <= rows - 4; ++i)
    {
        for (int j = 0; j <= cols - 4; ++j)
        {
            // The CheckOneDirection function is called in each iteration.In this i and J(rows and columns) are passed, or 1 or 1 indicates that positive diagonal is to be check.
            if (check_win_direction(i, j, 1, 1, player_piece))
            {
                return true;
            }
        }
    }

    // Check diagonally (negative slope)
    for (int i = 0; i <= rows - 4; ++i)
    {
        for (int j = 3; j < cols; ++j)
        {
            // The CheckOneDirection function is called in each iteration.In this i and J(rows and columns) are passed, or 1 or -1 indicates that negative diagonal is to be check.
            if (check_win_direction(i, j, 1, -1, player_piece))
            {
                return true;
            }
        }
    }

    return false; // No win in any direction
}

// Check if the game board is full
bool board_is_full_or_not()
{
    // Check if any cell in the top row is empty
    for (int i = 0; i < cols; ++i)
    {
        if (board[i] == ' ')
        {
            return false; // Board is not full
        }
    }
    return true; // Board is full
}

// Ask the player if they want to play again
bool play_again()
{
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// Main game function
void play_connect_4_game()
{
    char player1[50], player2[50]; // its means players names contains max 50 characters

    cout << "Welcome to Connect Four!\n";

    cout << "Enter Player 1's name: ";
    cin >> player1;
    cout << "Enter Player 2's name: ";
    cin >> player2;

    char current_player = 'X'; // player X start the game

    do
    {
        initialize_board(); // here board is intialize

        while (true)
        {
            print_board(); // the board is print here

            int col;
            cout << "Player " << ((current_player == 'X') ? player1 : player2) << "'s turn. Enter column (0-6): ";
            cin >> col;

            if (the_move_is_valid_or_not(col)) // check the move is valid or not
            {
                int row = drop_piece(col, current_player); // drop the piece at the player's choosen row

                if (check_win(row, col, current_player)) // check if the current player is win or not
                {
                    print_board(); // print the current board of the game
                    if (current_player == 'X')
                        cout << "Player X wins! Congratulations, " << player1 << "!\n";
                    else
                        cout << "Player O wins! Congratulations, " << player2 << "!\n";
                    break;
                }

                if (board_is_full_or_not()) // check that the board is full or not
                {
                    print_board(); // print the full board
                    cout << "It's a draw!\n";
                    break;
                }

                current_player = (current_player == 'X') ? 'O' : 'X';
            }
            else
            {
                cout << "Invalid move. Please choose a valid column.\n"; // if the move is not valid print this
            }
        }
    } while (play_again()); // do this all if player want to play again
}

// main function
int main()
{
    play_connect_4_game();
    // calling the play function (the main game function)
    return 0;
}