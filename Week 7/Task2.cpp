#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
private:
    int **MAT;
    int row;
    int col;

public:
    Matrix(int row_ = 0, int col_ = 0)
    {
        row = row_;
        col = col_;
        MAT = new int *[row];

        for (int i = 0; i < row; i++)
        {
            MAT[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                MAT[i][j] = 0;
    }
    void matinit(int row_, int col_)
    {
        row = row_;
        col = col_;
        MAT = new int *[row];

        for (int i = 0; i < row; i++)
        {
            MAT[i] = new int[col];
        }
        cout << "Please fill in the Array: \n";
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> MAT[i][j];
    }
    ~Matrix()
    {
        //
    }
    bool addsubcheck(Matrix m2)
    {
        if (row == m2.row && m2.col == col)
            return true;
        else
            return false;
    }
    bool multicheck(Matrix m2)
    {
        if (col == m2.row)
            return true;
        else
            return false;
    }
    Matrix operator+(Matrix m1)
    {
        Matrix temp(m1.row, m1.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                temp.MAT[i][j] = MAT[i][j] + m1.MAT[i][j];
            }

        return temp;
    }
    Matrix operator-(Matrix m1)
    {
        Matrix temp(m1.row, m1.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                temp.MAT[i][j] = MAT[i][j] - m1.MAT[i][j];
            }

        return temp;
    }
    Matrix operator*(Matrix m1)
    {
        Matrix temp(row, m1.col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < m1.col; j++)
                for (int k = 0; k < col; k++)
                {
                    temp.MAT[i][j] = temp.MAT[i][j] + (MAT[i][k] * m1.MAT[k][j]);
                }
        return temp;
    }

    friend ostream &operator<<(ostream &OUT, Matrix a)
    {
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < a.col; j++)
                OUT << a.MAT[i][j] << "  ";

            OUT << endl;
        }

        return OUT;
    }
};

void menu()
{
    cout << "(1)Initialize Array \n";
    cout << "(2)Addition \n";
    cout << "(3)Subtraction \n";
    cout << "(4)Multiplication \n\n";
    cout << setw(50) << "Enter the menu you would like to enter or enter -1 to exit:";
}
int main()
{
    int rows;
    int columns;
    int select_menu;
    menu();
    cin >> select_menu;
    Matrix m1, m2;
    do
    {

        switch (select_menu)
        {
        case 1:
        {
            cout << "Array No. 1 \n\n";
            cout << "Enter the Number of Rows: ";
            cin >> rows;
            cout << "Enter the Number of Columns: ";
            cin >> columns;
            m1.matinit(rows, columns);
            cout << "Array No. 2 \n\n";
            cout << "Enter the Number of Rows: ";
            cin >> rows;
            cout << "Enter the Number of Columns: ";
            cin >> columns;
            m2.matinit(rows, columns);
            break;
        }
        case 2:
        {
            bool check = m1.addsubcheck(m2);
            if (check)
                cout << m1 + m2;
            else
                cout << "Error, please reinitialize the array\n";

            break;
        }
        case 3:
        {
            bool check = m1.addsubcheck(m2);
            if (check)
            {
                Matrix m3;
                m3 = m1 - m2;
                cout << m3;
            }
            else
                cout << "Error, please reinitialize the array\n";

            break;
        }
        case 4:
        {
            bool check = m1.multicheck(m2);
            if (check)
            {
                Matrix m3;
                m3 = m1 * m2;
                cout << m3;
            }
            else
                cout << "Error, please reinitialize the array\n";
            break;
        }

        case -1:
        {
            system("CLS");
            cout << "Program Exiting...\n\n";
            exit(1);
        }
        default:
            system("CLS");
            cout << setw(50) << "Invalid Input...Try Again: \n";
        }

        menu();
        cin >> select_menu;
    } while (1);
}