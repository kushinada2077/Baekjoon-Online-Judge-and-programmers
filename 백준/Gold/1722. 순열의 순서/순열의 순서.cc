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

ll fac(int n) {
  if (n == 0) return 1;
  return n * fac(n - 1);
}
vector<int> f(int n, ll k) {
  k--;
  ll nf = fac(n);
  vector<int> a(n), ret;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  while (n > 0) {
    nf /= n--;
    int idx = k / nf;
    k %= nf;
    ret.pb(a[idx]);
    a.erase(a.begin() + idx);
  }
  return ret;
}
ll f2(vector<int>& p, int n) {
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  ll ret = 0, nf = fac(n);
  for (auto& v : p) {
    nf /= n--;
    int idx = find(all(a), v) - a.begin();
    a.erase(a.begin() + idx);
    ret += idx * nf;
  }
  return ret + 1;
}
int main() {
  fastio;
  int n, c;
  cin >> n >> c;
  ll k;
  if (c == 1) {
    cin >> k;
    vector<int> ans = f(n, k);
    for (auto v : ans) cout << v << " ";
  } else {
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    ll ans = f2(a, n);
    cout << ans << "\n";
  }
}