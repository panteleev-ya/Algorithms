#include <iostream>
#include <vector>

void dfs(std::vector <std::vector <int>>& graph, std::vector <bool>& visited, std::vector <int>& way, int from) {
    visited[from] = true;
    for (size_t i = 0; i < graph[from].size(); i++) {
        int to = graph[from][i];
        if (!visited[to])
            dfs(graph, visited, way, to);
    }
    way.push_back(from);
};

bool exist(std::vector <std::vector <int>>& graph, int from, int to) {
    for (size_t i : graph[from])
	    if (i == to)
            return true;
    return false;
};

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector <int>> graph(n);
    std::vector<bool> visited(n);
    std::vector<int> way;
    for (size_t i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    for (size_t i = 0; i < n; i++)
        if (!visited[i])
            dfs(graph, visited, way, i);
    for (size_t i = n - 1; i > 0; i--)
        if (!exist(graph, way[i], way[i - 1])) {
            std::cout << "NO";
            return 0;
        }
    std::cout << "YES";
    return 0;
}
