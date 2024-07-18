
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int lb(vector<int>& a, int target) {
  int lo = -1, hi = si(a);
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= target) hi = mid;
    else lo = mid;
  }
  return hi;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n), ans;
  for (auto& i : a) cin >> i;
  vector<int> b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  for (auto v : a) {
    ans.pb(lb(b, v));
  }
  for (auto v : ans) cout << v << " ";
}