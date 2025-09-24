#include <bits/stdc++.h>
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> max(3, 0), min(3, INF);
  std::cin >> max[0] >> max[1] >> max[2];
  min = max;

  for (int i = 1; i < n; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    auto tmp_max = max;
    auto tmp_min = min;
    max[0] = std::max(tmp_max[0], tmp_max[1]) + a;
    max[1] = std::max({tmp_max[0], tmp_max[1], tmp_max[2]}) + b;
    max[2] = std::max(tmp_max[1], tmp_max[2]) + c;
    min[0] = std::min(tmp_min[0], tmp_min[1]) + a;
    min[1] = std::min({tmp_min[0], tmp_min[1], min[2]}) + b;
    min[2] = std::min(tmp_min[1], tmp_min[2]) + c;
  }

  std::cout << *std::ranges::max_element(max) << " " << *std::ranges::min_element(min) << "\n";
}