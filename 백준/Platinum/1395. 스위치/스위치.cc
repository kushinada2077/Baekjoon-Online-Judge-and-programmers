#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
int info[MAX << 1];
bool lazy[MAX << 1];

void propagate(int p, int l, int r) {
  if (lazy[p] != 0) {
    if (p < MAX) {
      lazy[2 * p] = !lazy[2 * p];
      lazy[2 * p + 1] = !lazy[2 * p + 1];
    }
    info[p] = (r - l) - info[p];
    lazy[p] = false;
  }
}
void modify(int p, int l, int r, int x, int y) {
  propagate(p, l, r);
  if (r <= x || y <= l) {
    return;
  }
  if (x <= l && r <= y) {
    lazy[p] = !lazy[p];
    propagate(p, l, r);
    return;
  }
  int m = (l + r) / 2;
  modify(2 * p, l, m, x, y);
  modify(2 * p + 1, m, r, x, y);
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
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    b--;
    c--;
    if (a == 0) {
      modify(1, 0, MAX, b, c + 1);
    } else if (a == 1) {
      std::cout << rangeQuery(1, 0, MAX, b, c + 1) << "\n";
    }
  }
}