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

ll fac(ll n) {
  if (n == 0) return 1;
  ll ret = n * fac(n - 1);
  return ret;
}
vector<int> f1(int n, ll k) {
  k--;
  vector<int> a(n), ret;
  ll nf = fac(n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  while (n > 0) {
    nf /= n--;
    int idx = k / nf;
    ret.pb(a[idx]);
    a.erase(a.begin() + idx);
    k %= nf;
  }
  return ret;
}
ll f2(vector<int>& a) {
  int n = si(a);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) b[i] = i + 1;
  ll ret = 0, nf = fac(n);
  for (auto& v : a) {
    int idx = find(all(b), v) - b.begin();
    b.erase(b.begin() + idx);
    nf /= n--;
    ret += idx * nf;
  }
  return ret + 1;
}
int main() {
  fastio;
  int n, x;
  ll k;
  cin >> n >> x;
  if (x == 1) {
    cin >> k;
    vector<int> ans = f1(n, k);
    for (auto& v : ans) cout << v << " ";
  } else {
    vector<int> p(n);
    for (auto& i : p) cin >> i;
    ll ans = f2(p);
    cout << ans << "\n";
  }
}