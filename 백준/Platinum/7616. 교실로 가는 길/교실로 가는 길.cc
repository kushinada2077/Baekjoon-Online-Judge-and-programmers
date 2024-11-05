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

const int MX = 5001;

struct Edge {
  int to, f, c;
  Edge *dual;
  Edge(int to, int c) : to(to), f(0), c(c), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int flow) {
    f += flow;
    dual->f -= flow;
  }
};

int inverse(int i) { return (i + 1) / 2; }

int n, k;
vector<Edge *> adj[MX << 1];
string line;
void init() {
  for (int i = 0; i < (MX << 1); ++i) adj[i].clear();
}
int main() {
  fastio;

  for (int tc = 1;; tc++) {
    cin >> k >> n;
    if (k == 0 && n == 0) break;
    init();

    for (int u1, u2, i = 1; i <= n; ++i) {
      u1 = 2 * i - 1, u2 = 2 * i;
      Edge *e1 = new Edge(u2, 1), *e2 = new Edge(u1, 0);
      e1->dual = e2;
      e2->dual = e1;
      adj[u1].pb(e1);
      adj[u2].pb(e2);
    }

    cin.ignore();

    for (int v, i = 1, u = 1; i <= n; ++i, u = 2 * i - 1) {
      getline(cin, line);
      istringstream iss(line);
      while (iss >> v) {
        v = 2 * v - 1;
        Edge *e1 = new Edge(v, 1), *e2 = new Edge(u + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u + 1].pb(e1);
        adj[v].pb(e2);
        e1 = new Edge(u, 1), e2 = new Edge(v + 1, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[v + 1].pb(e1);
        adj[u].pb(e2);
      }
    }

    int s = 2, t = 3, cnt{};
    vector<vector<int>> ans;
    while (1) {
      queue<int> q;
      vector<int> prev(MX, -1), tmp;
      Edge *path[MX];
      q.push(s);
      prev[s] = 0;

      while (!q.empty() && prev[t] == -1) {
        int cur = q.front();
        q.pop();
        for (auto &edge : adj[cur]) {
          int nxt = edge->to;
          if (prev[nxt] == -1 && edge->spare()) {
            q.push(nxt);
            prev[nxt] = cur;
            path[nxt] = edge;
            if (nxt == t) break;
          }
        }
      }

      if (prev[t] == -1) break;

      cnt++;
      for (int i = t; i != s; i = prev[i]) path[i]->addFlow(1);
    }

    cout << "Case " << tc << ":\n";
    if (cnt >= k) {
      for (int i = 0; i < k; ++i) {
        int cur = 2;
        cout << "1 ";
        while (cur != 3) {
          if (cur % 2) cout << inverse(cur) << " ";
          for (auto &e : adj[cur]) {
            int nxt = e->to;
            if (e->f == 1) {
              e->addFlow(-1);
              cur = nxt;
              break;
            }
          }
        }

        cout << "2\n";
      }
    } else {
      cout << "Impossible\n";
    }
    cout << "\n";
  }
}