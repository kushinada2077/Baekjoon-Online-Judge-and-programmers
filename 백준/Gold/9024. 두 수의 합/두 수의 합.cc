#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::ranges::sort(a);
  int diff = INT_MAX, cnt = 0;

  for (int i = 0; i < n; ++i) {
    int j = std::lower_bound(a.begin() + i + 1, a.end(), k - a[i]) - a.begin();
    if (j < n) {
      int n_diff = std::abs(k - (a[j] + a[i]));
      if (diff == n_diff) cnt++;
      else if (diff > n_diff) {
        diff = n_diff;
        cnt = 1;
      }
    }
    if (j - 1 > 0 && j - 1 != i) {
      int n_diff = std::abs(k - (a[j - 1] + a[i]));
      if (diff == n_diff) cnt++;
      else if (diff > n_diff) {
        diff = n_diff;
        cnt = 1;
      }
    }
  }

  std::cout << cnt << "\n";
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }
}