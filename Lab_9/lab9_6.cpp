#include <iostream>
#include <vector>

enum Game {
	loss,
	win
};

void dfs(std::vector <std::vector <int>>& graph, std::vector <bool>& visited, std::vector<Game>& vertex, int from) {
	visited[from] = true;
	Game status = loss;
	for (size_t i = 0; i < graph[from].size(); i++) {
		size_t to = graph[from][i];
		if (!visited[to])
			dfs(graph, visited, vertex, to);
		if (vertex[to] == loss)
			status = win;
	}
	vertex[from] = status;
}

int main() {
	// freopen("game.in", "r", stdin);
	// freopen("game.out", "w", stdout);
	size_t n, m;
	int chip;
	std::cin >> n >> m >> chip;
	std::vector <std::vector <int>> graph(n);
	std::vector <Game> vertex(n);
	std::vector <bool> visited(n, false);
	for (size_t i = 0; i < m; i++) {
		int from, to;
		std::cin >> from >> to;
		graph[from - 1].push_back(to - 1);	
	}
	dfs(graph, visited, vertex, chip - 1);
	if (vertex[chip - 1])
		std::cout << "First player wins" << "\n";
	else
		std::cout << "Second player wins" << "\n";
	return 0;
}