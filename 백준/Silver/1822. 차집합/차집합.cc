#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

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
  int na, nb;
  cin >> na >> nb;
  vector<int> a(na), b(nb), ans;
  for (int i = 0; i < na; ++i) cin >> a[i];
  for (int i = 0; i < nb; ++i) cin >> b[i];
  sort(b.begin(), b.end());
  for (auto v : a) {
    if (!bs(b, v)) ans.push_back(v);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto v : ans) cout << v << " ";
}