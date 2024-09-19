#include <algorithm>
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

int v, e, a, b, cnt = 1;
vector<int> adj[10005], dfsn(10005);
vector<bool> finished(10005);
vector<vector<int>> ans;
stack<int> S;
int dfs(int cur) {
  dfsn[cur] = cnt++;
  S.push(cur);

  int ret = dfsn[cur];
  for (auto& nxt : adj[cur]) {
    if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
    else if (!finished[nxt]) ret = min(ret, dfsn[nxt]);
  }

  if (ret == dfsn[cur]) {
    vector<int> tmp;
    while (1) {
      int t = S.top();
      S.pop();
      tmp.pb(t);
      finished[t] = 1;
      if (t == cur) break;
    }
    sort(all(tmp));
    ans.pb(tmp);
  }

  return ret;
}
int main() {
  fastio;
  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    cin >> a >> b;
    adj[a].pb(b);
  }

  for (int i = 1; i <= v; ++i) {
    if (dfsn[i]) continue;
    dfs(i);
  }

  sort(all(ans), [&](vector<int>& a, vector<int>& b) -> bool { return a[0] < b[0]; });
  cout << si(ans) << "\n";
  for (auto& a : ans) {
    for (auto& i : a) cout << i << " ";
    cout << "-1\n";
  }
}