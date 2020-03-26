#include<iostream>
#include<vector>

int arr[100000];
int n;

using namespace std;

int heapify(int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] < arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] < arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		return 1;
	}
	return 0;
}

int main() {
	freopen("isheap.in", "r", stdin);
	freopen("isheap.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n / 2 - 1; i >= 0; i--) {
		if (heapify(n, i)) {
			cout << "NO" << '\n';
			flag = false;
			return 0;
		}
	}
	if (flag) {
		cout << "YES" << '\n';
	}
	return 0;
}

/*
if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			if (!(arr[i] <= arr[2 * i] && arr[i] <= arr[2 * i + 1])) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < n / 2 - 1; i++) {
			if (!(arr[i] <= arr[2 * i] && arr[i] <= arr[2 * i + 1])) {
				cout << "NO" << '\n';
				return 0;
			}
		}
		if (!(arr[n / 2 - 1] <= arr[n - 1])) {
			cout << "NO" << '\n';
			return 0;
		}
	}
*/