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

const int MX = 301, S = 299, T = 300;

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

int TC, n, needed, army[MX];
vector<Edge *> adj[MX];
void init() {
  for (int i = 0; i < MX; ++i) adj[i].clear();
  needed = 0;
}

int main() {
  fastio;
  cin >> TC;

  while (TC--) {
    init();
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> army[i];
    string s;
    set<int> adjLand;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (army[i] == 0) continue;
      for (int j = 0; j < n; ++j) {
        if (s[j] == 'Y' && army[j] == 0) adjLand.insert(i);
        if ((i == j || s[j] == 'Y') && army[j]) {
          Edge *e1 = new Edge(2 * j + 1, INF), *e2 = new Edge(2 * i, 0);
          e1->dual = e2;
          e2->dual = e1;
          adj[2 * i].pb(e1);
          adj[2 * j + 1].pb(e2);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (army[i] == 0) continue;
      Edge *e1 = new Edge(2 * i, army[i]), *e2 = new Edge(S, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[S].pb(e1);
      adj[2 * i].pb(e2);
    }

    for (int i = 0; i < n; ++i) {
      if (army[i] == 0 || adjLand.contains(i)) continue;
      Edge *e1 = new Edge(T, 1), *e2 = new Edge(2 * i + 1, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[2 * i + 1].pb(e1);
      adj[T].pb(e2);
      needed++;
    }

    int lo = 0, hi = 50000;

    while (lo + 1 < hi) {
      for (int i = 0; i < MX; ++i) {
        for (auto &e : adj[i]) e->f = 0;
      }
      int mid = (lo + hi) / 2, tot = 0;
      needed += mid * si(adjLand);

      for (auto i : adjLand) {
        int v = 2 * i + 1;
        Edge *e1 = new Edge(T, mid), *e2 = new Edge(v, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[v].pb(e1);
        adj[T].pb(e2);
      }

      while (1) {
        queue<int> q;
        q.push(S);
        vector<int> prev(MX, -1);
        vector<Edge *> path(MX);

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
        tot += flow;
      }

      for (auto i : adjLand) {
        int v = 2 * i + 1;
        adj[v].pop_back();
        adj[T].pop_back();
      }

      if (needed > tot) hi = mid;
      else lo = mid;
      needed -= mid * si(adjLand);
    }

    cout << lo << "\n";
  }
}