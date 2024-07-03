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
#define pb(x) push_back(x)
using namespace std;

template <typename T>
void merge(vector<T>& a, int st, int en) {
  int mid = (st + en) / 2, l = st, r = mid;
  vector<T> tmp;
  for_in(i, st, en) {
    if (l == mid) tmp.pb(a[r++]);
    else if (r == en) tmp.pb(a[l++]);
    else if (a[l] <= a[r]) tmp.pb(a[l++]);
    else tmp.pb(a[r++]);
  }
  for_in(i, st, en) a[i] = tmp[i - st];
}
template <typename T>
void merge_sort(vector<T>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
template <typename T>
int lb(vector<T>& a, int x) {
  int lo = -1, hi = si(a);
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
template <typename T>
int ub(vector<T>& a, int x) {
  int lo = -1, hi = si(a);
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] > x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int main() {
  fastio;
  int x1, x2, x3, x4, n;
  ll ans = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for_in(n) {
    cin >> x1 >> x2 >> x3 >> x4;
    a[i] = x1;
    b[i] = x2;
    c[i] = x3;
    d[i] = x4;
  }
  vector<int> ab, cd;
  for_in(n) {
    for_in(j, n) {
      ab.pb(a[i] + b[j]);
      cd.pb(c[i] + d[j]);
    }
  }
  merge_sort(ab, 0, si(ab));
  merge_sort(cd, 0, si(cd));
  for (auto ab_sum : ab) ans += ub(cd, -ab_sum) - lb(cd, -ab_sum);
  cout << ans;
}