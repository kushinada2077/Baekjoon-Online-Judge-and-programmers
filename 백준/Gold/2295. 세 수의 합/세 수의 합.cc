#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool bs(vector<int>& a, int x) {
  int lo = -1, hi = a.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return a[hi] == x;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> two_sum;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) two_sum.push_back(a[i] + a[j]);
  sort(two_sum.begin(), two_sum.end());
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (bs(two_sum, a[i] - a[j])) {
        cout << a[i];
        return 0;
      }
    }
  }
}