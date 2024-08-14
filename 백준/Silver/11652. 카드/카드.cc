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

int main() {
  fastio;
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  int cnt = 1, mx = 1;
  ll ans = a.back();
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] != a[i + 1]) {
      if (cnt >= mx) {
        mx = cnt;
        ans = a[i + 1];
      }
      cnt = 0;
    }
    cnt++;
  }
  if (cnt >= mx) ans = a[0];
  cout << ans << "\n";
}