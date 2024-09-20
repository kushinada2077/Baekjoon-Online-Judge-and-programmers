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

const int MX = 1005;
vector<int> adj[MX];
int indg[MX], order[MX], cnt[MX], mx_val[MX];
int t, k, m, p, a, b;
void init() {
  cin >> k >> m >> p;
  fill(indg, indg + m + 1, 0);
  fill(cnt, cnt + m + 1, 0);
  fill(mx_val, mx_val + m + 1, 0);
  for (int i = 1; i <= m; ++i) adj[i].clear();
  for (int i = 0; i < p; ++i) {
    cin >> a >> b;
    adj[a].pb(b);
    indg[b]++;
  }
}
int main() {
  fastio;
  cin >> t;

  while (t--) {
    init();
    queue<int> q;
    for (int i = 1; i <= m; ++i) {
      if (indg[i] == 0) {
        q.push(i);
        order[i] = 1;
      }
    }

    int ans = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto& nxt : adj[cur]) {
        indg[nxt]--;
        if (mx_val[nxt] < order[cur]) {
          mx_val[nxt] = order[cur];
          cnt[nxt] = 1;
        } else if (mx_val[nxt] == order[cur]) cnt[nxt]++;
        if (indg[nxt] == 0) {
          if (cnt[nxt] > 1) order[nxt] = mx_val[nxt] + 1;
          else order[nxt] = mx_val[nxt];
          q.push(nxt);
        }
      }
      ans = max(ans, order[cur]);
    }
    cout << k << " " << ans << "\n";
  }
}