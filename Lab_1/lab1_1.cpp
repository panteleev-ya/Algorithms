#include <iostream>
#include <fstream>
using namespace std;
// #define OUT cout
// #define IN cin

int main() {
	ifstream IN("input.txt");
	ofstream OUT("output.txt");
	int n, m;
	int a, b;
	bool table[100][100];
	IN >> n >> m; // количество вершин и ребер
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			table[i][j] = 0;
		}
	}
	for (size_t i = 0; i < m; i++) {
		IN >> a >> b;
		table[a - 1][b - 1] = 1;
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			OUT << table[i][j] << ' ';
		}
		OUT << endl;
	}
	return 0;
}