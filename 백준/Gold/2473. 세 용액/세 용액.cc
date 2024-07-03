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

void merge(vector<ll>& a, int st, int en) {
  int mid = (st + en) / 2, l = st, r = mid;
  vector<int> ret;
  for_in(i, st, en) {
    if (l == mid) ret.pb(a[r++]);
    else if (r == en) ret.pb(a[l++]);
    else if (a[l] <= a[r]) ret.pb(a[l++]);
    else ret.pb(a[r++]);
  }
  for_in(i, st, en) a[i] = ret[i - st];
}
void merge_sort(vector<ll>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
int lb(vector<ll>& a, int x) {
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
  int n;
  vector<ll> ans = {(int)1e9 + 5, (int)1e9 + 5, (int)1e9 + 5};
  cin >> n;
  vector<ll> a(n);
  for_in(n) cin >> a[i];
  merge_sort(a, 0, n);
  for_in(n) {
    for_in(j, i + 1, n) {
      ll two_sum = a[i] + a[j];
      ll absum = abs(ans[0] + ans[1] + ans[2]);
      int idx = lb(a, -two_sum);
      if (idx < n && i != idx && j != idx && absum > abs(two_sum + a[idx])) ans = {a[i], a[j], a[idx]};
      else if (idx - 1 >= 0 && i != idx - 1 && j != idx - 1 && absum > abs(two_sum + a[idx - 1])) ans = {a[i], a[j], a[idx - 1]};
      else if (idx + 1 < n && i != idx + 1 && j != idx + 1 && absum > abs(two_sum + a[idx + 1])) ans = {a[i], a[j], a[idx + 1]};
    }
  }
  merge_sort(ans, 0, 3);
  for (auto n : ans) cout << n << " ";
}