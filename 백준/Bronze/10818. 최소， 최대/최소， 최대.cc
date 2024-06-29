#define ll long long
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void merge(vector<int>& a, int st, int en) {
  vector<int> tmp;
  int mid = (st + en) / 2;
  int l = st;
  int r = mid;
  for (int i = st; i < en; ++i) {
    if (l == mid)
      tmp.push_back(a[r++]);
    else if (r == en)
      tmp.push_back(a[l++]);
    else if (a[l] < a[r])
      tmp.push_back(a[l++]);
    else
      tmp.push_back(a[r++]);
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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  merge_sort(a, 0, n);
  cout << a[0] << " " << a[n - 1];
}