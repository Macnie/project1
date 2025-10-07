#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct Stack
{
    char begin;
    Stack *next = NULL;
};

int Prior(char a)
{
    switch (a)
    {
    case '*':
    case '/':
        return 3;
    case '-':
    case '+':
        return 2;
    case '(':
        return 1;
    }
    return 0;
}

Stack *InStack(Stack *p, char out)
{
    Stack *t = new Stack;
    t->begin = out;
    t->next = p;
    return t;
}

Stack *OutStack(Stack *p, char &in)
{
    Stack *t = p;
    in = p->begin;
    p = p->next;
    delete t;
    return p;
}

double Result(Stack *top, char *str)
{
    int i, o = 0, b = 0, j = 0;
    char s, s1, s2, sR = 'z' + 1;
    double d1, d2, res = 0, mat[100];
    cout << "Введите значение переменной:" << endl;

    for (i = 0; str[i] != '\0'; ++i)
    {
        o++;
        s = str[i];
        for (int i = 0; i < j; ++i)
        {
            if (s == str[i])
            {
                b++;
            }
        }
        if (b != 0)
        {
            j++;
            continue;
        }
        if (s >= 'a' && s <= 'z')
        {
            cout << s << "=";
            cin >> mat[int(s - 'a')];
            str[j] = s;
            j++;
        }
    }
    if (o == 1 && (s >= 'a' && s <= 'z'))
    {
        return mat[int(s - 'a')];
    }

    for (i = 0; str[i] != '\0'; ++i)
    {
        s = str[i];
        if (!(s == '+' || s == '*' || s == '/' || s == '-'))
        {
            top = InStack(top, s);
        }
        else
        {
            top = OutStack(top, s2);
            top = OutStack(top, s1);
            d2 = mat[int(s2 - 'a')];
            d1 = mat[int(s1 - 'a')];
            switch (s)
            {
            case '+':
                res = d1 + d2;
                break;
            case '-':
                res = d1 - d2;
                break;
            case '*':
                res = d1 * d2;
                break;
            case '/':
            {
                if (d2 == 0)
                {
                    cout << "Ошибка. Деление на ноль!" << endl;
                    return 0;
                }
                else
                {
                    res = d1 / d2;
                    break;
                }
            }
            }
            mat[int(sR - 'a')] = res;
            top = InStack(top, sR);
            sR++;
        }
    }
    return res;
}

bool check(char *str)
{
    int a = 0, sz = 0, so = 0;
    if (str[0] != '(' && !(str[0] >= 'a' && str[0] <= 'z'))
    {
        return false;
    }
    if (str[0] == '(')
    {
        so++;
    }
    if (str[0] == '(' && str[1] == ')')
    {
        return false;
    }
    if (str[0] == ')' && str[1] == '(')
    {
        return false;
    }
    for (int i = 1; str[i]; i++)
    {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '^')
        {
            if ((str[i - 1] == ')' && str[i + 1] == '(') || (str[i - 1] == ')' && str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'a' && str[i + 1] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') || (str[i + 1] == '(' && str[i - 1] >= 'a' && str[i - 1] <= 'z'))
            {
                continue;
            }
        }
        if (str[i] == '(')
        {
            so++;
            if ((str[i - 1] == '(' && str[i + 1] == '(') || (str[i - 1] == '(' && str[i + 1] >= 'a' && str[i + 1] <= 'z') || ((str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '^') && str[i + 1] >= 'a' && str[i + 1] <= 'z'))
            {
                continue;
            }
        }
        if (str[i] == ')')
        {
            sz++;
            if ((str[i + 1] == ')' && str[i - 1] == ')') || (str[i + 1] == ')' && str[i - 1] >= 'a' && str[i - 1] <= 'z') || ((str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '^') && str[i - 1] >= 'a' && str[i - 1] <= 'z'))
            {
                continue;
            }
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (((str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '^') && (str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '^')) || (str[i + 1] == ')' && (str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '^')) || (str[i - 1] == '(' && (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '^')))
            {
                continue;
            }
        }
        if (i == strlen(str) - 1)
        {
            if (str[i] == ')' || (str[i] >= 'a' && str[i] <= 'z'))
            {
                continue;
            }
        }
        return false;
    }
    if (sz == so)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    Stack *t, *Op = NULL;
    Stack *top = NULL;
    char In[81], Out[81], a;
    int n = 0;
    cout << "Введите выражение: ";
    do
    {
        cin >> In;
        if (check(In) == true)
        {
            break;
        }
        else
        {
            cout << "Неверный ввод!" << endl;
        }
    } while (true);
    for (int i = 0; In[i]; i++)
    {
        if (In[i] >= 'a' && In[i] <= 'z')
        {
            Out[n++] = In[i];
        }
        if (In[i] == '(')
        {
            Op = InStack(Op, In[i]);
        }
        if (In[i] == ')')
        {
            while ((Op->begin) != '(')
            {
                Op = OutStack(Op, a);
                if (!Op)
                    a = '\0';
                Out[n++] = a;
            }
            Op = OutStack(Op, a);
        }
        if (In[i] == '+' || In[i] == '-' || In[i] == '*' || In[i] == '/' || In[i] == '^')
        {
            while (Op != NULL && Prior(Op->begin) >= Prior(In[i]))
            {
                Op = OutStack(Op, a);
                Out[n++] = a;
            }
            Op = InStack(Op, In[i]);
        }
    }
    while (Op != NULL)
    {
        Op = OutStack(Op, a);
        Out[n++] = a;
    }
    Out[n] = '\0';
    cout << "ОПЗ: " << Out << endl;
    cout << "Результат: " << Result(top, Out) << endl;
    return 0;
}