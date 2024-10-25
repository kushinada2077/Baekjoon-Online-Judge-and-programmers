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

const int MX = 100;
struct Edge {
  int to, c, f;
  Edge *dual;
  Edge(int to, int c) : to(to), c(c), f(0), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int f1) {
    f += f1;
    dual->f -= f1;
  }
};
inline int CtoI(int c) {
  if (c <= 'Z') return c - 'A';
  return c - 'a' + 26;
}
int n;
char u, v;
vector<Edge *> adj[MX];
int main() {
  fastio;
  cin >> n;
  for (int f, i{}; i < n; ++i) {
    cin >> u >> v >> f;
    u = CtoI(u);
    v = CtoI(v);
    Edge *e1 = new Edge(v, f), *e2 = new Edge(u, f);
    e1->dual = e2;
    e2->dual = e1;
    adj[u].pb(e1);
    adj[v].pb(e2);
  }

  int ans = 0, s = CtoI('A'), t = CtoI('Z');
  while (1) {
    vector<int> prev(MX, -1);
    Edge *path[MX]{};
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
          if (nxt == t) break;
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