#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;

int lb(vector<int>& a, int x) {
  int lo = -1, hi = si(a) - 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int main() {
  fastio;
  int n, ans = 2 * 1e9 + 5;
  cin >> n;
  vector<int> a(n);
  for_in(n) cin >> a[i];
  for_in(n) {
    int idx = lb(a, -a[i]);
    if (idx != i && abs(ans) > abs(a[i] + a[idx])) ans = a[i] + a[idx];
    else if (idx - 1 != i && idx > 0 && abs(ans) > abs(a[i] + a[idx - 1])) ans = a[i] + a[idx - 1];
  }
  cout << ans;
}