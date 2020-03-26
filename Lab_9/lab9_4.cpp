#include <iostream>
#include <vector>

void dfs(std::vector <std::vector <int>>& graph, std::vector <int>& topsort, std::vector <bool>& visited, size_t from) {
    visited[from] = true;
    for (size_t i = 0; i < graph[from].size(); i++) {
        size_t to = graph[from][i];
        if (!visited[to])
            dfs(graph, topsort, visited, to);
    }
    topsort.push_back(from);
}

void transdfs(std::vector <std::vector <int>>& transGraph, std::vector <int>& component, std::vector <bool>& visited, size_t& componentCount, size_t from) {
    visited[from] = true;
    component[from] = componentCount;
    for (size_t i = 0; i < transGraph[from].size(); i++) {
        size_t to = transGraph[from][i];
        if (!visited[to])
            transdfs(transGraph, component, visited, componentCount, to);
    }
}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    size_t n, m; 
    std::cin >> n >> m;
    std::vector<std::vector <int>> graph(n);
    std::vector<std::vector <int>> transGraph(n);
    std::vector<int> topsort;
    std::vector<int> component(n);
    std::vector<bool> visited(n, false);
    size_t componentCount = 1;
    for (size_t i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        transGraph[to - 1].push_back(from - 1);
    }
    for (size_t i = 0; i < n; i++)
        if (!visited[i])
            dfs(graph, topsort, visited, i);
    visited.assign(n, false);
    for (size_t i = 0; i < n; i++) {
        size_t v = topsort[n - 1 - i];
        if (!visited[v]) {
            transdfs(transGraph, component, visited, componentCount, v);
            componentCount++;
        }
    }
    std::cout << componentCount - 1 << "\n";
    for (size_t i = 0; i < n; i++)
        std::cout << component[i] << " ";
    return 0;
}