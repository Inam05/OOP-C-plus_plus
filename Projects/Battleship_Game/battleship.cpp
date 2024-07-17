#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 5;
const int SHIP_SIZE = 3;
const char EMPTY = '-';
const char SHIP = 'S';
const char HIT = 'X';
const char MISS = 'O';

class BattleshipGame
{
private:
    vector<vector<char>> playerBoard;
    vector<vector<char>> computerBoard;

public:
    BattleshipGame() : playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY)), computerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY))
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        placeShips(computerBoard);
        placeShips(playerBoard); // For simplicity, let the player place their ships.
    }

    void displayBoard(const vector<vector<char>> &board) const
    {
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void placeShips(vector<vector<char>> &board)
    {
        for (int ship = 0; ship < SHIP_SIZE; ++ship)
        {
            int row, col;
            do
            {
                row = rand() % BOARD_SIZE;
                col = rand() % BOARD_SIZE;
            } while (board[row][col] == SHIP);

            board[row][col] = SHIP;
        }
    }

    bool isGameOver() const
    {
        return allShipsSunk(playerBoard) || allShipsSunk(computerBoard);
    }

    bool allShipsSunk(const vector<vector<char>> &board) const
    {
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                if (cell == SHIP)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void playerTurn()
    {
        int row, col;
        cout << "Your Turn - Enter coordinates (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        {
            cout << "Invalid coordinates. Try again." << endl;
            return;
        }

        if (computerBoard[row][col] == SHIP)
        {
            cout << "Hit!" << endl;
            computerBoard[row][col] = HIT;
        }
        else
        {
            cout << "Miss!" << endl;
            computerBoard[row][col] = MISS;
        }
    }

    void computerTurn()
    {
        int row, col;
        do
        {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (playerBoard[row][col] == HIT || playerBoard[row][col] == MISS);

        if (playerBoard[row][col] == SHIP)
        {
            cout << "Computer Hit at (" << row << ", " << col << ")!" << endl;
            playerBoard[row][col] = HIT;
        }
        else
        {
            cout << "Computer Missed at (" << row << ", " << col << ")!" << endl;
            playerBoard[row][col] = MISS;
        }
    }

    void play()
    {
        cout << "Welcome to Battleship!" << endl;

        while (!isGameOver())
        {
            cout << "Your Board:" << endl;
            displayBoard(playerBoard);

            cout << "Computer's Board:" << endl;
            displayBoard(computerBoard);

            playerTurn();
            if (isGameOver())
            {
                break;
            }

            computerTurn();
        }

        if (allShipsSunk(playerBoard))
        {
            cout << "Congratulations! You've sunk all the computer's ships!" << endl;
        }
        else
        {
            cout << "Sorry, the computer has sunk all your ships. Better luck next time!" << endl;
        }
    }
};

int main()
{
    BattleshipGame game;
    game.play();

    return 0;
}
