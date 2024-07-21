/*
Description: A console-based game of Tic-Tac-Toe with a basic AI opponent.
Questions:
How will you represent the game board and moves?
How will you implement game logic and AI?
What features will you include for user interaction?
*/

/*
    Created by Inam Ul Hassan
    Github : https://github.com/Inam05
*/

// code

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

enum class Player
{
    NONE = ' ',
    PLAYER_X = 'X',
    PLAYER_O = 'O'
};

// Abstract base class for a player
class PlayerBase
{
public:
    virtual Player getSymbol() const = 0;
    virtual void makeMove(vector<vector<Player>> &board) = 0;
    virtual ~PlayerBase() {}
};

// Human player class
class HumanPlayer : public PlayerBase
{
private:
    Player symbol;

public:
    HumanPlayer(Player s) : symbol(s) {}

    Player getSymbol() const override { return symbol; }

    void makeMove(vector<vector<Player>> &board) override
    {
        int row, col;
        cout << "Enter row and column (0-2) for " << static_cast<char>(symbol) << ": ";
        cin >> row >> col;
        while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != Player::NONE)
        {
            cout << "Invalid move. Try again: ";
            cin >> row >> col;
        }
        board[row][col] = symbol;
    }
};

// AI player class (very basic)
class AIPlayer : public PlayerBase
{
private:
    Player symbol;

public:
    AIPlayer(Player s) : symbol(s) {}

    Player getSymbol() const override { return symbol; }

    void makeMove(vector<vector<Player>> &board) override
    {
        // Basic AI: choose the first available spot
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == Player::NONE)
                {
                    board[i][j] = symbol;
                    return;
                }
            }
        }
    }
};

// Game class
class TicTacToeGame
{
private:
    vector<vector<Player>> board;
    Player currentPlayer;
    vector<string> gameHistory;

    bool checkWin(Player player) const
    {
        for (int i = 0; i < 3; ++i)
        {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            {
                return true;
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
            return true;
        }
        return false;
    }

    bool isBoardFull() const
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                if (cell == Player::NONE)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void saveGame() const
    {
        ofstream outFile("game_history.txt", ios::app);
        if (!outFile)
        {
            cerr << "Error opening file for writing.\n";
            return;
        }
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                outFile << static_cast<char>(cell) << ' ';
            }
            outFile << '\n';
        }
        outFile << "Current player: " << static_cast<char>(currentPlayer) << '\n';
        outFile.close();
    }

public:
    TicTacToeGame() : board(3, vector<Player>(3, Player::NONE)), currentPlayer(Player::PLAYER_X) {}

    void playGame(PlayerBase &player1, PlayerBase &player2)
    {
        PlayerBase *players[] = {&player1, &player2};
        int turn = 0;

        while (true)
        {
            cout << "Current board:\n";
            for (const auto &row : board)
            {
                for (const auto &cell : row)
                {
                    cout << static_cast<char>(cell) << ' ';
                }
                cout << '\n';
            }
            players[turn]->makeMove(board);

            if (checkWin(players[turn]->getSymbol()))
            {
                cout << "Player " << static_cast<char>(players[turn]->getSymbol()) << " wins!\n";
                saveGame();
                return;
            }

            if (isBoardFull())
            {
                cout << "The game is a draw!\n";
                saveGame();
                return;
            }

            currentPlayer = (currentPlayer == Player::PLAYER_X) ? Player::PLAYER_O : Player::PLAYER_X;
            turn = 1 - turn;
        }
    }
};

// Admin class
class Admin
{
public:
    void manageGameSettings()
    {
        // Placeholder for managing game settings, e.g., AI difficulty, board size, etc.
        cout << "Game settings management is not yet implemented.\n";
    }
};

// Main function
int main()
{
    TicTacToeGame game;
    HumanPlayer playerX(Player::PLAYER_X);
    AIPlayer playerO(Player::PLAYER_O);
    Admin admin;

    string role;
    cout << "Enter role (admin/player): ";
    getline(cin, role);

    if (role == "admin")
    {
        admin.manageGameSettings();
    }
    else if (role == "player")
    {
        game.playGame(playerX, playerO);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
