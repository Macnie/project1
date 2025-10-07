#include <iostream>
#include <math.h>
using namespace std;
double f(double a)
{
    return exp(a) / pow(a, 3) - sin(a) * sin(a) * sin(a);
}
double A(double a, double b, int n)
{
    double s = 0, h, x;
    h = (b - a) / n;
    x = a;
    for (int i = 1; i <= n; i++)
    {
        s += f(x + h / 2);
        x += h;
    }
    return s * h;
}
double T(double a, double b, int n)
{
    double s = 0, h, x;
    h = (b - a) / n;
    x = a;
    s += (f(x) + f(b)) / 2;
    for (int i = 1; i < n; i++)
    {
        x += h;
        s += f(x);
    }
    return s * h;
}
double A_2(double IA, double IT, double err, double a, double b)
{
    double A_2;
    A_2 = (IT + 2 * IA) / 3;

    int n = 2;
    double NewT, NewA;
    do
    {
        n = n * 2;
        NewT = T(a, b, n);
        NewA = A(a, b, n);
    } while (abs(NewA - NewT) >= err);
    A_2 = (NewT + 2 * NewA) / 3;

    return A_2;
}
int main()
{
    double IT, IA, IA_2, err = 0.001;
    int a, b, n = 2;
    cout << "Input range:" << endl;
    cin >> a >> b;
    IA = A(a, b, n);
    IT = T(a, b, n);
    IA_2 = A_2(IA, IT, err, a, b);
    cout << "Integral with Average Method: " << IA << endl
         << "Integral with Trapezoid Method: " << IT << endl
         << "Integral Automatic (2): " << IA_2 << endl;
    return 0;
}