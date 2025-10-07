#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int i = 0, n = 0, z = 0;
    cout << "Введите количество элементов: ";
    cin >> n;
    char *a = new char[i];
    cout << "Введите элементы: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> a[i];
    }
    cout << "Массив заполнен" << endl;
    char x;
    while (z < n)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
            }
        }
        z++;
    }
    cout << "Полученный массив: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << i + 1 << " элемент: " << a[i] << endl;
    }
    delete[] a;
    cout << "Память очищена" << endl;
    return 0;
}
