#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct item {
	int k = 0;
	item* l = nullptr;
	item* r = nullptr;
};

void tree_insert(vector<item*>&, item**, item*);
void tree_delete(vector<item*>&, item**, item**, int, item**);
bool tree_exists(vector<item*>&, item**, int);
void tree_prev(item*, int, int);
void tree_next(item*, int, int);

void tree_insert(vector<item*>& v, item** _top, item* k) {
	item* here = (*_top);
	if (k->k < here->k) {
		here = here->l;
		if (here) {
			tree_insert(v, &((*_top)->l), k);
		}
		else {
			(*_top)->l = k;
			v.push_back(k);
			return;
		}
	}
	else if (k->k > here->k) {
		here = here->r;
		if (here) {
			tree_insert(v, &((*_top)->r), k);
		}
		else {
			(*_top)->r = k;
			v.push_back(k);
			return;
		}
	}
	else {
		(*_top)->k = k->k;
	}
	return;
}

void tree_delete(vector<item*>& v, item** _top, item** last, int k, item** invariant) {
	item* here = (*_top);
	if (k == here->k) {
		if (last != nullptr && (*last)->l && (*last)->l->k == k) (*last)->l = nullptr;
		if (last != nullptr && (*last)->r && (*last)->r->k == k) (*last)->r = nullptr;
		if (last == nullptr) {
			if ((*invariant)->r) {
				if ((*invariant)->l) tree_insert(v, &((*invariant)->r), (*invariant)->l);
				*invariant = (*invariant)->r;
			}
			else {
				*invariant = (*invariant)->l;
				return;
			}
		}
		else {
			if (here->r) tree_insert(v, invariant, here->r);
			if (here->l) tree_insert(v, invariant, here->l);
		}
		return;
	}
	else if (k < here->k) {
		if (here->l) {
			tree_delete(v, &((*_top)->l), _top, k, invariant);
		}
		return;
	}
	else if (k > here->k) {
		if (here->r) {
			tree_delete(v, &((*_top)->r), _top,  k, invariant);
		}
		return;
	}
	return;
}

bool tree_exists(vector<item*>& v, item** _top, int k) {
	item* here = (*_top);
	if (here) {
		if (here->k == k) {
			return true;
		}
		else if (k < here->k) {
			if (here->l) {
				return tree_exists(v, &((*_top)->l), k);
			}
			return false;
		}
		else if (k > here->k) {
			if (here->r) {
				return tree_exists(v, &((*_top)->r), k);
			}
			return false;
		}
	}
	return false;
}

void tree_prev(item* top, int k, int best) {
	if (top->k >= k) {
		if (top->l) {
			tree_prev(top->l, k, best);
			return;
		}
		else {
			if (best > INT_MIN) cout << best << '\n';
			else cout << "none" << '\n';
		}
	}
	else {
		if (best < top->k) best = top->k;
		if (top->r && (best > INT_MIN && k - best > 1)) {
			tree_prev(top->r, k, best);
			return;
		}
		else {
			if (best > INT_MIN) cout << best << '\n';
			else cout << "none" << '\n';
		}
	}
	return;
}

void tree_next(item* top, int k, int best) {
	if (top->k <= k) {
		if (top->r) {
			tree_next(top->r, k, best);
			return;
		}
		else {
			if (best < INT_MAX) cout << best << '\n';
			else cout << "none" << '\n';
		}
	}
	else {
		if (best > top->k) best = top->k;
		if (top->l && (best < INT_MAX && best - k > 1)) {
			tree_next(top->l, k, best);
			return;
		}
		else {
			if (best < INT_MAX) cout << best << '\n';
			else cout << "none" << '\n';
		}
	}
	return;
}

void show(vector<item*> v, item* top) {
	cout << "top: " << top->k << endl << endl;
	for (size_t i = 0; i < v.size(); i++) {
		cout << "k: " << v[i]->k << endl;
		if (v[i]->l) cout << " l: " << v[i]->l->k;
		else cout << " NO";
		if (v[i]->r) cout << " r: " << v[i]->r->k << endl;
		else cout << " NO" << endl;
	}
	return;
}

int main() {
	freopen("bstsimple.in", "r", stdin);
	freopen("bstsimple.out", "w", stdout);
	item* top = nullptr;
	vector<item*> v;
	string command;
	int k;
	while (cin >> command) {
		cin >> k;
		if (command == "insert") {
			if (top) {
				item* new_item = new item();
				new_item->k = k;
				tree_insert(v, &top, new_item);
			}
			else {
				top = new item();
				top->k = k;
				v.push_back(top);
			}
		}
		else if (command == "delete") {
			if (top) tree_delete(v, &top, nullptr, k, &top);
		}
		else if (command == "exists") {
			if (top) {
				if (tree_exists(v, &top, k)) cout << "true" << '\n';
				else cout << "false" << '\n';
			}
			else cout << "false" << '\n';
		}
		else if (command == "prev") {
			if (top) tree_prev(top, k, INT_MIN);
			else cout << "none" << '\n';
		}
		else if (command == "next") {
			if (top) tree_next(top, k, INT_MAX);
			else cout << "none" << '\n';
		}
		else if (command == "show") {
			show(v, top);
		}
	}
	return 0;
}