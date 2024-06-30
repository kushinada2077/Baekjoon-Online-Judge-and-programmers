#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

ll sol(vector<ll>& a, int x, int i) {
  int lo = 0, hi = a.size() - 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid;
  }
  if (i == hi) return a[lo];
  else if (i == lo) return a[hi];
  else if (abs(a[lo] - x) < abs(a[hi] - x)) return a[lo];
  else return a[hi];
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<ll> solution(n);
  for (int i = 0; i < n; ++i) cin >> solution[i];
  pair<ll, ll> ans = {solution[0], solution[1]};
  for (int i = 0; i < n; ++i) {
    ll s = solution[i];
    ll s2 = sol(solution, -s, i);
    if (abs(ans.first + ans.second) > abs(s + s2)) ans = {min(s, s2), max(s, s2)};
  }
  cout << ans.first << " " << ans.second;
}