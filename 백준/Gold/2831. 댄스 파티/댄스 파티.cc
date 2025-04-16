#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> bt, bs, gt, gs;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) {
      bt.push_back(x);
    } else {
      bs.push_back(-x);
    }
  }
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) {
      gt.push_back(x);
    } else {
      gs.push_back(-x);
    }
  }

  sort(bt.begin(), bt.end());
  sort(gs.begin(), gs.end());
  sort(bs.begin(), bs.end());
  sort(gt.begin(), gt.end());
  int ans = 0;
  for (int i = 0, j = 0; i < bt.size(); ++i) {
    while (j < gs.size() && bt[i] >= gs[j]) {
      j++;
    }
    if (j == gs.size()) {
      break;
    }
    ans++;
    j++;
  }
  for (int i = 0, j = 0; i < gt.size(); ++i) {
    while (j < bs.size() && gt[i] >= bs[j]) {
      j++;
    }
    if (j == bs.size()) {
      break;
    }
    ans++;
    j++;
  }
  std::cout << ans << "\n";
}