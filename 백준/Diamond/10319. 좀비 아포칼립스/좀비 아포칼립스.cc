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

const int MX = 2e5 + 100, S = 200002, T = 200003, division = 101;

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

int tc, n, m, st, g, timeLimit, r;
vector<Edge *> adj[MX];
void init() {
  for (int i = 0; i < MX; ++i) adj[i].clear();
}

int main() {
  fastio;
  cin >> tc;
  while (tc--) {
    init();
    int ans = 0;
    cin >> n >> st >> g >> timeLimit >> m;
    st = (st - 1) * division;
    Edge *e1 = new Edge(st, g), *e2 = new Edge(S, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[S].pb(e1);
    adj[st].pb(e2);

    for (int u = 0; u < n; ++u) {
      int uu = u * division;
      for (int i = 0; i < timeLimit; ++i) {
        Edge *e1 = new Edge(uu + i + 1, INF), *e2 = new Edge(uu + i, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[uu + i].pb(e1);
        adj[uu + 1 + i].pb(e2);
      }
    }

    for (int u, i = 0; i < m; ++i) {
      cin >> u;
      u = (u - 1) * division;
      for (int j = 0; j <= timeLimit; ++j) {
        Edge *e1 = new Edge(T, INF), *e2 = new Edge(u + j, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u + j].pb(e1);
        adj[T].pb(e2);
      }
    }

    cin >> r;
    for (int u, v, w, t, i{}; i < r; ++i) {
      cin >> u >> v >> w >> t;
      u = (u - 1) * division;
      v = (v - 1) * division;
      for (int j = 0; j + t <= timeLimit; ++j) {
        Edge *e1 = new Edge(v + j + t, w), *e2 = new Edge(u + j, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u + j].pb(e1);
        adj[v + j + t].pb(e2);
      }
    }

    while (1) {
      queue<int> q;
      vector<int> prev(MX, -1);
      vector<Edge *> path(MX);
      q.push(S);

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
}