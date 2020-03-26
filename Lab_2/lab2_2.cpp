#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void merge(vector <vector <string>>& m, int l, int mid, int r) {
	int i, j, k;
	vector <vector <string>> b;
	for (i = l, j = mid+1, k = 0; k <= r - l; k++) {
		if (i <= mid && j <= r) {
			if (m[i][0] <= m[j][0]) {
				b.push_back(m[i]);
				i++;
			}
			else {
				b.push_back(m[j]);
				j++;
			}
		}
		else if (i <= mid) {
			b.push_back(m[i]);
			i++;
		}
		else {
			b.push_back(m[j]);
			j++;
		}
	}
	for (k = l; k <= r; k++) {
		m[k] = b[k - l];
	}
	b.clear();
	return;
}

void merge_sort(vector <vector <string>>* m, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merge_sort(m, l, mid);
		merge_sort(m, mid + 1, r);
		merge(*m, l, mid, r);
	}
	return;
}

int main() {
	ifstream fileIN("race.in");
	ofstream fileOUT("race.out");
	vector <vector <string>> mas;
	vector <string> y;
	int n;
	fileIN >> n;//
	string x;
	for (int i = 0; i < n; i++) {
		fileIN >> x; //
		y.push_back(x);
		fileIN >> x; //
		y.push_back(x);
		mas.push_back(y);
		y.clear();
	}
	merge_sort(&mas, 0, n - 1);
	int i = 0;
	while (i < n) {
		string country = mas[i][0];
		fileOUT << "=== " << country << " ===" << '\n'; //
		while (i < n && mas[i][0] == country) {
			fileOUT << mas[i][1] << '\n'; //
			i++;
		}
	}
	return 0;
}