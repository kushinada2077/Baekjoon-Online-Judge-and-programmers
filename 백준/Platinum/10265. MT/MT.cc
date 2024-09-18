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

int n, k, c_num = 1, dp[1005][1005];
vector<int> adj(1005), cycle_num(1005), mn_sz(1005), mx_sz(1005);
vector<bool> vis(1005), finished(1005);
void cycle_dfs(int cur) {
  int nxt = adj[cur];
  if (vis[nxt] && !finished[nxt]) {
    int curr = nxt, cnt = 1;
    cycle_num[curr] = c_num;
    while (curr != cur) {
      curr = adj[curr];
      cycle_num[curr] = c_num;
      cnt++;
    }
    mn_sz[c_num++] = cnt;
  } else if (!vis[nxt]) {
    vis[nxt] = 1;
    cycle_dfs(nxt);
  }
  finished[cur] = 1;
}
int dfs(int cur) {
  int nxt = adj[cur], c_num = 0;
  if (cycle_num[nxt]) {
    mx_sz[cycle_num[nxt]]++;
    cycle_num[cur] = cycle_num[nxt];
    return cycle_num[nxt];
  }
  if (!vis[nxt]) {
    vis[nxt] = 1;
    c_num = dfs(nxt);
  }
  cycle_num[cur] = c_num;
  mx_sz[c_num]++;
  return c_num;
}
int main() {
  fastio;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> adj[i];
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vis[i] = 1;
    cycle_dfs(i);
  }
  for (int i = 1; i < c_num; ++i) mx_sz[i] = mn_sz[i];
  fill(all(vis), 0);
  for (int i = 1; i <= n; ++i) {
    if (vis[i] || cycle_num[i]) continue;
    vis[i] = 1;
    dfs(i);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = dp[i - 1][j];
      for (int k = mn_sz[i]; k <= mx_sz[i]; ++k) {
        if (j - k >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + k);
      }
    }
  }

  cout << dp[n][k] << "\n";
}