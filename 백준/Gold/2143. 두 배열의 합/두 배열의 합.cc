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
  vector<int> tmp;
  for_in(i, st, en) {
    if (l == mid) tmp.pb(a[r++]);
    else if (r == en) tmp.pb(a[l++]);
    else if (a[l] <= a[r]) tmp.pb(a[l++]);
    else tmp.pb(a[r++]);
  }
  for_in(i, st, en) a[i] = tmp[i - st];
}
void merge_sort(vector<ll>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
int lb(vector<ll>& a, ll x) {
  int lo = -1, hi = si(a);
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return hi;
}
int ub(vector<ll>& a, ll x) {
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
  int n, m, x;
  ll t, sum = 0;
  cin >> t >> n;
  vector<ll> a(n);
  for_in(n) {
    cin >> x;
    sum += x;
    a[i] = sum;
  }
  cin >> m;
  vector<ll> b(m);
  sum = 0;
  for_in(m) {
    cin >> x;
    sum += x;
    b[i] = sum;
  }
  vector<ll> sa, sb;
  for (int i = n - 1; i >= 0; --i) {
    sa.pb(a[i]);
    for (int j = i - 1; j >= 0; --j) sa.pb(a[i] - a[j]);
  }
  for (int i = m - 1; i >= 0; --i) {
    sb.pb(b[i]);
    for (int j = i - 1; j >= 0; --j) sb.pb(b[i] - b[j]);
  }
  merge_sort(sa, 0, si(sa));
  merge_sort(sb, 0, si(sb));
  sum = 0;
  for (auto ss : sa) sum += ub(sb, t - ss) - lb(sb, t - ss);
  cout << sum;
}