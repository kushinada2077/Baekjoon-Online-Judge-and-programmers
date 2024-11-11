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

const int MX_COL = 31, MX = 3100, T = 3000;
struct Edge {
  int to, c, f;
  Edge *dual;
  Edge(int to, int c) : to(to), c(c), f(0), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int flow) {
    f += flow;
    dual->f -= flow;
  }
};

int n, m, c, S, cost[26];
string board[MX_COL];
vector<Edge *> adj[MX];
inline int compress(int y, int x) { return y * MX_COL + x; }
int main() {
  fastio;
  cin >> m >> n >> c;
  for (int i = 0; i < n; ++i) cin >> board[i];
  for (int i = 0; i < c; ++i) cin >> cost[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int u = 2 * compress(i, j), cc = board[i][j] == '.' || board[i][j] == 'B' ? INF : cost[board[i][j] - 'a'];
      Edge *e1 = new Edge(u + 1, cc), *e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u].pb(e1);
      adj[u + 1].pb(e2);
      if (board[i][j] == 'B') S = 2 * compress(i, j);
      for (int dir = 0; dir < 4; ++dir) {
        int ny = i + "2101"[dir] - '1', nx = j + "1210"[dir] - '1';
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        int v = 2 * compress(ny, nx);
        e1 = new Edge(v, INF);
        e2 = new Edge(u + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u + 1].pb(e1);
        adj[v].pb(e2);
        e1 = new Edge(u, INF);
        e2 = new Edge(v + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[v + 1].pb(e1);
        adj[u].pb(e2);
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    int u = 2 * compress(0, j);
    Edge *e1 = new Edge(T, INF), *e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u + 1].pb(e1);
    adj[T].pb(e2);
    u = 2 * compress(n - 1, j);
    e1 = new Edge(T, INF);
    e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u + 1].pb(e1);
    adj[T].pb(e2);
  }

  for (int i = 1; i < n - 1; ++i) {
    int u = 2 * compress(i, 0);
    Edge *e1 = new Edge(T, INF), *e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u + 1].pb(e1);
    adj[T].pb(e2);
    u = 2 * compress(i, m - 1);
    e1 = new Edge(T, INF);
    e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u + 1].pb(e1);
    adj[T].pb(e2);
  }
  int ans = 0;

  while (1) {
    queue<int> q;
    vector<int> prev(MX, -1);
    vector<Edge *> path(MX);
    q.push(S);
    prev[S] = -2;

    while (!q.empty() && prev[T] == -1) {
      int cur = q.front();
      // cout << cur / 2 / MX_COL << " " << cur / 2 % MX_COL << "\n";
      q.pop();
      for (auto &e : adj[cur]) {
        int nxt = e->to;
        if (e->spare() && prev[nxt] == -1) {
          q.push(nxt);
          prev[nxt] = cur;
          path[nxt] = e;
          if (nxt == T) break;
        }
      }
    }

    if (prev[T] == -1) break;
    int flow = INF;
    for (int i = T; i != S; i = prev[i]) flow = min(flow, path[i]->spare());
    for (int i = T; i != S; i = prev[i]) path[i]->addFlow(flow);
    ans += flow;
  }

  if (ans == INF) cout << "-1\n";
  else cout << ans << "\n";
}