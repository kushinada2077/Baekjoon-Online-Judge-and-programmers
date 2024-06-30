#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

void merge(vector<int>& a, int st, int en) {
  int n = a.size(), mid = (st + en) / 2, l = st, r = mid;
  vector<int> tmp;
  for (int i = st; i < en; ++i) {
    if (l == mid) tmp.push_back(a[r++]);
    else if (r == en) tmp.push_back(a[l++]);
    else if (a[l] <= a[r]) tmp.push_back(a[l++]);
    else tmp.push_back(a[r++]);
  }
  for (int i = st; i < en; ++i) a[i] = tmp[i - st];
}
void merge_sort(vector<int>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
bool bs(vector<int>& a, int x) {
  int lo = -1, hi = a.size() - 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  return a[hi] == x;
}
int main() {
  fastio;
  int n, m, x;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  merge_sort(a, 0, a.size());
  cin >> m;
  while (m--) {
    cin >> x;
    cout << bs(a, x) << " ";
  }
}