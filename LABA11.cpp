#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;

struct Spis2
{
    int info;
    Spis2 *prev, *next;
};

void Create(Spis2 **begin, Spis2 **end, int in)
{
    Spis2 *t = new Spis2;
    t->info = in;
    t->next = t->prev = NULL;
    *begin = *end = t;
}

void AddF(int kod1, Spis2 **begin, Spis2 **end, int in)
{
    Spis2 *t = new Spis2;
    t->info = in;
    t->prev = NULL;
    t->next = *begin;
    (*begin)->prev = t;
    *begin = t;
}

void AddL(int kod1, Spis2 **begin, Spis2 **end, int in)
{
    Spis2 *t = new Spis2;
    t->info = in;
    t->next = NULL;
    t->prev = *end;
    (*end)->next = t;
    *end = t;
}

void View(Spis2 *t)
{
    Spis2 *end = t;
    cout << "Вывод с начала: " << endl;
    while (t != NULL)
    {
        end = t;
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
    cout << "Вывод с конца: " << endl;
    while (end != NULL)
    {
        cout << end->info << " ";
        end = end->prev;
    }
    cout << endl;
}

void Del(Spis2 **begin, Spis2 **end, int in)
{
    Spis2 *key = NULL;
    cout << "Введите искомый элемент: ";
    cin >> in;
    Spis2 *t = *begin;
    while (t != NULL)
    {
        if (t->info == in)
        {
            *key = *t;
        }
        t = t->next;
    }
    if (key == NULL)
    {
        cout << "Искомый элемент не найден" << endl;
        return;
    }
    else
    {
        if (key == *begin)
        {
            *begin = (*begin)->next;
            (*begin)->prev = NULL;
        }
        if (key == *end)
        {
            *end = (*end)->prev;
            (*end)->next = NULL;
        }
        (key->prev)->next = key->next;
        (key->next)->prev = key->prev;
    }
}

void Del_All(Spis2 **begin, Spis2 **end)
{
    Spis2 *t = new Spis2;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}

void Individ(Spis2 **begin, Spis2 **end)
{
    int k = 0;
    Spis2 *p_l = *begin, *l = *begin, *new_b = NULL;
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
            new_b = (*begin)->next;
            l->next = (*begin)->next;
            p_l->next = *begin;
            (*begin)->next = NULL;
            (*begin)->prev = p_l;
            new_b->prev = l;
            l->prev = NULL;
            View(l);
        }
    }
}

int main()
{
    int i, in, n, kod, kod1;
    setlocale(LC_ALL, "ru");
    Spis2 *begin = NULL;
    Spis2 *end = NULL;
    bool menu = 1;

    while (menu == 1)
    {
        cout << "1. Создать элемент" << endl;
        cout << "2. Добавить элемент" << endl;
        cout << "3. Просмотреть все элементы" << endl;
        cout << "4. Удалить элементы" << endl;
        cout << "5. Решение индивидуального задания" << endl;
        cout << "6. Выйти из программы" << endl;

        cin >> kod;
        if (!begin)
        {
            while ((!cin) || (kod != 1))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Список пуст. Создайте первый элемент.(Выберите первый пункт): " << endl;
                cin >> kod;
            }
        }
        while ((!cin) || (kod < 1) || (kod > 6))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Такого пункта нет. Введите пункт ещё раз: " << endl;
            cout << "1. Создать элемент" << endl;
            cout << "2. Добавить элемент" << endl;
            cout << "3. Просмотреть все элементы" << endl;
            cout << "4. Удалить элементы" << endl;
            cout << "5. Решение индивидуального задания" << endl;
            cout << "6. Выйти из программы" << endl;
            cin >> kod;
        }
        cout << endl;
        switch (kod)
        {
        case 1:
            if (begin != NULL)
            {
                cout << "Очистите память" << endl;
                break;
            }
            cout << "Первый элемент: ";
            cin >> in;
            while (!cin)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Неверное значение. Введите значение ещё раз: " << endl;
                cout << "Введите элемент: ";
                cin >> in;
            }
            Create(&begin, &end, in);
            break;
        case 2:
            cout << "Введите элемент: ";
            cin >> in;
            while (!cin)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Неверное значение. Введите значение ещё раз: " << endl;
                cout << "Введите элемент: ";
                cin >> in;
            }
            cout << "Добавить в начало - 1, добавить в конец - 2: ";
            cin >> kod1;
            while ((!cin) || (kod < 1) || (kod > 2))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Добавить в начало - 1, добавить в конец - 2: ";
                cin >> kod;
            }
            if (kod1 == 1)
            {
                AddF(kod1, &begin, &end, in);
                cout << "Элементы добавлены" << endl;
            }
            else
            {
                AddL(kod1, &begin, &end, in);
                cout << "Элементы добавлены" << endl;
            }
            break;
        case 3:
        {
            if (!begin)
            {
                cout << "Список пуст" << endl;
                break;
            }
            View(begin);
            break;
        }
        case 4:
        {
            Del_All(&begin, &end);
            cout << "Память очищена" << endl;
        }
        break;
        case 5:
            Individ(&begin, &end);
            break;
        case 6:
            menu = 0;
            break;
        }
    }
}