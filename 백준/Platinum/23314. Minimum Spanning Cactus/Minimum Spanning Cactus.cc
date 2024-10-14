#include <algorithm>
#include <iostream>
#include <map>
#include <set>
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
using T = std::tuple<int, int, int>;

const int MX = 100001;
int n, m, q, BN, cnt;
int dfsn[MX], bccNum[MX << 1];
set<T> bcc[MX << 1];
map<int, pair<int, int>> adj[MX];
stack<T> s;

int dfs(int cur, int prev = -1) {
  int res = dfsn[cur] = ++cnt;
  for (auto& [nxt, edge] : adj[cur]) {
    if (nxt == prev) continue;
    if (dfsn[cur] > dfsn[nxt]) s.push({edge.first, cur, nxt});
    if (dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
    else {
      int tmp = dfs(nxt, cur);
      res = min(res, tmp);
      if (tmp >= dfsn[cur]) {
        while (1) {
          auto& [c, u, v](s.top());
          s.pop();
          auto& [_, idx](adj[u][v]);
          bcc[BN].insert({c, min(u, v), max(u, v)});
          bccNum[idx] = BN;
          if (u == cur && v == nxt) break;
        }
        BN++;
      }
    }
  }
  return res;
}

int main() {
  fastio;
  cin >> n >> m >> q;
  ll ans{};
  for (int u, v, c, i{}; i++ < m; ans += c) {
    cin >> u >> v >> c;
    adj[u][v] = adj[v][u] = {c, i};
  }

  dfs(1);

  /*
  사이즈가 2인 BCC는 ans += d - c;
  쿼리당 처리
  기존 간선 가중치 c, 새로운 가중치 d, 변경하고자 하는 간선 e
  1. d > 0인 경우
  1-1. e가 기존의 가장 큰 간선이었다면
    1-1-1. 변경 후 e가 여전히 가장 큰 간선이라면 ans += c > 0 ? 0 : c
    1-1-2. 변경 후 e가 가장 큰 간선이 아니라면 ans += d + (maxC > 0 ? -maxC : 0)

  1-2. e가 기존의 가장 큰 간선이 아니었다면
    1-2-1. 변경 후 e가 가장 큰 간선이라면 ans += preMaxC > 0 ? preMaxC : 0 - c
    1-2-2. 변경 후 e가 가장 큰 간선이 아니라면 ans += d - c

  2. d <= 0인 경우
  2-1. e가 기존의 가장 큰 간선이었다면 ans += c > 0 ? c : 0 + d, ans += maxC > 0 ? -maxC : 0
  2-2. e가 기존의 가장 큰 간선이 아니었다면 ans += d - c
  */
  rep(BN) {
    if (si(bcc[i]) < 3) continue;
    auto& [c, u, v](*--bcc[i].end());
    if (c > 0) ans -= c;
  }

  cout << ans << "\n";

  for (int u, v, d, bn; q--;) {
    cin >> u >> v >> d;
    if (u > v) swap(u, v);
    auto [c, idx](adj[u][v]);
    adj[u][v].X = adj[v][u].X = d;
    bn = bccNum[idx];
    auto preAEdge = *--bcc[bn].end();
    bcc[bn].erase(T(c, u, v));
    bcc[bn].insert(T(d, u, v));
    auto newAEdge = *--bcc[bn].end();
    if (si(bcc[bn]) < 2) {
      ans += d - c;
      cout << ans << "\n";
      continue;
    }
    if (d > 0) {
      auto [a, b, aa] = preAEdge;
      if (preAEdge == T(c, u, v)) {
        if (newAEdge == T(d, u, v)) {
          ans += c > 0 ? 0 : -c;
        } else {
          int maxC = get<0>(newAEdge);
          ans += d + (maxC > 0 ? -maxC : 0);
        }
      } else {
        if (newAEdge == T(d, u, v)) {
          int preMaxC = get<0>(preAEdge);
          ans += (preMaxC > 0 ? preMaxC : 0) - c;
        } else {
          ans += d - c;
        }
      }
    } else {
      if (preAEdge == T(c, u, v)) {
        int maxC = get<0>(newAEdge);
        ans += d + (c > 0 ? 0 : -c);
        ans += (maxC > 0 ? -maxC : 0);
      } else {
        ans += d - c;
      }
    }

    cout << ans << "\n";
  }
}