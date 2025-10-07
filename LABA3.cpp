#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()

    // Zadanie 1
    //{
    //	int n = 0, d;
    //	double a, b, h, y, y1, x, x1, ymax, ymin;
    //	cout << "Enter 1, if you want check the result; 2 - write numbers: ";
    //	cin >> d;
    //	if ((!cin) || ((d < 1) || (d > 2)))
    //	{
    //		cout << "Neverniy vvod (vibirite ot 1 do 2)";
    //		return 0;
    //	}
    //	else
    //	{
    //		if (d == 1)
    //		{
    //			a = -0.9;
    //			b = 2.7;
    //			h = 0.3;
    //		}
    //		else
    //		{
    //			cout << "Enter a: ";
    //			cin >> a;
    //			if (!cin)
    //			{
    //				cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //				return 0;
    //			}
    //			cout << "Enter b: ";
    //			cin >> b;
    //			if (!cin)
    //			{
    //				cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //				return 0;
    //			}
    //			cout << "Enter h: ";
    //			cin >> h;
    //			if (!cin)
    //			{
    //				cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //				return 0;
    //			}
    //			if (a > b)
    //			{
    //				cout << "Neverniy vvod (a dozhno bit' men'she b)";
    //				return 0;
    //			}
    //			if (h <= 0)
    //			{
    //				cout << "Neverniy vvod (shag dolzhen bit' bol'she nulya)";
    //				return 0;
    //			}
    //		}
    //	}
    //	x = a;
    //	ymax = ymin = y = (1 - x * x / 4) * cos(x) - (x / 2) * sin(x);
    //	cout << "Results" << setw(25) << "Serial number: " << setw(25) << "X argument value: " << setw(25) << "Function value y: " << endl;
    //	for (x = a; x <= b; x = x + h)
    //	{
    //		y = (1 - x * x / 4) * cos(x) - (x / 2) * sin(x);
    //		if (y < ymin)
    //		{
    //			ymin = y;
    //		}
    //		else
    //		{
    //			if (y > ymax)
    //			{
    //				ymax = y;
    //			}
    //		}
    //		n++;
    //		cout << setw(25) << n << setw(25) << x << setw(25) << y << endl;
    //	}
    //	cout << "The maximum value of the function y: " << ymax << endl;
    //	cout << "The minimum value of the function y: " << ymin << endl;
    //	system("pause");
    // }

    // Zadanie 2
    //{
    //	double s, r, y, a, b, h, x, raz;
    //	int k, n, z;
    //	cout << "Enter a: ";
    //	cin >> a;
    //	if (!cin)
    //	{
    //		cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //		return 0;
    //	}
    //	cout << "Enter b: ";
    //	cin >> b;
    //	if (!cin)
    //	{
    //		cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //		return 0;
    //	}
    //	cout << "Enter h: ";
    //	cin >> h;
    //	if (!cin)
    //	{
    //		cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //		return 0;
    //	}
    //	cout << "Enter n: ";
    //	cin >> n;
    //	if (!cin)
    //	{
    //		cout << "Neverniy vvod (dolzhno bit' chislovoe znachenie)";
    //		return 0;
    //	}
    //	if (a > b)
    //	{
    //	    cout << "Neverniy vvod (a dozhno bit' men'she b)";
    //	    return 0;
    //	}
    //	if (h <= 0)
    //	{
    //		cout << "Neverniy vvod (shag dolzhen bit' bol'she nulya)";
    //		return 0;
    //	}
    //	z = 0;
    //	x = a;
    //	k = 0;
    //	cout << "Results" << setw(20) << "Serial number: " << setw(20) << "X argument value: " << setw(20) << "Function value y: " << setw(20) << "Sum value: " << setw(20) << "Difference value: " << endl;
    //	for (a; a <= b; a = a + h)
    //	{
    //		x = a;
    //		r = s = 1;
    //		for (k = 1; k <= n; k++)
    //		{
    //			r = -r * x * x / ((2*k)*(2*k-1));
    //			s += r;
    //		}
    //		y = cos(x);
    //		raz = abs(y - s);
    //		z++;
    //		cout << setw(20) << z << setw(20) << a << setw(20) << y << setw(20) << s << setw(20) << raz << endl;
    //	}
    //	system("pause");
    // }