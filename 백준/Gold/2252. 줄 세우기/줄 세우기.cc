#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[32001];
vector<int> ans;
queue<int> q;
int deg[32001];
int N, M, u, v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  while (M--) {
    cin >> u >> v;
    adj[u].push_back(v);
    deg[v]++;
  }

  for (int i = 1; i <= N; i++) {
    if (deg[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    ans.push_back(cur);
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }

  for (auto n : ans) cout << n << " ";
}