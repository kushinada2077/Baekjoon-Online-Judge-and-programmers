#include <bits/stdc++.h>
using i64 = long long;

const int MAX = 1 << 21;
int info[MAX << 1];
void update(int node, int x) {
  node += MAX;
  info[node] += x;
  while (node > 1) {
    node /= 2;
    info[node] = info[2 * node] + info[2 * node + 1];
  }
}
int solve(int node, int st, int en, int k) {
  if (st + 1 == en) {
    return st;
  }
  int l = info[2 * node];
  int mid = (st + en) / 2;
  if (k > l) {
    return solve(2 * node + 1, mid, en, k - l);
  } else {
    return solve(2 * node, st, mid, k);
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int T, X;
    std::cin >> T >> X;
    if (T == 1) {
      update(X, 1);
    } else if (T == 2) {
      int x = solve(1, 0, MAX, X);
      update(x, -1);
      std::cout << x << "\n";
    }
  }
}