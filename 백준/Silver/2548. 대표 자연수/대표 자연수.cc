#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
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
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n), sum(10001, 0);
  for (auto& i : a) cin >> i;
  sort(all(a));
  int ans, mx = 0x3f3f3f3f;
  for (int i = a[n - 1]; i >= a[0]; --i) {
    int tot = 0;
    for (int j = 0; j < n; ++j) {
      tot += abs(i - a[j]);
    }
    if (tot <= mx) {
      ans = i;
      mx = tot;
    }
  }
  cout << ans << "\n";
}