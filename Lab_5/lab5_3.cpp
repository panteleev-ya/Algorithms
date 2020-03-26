#include <iostream>
#include <vector>
#define mod 1000000

using namespace std;

struct item {
	item* prev = NULL;
	item* prev_key = NULL;
	string key;
	string value;
	item* next = NULL;
	item* next_key = NULL;
};

vector<item*> table(mod);

item* make_node(string& key, string& value) {
	item* node = new item();
	node->prev = NULL;
	node->prev_key = NULL;
	node->key = key;
	node->value = value;
	node->next_key = NULL;
	node->next = NULL;
	return node;
}

item* add_node(item*& last, string& key, string& value) {
	item* node = make_node(key, value);
	node->prev = last;
	last->next = node;
	return node;
}

int get_hash(string& key) {
	const int p = 31;
	int hash = 0, p_pow = 1;
	for (char i : key)
	{
		hash += (i - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	if (hash >= 0) {
		return hash % mod;
	}
	else {
		return (mod - abs(hash) % mod) % mod;
	}
}

item* hash_put(string& key, string& value, item*& last) {
	int hash = get_hash(key);
	item* head = table[hash];
	if (head) {
		item* pointer = head;
		while (pointer->next) {
			if (pointer->key == key) {
				pointer->value = value;
				return NULL;
			}
			pointer = pointer->next;
		}
		if (pointer->key != key) {
			item* new_node = add_node(pointer, key, value);
			new_node->prev_key = last;
			if (last) last->next_key = new_node;
			return new_node;
		}
		else {
			pointer->value = value;
			return NULL;
		}
	}
	else {
		table[hash] = make_node(key, value);
		table[hash]->prev_key = last;
		if (last) last->next_key = table[hash];
		return table[hash];
	}
}

void hash_delete(string& key, item*& last) {
	int hash = get_hash(key);
	item* pointer = table[hash];
	while (pointer) {
		if (pointer->key == key) {
			if (last == pointer) last = pointer->prev_key;
			if (pointer->prev_key) pointer->prev_key->next_key = pointer->next_key;
			if (pointer->next_key) pointer->next_key->prev_key = pointer->prev_key;
			if (pointer->prev) pointer->prev->next = pointer->next;
			if (pointer->next) pointer->next->prev = pointer->prev;
			if (pointer == table[hash]) table[hash] = NULL;
			free(pointer);
			return;
		}
		pointer = pointer->next;
	}
}

void hash_get(string& key) {
	item* pointer = table[get_hash(key)];
	while (pointer) {
		if (pointer->key == key) {
			cout << pointer->value << "\n";
			return;
		}
		pointer = pointer->next;
	}
	cout << "none" << '\n';
	return;
}

item* hash_find(string& key) {
	item* pointer = table[get_hash(key)];
	while (pointer) {
		if (pointer->key == key)
			return pointer;
		pointer = pointer->next;
	}
	return NULL;
}

void hash_prev(string& key) {
	item* element = hash_find(key);
	if (element && element->prev_key) cout << element->prev_key->value << "\n";
	else cout << "none" << '\n';
}

void hash_next(string& key) {
	item* element = hash_find(key);
	if (element && element->next_key) cout << element->next_key->value << "\n";
	else cout << "none" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("linkedmap.in", "r", stdin);
	freopen("linkedmap.out", "w", stdout);
	item* last = NULL;
	string command, key, value;
	while (cin >> command) {
		cin >> key;
		if (command == "put") {
			cin >> value;
			item* pointer = hash_put(key, value, last);
			if (pointer) last = pointer;
		}
		else if (command == "delete") {
			hash_delete(key, last);
		}
		else if (command == "get") {
			hash_get(key);
		}
		else if (command == "prev") {
			hash_prev(key);
		}
		else if (command == "next") {
			hash_next(key);
		}
	}
	return 0;
}