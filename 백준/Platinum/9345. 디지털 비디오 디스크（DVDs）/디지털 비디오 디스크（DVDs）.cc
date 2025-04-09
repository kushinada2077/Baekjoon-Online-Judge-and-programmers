#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
constexpr int INF = 0x3f3f3f3f;
int info[MAX << 1][2];
void construct() {
  for (int i = MAX - 1; i != 0; --i) {
    info[i][0] = std::max(info[2 * i][0], info[2 * i + 1][0]);
    info[i][1] = std::min(info[2 * i][1], info[2 * i + 1][1]);
  }
}
void update(int node, int x) {
  node += MAX;
  info[node][0] = x;
  info[node][1] = x;
  while (node > 1) {
    node /= 2;
    info[node][0] = std::max(info[2 * node][0], info[2 * node + 1][0]);
    info[node][1] = std::min(info[2 * node][1], info[2 * node + 1][1]);
  }
}
std::pair<int, int> rangeQuery(int node, int st, int en, int l, int r) {
  if (r <= st || en <= l) {
    return {0, INF};
  }
  if (l <= st && en <= r) {
    return {info[node][0], info[node][1]};
  }
  int mid = (st + en) / 2;
  auto [l1, l2] = rangeQuery(2 * node, st, mid, l, r);
  auto [r1, r2] = rangeQuery(2 * node + 1, mid, en, l, r);
  return {std::max(l1, r1), std::min(l2, r2)};
}
void solve() {
  int N, K;
  std::cin >> N >> K;
  for (int i = 0; i < MAX; ++i) {
    info[MAX + i][0] = info[MAX + i][1] = i;
  }
  construct();
  for (int i = 0; i < K; ++i) {
    int q, a, b;
    std::cin >> q >> a >> b;
    if (q == 0) {
      int tmp = info[a + MAX][0];
      update(a, info[b + MAX][0]);
      update(b, tmp);
    } else if (q == 1) {
      auto [max, min] = rangeQuery(1, 0, MAX, a, b + 1);
      if (min == a && max == b) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}