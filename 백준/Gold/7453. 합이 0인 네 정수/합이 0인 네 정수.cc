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

int main() {
  fastio;
  int x1, x2, x3, x4, n;
  ll ans = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for_in(n) {
    cin >> x1 >> x2 >> x3 >> x4;
    a[i] = x1;
    b[i] = x2;
    c[i] = x3;
    d[i] = x4;
  }
  vector<int> ab, cd;
  for_in(n) {
    for_in(j, n) {
      ab.pb(a[i] + b[j]);
      cd.pb(c[i] + d[j]);
    }
  }
  sort(all(ab));
  sort(all(cd));
  for (auto ab_sum : ab) ans += upper_bound(all(cd), -ab_sum) - lower_bound(all(cd), -ab_sum);
  cout << ans;
}