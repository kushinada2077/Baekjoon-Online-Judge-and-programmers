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
using T = tuple<int, int, int>;
using P = pair<int, int>;

const int MX_ROW = 50, MX = 3000, s = 2800, t = 2900;

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

int tc, n, m, board[MX_ROW][MX_ROW];
vector<Edge *> adj[MX];

inline int cmp(int y, int x) { return y * MX_ROW + x; }

int main() {
  fastio;
  cin >> tc;

  while (tc--) {
    int S = 0;
    for (int i = 0; i < MX; ++i) adj[i].clear();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int compressed = cmp(i, j);
        cin >> board[i][j];
        S += board[i][j];

        if ((i + j) % 2 == 0) {
          Edge *e1 = new Edge(compressed, board[i][j]), *e2 = new Edge(s, 0);
          e1->dual = e2;
          e2->dual = e1;
          adj[s].pb(e1);
          adj[compressed].pb(e2);

          for (int dir = 0; dir < 4; ++dir) {
            int ny = i + "2101"[dir] - '1', nx = j + "1210"[dir] - '1';
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            int nCompressed = cmp(ny, nx);
            e1 = new Edge(nCompressed, INF);
            e2 = new Edge(compressed, 0);
            e1->dual = e2;
            e2->dual = e1;
            adj[compressed].pb(e1);
            adj[nCompressed].pb(e2);
          }
        } else {
          Edge *e1 = new Edge(t, board[i][j]), *e2 = new Edge(compressed, 0);
          e1->dual = e2;
          e2->dual = e1;
          adj[compressed].pb(e1);
          adj[t].pb(e2);
        }
      }
    }

    int F = 0;
    while (1) {
      queue<int> q;
      vector<int> prev(MX, -1);
      vector<Edge *> path(MX);
      q.push(s);

      while (!q.empty() && prev[t] == -1) {
        int cur = q.front();
        q.pop();
        for (auto &e : adj[cur]) {
          int nxt = e->to;
          if (e->spare() && prev[nxt] == -1) {
            q.push(nxt);
            prev[nxt] = cur;
            path[nxt] = e;
            if (nxt == t) break;
          }
        }
      }

      if (prev[t] == -1) break;
      int flow = INF;
      for (int i = t; i != s; i = prev[i]) flow = min(flow, path[i]->spare());
      for (int i = t; i != s; i = prev[i]) path[i]->addFlow(flow);
      F += flow;
    }

    cout << S - F << "\n";
  }
}