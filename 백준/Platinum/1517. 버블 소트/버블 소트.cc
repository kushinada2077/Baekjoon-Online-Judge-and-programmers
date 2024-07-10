#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

ll merge(vector<int>& a, int st, int en) {
  int mid = (st + en) / 2, l = st, r = mid;
  ll ret = 0;
  vector<int> tmp;
  for (int i = st; i < en; ++i) {
    if (l == mid) tmp.pb(a[r++]);
    else if (r == en) tmp.pb(a[l++]);
    else if (a[l] <= a[r]) tmp.pb(a[l++]);
    else {
      ret += mid - l;
      tmp.pb(a[r++]);
    }
  }
  for (int i = st; i < en; ++i) a[i] = tmp[i - st];
  return ret;
}
ll merge_sort(vector<int>& a, int st, int en) {
  if (st + 1 == en) return 0;
  int mid = (st + en) / 2;
  ll ret = 0;
  ret += merge_sort(a, st, mid);
  ret += merge_sort(a, mid, en);
  ret += merge(a, st, en);
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  cout << merge_sort(a, 0, n);
}