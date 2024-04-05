#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, v, u;
int p[100001];
vector<int> adj[100001];

void dfs(int cur) {
  for (auto nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  int M = N - 1;
  while (M--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  for (int i = 2; i < N + 1; i++) {
    cout << p[i] << "\n";
  }
}