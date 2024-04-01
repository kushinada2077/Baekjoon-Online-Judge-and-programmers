#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[501];
bool vis[501];
int ans = -1;
queue<pair<int, int>> q;
void bfs(pair<int, int> st) {
  q.push(st);
  vis[st.first] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    ans++;
    if (cur.second >= 2) continue;
    for (auto nxt : adj[cur.first]) {
      if (vis[nxt]) continue;
      q.push({nxt, cur.second + 1});
      vis[nxt] = true;
    }
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

  bfs({1, 0});
  cout << ans;
}