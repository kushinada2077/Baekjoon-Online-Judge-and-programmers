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

const int MX_COL = 301, MX = 200001, T = 200000;
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

int n, m, c, S, sx, sy, board[MX_COL][MX_COL];
vector<Edge *> adj[MX];
inline int compress(int y, int x) { return y * MX_COL + x; }
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> board[i][j];
  }
  cin >> sy >> sx;
  S = 2 * compress(sy, sx);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 0) continue;
      int u = 2 * compress(i, j), cc = board[i][j];
      Edge *e1 = new Edge(u + 1, cc), *e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u].pb(e1);
      adj[u + 1].pb(e2);
      for (int dir = 0; dir < 4; ++dir) {
        int ny = i + "2101"[dir] - '1', nx = j + "1210"[dir] - '1';
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] == 0) continue;
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

  for (int u, j = 0; j < m; ++j) {
    Edge *e1, *e2;
    if (board[0][j]) {
      u = 2 * compress(0, j);
      e1 = new Edge(T, INF);
      e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u + 1].pb(e1);
      adj[T].pb(e2);
    }
    if (board[n - 1][j]) {
      u = 2 * compress(n - 1, j);
      e1 = new Edge(T, INF);
      e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u + 1].pb(e1);
      adj[T].pb(e2);
    }
  }

  for (int u, i = 1; i < n - 1; ++i) {
    Edge *e1, *e2;
    if (board[i][0]) {
      u = 2 * compress(i, 0);
      e1 = new Edge(T, INF);
      e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u + 1].pb(e1);
      adj[T].pb(e2);
    }
    if (board[i][m - 1]) {
      u = 2 * compress(i, m - 1);
      e1 = new Edge(T, INF);
      e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u + 1].pb(e1);
      adj[T].pb(e2);
    }
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

  cout << ans << "\n";
}