#include <iostream>
#include <fstream>
using namespace std;
//#define OUT cout
//#define IN cin

int table[100][100];
int main() {
	ifstream IN("input.txt");
	ofstream OUT("output.txt");
	int n, m;
	int a, b;
	IN >> n >> m;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			table[i][j] = 0;
		}
	}
	for (size_t i = 0; i < m; i++) {
		IN >> a >> b;
		table[a - 1][b - 1] += 1;
		if (a != b)
			table[b - 1][a - 1] += 1;
		if (table[a - 1][b - 1] > 1 || table[b - 1][a - 1] > 1) {
			OUT << "YES" << endl;
			return 0;
		}
	}
	OUT << "NO" << endl;
	return 0;
}