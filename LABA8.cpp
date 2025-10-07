#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;
int n;

double Y(double x)
{
    return cos(x);
}

double S(double x)
{
    double r, s;
    int k;
    r = s = 1;
    for (k = 1; k <= n; k++)
    {
        r = -r * x * x / ((2 * k) * (2 * k - 1));
        s = s + r;
    }
    return s;
}

double RAZ(double x)
{
    return fabs(Y(x) - S(x));
}

void Out_Rez(double (*f)(double), double xn, double xk, double h)
{
    for (double x = xn; x <= xk + h / 2.; x += h)
    {
        if (f == Y)
        {
            cout << "y = " << f(x) << endl;
        }
        else if (f == S)
        {
            cout << "s = " << f(x) << endl;
        }
        else if (f == RAZ)
        {
            cout << "raz = " << f(x) << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    double a, b, h;
    char cont;
    cout << "1- Запус с заданными параметрами.\n2- Запуск с вводом с клавиатуры " << endl;
    switch (_getch())
    {
    case '1':
        a = 0.1;
        b = 1.0;
        h = 0.1;
        cout << "Введите n" << endl;
        cin >> n;
        break;
    case '2':
        cout << "Введите диапазон значений x [ a, b ] с шагом h = " << endl;
        cin >> a >> b >> h >> n;
        break;
    default:
        a = 0.1;
        b = 1;
        h = 0.1;
        cout << "Ошибка ввода! Используются стандартные значения: a = 0.1; b = 1.0; h = 0.1\n"
             << "Введите n" << endl;
        cin >> n;
        break;
    }
    cout << "Выберите действие" << endl
         << "1 - Y(x)\n2 - S(x)\n3 - |Y(x) - S(x)|\n"
         << endl;
    switch (_getch())
    {
    case '1':
        Out_Rez(Y, a, b, h);
        break;
    case '2':
        Out_Rez(S, a, b, h);
        break;
    case '3':
        Out_Rez(RAZ, a, b, h);
        break;
    default:
        cout << "Будет выполняться функция |Y(x) - S(x)|" << endl;
        Out_Rez(RAZ, a, b, h);
    }
    system("pause");
}
