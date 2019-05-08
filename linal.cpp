#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Matrix3D
{
public:
    double** k;
    Matrix3D()
    {
        k = new double* [3];
        for (int i = 0; i < 3; i++)
            k[i] = new double [3];
    }

    ~Matrix3D()
    {
        for (int i = 0; i < 3; i++)
            delete [] k[i];
        delete[] k;
    }

     Matrix3D operator- (const Matrix3D& v)
     {
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                for (unsigned int j = 0; j < 3; j++)
                {
                    res.k[i][j] = k[i][j] - v.k[i][j];
                }
            }
        return res;
     }

     Matrix3D operator+ (const Matrix3D& v)
     {
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                for (unsigned int j = 0; j < 3; j++)
                {
                    res.k[i][j] = v.k[i][j] + k[i][j];
                }
            }
        return res;
     }

   Matrix3D operator* (double a) const
   {
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                for (unsigned int j = 0; j < 3; j++)
                {
                    res.k[i][j] = k[i][j] * a;
                }
            }
        return res;
   }

   Matrix3D operator* (const Matrix3D& v)
   {
        Matrix3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                for (unsigned int j = 0; j < 3; j++)
                {
                    res.k[i][j] = 0;
                }
            }
        for (unsigned int j = 0; j < 3; j++)
            {
            for (unsigned int i = 0; i < 3; i++)
            	for (int d = 0; d < 3; d++)
                {
                    res.k[i][j]+= v.k[d][j] * k[i][d];
                }
            }
        return res;
    }

    void setValue(unsigned int i, unsigned int j, double value)
    {
        k[i][j] = value;
    }

    double getValue(unsigned int i, unsigned int j) const
    {
        return k[i][j];
    }

    double determinant()
    {
        double det;
        det = k[0][0]*(k[1][1]*k[2][2] - k[1][2]*k[2][1]) - k[0][1]*(k[1][0]*k[2][2] - k[1][2]*k[2][0]) + k[0][2]*(k[1][0]*k[2][1] - k[1][1]*k[2][0]);
    return det;
    }
};

Matrix3D operator* (int a, const Matrix3D& v)
{
    return v * a;
}


class Vector3D
{
public:
    double* k;
    Vector3D()
    {
        k = new double[3];
    }

    ~Vector3D()
    {
        delete[] k;
    }
    Vector3D operator- (const Vector3D& v)
    {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                res.k[i] = k[i] - v.k[i];
            }
        return res;
    }

    Vector3D operator+ (const Vector3D& v)
    {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                res.k[i] = v.k[i] + k[i];
            }
        return res;
    }

    double operator* (const Vector3D& v)
    {
        double resk = 0;
        for (unsigned int i = 0; i < 3; i++)
           {
               resk+= v.k[i] * k[i];
           }
        return resk;
    }

    Vector3D operator* (double a) const
    {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                res.k[i] = k[i] * a;
            }
        return res;
    }

    Vector3D operator* (const Matrix3D& b) const
    {
        Vector3D res;
        for (unsigned int i = 0; i < 3; i++)
            {
                for (unsigned int j = 0; j < 3; j++)
                {
                    res.k[i]+= b.k[j][i] * k[j];
                }
            }
        return res;
    }

    void setValue(unsigned int i, double value)
    {
        k[i] = value;
    }

    double getValue(unsigned int i) const
    {
        return k[i];
    }
};
Vector3D operator* (double a, const Vector3D& v)
{
    return v * a;
}



int main()
{
    Vector3D a;
    a.setValue(0, 1);
    a.setValue(1, 3);
    a.setValue(2, 7);

    Vector3D b;
    b.setValue(0, 9);
    b.setValue(1, 0);
    b.setValue(2, -1);

    cout << "a" << endl;
    for(unsigned int i = 0; i < 3; i++)
        {
            cout << a.getValue(i) << " ";
        }
    cout << endl;
    cout << endl;

    cout << "b" << endl;
    for(unsigned int i = 0; i < 3; i++)
        {
            cout << b.getValue(i) << " ";
        }
    cout << endl;
    cout << endl;

    Vector3D c = a + b;
    Vector3D d = a * 9;
    Vector3D e = a - b;
    float ab = a * b;

    cout << "a + b" << endl;
    for(unsigned int i = 0; i < 3; i++)
        {
            cout << c.getValue(i) << " ";
        }
    cout << endl;
    cout << endl;

    cout << "a * 9" << endl;
    for(unsigned int i = 0; i < 3; i++)
        {
            cout << d.getValue(i) << " ";
        }
    cout << endl;
    cout << endl;

    cout << "a - b" << endl;
    for(unsigned int i = 0; i < 3; i++)
        {
            cout << e.getValue(i) << " ";
        }
    cout << endl;
    cout << endl;

    cout << "a * b" << endl;
    cout << ab << endl;
    cout << endl;

    Matrix3D x;
    x.setValue(0, 0, 9);
    x.setValue(0, 1, 1);
    x.setValue(0, 2, 2);
    x.setValue(1, 0, 6);
    x.setValue(1, 1, 3);
    x.setValue(1, 2, 8);
    x.setValue(2, 0, 6);
    x.setValue(2, 1, 9);
    x.setValue(2, 2, 0);

    Matrix3D y;
    y.setValue(0, 0, 5.5);
    y.setValue(0, 1, 0.6);
    y.setValue(0, 2, 0.5);
    y.setValue(1, 0, 6.8);
    y.setValue(1, 1, 1.4);
    y.setValue(1, 2, 7.7);
    y.setValue(2, 0, 4.5);
    y.setValue(2, 1, 5.5);
    y.setValue(2, 2, 4.4);

    cout << "matrix x" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            cout << (x.k[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "matrix y" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            {
                cout << (y.k[i][j]) << " ";
            }
        cout << endl;
    }
    cout << endl;

    Matrix3D q = x + y;
    Matrix3D w = x - y;
    Matrix3D z = x * y;
    Matrix3D u = y * 2;

    cout << "x + y" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            {
                cout << q.getValue(i,j) << " ";
            }
        cout << endl;
    }
    cout << endl;

    cout << "x - y" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            cout << w.getValue(i,j) << " ";
        cout << endl;
    }
    cout << endl;

    cout << "y * 2" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            {
                cout << u.getValue(i,j) << " ";
            }
        cout << endl;
    }
    cout << endl;

    cout << "x * y" << endl;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
            {
                cout << (z.k[i][j]) << " ";
            }
        cout << endl;
    }
    cout << endl;
    cout << "determinant x" << endl;
    cout << x.determinant() << endl;

    return 0;
}
