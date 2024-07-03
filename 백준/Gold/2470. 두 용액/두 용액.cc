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
  int n, ans1 = 1e9 + 5, ans2 = 1e9 + 5;
  cin >> n;
  vector<int> a(n);
  for_in(n) cin >> a[i];
  merge_sort(a, 0, si(a));
  for_in(n) {
    int idx = lb(a, -a[i]);
    if (idx != i && idx < n && abs(ans1 + ans2) > abs(a[i] + a[idx])) {
      ans1 = a[i];
      ans2 = a[idx];
    } else if (idx - 1 != i && idx > 0 && abs(ans1 + ans2) > abs(a[i] + a[idx - 1])) {
      ans1 = a[i];
      ans2 = a[idx - 1];
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  cout << ans1 << " " << ans2;
}