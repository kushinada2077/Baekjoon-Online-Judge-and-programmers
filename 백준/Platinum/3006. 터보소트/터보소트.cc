#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 17;
int info[MAX << 1];
void construct() {
  for (int i = MAX - 1; i != 0; --i) {
    info[i] = info[2 * i] + info[2 * i + 1];
  }
}
void update(int node, int x) {
  node += MAX;
  info[node] += x;
  while (node > 1) {
    node /= 2;
    info[node] = info[2 * node] + info[2 * node + 1];
  }
}
int sum(int node, int st, int en, int l, int r) {
  if (en <= l || r <= st) {
    return 0;
  }
  if (l <= st && en <= r) {
    return info[node];
  }
  int mid = (st + en) / 2;
  return sum(2 * node, st, mid, l, r) + sum(2 * node + 1, mid, en, l, r);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> idx(N);
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    idx[x - 1] = i;
    info[MAX + i] = 1;
  }
  construct();
  for (int i = 0; i < N; ++i) {
    int cur = i % 2 == 0 ? i / 2 : N - 1 - i / 2;
    int j = idx[cur];
    int dis = i % 2 == 0 ? sum(1, 0, MAX, 0, j) : sum(1, 0, MAX, j + 1, N);
    update(j, -1);
    std::cout << dis << "\n";
  }
}