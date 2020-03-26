#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    std::vector<std::vector <int>> graph(n);
    for (size_t i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    for (auto& i : graph)
	    cout << i.size() << ' ';
    return 0;
}