#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> e[1001];
queue<int> q;
int vis[1001];

void dfs(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  for (auto i : e[v]) {
    dfs(i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, x1, x2, ans = 0;
  cin >> n >> m;
  fill(vis, vis + n + 1, 0);
  while (m--) {
    cin >> x1 >> x2;
    e[x1].push_back(x2);
    e[x2].push_back(x1);
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    else {
      ans++;
      dfs(i);
    }
  }

  cout << ans;
}