#include <iostream>
#include <fstream>
using namespace std;
//#define OUT cout
//#define IN cin

int main() {
	ifstream IN("input.txt");
	ofstream OUT("output.txt");
	int n;
	bool table[100][100];
	IN >> n;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			IN >> table[i][j];
		}
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (table[i][j] ^ table[j][i]) {
				OUT << "NO" << endl;
				return 0;
			}
			if (i == j && table[i][j]) {
				OUT << "NO" << endl;
				return 0;
			}
		}
	}
	OUT << "YES" << endl;
	return 0;
}