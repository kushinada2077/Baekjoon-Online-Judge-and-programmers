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

const int MX_COL = 101, MX = MX_COL * MX_COL * 4;

struct Edge {
  int to, c, f;
  Edge* dual;
  Edge(int to, int c) : to(to), c(c), f(0), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int flow) {
    f += flow;
    dual->f -= flow;
  }
};
int n, m, S, T;
string board[MX_COL];
vector<Edge*> adj[MX];
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'K') S = 2 * (i * MX_COL + j) + 1;
      if (board[i][j] == 'H') T = 2 * (i * MX_COL + j);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == '#') continue;
      int u = 2 * (MX_COL * i + j);
      Edge *e1 = new Edge(u + 1, 1), *e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u].pb(e1);
      adj[u + 1].pb(e2);
      for (int dir = 0; dir < 4; ++dir) {
        int ny = i + "2101"[dir] - '1', nx = j + "1210"[dir] - '1';
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[i][j] == 'K' && board[ny][nx] == 'H') {
          cout << "-1\n";
          return 0;
        }
        if (board[ny][nx] == '#') continue;
        int v = 2 * (MX_COL * ny + nx);
        e1 = new Edge(v, 1);
        e2 = new Edge(u + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u + 1].pb(e1);
        adj[v].pb(e2);
      }
    }
  }

  int ans = 0;

  while (1) {
    queue<int> q;
    vector<int> prev(MX, -1);
    vector<Edge*> path(MX);
    q.push(S);

    while (!q.empty() && prev[T] == -1) {
      int cur = q.front();
      q.pop();
      for (auto& e : adj[cur]) {
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
    for (int i = T; i != S; i = prev[i]) path[i]->addFlow(1);
    ans++;
  }

  cout << ans << "\n";
}