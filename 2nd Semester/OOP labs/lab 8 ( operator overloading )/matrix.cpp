#include <iostream>
#include <cmath>
using namespace std;

class Matrix
{
private:
    int r1c1, r1c2, r2c1, r2c2;

public:
    Matrix(int r1c1 = 0, int r1c2 = 0, int r2c1 = 0, int r2c2 = 0)
    {
        this->r1c1 = r1c1;
        this->r1c2 = r1c2;
        this->r2c1 = r2c1;
        this->r2c2 = r2c2;
    }

    void display() const
    {
        cout << "| " << r1c1 << "  " << r1c2 << " |" << endl;
        cout << "| " << r2c1 << "  " << r2c2 << " |" << endl;
    }

    friend Matrix operator+(const Matrix &obj1, const Matrix &obj2);
    friend Matrix operator-(const Matrix &obj1, const Matrix &obj2);
};

Matrix operator+(const Matrix &obj1, const Matrix &obj2)
{
    Matrix temp;
    temp.r1c1 = obj1.r1c1 + obj2.r1c1;
    temp.r1c2 = obj1.r1c2 + obj2.r1c2;
    temp.r2c1 = obj1.r2c1 + obj2.r2c1;
    temp.r2c2 = obj1.r2c2 + obj2.r2c2;
    return temp;
}

Matrix operator-(const Matrix &obj1, const Matrix &obj2)
{
    Matrix temp;
    temp.r1c1 = obj1.r1c1 - obj2.r1c1;
    temp.r1c2 = obj1.r1c2 - obj2.r1c2;
    temp.r2c1 = obj1.r2c1 - obj2.r2c1;
    temp.r2c2 = obj1.r2c2 - obj2.r2c2;
    return temp;
}

int main()
{
    Matrix mat1(1, 2, 3, 4);
    Matrix mat2(11, 12, 13, 14);

    cout << " -- Matrix 1 --" << endl;
    mat1.display();

    cout << " \n-- Matrix 2 --" << endl;
    mat2.display();

    Matrix mat3 = mat1 + mat2;
    cout << " \n-- Matrix 1 + Matrix 2 --" << endl;
    mat3.display();
}

/*
Output

 -- Matrix 1 --
| 1  2 |
| 3  4 |

-- Matrix 2 --
| 11  12 |
| 13  14 |

-- Matrix 1 + Matrix 2 --
| 12  14 |
| 16  18 |

*/