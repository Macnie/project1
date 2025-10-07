#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack *next;
};

Stack *InStack(Stack *p, int in)
{
    Stack *t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}

void View(Stack *p)
{
    Stack *t = p;
    while (t != NULL)
    {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
}

void Del_All(Stack *&p)
{
    Stack *t;
    while (p != NULL)
    {
        t = p;
        p = p->next;
        delete t;
    }
}

Stack *OutStack(Stack *p, int *out)
{
    Stack *t = p;
    *out = p->info;
    p = p->next;
    delete t;
    return p;
}

void Individ(Stack *p)
{
    int k = 0;
    Stack *p_l = p, *l = p, *new_b = NULL;
    while (l->next != NULL)
    {
        p_l = l;
        l = l->next;
        k++;
    }
    if ((k + 1) == 2)
    {
        l->next = p_l;
        p_l->next = NULL;
        View(l);
    }
    else
    {
        if ((k + 1) == 1)
        {
            View(l);
        }
        else
        {
            l->next = p->next;
            p_l->next = p;
            p->next = NULL;
            View(l);
        }
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    Stack *begin = NULL;
    int n;
    bool menu = 1;

    while (menu == 1)
    {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Просмотреть все элементы" << endl;
        cout << "3. Решение индивидуального задания" << endl;
        cout << "4. Удалить все элементы" << endl;
        cout << "5. Выйти из программы" << endl;

        cin >> n;
        while (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Такого пункта нет. Введите пункт ещё раз: " << endl;
        }
        cout << endl;
        switch (n)
        {
        case 1:
            int i, in, n;
            cout << "Количество n = ";
            cin >> n;
            while (!cin)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Неверное количество. Введите значение n ещё раз: " << endl;
                cout << "Количество n = ";
                cin >> n;
            }
            cout << "Если хотите сами добавить элементы, нажмите 1, если рандомно - 2" << endl;
            switch (_getch())
            {
            case '1':
                for (i = 0; i < n; i++)
                {
                    cout << " Info = ";
                    cin >> in;
                    while (!cin)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Неверное значение. Введите значение ещё раз: " << endl;
                        cout << " Info = ";
                        cin >> in;
                    }
                    begin = InStack(begin, in);
                }
                break;
            default:
            case '2':
                for (i = 0; i < n; i++)
                {
                    in = rand() % 21 - 10;
                    begin = InStack(begin, in);
                }
                break;
            }
            break;
        case 2:
            if (begin == NULL)
            {
                cout << "Стек пуст" << endl;
                break;
            }
            else
                View(begin);
            break;
        case 3:
            Individ(begin);
            break;
        case 4:
            Del_All(begin);
            break;
        case 5:
            menu = 0;
            break;
        default:
            cout << "Такого пункта нет. Введите пункт ещё раз:" << endl;
        }
    }
}