#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
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

const int MX = 501;
const int s = 0;
const int t = 500;
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
  cin >> n >> m;
  for (int x, v, u = 1; u <= n; ++u) {
    Edge *e1 = new Edge(u, 1), *e2 = new Edge(s, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[0].pb(e1);
    adj[u].pb(e2);
    cin >> x;
    for (int j = 0; j < x; ++j) {
      cin >> v;
      v += 200;
      Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u].pb(e1);
      adj[v].pb(e2);
    }
  }

  for (int i = 1; i <= m; ++i) {
    Edge *e1 = new Edge(t, 1), *e2 = new Edge(i + 200, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[i + 200].pb(e1);
    adj[t].pb(e2);
  }

  int ans = 0;
  while (1) {
    vector<int> prev(MX, -1);
    Edge *path[MX];
    queue<int> q;
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
          if (prev[t] != -1) break;
        }
      }
    }

    if (prev[t] == -1) break;

    int flow = INF;
    for (int i = t; i != s; i = prev[i]) flow = min(flow, path[i]->spare());
    for (int i = t; i != s; i = prev[i]) path[i]->addFlow(flow);
    ans += flow;
  }

  cout << ans << "\n";
}