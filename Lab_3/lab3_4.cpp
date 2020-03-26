#include<iostream>
#include<vector>

long long arr[100000];
long long n;

using namespace std;

void heapify(int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(n, largest);
	}
}

void heapSort(int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(n, i); // образуем дерево
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); // переставляем максимальный элемент в конец
		heapify(i, 0); // образуем дерево
	}
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	heapSort(n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}