/*
Implement a template class for a Matrix with basic operations like addition, subtraction,
and multiplication. Include error handling for invalid operations.
*/

#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:
    T **data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new T *[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    T &operator()(int r, int c)
    {
        return data[r][c];
    }

    Matrix operator+(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw invalid_argument("Matrix dimensions must match");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Similarly, implement subtraction and multiplication
};

int main()
{
    Matrix<int> mat1(2, 2);
    Matrix<int> mat2(2, 2);

    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(1, 0) = 3;
    mat1(1, 1) = 4;

    mat2(0, 0) = 5;
    mat2(0, 1) = 6;
    mat2(1, 0) = 7;
    mat2(1, 1) = 8;

    Matrix<int> result = mat1 + mat2;

    cout << "Result matrix:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << result(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
