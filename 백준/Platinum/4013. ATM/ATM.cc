#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 500000;
int N, M, S, P;
std::vector adj(MAX, std::vector<int>());
int cash[MAX], dfsn[MAX], cashSCC[MAX], cashAcc[MAX], SCC[MAX], indg[MAX];
bool restaur[MAX], restaurSCC[MAX], finished[MAX];
int cnt, SN;
std::stack<int> ST;
int dfs(int u) {
  dfsn[u] = ++cnt;
  ST.push(u);
  int result = dfsn[u];
  for (auto v : adj[u]) {
    if (dfsn[v] == 0) {
      result = std::min(result, dfs(v));
    } else if (finished[v] == 0) {
      result = std::min(result, dfsn[v]);
    }
  }

  if (result == dfsn[u]) {
    while (true) {
      int t = ST.top();
      ST.pop();
      cashSCC[SN] += cash[t];
      finished[t] = true;
      SCC[t] = SN;
      if (restaur[t] == true && restaurSCC[SN] == false) {
        restaurSCC[SN] = true;
      }
      if (t == u) {
        break;
      }
    }
    SN++;
  }
  return result;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> cash[i];
  }
  std::cin >> S >> P;
  S--;
  for (int i = 0; i < P; ++i) {
    int x;
    std::cin >> x;
    restaur[x - 1] = true;
  }

  for (int i = 0; i < N; ++i) {
    if (dfsn[i] == 0) {
      dfs(i);
    }
  }

  std::vector sAdj(MAX, std::vector<int>());
  bool isPoss[MAX];
  for (int u = 0; u < N; ++u) {
    for (int v : adj[u]) {
      if (SCC[u] != SCC[v]) {
        sAdj[SCC[u]].push_back(SCC[v]);
        indg[SCC[v]]++;
      }
    }
  }

  std::queue<int> Q;
  for (int i = 0; i < SN; ++i) {
    cashAcc[i] = cashSCC[i];
    if (SCC[S] == i) {
      isPoss[i] = true;
    }
    if (indg[i] == 0) {
      Q.push(i);
    }
  }

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : sAdj[u]) {
      if (isPoss[u]) {
        isPoss[v] = true;
        cashAcc[v] = std::max(cashAcc[v], cashAcc[u] + cashSCC[v]);
      }
      if (--indg[v] == 0) {
        Q.push(v);
      }
    }
  }

  int ans = -1;
  for (int i = 0; i < SN; ++i) {
    if (restaurSCC[i] == true && isPoss[i] == true) {
      ans = std::max(ans, cashAcc[i]);
    }
  }
  std::cout << ans << "\n";
}