#include <bits/stdc++.h>
using i64 = long long;

const int MX = 1 << 20;
int info[MX << 1];
void update(int node, int x) {
  node += MX;
  info[node] = std::max(info[node], x);
  while (node > 0) {
    node /= 2;
    info[node] = std::max(info[2 * node], info[2 * node + 1]);
  }
}
int max(int node, int st, int en, int l, int r) {
  if (r <= st || en <= l) {
    return -1;
  }
  if (l <= st && en <= r) {
    return info[node];
  }
  int mid = (st + en) / 2;
  return std::max(max(2 * node, st, mid, l, r), max(2 * node + 1, mid, en, l, r));
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> A(N);
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    A[i] = {x, -i};
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; ++i) {
    int j = -A[i].second;
    int len = max(1, 0, MX, 0, j + 1);
    update(j, len + 1);
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = std::max(ans, info[MX + i]);
  }
  std::cout << ans << "\n";
}