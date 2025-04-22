#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int N, M;
  std::cin >> N >> M;
  std::vector adj(N, std::vector<int>());
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }

  int cnt = 0, SN = 0;
  std::vector<int> dfsn(N), sn(N);
  std::vector<bool> finished(N);
  std::vector<std::vector<int>> SCC;
  std::stack<int> S;
  std::function<int(int)> dfs = [&](int curr) {
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
      SCC.push_back(currSCC);
      SN++;
    }
    return result;
  };
  for (int i = 0; i < N; ++i) {
    if (dfsn[i] == 0) {
      dfs(i);
    }
  }
  std::vector<int> indg(SN);
  for (int u = 0; u < N; ++u) {
    for (int v : adj[u]) {
      if (sn[u] != sn[v]) {
        indg[sn[v]]++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < SN; ++i) {
    if (indg[i] == 0) {
      ans++;
    }
  }
  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}