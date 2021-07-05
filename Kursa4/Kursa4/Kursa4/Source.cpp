#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>
#include <queue>



using namespace std;

// Вывод матрицы

void printMatrix(int** matrix, int n, ofstream& fout) {
	cout << "Исходная матрица: " << endl;
	fout << "Исходная матрица: " << endl;
	fout << "Количество вершин: " << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
			fout << matrix[i][j] << " ";
		}
		cout << endl;
		fout << endl;
	}
	cout << endl;
	fout << endl;
}

//Алгоритм обхода в ширину

void bfs(int v, int** p, int n, int* vis, ofstream& fout)
{
	queue <int> q{};
	q.push(v);
	vis[v] = true;

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << ">> " << v + 1 << " ";
		fout << ">> " << v + 1 << " ";
		for (int i = 0; i < n; i++)
		{
			if (p[v][i] == 1 and vis[i] == false)
			{
				q.push(i);
				vis[i] = true;
			}
		}
	}
}

int main(int argc, char** argv) {
	//matrix - матрица смежности
	ofstream fout("result.txt");
	setlocale(LC_ALL, "Rus");
	// n - количество вершин
	// numberEnter - номер выбранного варианта ввода матрицы
	// numberVec - номер ввода для вида направленности графа
	// v - вершина, с которой начинается обход
	int n, numberEnter, numberVec, v;

	// proverka - переменная для проверки правильности варианта ввода
	bool proverka = false;
	//ver - переменная, отвечающая за вероятность генерации связанной вершины
	int ver;
	cout << "Выберите как вы хотите задать матрицу смежности: " << endl << "1. Случайно сгенерировать" << endl << "2. Ввести вручную" << endl << "3. Ввести из файла" << endl;
	while (!proverka) {
		scanf_s("%d", &numberEnter);
		cout << endl;
		if (numberEnter == 1 || numberEnter == 2 || numberEnter == 3) proverka = true;
		else printf("Команда введена неверно или её не существует. Попробуйте ещё раз.\n");
	}

	if (numberEnter == 1) {
		cout << "Введите количество вершин в матрице: ";
		scanf_s("%d", &n);
		cout << endl;
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}

		cout << "Выберите вид графа: " << endl << "1. Ориентированный" << endl << "2. Неориентированный" << endl;

		srand(time(NULL));



		int** matrix;
		matrix = (int**)malloc(sizeof(int) * n); //выделяем память для 


		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); // заполнения матрицы
		}

		proverka = false;
		while (!proverka)
		{
			cin >> numberVec;
			if (numberVec == 1 || numberVec == 2) {
				proverka = true;
			}
			else
			{
				printf("Команда введена неверно или её не существует. Попробуйте ещё раз.\n");
			}
		}

		// Случайная генерация матрицы

		if (numberEnter == 1) {
			for (int i = 0; i < n; i++)							//заполнение массива 
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j)
					{
						matrix[i][j] = 0;
					}

					else
					{
						ver = rand() % 2;
						// вершины связаны
						if (ver == 1) {
							matrix[i][j] = rand() % 2;
						}
						// вершины не связаны
						else {
							matrix[i][j] = 0;
						}
					}
				}
			}

			if (numberVec == 2) {
				for (int i = 0; i < n; i++)							//отзеркаливание матрицы
				{
					for (int j = 0; j < n; j++)
					{
						matrix[j][i] = matrix[i][j];
					}
				}

			}
		}




		printMatrix(matrix, n, fout);

		proverka = false;
		while (!proverka) {
			cout << "Введите вершину для начала поиска в ширину: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "Неверный ввод вершины. Повторите попытку" << endl;
				proverka = false;
			}

			else
			{
				proverka = true;
			}
		}

		v--;
		cout << endl;
		bfs(v, matrix, n, vis, fout);
		cout << endl << "Результат сохранён в файл result.txt" << endl;
	}

	// Ручной ввод

	if (numberEnter == 2) {
		cout << "Введите количество вершин в матрице: ";
		scanf_s("%d", &n);
		cout << endl;
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}

		int** matrix;
		int numb;
		matrix = (int**)malloc(sizeof(int) * n); //выделяем память для
		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); //заполнения матрицы
		}
		for (int i = 0; i < n; i++) {
			cout << "Ввод " << i + 1 << "-й строки" << endl << endl;
			for (int j = 0; j < n; j++) {
				if (i == j)
				{
					cout << j + 1 << "-й элемент массива по умолчанию 0" << endl;
					matrix[i][j] = 0;
				}

				else
				{
					proverka = false;
					while (!proverka) {
						cout << "Введите " << j + 1 << "-й элемент массива: ";
						cin >> numb;
						cout << endl;
						if (numb == 0 || numb == 1) {
							matrix[i][j] = numb;
							proverka = true;
						}

						else
						{
							cout << "Невозможно ввод. Повторите попытку" << endl;
							proverka = false;
						}
					}
				}
			}
		}


		printMatrix(matrix, n, fout);
		proverka = false;
		while (!proverka) {
			cout << "Введите вершину для начала поиска в ширину: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "Неверный ввод вершины. Повторите попытку" << endl;
				proverka = false;
			}

			else
			{
				proverka = true;
			}
		}
		v--;
		bfs(v, matrix, n, vis, fout);


		cout << endl
			<< "Результат сохранён в файл result.txt" << endl;
	}

	// с Ввод с файла

	if (numberEnter == 3) {
		ifstream file("matrix.txt");
		if (!file.is_open()) { // если файл не открыт
			cout << "Файл не может быть открыт!\n";
			system("pause");
			return 1;
		}
		file >> n;
		cout << "Количесвто вершин в матрице равно: " << n << endl;

		int** matrix = (int**)malloc(sizeof(int) * n); //выделяем память для
		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); //заполнения матрицы
		}
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}


		//Считываем матрицу 
		//return 1 - аварийное завершение
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file >> matrix[i][j];
				if (matrix[i][j] < 0) {
					cout << "В матрице обнаружет отрицательный элемент. Исправьте матрицу." << endl;
					system("pause");
					return 1;
				}
				if (i == j) {
					if (matrix[i][j] != 0) {
						cout << "В матрице не все элементы главной диагонали нули. Исправьте матрицу." << endl;
						system("pause");
						return 1;
					}
				}
			}
		}

		file.close(); // закрываем файл


		printMatrix(matrix, n, fout);
		proverka = false;
		while (!proverka) {
			cout << "Введите вершину для начала поиска в ширину: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "Неверный ввод вершины. Повторите попытку" << endl;
				proverka = false;
			}

			else
			{
				proverka = true;
			}
		}
		v--;
		bfs(v, matrix, n, vis, fout);

		cout << endl << "Результат сохранён в файл result.txt" << endl;
	}
	system("pause");
	return 0;
}
