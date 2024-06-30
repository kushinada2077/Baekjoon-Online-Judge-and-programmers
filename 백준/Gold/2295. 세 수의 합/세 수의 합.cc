#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int bs(vector<int>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return a[hi] == x ? a[hi] : -1;
}
int main() {
  fastio;
  int n, ans = -1;
  cin >> n;
  vector<int> a(n);
  vector<int> two_sum;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) two_sum.push_back(a[i] + a[j]);
  sort(two_sum.begin(), two_sum.end());
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int apb = bs(two_sum, a[j] - a[i]);
      if (apb != -1) ans = max(ans, apb + a[i]);
    }
  }
  cout << ans;
}