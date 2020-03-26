#include <iostream>

using namespace std;

long double ans = 0;

bool check(int n, long double begin, long double end) {
	long double a = begin, b = end, next;
	bool res = (b > 0);
	for (int i = 2; i < n; i++)
	{
		next = b * 2.0 - a + 2.0;
		if (next < 0)
		{
			res = 0;
			break;
		}
		a = b;
		b = next;
	}
	if (res) ans = b;
	return res;
}

int main() {
	freopen("garland.in", "r", stdin);
	freopen("garland.out", "w", stdout);
	int n;
	long double A;
	cin >> n >> A;
	long double l = 0, r = A;
	int i = 0;
	while (i < 100)
	{
		i++;
		long double m = (l + r) / 2;
		if (check(n, A, m)) r = m;
		else l = m;
	}
	cout << fixed << ans << endl;
}