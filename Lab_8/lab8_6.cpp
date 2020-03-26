#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>&, vector<bool>&, vector<int>&, queue<int>&, vector<int>&);

int main() {
	ifstream IN("input.txt");
	ofstream OUT("output.txt");
	int n, m;
	char symbol;
	IN >> n >> m;
	if (n * m < 2) {
		OUT << -1;
		return 0;
	}
	vector < vector <bool> > arr(n, vector <bool>(m, 0));
	int Sx, Sy, Fx, Fy;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			IN >> symbol;
			if (symbol == '.') {
				arr[i][j] = 1;
			}
			else if (symbol == '#') {
				arr[i][j] = 0;
			}
			else if (symbol == 'S') {
				Sx = i;
				Sy = j;
				arr[i][j] = 1;
			}
			else if (symbol == 'T') {
				Fx = i;
				Fy = j;
				arr[i][j] = 1;
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	int N = n * (m + 1);
	vector < vector <int> > g(N);
	vector <int> ways(N);
	vector <int> pred(N);
	queue <int> top;
	vector <bool> used(N, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				if (i > 0 && arr[i - 1][j]) {
					g[i * (m + 1) + j].push_back((i - 1) * (m + 1) + j);
				}
				if (j > 0 && arr[i][j - 1]) {
					g[i * (m + 1) + j].push_back(i * (m + 1) + (j - 1));
				}
				if (i < (n - 1) && arr[i + 1][j]) {
					g[i * (m + 1) + j].push_back((i + 1) * (m + 1) + j);
				}
				if (j < (m - 1) && arr[i][j + 1]) {
					g[i * (m + 1) + j].push_back(i * (m + 1) + (j + 1));
				}
			}
		}
	}
	arr.clear();
	/*
	for (int i = 0; i < g.size(); i++) {
		cout << i << ": ";
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	int start = Sx * (m + 1) + Sy;
	int finish = Fx * (m + 1) + Fy;
	used[start] = 1;
	ways[start] = 0;
	pred[start] = -1;
	for (size_t i = 0; i < g[start].size(); i++) {
		if (used[g[start][i]] == 0) {
			used[g[start][i]] = 1;
			ways[g[start][i]] = ways[start] + 1;
			pred[g[start][i]] = start;
			top.push(g[start][i]);
		}
	}
	while (top.size() > 0 && !used[finish]) {
		bfs(g, used, ways, top, pred);
	}
	if (!used[finish])
		OUT << -1;
	else {
		vector<int> path;
		for (int i = finish; i != -1; i = pred[i])
			path.push_back(i);
		OUT << path.size() - 1 << endl;
		int size = path.size() - 1;
		int last = path[size];
		int diff;
		for (int i = size; i >= 0; i--) {
			diff = path[i] - last;
			if (diff == 1) OUT << 'R';
			else if (diff == -1) OUT << 'L';
			else if (diff == (m + 1)) OUT << 'D';
			else if (diff == -(m + 1)) OUT << 'U';
			last = path[i];
		}
	}
	return 0;
}

void bfs(vector<vector<int>>& g, vector<bool>& used, vector<int>& ways, queue<int>& top, vector<int>& pred) {
	int here = top.front();
	top.pop();
	for (size_t i = 0; i < g[here].size(); i++) {
		if (used[g[here][i]] == 0) {
			used[g[here][i]] = 1;
			ways[g[here][i]] = ways[here] + 1;
			pred[g[here][i]] = here;
			top.push(g[here][i]);
		}
	}
}