#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

void bfs(int, int, vector<vector<int>>&, vector<int>&, vector<int>&, queue<int>&);

int main() {
    ifstream IN("pathbge1.in");
    ofstream OUT("pathbge1.out");
    int n, m, a, b;
    IN >> n >> m;
	vector < vector <int> > g(n);
    for(size_t i = 0; i < m; i++) {
        IN >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector <int> ways(n);
	queue <int> top;
	vector <int> used(n, 0);
	used[0] = 1;
    bfs(0, 0, g, used, ways, top);
    int current;
    while(top.size() > 0){
        current = top.front();
        top.pop();
        bfs(ways[current], current, g, used, ways, top);
    }
    for(size_t i = 0; i < n; i++){
        OUT << ways[i] << ' ';
    }
    OUT.close();
    IN.close();
    return 0;
}

void bfs(int waylen, int here, vector<vector<int>>& g, vector<int>& used, vector<int>& ways, queue<int>& top) {
	for (size_t i = 0; i < g[here].size(); i++) {
		if (used[g[here][i]] == 0) {
			used[g[here][i]] = 1;
			ways[g[here][i]] = waylen + 1;
			top.push(g[here][i]);
		}
	}
}