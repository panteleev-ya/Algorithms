#include <iostream>
#include <vector>

using namespace std;

struct item {
	int k;
	int left;
	int right;
	item* l = nullptr;
	item* r = nullptr;
	int depth = 1;
};

int main() {
	freopen("height.in", "r", stdin);
	freopen("height.out", "w", stdout);
	int n;
	cin >> n;
	int max_size = 0;
	vector<item*> v;
	for (int i = 0; i < n; i++) {
		item* new_item = new item();
		cin >> new_item->k >> new_item->left >> new_item->right;
		v.push_back(new_item);
	}
	for (size_t i = 0; i < v.size(); i++) {
		// cout << "k: " << v[i]->k << endl;
		if (v[i]->left) {
			v[i]->l = v[v[i]->left - 1];
			v[i]->l->depth = v[i]->depth + 1;
			if (v[i]->l->depth > max_size) {
				max_size = v[i]->l->depth;
			}
			/*
			cout << v[i]->l << endl;
			cout << "depth here: " << v[i]->depth << endl;
			cout << "depth in left: " << v[i]->l->depth << endl;
			*/
		}
		if (v[i]->right) {
			v[i]->r = v[v[i]->right - 1];
			v[i]->r->depth = v[i]->depth + 1;
			if (v[i]->r->depth > max_size) {
				max_size = v[i]->r->depth;
			}
			/*
			cout << v[i]->r << endl;
			cout << "depth here: " << v[i]->depth << endl;
			cout << "depth in right: " << v[i]->r->depth << endl;
			*/
		}
	}
	if (v.size() == 1) cout << 1 << '\n';
	else cout << max_size << '\n';
	/*
	for (int i = 0; i < n; i++) {
		cout << "k: " << v[i]->k << " left: " << v[i]->left << " right: " << v[i]->right << " depth: " << v[i]->depth << endl;
	}
	*/
	return 0;
}