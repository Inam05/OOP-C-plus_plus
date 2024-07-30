#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

class SudokuSolver
{
private:
    vector<vector<int>> sudoku;

public:
    SudokuSolver(const vector<vector<int>> &initialSudoku) : sudoku(initialSudoku) {}

    void displaySudoku() const
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                cout << sudoku[i][j] << " ";
                if ((j + 1) % 3 == 0 && j + 1 < SIZE)
                    cout << "| ";
            }
            cout << endl;
            if ((i + 1) % 3 == 0 && i + 1 < SIZE)
                cout << "------+-------+------" << endl;
        }
        cout << endl;
    }

    bool isSafe(int row, int col, int num) const
    {
        // Check if 'num' is not present in the current row and column 
        for (int i = 0; i < SIZE; ++i)
        {
            if (sudoku[row][i] == num || sudoku[i][col] == num)
            {
                return false;
            }
        }

        // Check if 'num' is not present in the current 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (sudoku[i + startRow][j + startCol] == num)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool findUnassignedLocation(int &row, int &col) const
    {
        for (row = 0; row < SIZE; ++row)
        {
            for (col = 0; col < SIZE; ++col)
            {
                if (sudoku[row][col] == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool solveSudoku()
    {
        int row, col;

        // Check if there are no unassigned locations
        if (!findUnassignedLocation(row, col))
        {
            return true; // Puzzle is solved
        }

        // Try digits 1 to 9
        for (int num = 1; num <= 9; ++num)
        {
            if (isSafe(row, col, num))
            {
                // Assign the digit if it's safe
                sudoku[row][col] = num;

                // Recursively attempt to solve the remaining puzzle
                if (solveSudoku())
                {
                    return true;
                }

                // If assigning the digit doesn't lead to a solution, backtrack
                sudoku[row][col] = 0;
            }
        }

        return false; // No solution found
    }
};

int main()
{
    vector<vector<int>> initialSudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    SudokuSolver solver(initialSudoku);

    cout << "Original Sudoku Board:" << endl;
    solver.displaySudoku();

    if (solver.solveSudoku())
    {
        cout << "Sudoku Solution:" << endl;
        solver.displaySudoku();
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}