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

int n, m, p, v, u;
vector<int> adj[100005];
vector<bool> vis(100005);
int main() {
  fastio;
  cin >> n >> m >> p;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    adj[v].pb(u);
  }

  int ans = 0;
  vis[p] = 1;
  while (true) {
    if (si(adj[p]) == 0) break;
    int nxt = adj[p].front();
    if (vis[nxt]) {
      cout << "-1\n";
      return 0;
    }
    vis[nxt] = 1;
    p = nxt;
    ans++;
  }
  cout << ans << "\n";
}