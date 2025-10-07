#include <iostream>

using namespace std;

int funrec(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    else
        return funrec(n - 1) + funrec(n - 2);
}

int fun(int n)
{
    int fb = 0, i = 0, fb1 = 1, fb2 = 1;
    while (i < n - 2)
    {
        fb = fb1 + fb2;
        fb1 = fb2;
        fb2 = fb;
        i = i + 1;
    }
    return fb;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n = 5;
    cout << "Введите n: ";
    cin >> n;
    cout << "Ответ через рекурсию: " << funrec(n) << endl;
    cout << "Ответ без рекурсии: " << fun(n) << endl;
}