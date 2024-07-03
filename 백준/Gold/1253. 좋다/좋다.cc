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

void merge(vector<int>& a, int st, int en) {
  int mid = (st + en) / 2, l = st, r = mid;
  vector<int> tmp;
  for_in(i, st, en) {
    if (l == mid) tmp.pb(a[r++]);
    else if (r == en) tmp.pb(a[l++]);
    else if (a[l] <= a[r]) tmp.pb(a[l++]);
    else tmp.pb(a[r++]);
  }
  for_in(i, st, en) a[i] = tmp[i - st];
}
void merge_sort(vector<int>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
int lb(vector<int>& a, int x) {
  int lo = -1, hi = si(a);
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int main() {
  fastio;
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for_in(n) cin >> a[i];
  merge_sort(a, 0, si(a));
  for_in(i, n) {
    for_in(j, n) {
      if (i == j) continue;
      int x = a[i] - a[j], idx = lb(a, x);
      if ((i != idx && j != idx && idx < n && a[idx] == x) || (i != idx + 1 && j != idx + 1 && idx + 1 < n && a[idx + 1] == x)) {
        ans++;
        break;
      }
    }
  }
  cout << ans;
}