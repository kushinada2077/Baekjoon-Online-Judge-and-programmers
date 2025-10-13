#include <bits/stdc++.h>
using i64 = long long;
using P = std::pair<int, int>;

void solve(int x) {
  x *= 10000000;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::ranges::sort(a);
  std::map<int, int> cnt;
  int ans1 = -1, ans2 = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt.contains(x - a[i])) {
      ans1 = a[i];
      ans2 = x - a[i];
    }
    cnt[a[i]]++;
  }

  if (ans1 == -1) std::cout << "danger\n";
  else {
    std::cout << "yes " << std::min(ans1, ans2) << " " << std::max(ans1, ans2) << "\n";
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x;
  while (std::cin >> x) {
    solve(x);
  }
}