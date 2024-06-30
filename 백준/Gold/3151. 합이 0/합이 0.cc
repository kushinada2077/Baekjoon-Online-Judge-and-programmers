#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  int n;
  ll ans = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = a[i] + a[j];
      auto lo_iter = lower_bound(a.begin() + j + 1, a.end(), -sum);
      if (lo_iter == a.end()) continue;
      ans += upper_bound(a.begin() + j + 1, a.end(), -sum) - lo_iter;
    }
  }
  cout << ans;
}