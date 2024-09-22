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

vector<pair<int, int>> adj[101];
int n, m, x, y, z;
int indg[101], ans[101][101];
bool chk[101];
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    adj[y].pb({z, x});
    indg[x]++;
  }

  queue<int> q;
  vector<int> sorted, basic;

  for (int i = 1; i < n; ++i) {
    if (indg[i] == 0) {
      basic.pb(i);
      q.push(i);
      chk[i] = 1;
    }
  }
  sort(all(basic));

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto& [c, nxt] : adj[cur]) {
      if (chk[cur]) ans[nxt][cur] = c;
      else {
        for (auto& base : basic) {
          ans[nxt][base] += ans[cur][base] * c;
        }
      }
      if (--indg[nxt] == 0) {
        q.push(nxt);
      }
    }
    sorted.pb(cur);
  }

  for (auto& st : basic) {
    cout << st << " " << ans[n][st] << "\n";
  }
}