#include <algorithm>
#include <iostream>
#include <stack>
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

const int MX = 200001;
int n, SN, cnt;
int dfsn[MX << 2], sn[MX << 2], cost[MX << 1];
vector<int> adj[MX << 2], suspect[MX << 2];
stack<int> s;

void init() {
  cnt = 0;
  SN = 1;
  for (int i = 0; i < 4 * n; ++i) dfsn[i] = sn[i] = 0;
}
int dfs(int cur) {
  int res = dfsn[cur] = ++cnt;
  s.push(cur);

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (sn[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (res == dfsn[cur]) {
    while (1) {
      int v = s.top();
      s.pop();
      sn[v] = SN;
      if (cur == v) break;
    }
    SN++;
  }
  return res;
}

int main() {
  fastio;
  cin >> n;
  for (int a, ka, b, i{}; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> a >> ka;
      suspect[a - 1].pb(2 * i + j);
      cost[2 * i + j] = ka;
    }

    a = 2 * i;
    b = 2 * i + 1;
    adj[2 * a].pb(2 * b + 1);
    adj[2 * b].pb(2 * a + 1);
  }

  for (int i = 0; i < 2 * n; ++i) {
    if (si(suspect[i]) != 2) continue;
    int a = suspect[i][0], b = suspect[i][1];
    adj[2 * a + 1].pb(2 * b);
    adj[2 * b + 1].pb(2 * a);
  }

  int lo = -1, hi = 1000001;

  while (lo + 1 < hi) {
    init();
    int mid = (lo + hi) / 2;
    vector<int> tmp;
    tmp.clear();

    bool ff = 0;
    for (int i = 0; i < n; ++i) {
      int cntt = 0;
      for (int j = 0; j < 2; ++j) {
        int x = 2 * i + j;
        if (cost[x] > mid) {
          adj[2 * x + 1].pb(2 * x);
          tmp.pb(2 * x + 1);
          cntt++;
        }
      }

      if (cntt == 2) {
        ff = 1;
        break;
      }
    }

    if (ff) {
      for (auto i : tmp) adj[i].pop_back();
      lo = mid;
      continue;
    }

    for (int i = 0; i < 4 * n; ++i) {
      if (dfsn[i] == 0) dfs(i);
    }

    bool f = 1;
    for (int i = 0; i < 2 * n; ++i) {
      if (sn[2 * i] == sn[2 * i + 1]) {
        f = 0;
        break;
      }
    }

    if (f) hi = mid;
    else lo = mid;

    if (lo + 1 == hi) break;
    for (auto i : tmp) {
      adj[i].pop_back();
    }
  }

  if (lo == 1000000) cout << "-1\n";
  else cout << hi << "\n";
}