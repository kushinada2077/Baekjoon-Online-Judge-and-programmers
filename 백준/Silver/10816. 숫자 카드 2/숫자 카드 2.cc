#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

void merge(vector<int> &a, int st, int en) {
  vector<int> tmp(en - st);
  int n = a.size();
  int mid = (st + en) / 2;
  int l = st;
  int r = mid;
  for (int i = st; i < en; ++i) {
    if (l == mid) tmp[i - st] = a[r++];
    else if (r == en) tmp[i - st] = a[l++];
    else if (a[l] <= a[r]) tmp[i - st] = a[l++];
    else tmp[i - st] = a[r++];
  }
  for (int i = st; i < en; ++i) a[i] = tmp[i - st];
}
void merge_sort(vector<int> &a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(a, st, mid);
  merge_sort(a, mid, en);
  merge(a, st, en);
}
int main() {
  fastio;
  int n, m, x;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  merge_sort(a, 0, n);
  cin >> m;
  while (m--) {
    cin >> x;
    cout << upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x) << " ";
  }
}