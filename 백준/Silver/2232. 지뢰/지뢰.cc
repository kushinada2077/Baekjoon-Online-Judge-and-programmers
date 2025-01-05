#include <bits/stdc++.h>

int n;
void bomb(int i, std::vector<int>& a, std::vector<bool>& check) {
  check[i] = true;
  if (i > 0 && a[i - 1] < a[i] && !check[i - 1]) bomb(i - 1, a, check);
  if (i < n - 1 && a[i + 1] < a[i] && !check[i + 1]) bomb(i + 1, a, check);
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::pair<int, int>> o(n);
  std::vector<bool> check(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    o[i] = {-a[i], i};
  }
  sort(o.begin(), o.end());
  std::vector<int> ans;

  for (int i = 0; i < n; ++i) {
    auto [_, idx] = o[i];
    if (check[idx]) continue;
    ans.push_back(idx + 1);
    bomb(idx, a, check);
  }

  std::sort(ans.begin(), ans.end());
  for (auto i : ans) std::cout << i << "\n";
}