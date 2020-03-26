#include<iostream>
#include<fstream>

unsigned long long count = 0;
int m[100001];

using namespace std;

void merge(int* m, int l, int mid, int r) {
	int i, j, k;
	int* b = new int[r - l + 1];
	for (i = l, j = mid + 1, k = 0; k <= r - l; k++) {
		if (i <= mid && j <= r) {
			if (m[i] <= m[j]) {
				b[k] = m[i];
				i++;
			}
			else {
				b[k] = m[j];
				j++;
				::count += mid - i + 1;
			}
		}
		else if (i <= mid) {
			b[k] = m[i];
			i++;
		}
		else {
			b[k] = m[j];
			j++;
		}
	}
	for (k = l; k <= r; k++) {
		m[k] = b[k - l];
	}
	delete[] b;
	return;
}

void merge_sort(int* m, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(m, l, mid);
		merge_sort(m, mid + 1, r);
		merge(m, l, mid, r);
	}
	return;
}

int main() {
	ifstream fileIN("inversions.in");
	ofstream fileOUT("inversions.out");
	int n;
	fileIN >> n;
	//cin >> n;
	for (int i = 0; i < n; i++) {
		fileIN >> ::m[i];
		//cin >> ::m[i];
	}
	merge_sort(::m, 0, n - 1);
	fileOUT << ::count << endl;
	//cout << ::count << endl;
	fileIN.close();
	fileOUT.close();
	return 0;
}