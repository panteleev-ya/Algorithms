#include<iostream>
#include<vector>

long long arr[100000];
long long n;

using namespace std;

long long binarysearchLeft(long long a, long long begin, long long end) {
	long long middle = (begin + end) / 2;
	if (arr[middle] < a) {
		if (end - middle == 1) {
			if (arr[middle] == a) {
				return middle + 1;
			}
			if (arr[end] == a) {
				return end + 1;
			}
			return -1;
		}
		else {
			return binarysearchLeft(a, middle, end);
		}
	}
	else if (arr[middle] > a) {
		return binarysearchLeft(a, begin, middle);
	}
	else {
		if (middle == 0 || arr[middle - 1] < a) {
			return middle + 1;
		}
		else {
			return binarysearchLeft(a, begin, middle);
		}
	}
};

long long binarysearchRight(long long a, long long begin, long long end) {
	long long middle = (begin + end) / 2;
	if (arr[middle] < a) {
		if (end - middle == 1) {
			if (arr[end] == a) {
				return end + 1;
			}
			if (arr[middle] == a) {
				return middle + 1;
			}
			return -1;
		}
		else {
			return binarysearchRight(a, middle, end);
		}
	}
	else if (arr[middle] > a) {
		return binarysearchRight(a, begin, middle);
	}
	else {
		if (middle == n - 1 || arr[middle + 1] > a) {
			return middle + 1;
		}
		else if (middle + 1 == end && arr[end] == a) {
			return middle + 2;
		}
		else {
			return binarysearchRight(a, middle, end);
		}
	}
	return -1;
};

int main() {
	freopen("binsearch.in", "r", stdin);
	freopen("binsearch.out", "w", stdout);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long m, q;
	cin >> m;
	for (long long i = 0; i < m; i++) {
		cin >> q;
		if (arr[0] <= q && arr[n - 1] >= q) {
			cout << binarysearchLeft(q, 0, n - 1) << ' ' << binarysearchRight(q, 0, n - 1) << '\n';
		}
		else {
			cout << -1 << ' ' << -1 << '\n';
		}
	}
	return 0;
}