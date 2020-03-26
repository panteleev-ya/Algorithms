#include <algorithm>
#include <iostream>
#include <vector>
constexpr int INF = 10e5 + 7;
#define int long long
using std::cin;
using std::cout;

std::vector <int> p;
int fp(int x);
bool united(std::pair<int, int> e);
void unite(std::pair<int, int> e);

// Kruskal algo
int32_t main() {
	// freopen("spantree3.in", "r", stdin);
	// freopen("spantree3.out", "w", stdout);

	std::ios_base::sync_with_stdio(false);
    int n, m, a, b, l;
    cin >> n >> m;
    p.resize(n + 1);
    std::vector <std::pair <int, std::pair <int, int>>> edges;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        edges.push_back({ l, {a, b} });
    }
    int ans = 0;
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (auto& e : edges) {
        if (!united(e.second)) {
            unite(e.second);
            ans += e.first;
        }
    }
    cout << ans << "\n";
	return 0;
}

int fp(int x) {
    if (p[x] == x) return x;
    return p[x] = fp(p[x]);
}

bool united(std::pair<int, int> e) {
    return fp(e.first) == fp(e.second);
}

void unite(std::pair<int, int> e) {
    e.first = fp(e.first);
    e.second = fp(e.second);
    if (e.first != e.second)
        p[e.first] = e.second;
}