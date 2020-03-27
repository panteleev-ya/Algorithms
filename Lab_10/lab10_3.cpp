#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using std::cin;
using std::cout;

std::vector <ll> p;
ll find(ll x);
bool united(std::pair<ll, ll> e);
void unite(std::pair<ll, ll> e);

int main() {
	freopen("spantree3.in", "r", stdin);
	freopen("spantree3.out", "w", stdout);

	std::ios_base::sync_with_stdio(false);
    ll n, m, a, b, l;
    cin >> n >> m;
    p.resize(n + 1);
    std::vector <std::pair <ll, std::pair <ll, ll>>> edges;
    for (size_t i = 0; i < m; i++) {
        cin >> a >> b >> l;
        edges.push_back({ l, {a, b} });
    }
    ll ans = 0;
    sort(edges.begin(), edges.end());
    for (size_t i = 1; i <= n; i++)
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

ll find(ll x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool united(std::pair<ll, ll> e) {
    return find(e.first) == find(e.second);
}

void unite(std::pair<ll, ll> e) {
    e.first = find(e.first);
    e.second = find(e.second);
    if (e.first != e.second)
        p[e.first] = e.second;
}
