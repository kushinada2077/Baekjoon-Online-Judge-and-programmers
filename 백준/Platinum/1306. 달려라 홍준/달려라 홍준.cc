#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 20;
int info[MAX << 1];
int rangeQuery(int p, int l, int r, int x, int y) {
  if (r <= x || y <= l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return info[p];
  }
  int m = (l + r) / 2;
  return std::max(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    std::cin >> info[MAX + i];
  }
  for (int i = MAX - 1; i != 0; --i) {
    info[i] = std::max(info[2 * i], info[2 * i + 1]);
  }
  for (int i = M - 1; i < N - M + 1; ++i) {
    std::cout << rangeQuery(1, 0, MAX, i - M + 1, i + M) << " \n"[i == N - M];
  }
}