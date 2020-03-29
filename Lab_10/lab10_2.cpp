#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
constexpr int INF = 31415926535;
using std::cin;
using std::cout;
using std::vector;

void prim(std::vector <std::vector <int>>&, std::vector <int>&, std::vector <bool>&, int, int);

int main() {
	freopen("spantree.in", "r", stdin);
	freopen("spantree.out", "w", stdout);
	int n;
	double result = 0;
	cin >> n;
	std::vector <std::vector <int>> g(n, std::vector <int>(n));
	std::vector <bool> visited(n, false);
	std::vector <std::pair <int, int>> points(n);
	std::vector <int> distanse(n, INF);
	for (auto& point : points)
		cin >> point.first >> point.second;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			g[i][j] = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
	prim(g, distanse, visited, n, 0);
	for (size_t i = 0; i < n; i++)
		result += sqrt(distanse[i]);
	cout.precision(10);
	cout << result << "\n";
	return 0;
};

void prim(std::vector <std::vector <int>>& graph, std::vector <int>& distanse, std::vector <bool>& visited, int n, int start) {
	distanse[start] = 0;
	for (size_t i = 0; i < n; i++) {
		int v = -1;
		for (size_t j = 0; j < n; j++)
			if (!visited[j] && (v == -1 || distanse[j] < distanse[v]))
				v = j;
		visited[v] = true;
		for (size_t j = 0; j < n; j++)
			if (!visited[j] && graph[v][j] < distanse[j] && v != j)
				distanse[j] = graph[v][j];
	}
};
