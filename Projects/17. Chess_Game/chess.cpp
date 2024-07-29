#include <iostream>
using namespace std;
class GamePiece
{
    virtual bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8]) = 0;
    char player_piece_colour;

public:
    virtual char Get_piece_name() = 0;
    GamePiece(char PieceColor)
    {
        player_piece_colour = PieceColor;
    }
    char color_piece()
    {
        return player_piece_colour;
    }
    bool legal_move_or_not(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        GamePiece *ptr_gamepiece = Design_game_board[Second_row][Second_col];
        if ((ptr_gamepiece == 0) || (player_piece_colour != color_piece()))
        {
            return Check_legal(First_row, First_col, Second_row, Second_col, Design_game_board);
        }
        return false;
    }
};
class pawn_pieces : public GamePiece
{
public:
    pawn_pieces(char Piece_Color) : GamePiece(Piece_Color) {}

private:
    char Get_piece_name()
    {
        return 'P';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        GamePiece *ptr_gamepiece = Design_game_board[Second_row][Second_col];
        if (ptr_gamepiece == 0)
        {
            if (First_col == Second_col)
            {
                if (color_piece() == 'W')
                {
                    if (Second_row == First_row + 1)
                    {
                        return true;
                    }
                }
                else
                {
                    if (Second_row == First_row - 1)
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            if ((First_col == Second_col + 1) || (First_col == Second_col - 1))
            {
                if (color_piece() == 'W')
                {
                    if (Second_row == First_row + 1)
                    {
                        return true;
                    }
                }
                else
                {
                    if (Second_row == First_row - 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Knight_Piece : public GamePiece
{
public:
    Knight_Piece(char PieceColor) : GamePiece(PieceColor) {}

private:
    char Get_piece_name()
    {
        return 'N';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        if ((First_col == Second_col + 1) || (First_col == Second_col - 1))
        {
            if ((First_row == Second_row + 2) || (First_row == Second_row - 2))
            {
                return true;
            }
        }
        if ((First_col == Second_col + 2) || (First_col == Second_col - 2))
        {
            if ((First_row == Second_row + 1) || (First_row == Second_row - 1))
            {
                return true;
            }
        }
        return false;
    }
};

class Bishop_Piece : public GamePiece
{
public:
    Bishop_Piece(char Piece_Color) : GamePiece(Piece_Color) {}

private:
    char Get_piece_name()
    {
        return 'B';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        if ((Second_col - First_col == Second_row - First_row) || (Second_col - First_col == First_row - Second_row))
        {
            int row_set = (Second_row - First_row > 0) ? 1 : -1;
            int col_set = (Second_col - First_col > 0) ? 1 : -1;
            int check_row;
            int check_col;
            for (check_row = First_row + row_set, check_col = First_col + col_set;
                 check_row != Second_row;
                 check_row = check_row + row_set, check_col = check_col + col_set)
            {
                if (Design_game_board[check_row][check_col] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
class Rook_piece : public GamePiece
{
public:
    Rook_piece(char Piece_Color) : GamePiece(Piece_Color) {}

private:
    char Get_piece_name()
    {
        return 'R';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        if (First_row == Second_row)
        {
            int col_set;
            col_set = (Second_col - First_col > 0) ? 1 : -1;
            for (int check_col = First_col + col_set; check_col != Second_col; check_col += col_set)
            {
                if (Design_game_board[First_row][check_col] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        else if (Second_col == First_col)
        {
            int row_set;
            row_set = (Second_row - First_row > 0) ? 1 : -1;
            for (int check_row = First_row + row_set; check_row != Second_row; check_row += row_set)
            {
                if (Design_game_board[check_row][First_col] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
class Queen_Piece : public GamePiece
{
public:
    Queen_Piece(char PieceColor) : GamePiece(PieceColor) {}

private:
    char Get_piece_name()
    {
        return 'Q';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        if (First_row == Second_row)
        {
            int col_set;
            col_set = (Second_col - First_col > 0) ? 1 : -1;
            for (int check_col = First_col + col_set; check_col != Second_col; check_col += col_set)
            {
                if (Design_game_board[First_row][check_col] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        else if (Second_col == First_col)
        {
            int row_set;
            row_set = (Second_row - First_row > 0) ? 1 : -1;
            for (int check_row = First_row + row_set; check_row != Second_row; check_row += row_set)
            {
                if (Design_game_board[check_row][First_col] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        else if ((Second_col - First_col == Second_row - First_row) || (Second_col - First_col == First_row - Second_row))
        {
            int iRowOffset = (Second_row - First_row > 0) ? 1 : -1;
            int iColOffset = (Second_col - First_col > 0) ? 1 : -1;
            int iCheckRow;
            int iCheckCol;
            for (iCheckRow = First_row + iRowOffset, iCheckCol = First_col + iColOffset;
                 iCheckRow != Second_row;
                 iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
            {
                if (Design_game_board[iCheckRow][iCheckCol] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

class King_Piece : public GamePiece
{
public:
    King_Piece(char PieceColor) : GamePiece(PieceColor) {}

private:
    char Get_piece_name()
    {
        return 'K';
    }
    bool Check_legal(int First_row, int First_col, int Second_row, int Second_col, GamePiece *Design_game_board[8][8])
    {
        int row_data = Second_row - First_row;
        int col_data = Second_col - First_col;
        if (((row_data >= -1) && (row_data <= 1)) && ((col_data >= -1) && (col_data <= 1)))
        {
            return true;
        }
        return false;
    }
};
class Chess_board_class
{
public:
    GamePiece *Actual_game_board[8][8];
    Chess_board_class()
    {
        for (int Row = 0; Row < 8; ++Row)
        {
            for (int Col = 0; Col < 8; ++Col)
            {
                Actual_game_board[Row][Col] = 0;
            }
        }
        for (int Col = 0; Col < 8; ++Col)
        {
            Actual_game_board[6][Col] = new pawn_pieces('B');
        }
        Actual_game_board[7][0] = new Rook_piece('B');
        Actual_game_board[7][1] = new Knight_Piece('B');
        Actual_game_board[7][2] = new Bishop_Piece('B');
        Actual_game_board[7][3] = new King_Piece('B');
        Actual_game_board[7][4] = new Queen_Piece('B');
        Actual_game_board[7][5] = new Bishop_Piece('B');
        Actual_game_board[7][6] = new Knight_Piece('B');
        Actual_game_board[7][7] = new Rook_piece('B');
        for (int Col = 0; Col < 8; ++Col)
        {
            Actual_game_board[1][Col] = new pawn_pieces('W');
        }
        Actual_game_board[0][0] = new Rook_piece('W');
        Actual_game_board[0][1] = new Knight_Piece('W');
        Actual_game_board[0][2] = new Bishop_Piece('W');
        Actual_game_board[0][3] = new King_Piece('W');
        Actual_game_board[0][4] = new Queen_Piece('W');
        Actual_game_board[0][5] = new Bishop_Piece('W');
        Actual_game_board[0][6] = new Knight_Piece('W');
        Actual_game_board[0][7] = new Rook_piece('W');
    }
    ~Chess_board_class()
    {
        for (int Row = 0; Row < 8; ++Row)
        {
            for (int Col = 0; Col < 8; ++Col)
            {
                delete Actual_game_board[Row][Col];
            }
        }
    }
    void print_tabel()
    {
        using namespace std;
        const int width_square = 4;
        const int height_square = 3;
        for (int Row = 0; Row < 8 * height_square; ++Row)
        {
            int square_row = Row / height_square;
            if (Row % 3 == 1)
            {
                cout << '-' << (char)('1' + 7 - square_row) << '-';
            }
            else
            {
                cout << "---";
            }
            for (int Col = 0; Col < 8 * width_square; ++Col)
            {
                int iSquareCol = Col / width_square;
                if (((Row % 3) == 1) && ((Col % 4) == 1 || (Col % 4) == 2) && Actual_game_board[7 - square_row][iSquareCol] != 0)
                {
                    if ((Col % 4) == 1)
                    {
                        cout << Actual_game_board[7 - square_row][iSquareCol]->color_piece();
                    }
                    else
                    {
                        cout << Actual_game_board[7 - square_row][iSquareCol]->Get_piece_name();
                    }
                }
                else
                {
                    if ((square_row + iSquareCol) % 2 == 1)
                    {
                        cout << '*';
                    }
                    else
                    {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
        for (int Row1 = 0; Row1 < height_square; ++Row1)
        {
            if (Row1 % 3 == 1)
            {
                cout << "---";
                for (int Col1 = 0; Col1 < 8 * width_square; ++Col1)
                {
                    int iSquareCol = Col1 / width_square;
                    if ((Col1 % 4) == 1)
                    {
                        cout << (iSquareCol + 1);
                    }
                    else
                    {
                        cout << '-';
                    }
                }
                cout << endl;
            }
        }
    }
    bool check_mate_or_not(char PieceColor)
    {
        int king_row;
        int king_col;
        for (int Row = 0; Row < 8; ++Row)
        {
            for (int Col = 0; Col < 8; ++Col)
            {
                if (Actual_game_board[Row][Col] != 0)
                {
                    if (Actual_game_board[Row][Col]->color_piece() == PieceColor)
                    {
                        if (Actual_game_board[Row][Col]->Get_piece_name() == 'K')
                        {
                            king_row = Row;
                            king_col = Col;
                        }
                    }
                }
            }
        }
        for (int Row = 0; Row < 8; ++Row)
        {
            for (int Col = 0; Col < 8; ++Col)
            {
                if (Actual_game_board[Row][Col] != 0)
                {
                    if (Actual_game_board[Row][Col]->color_piece() != PieceColor)
                    {
                        if (Actual_game_board[Row][Col]->legal_move_or_not(Row, Col, king_row, king_col, Actual_game_board))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool can_move_or_not(char PieceColor)
    {
        for (int Row = 0; Row < 8; ++Row)
        {
            for (int Col = 0; Col < 8; ++Col)
            {
                if (Actual_game_board[Row][Col] != 0)
                {
                    if (Actual_game_board[Row][Col]->color_piece() == PieceColor)
                    {
                        for (int row_move = 0; row_move < 8; ++row_move)
                        {
                            for (int col_move = 0; col_move < 8; ++col_move)
                            {
                                if (Actual_game_board[Row][Col]->legal_move_or_not(Row, Col, row_move, col_move, Actual_game_board))
                                {
                                    GamePiece *Game_pice_temporary_obj = Actual_game_board[row_move][col_move];
                                    Actual_game_board[row_move][col_move] = Actual_game_board[Row][Col];
                                    Actual_game_board[Row][Col] = 0;
                                    bool b_can_move = !check_mate_or_not(PieceColor);
                                    Actual_game_board[Row][Col] = Actual_game_board[row_move][col_move];
                                    Actual_game_board[row_move][col_move] = Game_pice_temporary_obj;
                                    if (b_can_move)
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
class Chess_board_class_2
{
private:
    Chess_board_class Chess_board_class_obj;
    char player_turn;

public:
    Chess_board_class_2() : player_turn('W') {}
    void Start()
    {
        do
        {
            Next_move_game(Chess_board_class_obj.Actual_game_board);
            Alternative_turn_piece();
        } while (!Game_over_or_not());
        Chess_board_class_obj.print_tabel();
    }
    void Next_move_game(GamePiece *Design_game_board[8][8])
    {
        using namespace std;
        bool valid_moves_piece = false;
        do
        {
            cout << " \n         Welcome to Chess Game Developed by Group no 3 \n\n" << endl;
            cout << "\tK=King     square one : " << endl;
            cout << "\tN=Knight  L_shape two move vetically up_down_left_right" << endl;
            cout << "\tQ=Queen   mix bishop_rook" << endl;
            cout << "\tR=Rook    up_dwon  " << endl;
            cout << "\tB=Bishop  diagonally" << endl;
            cout << "\tP=pawn" << endl;
            cout << "Rule for move is :first hight_width of piece second hight_width of piece where to move\n\n" << endl;
            Chess_board_class_obj.print_tabel();
            cout << player_turn << "'s Move  (height_widht) location of piece : ";
            int piece_location;
            cin >> piece_location;
            int start_row = (piece_location / 10) - 1;
            int start_col = (piece_location % 10) - 1;
            cout << "where to move (hight_width) : ";
            int where_to_move_location;
            cin >> where_to_move_location;
            int end_row = (where_to_move_location / 10) - 1;
            int end_col = (where_to_move_location % 10) - 1;
            if ((start_row >= 0 && start_row <= 7) && (start_col >= 0 && start_col <= 7) &&
                (end_row >= 0 && end_row <= 7) && (end_col >= 0 && end_col <= 7))
            {
                GamePiece *Game_pice_obj = Design_game_board[start_row][start_col];
                if ((Game_pice_obj != 0) && (Game_pice_obj->color_piece() == player_turn))
                {
                    if (Game_pice_obj->legal_move_or_not(start_row, start_col, end_row, end_col, Design_game_board))
                    {
                        GamePiece *Game_pice_temporary_obj = Design_game_board[end_row][end_col];
                        Design_game_board[end_row][end_col] = Design_game_board[start_row][start_col];
                        Design_game_board[start_row][start_col] = 0;
                        if (!Chess_board_class_obj.check_mate_or_not(player_turn))
                        {
                            delete Game_pice_temporary_obj;
                            valid_moves_piece = true;
                        }
                        else
                        {
                            Design_game_board[start_row][start_col] = Design_game_board[end_row][end_col];
                            Design_game_board[end_row][end_col] = Game_pice_temporary_obj;
                        }
                    }
                }
            }
            if (!valid_moves_piece)
            {
                cout << "Invalid Move!" << endl;
                cout << "Invalid Move!" << endl;
                cout << "Invalid Move!" << endl;
                cout << "Invalid Move!" << endl;
            }
            else
            {
                system("cls");
            }

        } while (!valid_moves_piece);
    }
    void Alternative_turn_piece()
    {
        player_turn = (player_turn == 'W') ? 'B' : 'W';
    }
    bool Game_over_or_not()
    {

        bool b_can_move(false);
        b_can_move = Chess_board_class_obj.can_move_or_not(player_turn);
        if (!b_can_move)
        {
            if (Chess_board_class_obj.check_mate_or_not(player_turn))
            {
                Alternative_turn_piece();
                cout << "Checkmate, " << player_turn << " Wins!" << endl;
            }
            else
            {
                cout << "Stalemate!" << std::endl;
            }
        }
        return !b_can_move;
    }
};
int main()
{
    Chess_board_class_2 Game_obj_created;
    Game_obj_created.Start();
    return 0;
}