#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int bs(vector<pair<int, int>>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid].first >= x) hi = mid;
    else lo = mid;
  }
  return a[hi].first == x ? a[hi].second : -1;
}
int main() {
  fastio;
  int n, ans = -1;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> diff;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; ++j) {
      if (a[j] - a[i] > 0) diff.push_back({a[j] - a[i], a[i]});
    }
  }
  sort(diff.begin(), diff.end());
  diff.erase(unique(diff.begin(), diff.end()), diff.end());
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int apb = a[i] + a[j];
      if (apb < 0) continue;
      int c = bs(diff, apb);
      if (c != -1) ans = max(ans, apb + c);
    }
  }
  cout << ans;
}