// Создать новую строку символов, где каждый символ а исходной строки
// дублируется.

// #include <iostream>
//
// using namespace std;
//
// int main()
//{
//	char s[500];
//	char s2[500];
//	int i = 0;
//	int k = 0;
//	cout << "Enter your string: ";
//	gets_s(s);
//	for (i; i <= strlen(s); i++)
//	{
//		s2[k] = s[i];
//		s2[k + 1] = s[i];
//		k += 2;
//	}
//	cout << " Your anser: " << s2 << endl;
//	return 0;
// }

// В строке, состоящей из групп нулей и единиц, найти и вывести на
// экран группы с четным количеством символов.

#include <iostream>
#include <conio.h>

using namespace std;

void Input(char *s)
{
    int i = 0;
    while (1)
    {
        s[i] = _getch();
        if (s[0] == 13)
            continue;
        if (s[i] == 13)
            break;
        if (!(s[i] == '0' || s[i] == '1' || s[i] == ' '))
            continue;
        if (s[i] == ' ' && s[i - 1] == ' ')
            continue;
        if (s[0] == ' ')
            continue;
        cout << s[i];
        i++;
    }
    s[i] = '\0';
}

void main()
{
    char s[500];
    cout << "Input string with 0, 1 " << endl;
    Input(s);
    cout << endl;
    for (int i = 0; i < strlen(s); i++)
    {
        int k = i;
        while (s[i] == s[i + 1])
            i++;
        if ((i - k) % 2)
        {
            for (int t = k; t <= i; t++)
            {
                cout << s[t];
            }
            cout << endl;
        }
    }
}