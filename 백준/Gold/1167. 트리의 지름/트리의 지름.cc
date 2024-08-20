#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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

int dist, dest;
vector<bool> vis(100005, 0);
vector<pair<int, int>> adj[1000005];
void dfs(int cur, int d) {
  if (d > dist) {
    dist = d;
    dest = cur;
  }
  for (auto& [c, nxt] : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt, d + c);
  }
}
int main() {
  fastio;
  int v, a, b, c, d;
  cin >> v;
  while (v--) {
    cin >> a;
    while (true) {
      cin >> b;
      if (b == -1) break;
      cin >> c;
      adj[a].pb({c, b});
      adj[b].pb({c, a});
    }
  }
  vis[1] = 1;
  dfs(1, 0);
  dist = 0;
  fill(all(vis), 0);
  vis[dest] = 1;
  dfs(dest, 0);
  cout << dist << "\n";
}