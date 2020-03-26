#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

const int mod = 1000000;
struct Hash {
	int value;
	Hash* next = NULL;
};
Hash* arr[mod];

void hash_insert(int x, int h) {
	Hash* el = new Hash();
	el->value = x;
	if (!arr[h]) {
		arr[h] = el;
	}
	else {
		Hash** q = &arr[h];
		while ((*q)->next != NULL && (*q)->value != x) {
			q = &(*q)->next;
		}
		if ((*q)->next == NULL && (*q)->value != x) {
			(*q)->next = el;
		}
	}
};

void hash_delete(int x, int h) {
	if (arr[h]) {
		if (arr[h]->value == x) {
			arr[h] = arr[h]->next;
		}
		else if (arr[h]->next) {
			Hash** prev = &arr[h];
			Hash** q = &(*prev)->next;
			while ((*q)->next != NULL && (*q)->value != x) {
				prev = q;
				q = &(*q)->next;
			}
			if ((*q)->value == x) {
				(*prev)->next = (*q)->next;
			}
		}
	}
};

void hash_exists (int x, int h) {
	if (arr[h]) {
		Hash* q = arr[h];
		while (q->next != NULL && q->value != x) {
			q = q->next;
		}
		if (q->value == x) {
			cout << "true" << '\n';
			return;
		}
		else {
			cout << "false" << '\n';
			return;
		}
	}
	else {
		cout << "false" << '\n';
		return;
	}
};

int main() {
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int value, h;
	string oper;
	while (cin >> oper) {
		cin >> value;
		h = abs(value) % mod;
		if (oper == "insert") {
			hash_insert(value, h);
		}
		else if (oper == "delete") {
			hash_delete(value, h);
		}
		else if (oper == "exists") {
			hash_exists(value, h);
		}
		/*
		for (int i = 0; i < 10; i++) {
			Hash* q = arr[i];
			if (q) {
				while (q) {
					cout << q->value << ' ';
					q = q->next;
				}
			}
			else {
				cout << -1;
			}
			cout << endl;
		}
		*/
	}
	return 0;
};