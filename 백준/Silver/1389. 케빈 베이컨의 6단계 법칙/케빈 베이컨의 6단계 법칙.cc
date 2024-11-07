#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

vector<int> adj[105];
int main() {
  fastio;
  int n, m;
  cin >> n >> m;

  for (int u, v, i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int cnt = INF, ans = 0;
  for (int i = n; i != 0; --i) {
    queue<int> q;
    q.push(i);
    vector<int> dist(105, -1);
    dist[i] = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto nxt : adj[cur]) {
        if (dist[nxt] != -1) continue;
        q.push(nxt);
        dist[nxt] = dist[cur] + 1;
      }
    }

    int tot = 0;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      tot += dist[j];
    }

    if (cnt >= tot) {
      ans = i;
      cnt = tot;
    }
  }

  cout << ans << "\n";
}