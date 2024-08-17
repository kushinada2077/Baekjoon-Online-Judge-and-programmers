#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, m, r, cnt = 1;
ll ans;
set<int> adj[100005];
vector<bool> vis(100005);
void f(int d, int cur) {
  ans += 1ll * d * (cnt++);
  for (auto& nxt : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    f(d + 1, nxt);
  }
}
int main() {
  fastio;
  cin >> n >> m >> r;
  int u, v;

  while (m--) {
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  vis[r] = true;
  f(0, r);
  cout << ans << "\n";
}