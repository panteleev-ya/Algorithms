#include <iostream>
#include <vector> 
#include <string> 
#define mod 1000000

using namespace std;

struct item {
	string key;
	string value;
};

void table_put(string key, string value, vector<vector<item>>& t, int hash) {
	for (size_t i = 0; i < t[hash].size(); i++) {
		if (t[hash][i].key == key) {
			t[hash][i].value = value;
			return;
		}
	}
	t[hash].push_back({ key, value });
	return;
};

void table_delete(string key, vector<vector<item>>& t, int hash) {
	int number = -1;
	for (size_t i = 0; i < t[hash].size(); i++) {
		if (t[hash][i].key == key) {
			number = i;
		}
	}
	if (number > -1) {
		for (size_t i = number; i < t[hash].size() - 1; i++) {
			swap(t[hash][i], t[hash][i + 1]);
		}
		t[hash].resize(t[hash].size() - 1);
	}
	return;
};

void table_get(string key, vector<vector<item>>& A, int hash) {
	for (size_t i = 0; i < A[hash].size(); i++) {
		if (A[hash][i].key == key) {
			cout << A[hash][i].value << '\n';
			return;
		}
	}
	cout << "none" << '\n';
	return;
};

int main() {
	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	vector<vector<item>> table(mod);
	int primes[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	int hash;
	string s;
	while (cin >> s) {
		string a, b;
		cin >> a;
		hash = 0;
		for (size_t i = 0; i < a.size(); i++) {
			hash += primes[abs(a[i] - 'a') % 10] * primes[i % 10];
		}
		if (s == "put") {
			cin >> b;
			table_put(a, b, table, hash);
		}
		else if (s == "delete") {
			table_delete(a, table, hash);
		}
		else {
			table_get(a, table, hash);
		}
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>
#define mod 1000000

using namespace std;

struct item {
	string key;
	string value;
};

void table_put(string key, string value, vector<vector<item>>& t, int hash) {
	for (size_t i = 0; i < t[hash].size(); i++) {
		if (t[hash][i].key == key) {
			t[hash][i].value = value;
			return;
		}
	}
	t[hash].push_back({ key, value });
	return;
};

void table_delete(string key, vector<vector<item>>& t, int hash) {
	int number = -1;
	for (size_t i = 0; i < t[hash].size(); i++) {
		if (t[hash][i].key == key) {
			number = i;
		}
	}
	if (number > -1) {
		for (size_t i = number; i < t[hash].size() - 1; i++) {
			swap(t[hash][i], t[hash][i + 1]);
		}
		t[hash].resize(t[hash].size() - 1);
	}
	return;
};

void table_get(string key, vector<vector<item>>& A, int hash) {
	for (size_t i = 0; i < A[hash].size(); i++) {
		if (A[hash][i].key == key) {
			cout << A[hash][i].value << '\n';
			return;
		}
	}
	cout << "none" << '\n';
	return;
};

int main() {
	freopen("map.in", "r", stdin);
	freopen("map.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	vector<vector<item>> table(mod);
	int primes[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	int hash;
	string s;
	while (cin >> s) {
		string a, b;
		cin >> a;
		hash = 0;
		for (int i = 0; i < a.size(); i++) {
			hash += primes[(a[i] - 'a') % 10] * primes[i % 10];
		}
		if (s == "put") {
			cin >> b;
			table_put(a, b, table, hash);
		}
		else if (s == "delete") {
			table_delete(a, table, hash);
		}
		else {
			table_get(a, table, hash);
		}
	}
	return 0;
}
*/
