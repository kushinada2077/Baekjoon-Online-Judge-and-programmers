#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 18;
int info[MAX << 1];
void modify(int p, int x) {
  p += MAX;
  info[p] = x;
  while (p > 1) {
    p /= 2;
    info[p] = info[2 * p] + info[2 * p + 1];
  }
}
int find(int p, int l, int r, int k) {
  if (l + 1 == r) {
    return l;
  }
  int x = info[2 * p];
  int m = (l + r) / 2;
  if (x >= k) {
    return find(2 * p, l, m, k);
  }
  return find(2 * p + 1, m, r, k - x);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, K;
  std::cin >> N >> K;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < K - 1; ++i) {
    int x = A[i];
    modify(x, info[MAX + x] + 1);
  }
  i64 ans = 0;
  for (int i = K - 1; i < N; ++i) {
    int x = A[i];
    modify(x, info[MAX + x] + 1);
    i64 gain = find(1, 0, MAX, (K + 1) / 2);
    ans += gain;
    int y = A[i - K + 1];
    modify(y, info[MAX + y] - 1);
  }
  std::cout << ans << "\n";
}