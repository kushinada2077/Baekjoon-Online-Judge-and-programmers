#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
int info[MAX << 1], lazy[MAX << 1];
int pn = 0;
void propagate(int p, int l, int r) {
  if (lazy[p] != 0) {
    if (p < MAX) {
      lazy[2 * p] += lazy[p];
      lazy[2 * p + 1] += lazy[p];
    }
    info[p] += lazy[p] * (r - l);
    lazy[p] = 0;
  }
}
void modify(int p, int l, int r, int x, int y, int k) {
  propagate(p, l, r);
  if (r <= x || y <= l) {
    return;
  }
  if (x <= l && r <= y) {
    lazy[p] += k;
    propagate(p, l, r);
    return;
  }
  int m = (l + r) / 2;
  modify(2 * p, l, m, x, y, k);
  modify(2 * p + 1, m, r, x, y, k);
  info[p] = info[2 * p] + info[2 * p + 1];
}
int rangeQuery(int p, int l, int r, int x, int y) {
  propagate(p, l, r);
  if (r <= x || y <= l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return info[p];
  }
  int m = (l + r) / 2;
  return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
}
void dfs(int p, std::vector<std::vector<int>>& adj, std::vector<std::pair<int, int>>& section) {
  section[p].first = pn++;
  for (auto v : adj[p]) {
    dfs(v, adj, section);
  }
  section[p].second = pn;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  std::vector adj(N, std::vector<int>());
  std::vector<std::pair<int, int>> section(N);
  int x;
  std::cin >> x;
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> x;
    x--;
    adj[x].push_back(i + 1);
  }
  dfs(0, adj, section);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    b--;
    auto [l, r] = section[b];
    if (a == 1) {
      int c;
      std::cin >> c;
      modify(1, 0, MAX, l, r, c);
    } else if (a == 2) {
      std::cout << rangeQuery(1, 0, MAX, l, l + 1) << "\n";
    }
  }
}