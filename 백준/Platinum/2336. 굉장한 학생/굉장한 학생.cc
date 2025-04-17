#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 19;
constexpr int INF = 0x3f3f3f3f;
int info[MAX << 1];
void pull(int node) {
  info[node] = std::min(info[2 * node], info[2 * node + 1]);
}
void update(int node, int x) {
  node += MAX;
  info[node] = x;
  while (node > 1) {
    node /= 2;
    pull(node);
  }
}
int rangeQuery(int node, int l, int r, int x, int y) {
  if (r <= x || y <= l) {
    return INF;
  }
  if (x <= l && r <= y) {
    return info[node];
  }
  int m = (l + r) / 2;
  return std::min(rangeQuery(2 * node, l, m, x, y), rangeQuery(2 * node + 1, m, r, x, y));
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (int i = 1; i < (MAX << 1); ++i) {
    info[i] = INF;
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    A[i]--;
  }
  std::vector<std::pair<int, int>> B(N);
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    x--;
    B[x].first = i;
  }
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    x--;
    B[x].second = i;
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int f = A[i];
    auto [s, t] = B[f];
    int m = rangeQuery(1, 0, MAX, 0, s + 1);
    if (m > t) {
      ans++;
    }
    update(s, t);
  }
  std::cout << ans << "\n";
}