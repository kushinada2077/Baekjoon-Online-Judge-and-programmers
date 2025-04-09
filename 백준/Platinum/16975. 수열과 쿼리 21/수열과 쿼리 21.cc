#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
i64 info[MAX << 1];
void construct() {
  for (int i = MAX - 1; i != 0; --i) {
    info[i] = info[2 * i] + info[2 * i + 1];
  }
}
void update(int p, int x) {
  p += MAX;
  info[p] += x;
  while (p > 1) {
    p /= 2;
    info[p] = info[2 * p] + info[2 * p + 1];
  }
}
i64 rangeQuery(int p, int l, int r, int x, int y) {
  if (r <= x || y <= l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return info[p];
  }
  int m = (l + r) / 2;
  return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    info[MAX + i] += x;
    info[MAX + i + 1] -= x;
  }
  construct();
  std::cin >> M;
  for (int i = 0; i < M; ++i) {
    int q;
    std::cin >> q;
    if (q == 1) {
      int l, r, k;
      std::cin >> l >> r >> k;
      l--;
      update(l, k);
      update(r, -k);
    } else if (q == 2) {
      int x;
      std::cin >> x;
      std::cout << rangeQuery(1, 0, MAX, 0, x) << "\n";
    }
  }
}