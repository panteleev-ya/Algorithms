#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

enum Color {
    white,
    gray,
    black
};

std::vector <std::vector <int> > graph;
std::vector <int> result;
std::vector <Color> color;

bool dfs(int v) {
    color[v] = gray;
    for (int to : graph[v]) {
	    if (color[to] == white)
            dfs(to);
        if (color[to] == gray)
            return true;
    }
    color[v] = black;
    result.push_back(v);
    return false;
}

bool topsort() {
    for (size_t i = 1; i < graph.size(); i++)
        color[i] = white;
    result.clear();
    for (size_t i = 1; i < graph.size(); i++) {
        if (color[i] == white)
            if(dfs(i))
	            return true;
    }
    return false;
}

int main() {
	// freopen("topsort.in", "r", stdin);
    // freopen("topsort.out", "w", stdout);
    int n, m;
	std::cin >> n >> m;
    graph.resize(n + 1);
    color.resize(n + 1);
    result.resize(n + 1);
    for (size_t i = 1; i <= m; i++) {
        int from, to;
        std::cin >> from >> to;
        graph[from].push_back(to);
    }
    if (topsort())
	    std::cout << "-1" << std::endl;
    else
        for (size_t i = n; i >= 1; i--)
	        std::cout << result[i - 1] << " ";
    return 0;
}