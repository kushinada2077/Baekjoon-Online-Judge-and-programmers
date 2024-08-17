#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int t, d, n;
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> d >> n;
    vector<ll> a(n), cnt(d + 1);
    ll tot = 0;
    for (auto& i : a) {
      cin >> i;
      tot = (1ll * tot + i) % d;
      cnt[tot]++;
    }
    ll ans = cnt[0];
    for (int i = 0; i < d; ++i) {
      if (cnt[i] < 2) continue;
      ans += cnt[i] * (cnt[i] - 1) / 2ll;
    }
    cout << ans << "\n";
  }
}