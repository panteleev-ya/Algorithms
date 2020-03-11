#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//#define OUT cout
//#define IN cin

int n, m, a, b;
vector < vector <int> > g(100000);
bool used[100000];
vector <int> comp;
int arr[100000];
ifstream IN("components.in");
ofstream OUT("components.out");

void dfs(int);
void find_comps();

int main() {
	IN >> n >> m;
	for (size_t i = 0; i < m; i++) {
		IN >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	find_comps();
	return 0;
}

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	int counter = 0;
	for (size_t i = 0; i < n; i++) {
		arr[i] = i;
	}
	for (size_t i = 0; i < n; i++) {
		used[i] = false;
	}
	for (size_t i = 0; i < n; i++) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			for (size_t j = 0; j < comp.size(); j++) {
				arr[comp[j]] = counter;
			}
			counter++;
		}
	}
	OUT << counter << endl;
	for (size_t i = 0; i < n; i++) {
		OUT << ++arr[i] << ' ';
	}
}