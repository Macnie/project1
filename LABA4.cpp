#include <iostream>
#include <cmath>

using namespace std;

int main()

// Zadanie 1
//{
//	int i;
//	double n, mini, minn, sum = 0;
//	cout << "Enter n: ";
//	cin >> n;
//	if ((n < 1) || (n > floor(n)) || (!cin))
//	{
//		cout << "Neverniy vvod (n dolzno bit' natural'nim chislom)" << endl;
//		return 0;
//	}
//	double* a = new double[n];
//	cout << "Enter array character: " << endl;
//	for (i = 0; i < n; i++)
//	{
//		cout << "[" << i << "]: ";
//		cin >> a[i];
//	}
//	mini = a[0];
//	minn = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (a[i] < mini)
//		{
//			mini = a[i];
//			minn = i;
//		}
//	}
//	if (minn == 0)
//	{
//		cout << "Min element perviy (symmy poschitet' nevozmozhno)";
//		return 0;
//	}
//	for (i = 0; i < minn; i++)
//	{
//		sum += a[i];
//	}
//	cout << "Result is: " << sum << endl;
//	delete[] a;
//	system("pause");
// }

// Zadanie 2
{
    int i, notr = 0, d, n;
    cout << "Enter n: ";
    cin >> n;
    if ((n < 1) || (!cin))
    {
        cout << "Neverniy vvod (n dolzno bit' natural'nim chislom)" << endl;
        return 0;
    }
    int *a = new int[n];
    cout << "Enter 1 if you want to write array numbers, 2 - random array numbers: ";
    cin >> d;
    if (d != 1 && d != 2)
    {
        cout << "Neverniy vvod (vibirite 1 ili 2)";
        return 0;
    }
    else
    {
        if (d == 1)
        {
            cout << "Enter array characters: " << endl;
            for (i = 0; i < n; i++)
            {
                cout << "[" << i << "]: ";
                cin >> a[i];
            }
        }
        else
        {
            cout << "Array characters: " << endl;
            for (i = 0; i < n; i++)
            {
                a[i] = -n + rand() % (2 * n + 1);
                cout << "[" << i << "]: " << a[i] << endl;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            for (notr = i; notr < n - 1; notr++)
            {
                a[notr] = a[notr + 1];
            }
            n--;
            i--;
        }
    }
    cout << "New array is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]: " << a[i] << endl;
    }
    delete[] a;
    system("pause");
}