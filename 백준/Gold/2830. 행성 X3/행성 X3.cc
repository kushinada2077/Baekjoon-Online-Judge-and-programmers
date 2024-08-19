#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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
  ll ans = 0;
  cin >> n;
  vector<int> a(n), cnt(20, 0);
  for (auto& i : a) {
    cin >> i;
    for (int j = 0; j < 20; ++j) {
      if (i & (1 << j)) cnt[j]++;
    }
  }
  for (int j = 0; j < 20; ++j) ans += (1ll << j) * cnt[j] * (n - cnt[j]);
  cout << ans << "\n";
}