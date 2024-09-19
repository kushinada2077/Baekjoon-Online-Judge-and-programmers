#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

const int MX = 505;
int cost[MX], ans[MX], indg[MX];
vector<int> adj[MX];
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int c, v = 0;
    cin >> c;
    cost[i] = c;
    while (1) {
      cin >> v;
      if (v == -1) break;
      adj[v].pb(i);
      indg[i]++;
    }
  }

  queue<int> q;
  vector<int> sorted;

  for (int i = 1; i <= n; ++i) {
    if (!indg[i]) q.push(i);
  }

  for (int i = 1; i <= n; ++i) {
    int cur = q.front();
    q.pop();
    sorted.pb(cur);
    for (auto& nxt : adj[cur]) {
      if (--indg[nxt] == 0) q.push(nxt);
    }
  }

  for (auto& cur : sorted) {
    ans[cur] += cost[cur];
    for (auto& nxt : adj[cur]) ans[nxt] = max(ans[nxt], ans[cur]);
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
}