#include <iostream>

using namespace std;

int queue[1000000];
int start = 0;
int last = -1;

void queue_push(int x) {
	queue[++last] = x;
	return;
};

void queue_pop() {
	cout << queue[start] << '\n';
	start++;
	return;
};

int main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	int n, y;
	char x;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == '+') {
			cin >> y;
			queue_push(y);
		}
		else {
			queue_pop();
		}
	}
	return 0;
}