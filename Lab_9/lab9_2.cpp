#include <iostream>
#include <vector>

int cycleStart = -1, cycleEnd;

enum Color {
	white,
	grey,
	black
};

bool dfs(size_t& from, std::vector<std::vector<int>>& graph, std::vector<Color>& color, std::vector<int>& parent) {
	color[from] = grey;
	for (size_t i = 0; i < graph[from].size(); i++) {
		size_t to = graph[from][i];
		if (color[to] == white) {
			parent[to] = from;
			if (dfs(to, graph, color, parent))
				return true;
		}
		else if (color[to] == grey) {
			cycleStart = to;
			cycleEnd = from;
			return true;
		}
	}
	color[from] = black;
	return false;
}

int main() {
	// freopen("cycle.in", "r", stdin);
	// freopen("cycle.out", "w", stdout);
	size_t n, m;
	std::cin >> n >> m;
	std::vector<std::vector <int>> graph(n);
	std::vector<Color> color(n, white);
	std::vector<int> parent(n, -1);
	for (size_t i = 0; i < m; i++) {
		size_t from, to;
		std::cin >> from >> to;
		graph[from - 1].push_back(to - 1);
		if (from == to) {
			std::cout << "YES\n" << to;
			return 0;
		}
	}
	for (size_t i = 0; i < n; i++)
		if (color[i] == white && dfs(i, graph, color, parent))
			break;
	if (cycleStart != -1) {
		std::cout << "YES" << "\n";
		std::vector <int> way;
		for (int cycleNow = cycleEnd; cycleNow != cycleStart; cycleNow = parent[cycleNow])
			way.push_back(cycleNow);
		way.push_back(cycleStart);
		for (size_t i = way.size(); i >= 1; i--)
			std::cout << way[i - 1] + 1 << " ";
	}
	else
		std::cout << "NO";
	return 0;
}
