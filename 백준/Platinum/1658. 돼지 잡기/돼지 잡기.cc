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

const int MX = 200000, MX_ROW = 100, S = 199998, T = 199999;
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

int n, m;
vector<Edge *> adj[MX];
int main() {
  fastio;
  cin >> m >> n;
  for (int c, i = 0; i < m; ++i) {
    cin >> c;
    int cur = MX_ROW * i;
    Edge *e1 = new Edge(cur, c), *e2 = new Edge(S, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[S].pb(e1);
    adj[cur].pb(e2);

    for (int j = 0; j < n - 1; ++j) {
      e1 = new Edge(cur + 1, INF);
      e2 = new Edge(cur, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[cur].pb(e1);
      adj[cur + 1].pb(e2);
      cur++;
    }
  }

  for (int b, u, v, x, i = 0; i < n; ++i) {
    cin >> x;
    u = i + 150000;
    vector<int> tmp;
    for (int j = 0; j < x; ++j) {
      cin >> v;
      tmp.pb(MX_ROW * (v - 1));
      v = MX_ROW * (v - 1) + i;
      Edge *e1 = new Edge(u, INF), *e2 = new Edge(v, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[v].pb(e1);
      adj[u].pb(e2);
    }
    cin >> b;
    Edge *e1 = new Edge(T, b), *e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u].pb(e1);
    adj[T].pb(e2);

    if (i == n - 1) continue;
    for (auto u : tmp) {
      int uu = u + i;
      for (auto v : tmp) {
        if (u == v) continue;
        int vv = v + i + 1;
        Edge *e1 = new Edge(vv, INF), *e2 = new Edge(uu, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[uu].pb(e1);
        adj[vv].pb(e2);
      }
    }
  }

  int ans = 0;
  while (1) {
    queue<int> q;
    vector<int> prev(MX, -1);
    Edge *path[MX];
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