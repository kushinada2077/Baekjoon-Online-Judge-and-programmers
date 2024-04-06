#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, u, v, case_num, ans;
vector<int> adj[501];
int p[501];

int bfs(int v) {
  queue<int> q;
  q.push(v);

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto nxt : adj[cur]) {
      if (nxt == p[cur]) continue;
      if (p[nxt]) return 0;
      q.push(nxt);
      p[nxt] = cur;
    }
  }

  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    for (int i = 1; i < n + 1; i++) {
      adj[i].clear();
    }
    fill(p, p + n + 1, 0);
    ans = 0;
    while (m--) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 1; i < n + 1; i++) {
      if (p[i]) continue;
      ans += bfs(i);
    }

    cout << "Case " << ++case_num << ": ";
    if (ans == 0)
      cout << "No trees.\n";
    else if (ans == 1)
      cout << "There is one tree.\n";
    else {
      cout << "A forest of " << ans << " trees.\n";
    }
  }
}