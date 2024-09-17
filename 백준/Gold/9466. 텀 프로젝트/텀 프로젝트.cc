#include <algorithm>
#include <climits>
#include <iostream>
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

int t, n;
vector<int> adj;
vector<bool> vis, finished;
int dfs(int cur) {
  int nxt = adj[cur], ret = 0;
  if (vis[nxt] && !finished[nxt]) {
    int ccur = nxt;
    ret++;
    while (ccur != cur) {
      ret++;
      ccur = adj[ccur];
    }
  }

  if (!vis[nxt]) {
    vis[nxt] = true;
    ret = dfs(nxt);
  }
  finished[cur] = true;
  return ret;
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = n;
    adj = vector<int>(n + 1);
    vis = vector<bool>(n + 1);
    finished = vector<bool>(n + 1);
    for (int i = 1; i <= n; ++i) cin >> adj[i];
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      vis[i] = true;
      ans -= dfs(i);
    }
    cout << ans << "\n";
  }
}