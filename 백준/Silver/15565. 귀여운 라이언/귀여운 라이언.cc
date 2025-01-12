#include <bits/stdc++.h>
using i64 = long long;

bool ok(int l, int k, std::vector<int>& a) {
  int n = a.size();
  int cnt = 0;
  for (int i = 0; i < l - 1; ++i) {
    if (a[i] == 1) cnt++;
  }

  for (int i = l - 1; i < n; ++i) {
    cnt += a[i] == 1;
    if (cnt >= k) return true;
    cnt -= a[i - l + 1] == 1;
  }

  return false;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, cnt = 0, ans = 0x3f3f3f3f;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int lo = 0, hi = n;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid, k, a)) hi = mid;
    else lo = mid;
  }

  if (hi == n) hi = -1;
  std::cout << hi << "\n";
}