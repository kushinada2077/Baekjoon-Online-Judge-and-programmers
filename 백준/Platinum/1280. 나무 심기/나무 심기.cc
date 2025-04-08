#include <bits/stdc++.h>
using i64 = long long;

const int MOD = 1e9 + 7;
const int MAX = 1 << 18;
i64 info[MAX << 1][2];
void update(int node, std::pair<i64, i64> x) {
  node += MAX;
  info[node][0] += x.first;
  info[node][1] += x.second;
  while (node > 1) {
    node /= 2;
    info[node][0] = info[2 * node][0] + info[2 * node + 1][0];
    info[node][1] = info[2 * node][1] + info[2 * node + 1][1];
  }
}
std::pair<i64, i64> sum(int node, int st, int en, int l, int r) {
  if (en <= l || r <= st) {
    return {0LL, 0LL};
  }
  if (l <= st && en <= r) {
    return {info[node][0], info[node][1]};
  }
  int mid = (st + en) / 2;
  auto [v1, n1] = sum(2 * node, st, mid, l, r);
  auto [v2, n2] = sum(2 * node + 1, mid, en, l, r);
  return {v1 + v2, n1 + n2};
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  i64 x;
  i64 ans = 1;
  std::cin >> N >> x;
  update(x, {x, 1});
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> x;
    auto [tl, nl] = sum(1, 0, MAX, 0, x);
    auto [tr, nr] = sum(1, 0, MAX, x, MAX);
    i64 l = (nl * x - tl) % MOD;
    i64 r = (tr - nr * x) % MOD;
    i64 tot = (l + r) % MOD;
    ans = (ans * tot) % MOD;
    update(x, {x, 1});
  }
  std::cout << ans << "\n";
}