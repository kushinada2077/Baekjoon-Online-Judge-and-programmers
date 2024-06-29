#define ll long long
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int st, int en) {
  vector<int> tmp;
  int mid = (st + en) / 2;
  int l = st;
  int r = mid;

  while (l < mid && r < en) {
    if (a[l] > a[r])
      tmp.push_back(a[l++]);
    else
      tmp.push_back(a[r++]);
  }

  while (l <= mid) tmp.push_back(a[l++]);
  while (r <= en) tmp.push_back(a[r++]);
  for (int i = st; i < en; ++i) a[i] = tmp[i - st];
}
void partition(vector<int>& a, int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  partition(a, st, mid);
  partition(a, mid, en);
  merge(a, st, en);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> a(9);
  vector<int> n2i(101);
  for (int i = 0; i < 9; ++i) {
    cin >> a[i];
    n2i[a[i]] = i;
  }
  partition(a, 0, a.size());
  cout << a[0] << "\n" << n2i[a[0]] + 1;
}