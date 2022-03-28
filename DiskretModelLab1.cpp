#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

#define N 8
int parent[N];

// ����� ������� ������ i
int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

// �ᒺ������ i �� j. ������� false, ���� i �� j ��� ����������� � ������ �����
void unionij(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

// ����������� ���������� �������� ������ �� ��������� ��������� ��������
void kruskal(int cost[][N])
{
	int mincost = 0; // ���� ���������� �������� ������

	// ����������� ������ ������������� ������
	for (int i = 0; i < N; i++)
		parent[i] = i;

	// �������� ���� �� ����� ����� �������� ����
	cout << "�i�i������ ������ ������ (�� ���������� ��������):" << endl;
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
		printf("����� %d:(%d, %d) ����:%d \n",
			edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n̳������� ����: %d \n", mincost);
}

// ������� ������� �������
int read_matrix(int cost[N][N]) {
	char line[2];
	string filename;
	
	cout << "������ ����� �����, ���� ������ �������:" << std::endl;
	cin >> filename;

	ifstream in(filename.c_str());
	if (in.is_open())
				
	{
		in.getline(line, 2); 
		
		cout << "�i���i��� ������: " << line << endl;

		
		cout << "������� ���: " << endl;
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
		cout << "!���� �� ��������!";
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
