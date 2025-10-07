#include <iostream>
#include <cmath>

using namespace std;
double fun(double x)
{
    return exp(x) / (x * x * x) - pow(sin(x), 3) - 2;
}

double vvod(char *text)
{
    char u[50];
    double l;
    while (true)
    {
        cout << text;
        gets_s(u);
        int p = 0;
        int chpoint = 0;
        for (int a = 0; u[a]; a++)
        {
            for (char i = '0'; i <= '9'; i++)
            {
                if (u[a] == i)
                {
                    p++;
                }
            }
            if (u[a] == '.')
            {
                chpoint++;
            }
        }
        if (p == strlen(u) || (p == strlen(u) - 1 && u[0] == '-') || (p == strlen(u) - 1 && chpoint == 1) || (p == strlen(u) - 2 && chpoint == 1 && u[0] == '-'))
        {
            break;
        }
        else
            cout << "Error" << endl;
    }
    l = atof(u);
    return l;
}

double MetodMS(double a, double h, double eps, int k)
{
    double res1;
    res1 = a - (fun(a) * h / (fun(a) - fun(a - h)));
    while (fabs(res1 - a) > eps)
    {
        (k)++;
        a = res1;
        res1 = a - ((fun(a) * h) / (fun(a) - fun(a - h)));

        if (k == 100)
            break;
    }
    return res1;
}

double MetodMV(double a, double b, double eps, int k)
{
    double res2;
    res2 = b - (fun(b) * (b - a) / (fun(b) - fun(a)));
    while (abs(res2 - b) > eps)
    {
        k++;
        a = b;
        b = res2;
        res2 = b - (fun(b) * (b - a) / (fun(b) - fun(a)));

        if (k == 100)
            break;
    }
    return res2;
}

int main()
{
    double a, b, h, eps;
    char ta[] = "Vvedite a: ";
    char tb[] = "Vvedite b: ";
    char th[] = "Vvedite h: ";
    char ts[] = "Vvedite eps: ";
    int z = 0, k = 0, kod;
    a = vvod(ta);
    do
    {
        b = vvod(tb);
        if (b <= a)
        {
            cout << "Error" << endl;
        }
        else
        {
            break;
        }
    } while (b <= a);
    h = vvod(th);
    do
    {
        eps = vvod(ts);
        if (eps <= 0)
        {
            cout << "Error" << endl;
        }
        else
        {
            break;
        }
    } while (eps <= 0);
    cout << "Viberite 1 - MV, 2 - MS" << endl;
    cin >> kod;
    switch (kod)
    {
    case 1:
    {
        for (double x = a; x < b; x += h)
        {
            if (fun(x) * fun(x + h) < 0)
            {
                z++;
                cout << "Root " << z << " = " << MetodMV(x, h, eps, k) << " " << "Fun(x) = " << fun(MetodMV(x, h, eps, k)) << endl;
            }
        }
        if (z == 0)
        {
            cout << "No root " << endl;
        }
        break;
    }
    case 2:
    {
        for (double x = a; x <= b; x += h)
        {
            if (fun(x) * fun(x + h) < 0)
            {
                z++;
                cout << "Root " << z << " = " << MetodMS(x, h, eps, k) << " " << "Fun(x) = " << fun(MetodMS(x, h, eps, k)) << endl;
            }
        }
        if (z == 0)
        {
            cout << "No root " << endl;
        }
        break;
    }
    }
}