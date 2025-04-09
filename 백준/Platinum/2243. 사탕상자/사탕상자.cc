#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 20;
int info[MAX << 1];
void update(int p, int x) {
  p += MAX;
  info[p] += x;
  while (p > 1) {
    p /= 2;
    info[p] = info[2 * p] + info[2 * p + 1];
  }
}
int find(int p, int l, int r, int k) {
  if (l + 1 == r) {
    return l;
  }
  int ln = info[2 * p];
  int m = (l + r) / 2;
  if (k > ln) {
    return find(2 * p + 1, m, r, k - ln);
  }
  return find(2 * p, l, m, k);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int A;
    std::cin >> A;
    if (A == 1) {
      int B;
      std::cin >> B;
      int x = find(1, 0, MAX, B);
      update(x, -1);
      std::cout << x << "\n";
    } else if (A == 2) {
      int B, C;
      std::cin >> B >> C;
      update(B, C);
    }
  }
}