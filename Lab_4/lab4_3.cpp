#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	string s;
	while (cin >> s) {
		char stack[500];
		int last = -1;
		string ans = "YES";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				stack[++last] = s[i];
			}
			else if (s[i] == ')') {
				if (last > -1) {
					if (stack[last] == '(') {
						last--;
					}
					else {
						ans = "NO";
						break;
					}
				}
				else {
					ans = "NO";
					break;
				}
			}
			else if (s[i] == ']') {
				if (last > -1) {
					if (stack[last] == '[') {
						last--;
					}
					else {
						ans = "NO";
						break;
					}
				}
				else {
					ans = "NO";
					break;
				}
			}
		}
		if (last > -1) {
			ans = "NO";
		}
		cout << ans << '\n';
	}
	return 0;
}