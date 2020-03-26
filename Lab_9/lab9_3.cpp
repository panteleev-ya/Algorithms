#include <iostream>
#include <vector>

enum Color {
	white,
	black
};

Color reverse(Color clr) {
	if (clr == black)
		return white;
	return black;
};

void dfs(std::vector <std::vector <int>>& graph, std::vector <Color>& color, int from, Color vertexColor, bool& isBiGraph) {
	color[from] = vertexColor;
	for (size_t to : graph[from]) {
		if (color[to] == white)
			dfs(graph, color, to, reverse(vertexColor), isBiGraph);
		else if (color[to] == vertexColor) {
			isBiGraph = false;
			return;
		}
	}
}

int main() {
	freopen("bipartite.in", "r", stdin);
	freopen("bipartite.out", "w", stdout);
	size_t n, m;
	std::cin >> n >> m;
	std::vector <std::vector <int>> graph(n);
	std::vector <Color> color(n, white);
	for (size_t i = 0; i < m; i++) {
		int from, to;
		std::cin >> from >> to;
		graph[from - 1].push_back(to - 1);
		graph[to - 1].push_back(from - 1);
	}
	bool isBiGraph = true;
	for (size_t i = 0; i < n; i++)
		if (color[i] == white) {
			dfs(graph, color, i, white, isBiGraph);
			if (!isBiGraph) {
				std::cout << "NO";
				return 0;
			}
		}
	std::cout << "YES";
	return 0;
}