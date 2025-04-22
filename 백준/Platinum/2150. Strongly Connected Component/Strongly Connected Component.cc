#include <bits/stdc++.h>
using i64 = long long;

constexpr int MAX = 10000;
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
std::vector<int> adj[MAX];
bool finished[MAX];
std::vector<std::vector<int>> SCC;
std::stack<int> S;
int dfs(int curr) {
  dfsn[curr] = ++cnt;
  S.push(curr);

  int result = dfsn[curr];
  for (int next : adj[curr]) {
    if (dfsn[next] == 0) {
      result = std::min(result, dfs(next));
    } else if (finished[next] == 0) {
      result = std::min(result, dfsn[next]);
    }
  }

  if (result == dfsn[curr]) {
    std::vector<int> currSCC;
    while (true) {
      int t = S.top();
      S.pop();
      currSCC.push_back(t);
      finished[t] = true;
      sn[t] = SN;
      if (t == curr) {
        break;
      }
    }
    sort(currSCC.begin(), currSCC.end());
    SCC.push_back(currSCC);
    SN++;
  }
  return result;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }
  for (int i = 0; i < V; ++i) {
    if (dfsn[i] == 0) {
      dfs(i);
    }
  }
  sort(SCC.begin(), SCC.end());
  std::cout << SCC.size() << "\n";
  for (auto scc : SCC) {
    for (auto i : scc) {
      std::cout << i + 1 << " ";
    }
    std::cout << "-1 \n";
  }
}