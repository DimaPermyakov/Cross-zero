#include "Header.h"

bool CheckX(int** arr)
{
	// проверка побочной диагонали
	if (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1)
		return true;

	// проверка главной диагонали
	if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1)
		return true;

	for (size_t i = 0; i < 3; i++)
	{
		bool nice = true;
		// проверка строк
		for (size_t j = 0; j < 3; j++)
		{
			if (arr[i][j] == 1)
				continue;
			nice = false;
		}
		if (nice)
			return true;
		// кек

		// проверка столбцов
		nice = true;
		for (size_t j = 0; j < 3; j++)
		{
			if (arr[j][i] == 1)
				continue;
			nice = false;
		}
		if (nice)
			return true;
		// кек
	}
	return false;
}

void PrintArr(int** arr)
{
	cout << "\n\x1b[35m";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (j == 0)
				cout << ' ';
			if (arr[i][j] != 7)
			{
				if (arr[i][j] == 1)
					cout << "x ";
				else
					cout << "o ";
			}
			else
				cout << "_ ";
		}
		cout << endl;
	}
	cout << "\x1b[0m\n";
}

bool CheckO(int** arr)
{
	// проверка побочной диагонали
	if (arr[0][2] == 0 && arr[1][1] == 0 && arr[2][0] == 0)
		return true;

	// проверка главной диагонали
	if (arr[0][0] == 0 && arr[1][1] == 0 && arr[2][2] == 0)
		return true;

	// проверим строки и столбцы
	for (size_t i = 0; i < 3; i++)
	{
		bool nice = true;
		// проверка строк
		for (size_t j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
				continue;
			nice = false;
		}
		if (nice)
			return true;
		// кек

		// проверка столбцов
		nice = true;
		for (size_t j = 0; j < 3; j++)
		{
			if (arr[j][i] == 0)
				continue;
			nice = false;
		}
		if (nice)
			return true;
		// кек
	}
	return false;
}

void PrintTable()
{
	cout << "\x1b[31m*-*-*-*-*-*-ПОМОГАЛКА-*-*-*-*-*\x1b[0m\n\x1b[36m";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			cout << " i=" << i << " j=" << j << "   ";
		cout << endl;
	}
	cout << "\x1b[0m" << endl;
}

size_t GetDataInt()
{
	while (true)
	{
		size_t num;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\x1b[31mВводи числа, горилла!\x1b[0m\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			return num;
		}

	} 
}

void Congratulation()
{
	string text = "";
	ofstream fin2("congratulation.txt");
	ifstream fin("model.txt");
	fin >> text;
	text += ' ';
	string helper;
	cout << "Введите имя человека, кого хотите поздравить(в Р.п.): ";
	getline(cin, helper);
	text += helper;

	getline(fin, helper);
	text += helper;
	fin2 << text;
	fin2.close();
	fin.close();
}

void CrossZero()
{
	int** arr = new int* [3];
	for (size_t i = 0; i < 3; i++)
		arr[i] = new int[3];

	// заполяем для красоты
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			arr[i][j] = 7;

	PrintTable();
	size_t k = 0, i = 0, j = 0;
	while (true)
	{
		if (k != 0)
			PrintArr(arr);
		cout << "Куда ставим 'x'? \n";
		bool ok = false;
		do
		{
			cout << "i = ";
			i = GetDataInt();
			cout << "j = ";
			j = GetDataInt();
			if (i > 2 || j > 2)
			{
				cout << "\x1b[31mИшак! Вводи существующие координаты, обезьяна!\x1b[0m\n";
				continue;
			}

			if (arr[i][j] == 7)
				ok = true;
			else
				cout << "\x1b[31mИшак! Вводи незанятые координаты, обезьяна!\x1b[0m\n";
		} while (!ok);

		arr[i][j] = 1;
		++k;
		PrintArr(arr);
		if (k == 9)
			break;
		if (k > 4)
			if (CheckX(arr))
			{
				cout << "\n  *-*-*-*-*-*-*-*-*-*\n"
					<< "\x1b[36m   Победа крестиков!\x1b[0m"
					<< "\n  *-*-*-*-*-*-*-*-*-*\n";
				for (size_t i = 0; i < 3; i++)
					delete[] arr[i];
				delete[] arr;
				return;
			}

		cout << "Куда ставим 'o'? \n";
		ok = false;
		do
		{
			cout << "i = ";
			i = GetDataInt();
			cout << "j = ";
			j = GetDataInt();
			if (i > 2 || j > 2)
			{
				cout << "\x1b[31mИшак! Вводи существующие координаты, обезьяна!\x1b[0m\n";
				continue;
			}
			if (arr[i][j] == 7)
				ok = true;
			else
				cout << "\x1b[31mИшак! Вводи незанятые координаты, обезьяна!\x1b[0m\n";
		} while (!ok);
		arr[i][j] = 0;
		++k;
		if (k > 4)
			if (CheckO(arr))
			{
				PrintArr(arr);
				cout << "\n  *-*-*-*-*-*-*-*-*-*\n"
					<< "\x1b[36m   Победа ноликов!\x1b[0m"
					<< "\n  *-*-*-*-*-*-*-*-*-*\n";
				for (size_t i = 0; i < 3; i++)
					delete[] arr[i];
				delete[] arr;
				return;
			}

		system("cls");
		PrintTable();
	}

	cout << "\n  *-*-*-*\n"
		<< "\x1b[36m   Ничья!\x1b[0m"
		<< "\n  *-*-*-*\n";
	for (size_t i = 0; i < 3; i++)
		delete[] arr[i];
	delete[] arr;
	return;
}