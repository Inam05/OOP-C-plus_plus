/*
Description: A console-based Chess game with basic AI for playing against the computer.
Questions:
How will you represent the game board and pieces?
How will you implement chess rules and moves?
What features will you include for user interaction and AI?
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
#include <cctype>

using namespace std;

enum class PieceColor
{
    WHITE,
    BLACK
};
enum class PieceType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    NONE
};

class Piece
{
protected:
    PieceColor color;
    PieceType type;
    int row;
    int col;

public:
    Piece(PieceColor color, PieceType type, int row, int col)
        : color(color), type(type), row(row), col(col) {}

    PieceColor getColor() const { return color; }
    PieceType getType() const { return type; }
    int getRow() const { return row; }
    int getCol() const { return col; }

    void setPosition(int newRow, int newCol)
    {
        row = newRow;
        col = newCol;
    }

    virtual bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const = 0;
    virtual ~Piece() {}
};

class Pawn : public Piece
{
public:
    Pawn(PieceColor color, int row, int col) : Piece(color, PieceType::PAWN, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic pawn move logic
        int direction = (color == PieceColor::WHITE) ? 1 : -1;
        if (col == newCol && (row + direction == newRow && board[newRow][newCol] == nullptr))
        {
            return true;
        }
        if ((col + 1 == newCol || col - 1 == newCol) && (row + direction == newRow && board[newRow][newCol] != nullptr && board[newRow][newCol]->getColor() != color))
        {
            return true;
        }
        return false;
    }
};

class Rook : public Piece
{
public:
    Rook(PieceColor color, int row, int col) : Piece(color, PieceType::ROOK, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic rook move logic
        if (row == newRow || col == newCol)
        {
            return true;
        }
        return false;
    }
};

class Knight : public Piece
{
public:
    Knight(PieceColor color, int row, int col) : Piece(color, PieceType::KNIGHT, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic knight move logic
        int dRow = abs(row - newRow);
        int dCol = abs(col - newCol);
        return (dRow == 2 && dCol == 1) || (dRow == 1 && dCol == 2);
    }
};

class Bishop : public Piece
{
public:
    Bishop(PieceColor color, int row, int col) : Piece(color, PieceType::BISHOP, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic bishop move logic
        return abs(row - newRow) == abs(col - newCol);
    }
};

class Queen : public Piece
{
public:
    Queen(PieceColor color, int row, int col) : Piece(color, PieceType::QUEEN, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic queen move logic
        return (row == newRow || col == newCol) || (abs(row - newRow) == abs(col - newCol));
    }
};

class King : public Piece
{
public:
    King(PieceColor color, int row, int col) : Piece(color, PieceType::KING, row, col) {}

    bool isValidMove(int newRow, int newCol, const vector<vector<Piece *>> &board) const override
    {
        // Basic king move logic
        return abs(row - newRow) <= 1 && abs(col - newCol) <= 1;
    }
};

class ChessBoard
{
private:
    vector<vector<Piece *>> board;

public:
    ChessBoard() : board(8, vector<Piece *>(8, nullptr))
    {
        setupBoard();
    }

    ~ChessBoard()
    {
        for (auto &row : board)
        {
            for (auto &piece : row)
            {
                delete piece;
            }
        }
    }

    void setupBoard()
    {
        // Place pawns
        for (int col = 0; col < 8; ++col)
        {
            board[1][col] = new Pawn(PieceColor::WHITE, 1, col);
            board[6][col] = new Pawn(PieceColor::BLACK, 6, col);
        }

        // Place rooks
        board[0][0] = new Rook(PieceColor::WHITE, 0, 0);
        board[0][7] = new Rook(PieceColor::WHITE, 0, 7);
        board[7][0] = new Rook(PieceColor::BLACK, 7, 0);
        board[7][7] = new Rook(PieceColor::BLACK, 7, 7);

        // Place knights
        board[0][1] = new Knight(PieceColor::WHITE, 0, 1);
        board[0][6] = new Knight(PieceColor::WHITE, 0, 6);
        board[7][1] = new Knight(PieceColor::BLACK, 7, 1);
        board[7][6] = new Knight(PieceColor::BLACK, 7, 6);

        // Place bishops
        board[0][2] = new Bishop(PieceColor::WHITE, 0, 2);
        board[0][5] = new Bishop(PieceColor::WHITE, 0, 5);
        board[7][2] = new Bishop(PieceColor::BLACK, 7, 2);
        board[7][5] = new Bishop(PieceColor::BLACK, 7, 5);

        // Place queens
        board[0][3] = new Queen(PieceColor::WHITE, 0, 3);
        board[7][3] = new Queen(PieceColor::BLACK, 7, 3);

        // Place kings
        board[0][4] = new King(PieceColor::WHITE, 0, 4);
        board[7][4] = new King(PieceColor::BLACK, 7, 4);
    }

    void displayBoard() const
    {
        for (const auto &row : board)
        {
            for (const auto &piece : row)
            {
                if (piece == nullptr)
                {
                    cout << ". ";
                }
                else
                {
                    cout << static_cast<char>(piece->getType()) << ' ';
                }
            }
            cout << '\n';
        }
    }

    bool movePiece(int startRow, int startCol, int endRow, int endCol, PieceColor color)
    {
        Piece *piece = board[startRow][startCol];
        if (piece == nullptr || piece->getColor() != color)
        {
            cout << "Invalid move.\n";
            return false;
        }

        if (piece->isValidMove(endRow, endCol, board))
        {
            delete board[endRow][endCol];
            board[endRow][endCol] = piece;
            board[startRow][startCol] = nullptr;
            piece->setPosition(endRow, endCol);
            return true;
        }
        else
        {
            cout << "Invalid move.\n";
            return false;
        }
    }

    void saveGame() const
    {
        ofstream outFile("chess_game_history.txt", ios::app);
        if (!outFile)
        {
            cerr << "Error opening file for writing.\n";
            return;
        }
        for (const auto &row : board)
        {
            for (const auto &piece : row)
            {
                if (piece == nullptr)
                {
                    outFile << ". ";
                }
                else
                {
                    outFile << static_cast<char>(piece->getType()) << ' ';
                }
            }
            outFile << '\n';
        }
        outFile.close();
    }
};

// Main function
int main()
{
    ChessBoard board;
    char playAgain;
    int startRow, startCol, endRow, endCol;
    PieceColor currentPlayer = PieceColor::WHITE;

    do
    {
        board.displayBoard();
        cout << "Player " << ((currentPlayer == PieceColor::WHITE) ? "White" : "Black") << "'s turn.\n";
        cout << "Enter start row, start column, end row, end column: ";
        cin >> startRow >> startCol >> endRow >> endCol;
        if (board.movePiece(startRow, startCol, endRow, endCol, currentPlayer))
        {
            board.saveGame();
            currentPlayer = (currentPlayer == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
        }
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (tolower(playAgain) == 'y');

    return 0;
}
