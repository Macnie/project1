#include <iostream>

using namespace std;

int main()

    // Первый уровень сложности.
    // 4. Определить произведение элементов в тех строках, которые не содержат отрицательных элементов.

    //{
    //	int n, m, i, j, k;
    //	double pr;
    //	cout << "Vvedite kolichestvo strok: ";
    //	cin >> n;
    //	if ((n < 1) || (!cin))
    //	{
    //		cout << "Neverniy vvod (kolichestvo strok dolzno bit' natural'nim chislom)" << endl;
    //		return 0;
    //	}
    //	cout << "Vvedite kolichestvo stolbcov: ";
    //	cin >> m;
    //	if ((m < 1) || (!cin))
    //	{
    //		cout << "Neverniy vvod (kolichestvo stolbcov dolzno bit' natural'nim chislom)" << endl;
    //		return 0;
    //	}
    //	double **a;
    //	a = new double *[n];
    //	for (i = 0; i < n; i++)
    //	{
    //		a[i] = new double[m];
    //	}
    //	cout << "Vvedite elementi massiva: "  << endl;
    //	for (i = 0; i < n; i++)
    //	{
    //		for (j = 0; j < m; j++)
    //		{
    //			cout << "a[" << i << "][" << j << "]: ";
    //			cin >> a[i][j];
    //		}
    //	}
    //	for (i = 0; i < n; i++)
    //	{
    //		for (j = 0; j < m; j++)
    //			cout << a[i][j] << "   ";
    //		cout << endl << endl;
    //	}
    //	for (i = 0; i < n; i++)
    //	{
    //		k = 0;
    //		pr = 1;
    //		for (j = 0; j < m; j++)
    //		{
    //			if (a[i][j] < 0)
    //			{
    //				k = 1;
    //				break;
    //			}
    //			else
    //			{
    //				pr *= a[i][j];
    //			}
    //		}
    //		if (k == 1)
    //		{
    //			cout << "Stroka pod nomerom " << i << " soderzhit otricatelniy element" << endl;
    //		}
    //		else
    //		{
    //			cout << "Proizvedenie stroki pod nomerom " << i << ": " << pr << endl;
    //		}
    //	}
    //	for (int i = 0; i < n; i++)
    //		delete[] a[i];
    //	delete[] a;
    //	system("pause");
    //}

    // Второй уровень сложности.
    // 4. Задана матрица размером n x m.Определить количество «особых» элементов матрицы, считая элемент «особым», если он больше суммы остальных
    // элементов своего столбца.

    //
    //{
    //	int n, m, i, j, k = 0;
    //	double sum;
    //	cout << "Vvedite kolichestvo strok: ";
    //	cin >> n;
    //	if ((n < 1) || (!cin))
    //	{
    //		cout << "Neverniy vvod (kolichestvo strok dolzno bit' natural'nim chislom)" << endl;
    //		return 0;
    //	}
    //	cout << "Vvedite kolichestvo stolbcov: ";
    //	cin >> m;
    //	if ((m < 1) || (!cin))
    //	{
    //		cout << "Neverniy vvod (kolichestvo stolbcov dolzno bit' natural'nim chislom)" << endl;
    //		return 0;
    //	}
    //	double **a;
    //	a = new double *[n];
    //	for (i = 0; i < n; i++)
    //	{
    //		a[i] = new double[m];
    //	}
    //	cout << "Vvedite elementi massiva: " << endl;
    //	for (i = 0; i < n; i++)
    //	{
    //		for (j = 0; j < m; j++)
    //		{
    //			cout << "a[" << i << "][" << j << "]: ";
    //			cin >> a[i][j];
    //		}
    //	}
    //	for (i = 0; i < n; i++)
    //	{
    //		for (j = 0; j < m; j++)
    //			cout << a[i][j] << "   ";
    //		cout << endl << endl;
    //	}
    //	for (j = 0; j < m; j++)
    //	{
    //		sum = 0;
    //		for (i = 0; i < n - 1; i++)
    //		{
    //			sum += a[i][j];
    //		}
    //		for (i = 0; i < n - 1; i++)
    //		{
    //			if (a[i][j] > (sum-a[i][j]))
    //			{
    //				k++;
    //			}
    //
    //		}
    //	}
    //	cout << "Kolichestvo osobih chisel ravno: " << k << endl;
    //	for (int i = 0; i < n; i++)
    //		delete[] a[i];
    //	delete[] a;
    //	system("pause");
    //}