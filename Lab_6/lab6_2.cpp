#include <iostream>
#include <vector>
#define TRASH 1e9+7
using namespace std;

struct item {
	int k = 0;
	item* l = nullptr;
	item* r = nullptr;
	int depth = 1;
};

item* findroot(item* node, vector<item*> v)
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->l == node || v[i]->r == node) {
			return findroot(v[i], v);
		}
	}
	return node;
}

bool flag = true;

void check(item* root, int low, int high) {
	if (root == nullptr || !flag) {
		return;
	}
	if (high != TRASH && root->k >= high) {
		flag = false;
		return;
	}
	if (low != TRASH && root->k <= low) {
		flag = false;
		return;
	}
	check(root->r, root->k, high);
	check(root->l, low, root->k);
	return;
}

int main() {
	freopen("check.in", "r", stdin);
	freopen("check.out", "w", stdout);
	int n;
	cin >> n;
	int max_size = 0;
	int left, right;
	vector<item*> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = new item();
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i]->k >> left >> right;
		if (left) v[i]->l = v[left - 1];
		if (right) v[i]->r = v[right - 1];
	}
	if (n) {
		item* root = findroot(v[0], v);
		check(root, TRASH, TRASH);
		if (v.size() == 0 || v.size() == 1 || flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	else {
		cout << "YES" << '\n';
	}
	return 0;
}