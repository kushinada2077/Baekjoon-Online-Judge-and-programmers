#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 20;
i64 seg[MAX << 1];
void init() {
  for (int i = MAX - 1; i != 0; --i) {
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
}
void add(int node, i64 x) {
  node += MAX;
  while (node != 0) {
    seg[node] += x;
    node /= 2;
  }
}
i64 sum(int node, int l, int r, int st, int en) {
  if (r <= st || en <= l) {
    return 0LL;
  }
  if (l <= st && en <= r) {
    return seg[node];
  }
  int mid = (st + en) / 2;
  return sum(2 * node, l, r, st, mid) + sum(2 * node + 1, l, r, mid, en);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M, K;
  std::cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    std::cin >> seg[MAX + i];
  }
  init();
  for (int i = 0; i < M + K; ++i) {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    b--;
    if (a == 1) {
      add(b, c - seg[MAX + b]);
    } else if (a == 2) {
      std::cout << sum(1, b, c, 0, MAX) << "\n";
    }
  }
}