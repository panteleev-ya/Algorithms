#include <iostream>

using namespace std;

int stack[1000000];
int last = -1;

void stack_push(int x) {
	stack[++last] = x;
	return;
};

void stack_pop() {
	cout << stack[last] << '\n';
	last--;
	return;
};

int main() {
	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);
	int n, y;
	char x;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == '+') {
			cin >> y;
			stack_push(y);
		}
		else {
			stack_pop();
		}
	}
	return 0;
}