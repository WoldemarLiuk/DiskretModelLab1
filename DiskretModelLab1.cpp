#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

#define N 8
int parent[N];

// Пошук множини вершин i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// Об’єднання i та j. Повертає false, якщо i та j вже знаходяться в одному наборі
void unionij(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// Знаходження мінімального остового дерева за допомогою алгоритму Крускала
void kruskal(int cost[][N])
{
	int mincost = 0; // Вага мінімального остового дерева

	// Ініціалізація множин непересікаючих множин
	for (int i = 0; i < N; i++)
		parent[i] = i;

	// Включати один за одним ребра мінімальної ваги
	cout << "Мiнiмальне остове дерево (за алгоритмом Крускала):" << endl;
	int edge_count = 0;
	while (edge_count < N - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (find(i) != find(j) && cost[i][j] < min && cost[i][j] > 0) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
				
		unionij(a, b);
		printf("Ребро %d:(%d, %d) вага:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\nМінімальна вага: %d \n", mincost);
}

// Функція читання матриці
int read_matrix(int cost[N][N]) {
	char line[2];
	string filename;
	
	cout << "Введіть назву файлу, який бажаєте відкрити:" << std::endl;
	cin >> filename;

	ifstream in(filename.c_str());
	if (in.is_open())
				
	{
		in.getline(line, 2); 
		
		cout << "Кiлькiсть вершин: " << line << endl;

		
		cout << "Матриця ваг: " << endl;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				in >> cost[i][j];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << cost[i][j] << "\t";
			cout << "\n";
		}

		in.close();
		return **cost;
	}
	else
	{
		cout << "!Файл не знайдено!";
		return 0;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int cost[N][N];
	read_matrix(cost);

	kruskal(cost);

	return 0;
}
