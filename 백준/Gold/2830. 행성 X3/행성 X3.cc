#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
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

vector<int> b(30, 0);
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
    for (int j = 0, k; (k = (1 << j)) <= i; ++j) {
      if (i & k) b[j]++;
    }
  }

  ll m = 1, ans = 0;
  for (int j = 0; j < 30; ++j) {
    ll num = 1ll * b[j] * (n - b[j]);
    ans += (num << j);
  }
  cout << ans << "\n";
}