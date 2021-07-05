#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>
#include <queue>



using namespace std;

// ����� �������

void printMatrix(int** matrix, int n, ofstream& fout) {
	cout << "�������� �������: " << endl;
	fout << "�������� �������: " << endl;
	fout << "���������� ������: " << n << endl;
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

//�������� ������ � ������

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
	//matrix - ������� ���������
	ofstream fout("result.txt");
	setlocale(LC_ALL, "Rus");
	// n - ���������� ������
	// numberEnter - ����� ���������� �������� ����� �������
	// numberVec - ����� ����� ��� ���� �������������� �����
	// v - �������, � ������� ���������� �����
	int n, numberEnter, numberVec, v;

	// proverka - ���������� ��� �������� ������������ �������� �����
	bool proverka = false;
	//ver - ����������, ���������� �� ����������� ��������� ��������� �������
	int ver;
	cout << "�������� ��� �� ������ ������ ������� ���������: " << endl << "1. �������� �������������" << endl << "2. ������ �������" << endl << "3. ������ �� �����" << endl;
	while (!proverka) {
		scanf_s("%d", &numberEnter);
		cout << endl;
		if (numberEnter == 1 || numberEnter == 2 || numberEnter == 3) proverka = true;
		else printf("������� ������� ������� ��� � �� ����������. ���������� ��� ���.\n");
	}

	if (numberEnter == 1) {
		cout << "������� ���������� ������ � �������: ";
		scanf_s("%d", &n);
		cout << endl;
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}

		cout << "�������� ��� �����: " << endl << "1. ���������������" << endl << "2. �����������������" << endl;

		srand(time(NULL));



		int** matrix;
		matrix = (int**)malloc(sizeof(int) * n); //�������� ������ ��� 


		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); // ���������� �������
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
				printf("������� ������� ������� ��� � �� ����������. ���������� ��� ���.\n");
			}
		}

		// ��������� ��������� �������

		if (numberEnter == 1) {
			for (int i = 0; i < n; i++)							//���������� ������� 
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
						// ������� �������
						if (ver == 1) {
							matrix[i][j] = rand() % 2;
						}
						// ������� �� �������
						else {
							matrix[i][j] = 0;
						}
					}
				}
			}

			if (numberVec == 2) {
				for (int i = 0; i < n; i++)							//�������������� �������
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
			cout << "������� ������� ��� ������ ������ � ������: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "�������� ���� �������. ��������� �������" << endl;
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
		cout << endl << "��������� ������� � ���� result.txt" << endl;
	}

	// ������ ����

	if (numberEnter == 2) {
		cout << "������� ���������� ������ � �������: ";
		scanf_s("%d", &n);
		cout << endl;
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}

		int** matrix;
		int numb;
		matrix = (int**)malloc(sizeof(int) * n); //�������� ������ ���
		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); //���������� �������
		}
		for (int i = 0; i < n; i++) {
			cout << "���� " << i + 1 << "-� ������" << endl << endl;
			for (int j = 0; j < n; j++) {
				if (i == j)
				{
					cout << j + 1 << "-� ������� ������� �� ��������� 0" << endl;
					matrix[i][j] = 0;
				}

				else
				{
					proverka = false;
					while (!proverka) {
						cout << "������� " << j + 1 << "-� ������� �������: ";
						cin >> numb;
						cout << endl;
						if (numb == 0 || numb == 1) {
							matrix[i][j] = numb;
							proverka = true;
						}

						else
						{
							cout << "���������� ����. ��������� �������" << endl;
							proverka = false;
						}
					}
				}
			}
		}


		printMatrix(matrix, n, fout);
		proverka = false;
		while (!proverka) {
			cout << "������� ������� ��� ������ ������ � ������: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "�������� ���� �������. ��������� �������" << endl;
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
			<< "��������� ������� � ���� result.txt" << endl;
	}

	// � ���� � �����

	if (numberEnter == 3) {
		ifstream file("matrix.txt");
		if (!file.is_open()) { // ���� ���� �� ������
			cout << "���� �� ����� ���� ������!\n";
			system("pause");
			return 1;
		}
		file >> n;
		cout << "���������� ������ � ������� �����: " << n << endl;

		int** matrix = (int**)malloc(sizeof(int) * n); //�������� ������ ���
		for (int i = 0; i < n; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * n); //���������� �������
		}
		int* vis = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			vis[i] = 0;
		}


		//��������� ������� 
		//return 1 - ��������� ����������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				file >> matrix[i][j];
				if (matrix[i][j] < 0) {
					cout << "� ������� ��������� ������������� �������. ��������� �������." << endl;
					system("pause");
					return 1;
				}
				if (i == j) {
					if (matrix[i][j] != 0) {
						cout << "� ������� �� ��� �������� ������� ��������� ����. ��������� �������." << endl;
						system("pause");
						return 1;
					}
				}
			}
		}

		file.close(); // ��������� ����


		printMatrix(matrix, n, fout);
		proverka = false;
		while (!proverka) {
			cout << "������� ������� ��� ������ ������ � ������: ";
			cin >> v;
			cout << endl;
			if (v > n || v <= 0) {
				cout << "�������� ���� �������. ��������� �������" << endl;
				proverka = false;
			}

			else
			{
				proverka = true;
			}
		}
		v--;
		bfs(v, matrix, n, vis, fout);

		cout << endl << "��������� ������� � ���� result.txt" << endl;
	}
	system("pause");
	return 0;
}
