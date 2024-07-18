
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

ll f(vector<ll>& a) {
  vector<ll> compress, b = a;
  int stan = si(a) / 2;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  vector<int> cnt(si(b));
  for (auto v : a) compress.pb(lower_bound(all(b), v) - b.begin());
  for (auto v : compress) {
    cnt[v]++;
    if (cnt[v] > stan) return b[v];
  }
  return -1;
}
int main() {
  fastio;
  int n, ti;
  cin >> n;
  while (n--) {
    cin >> ti;
    vector<ll> a(ti);
    for (auto& i : a) cin >> i;
    ll res = f(a);
    if (res == -1) cout << "SYJKGW\n";
    else cout << res << "\n";
  }
}