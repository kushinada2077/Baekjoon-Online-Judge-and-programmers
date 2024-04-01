#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool vis[101];
int ans = -1;
void dfs(int cur) {
  ans++;
  vis[cur] = true;
  for (auto nxt : adj[cur]) {
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, v1, v2;
  cin >> N >> M;
  while (M--) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  dfs(1);
  cout << ans;
}