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
  int n, st = 0;
  ll m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  ll sum = 0, ans = -1;
  for (int en = 0; en < n; ++en) {
    sum += 1ll * a[en];
    while (sum > m && st <= en) sum -= a[st++];
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}