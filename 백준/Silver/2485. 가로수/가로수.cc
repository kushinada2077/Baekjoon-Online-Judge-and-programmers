#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
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

int main() {
  fastio;
  int n, ans = 0;
  cin >> n;
  vector<int> tree(n), diff;
  for (auto& i : tree) cin >> i;
  for (int i = 1; i < n; ++i) diff.pb(tree[i] - tree[i - 1]);
  int l = diff[0];
  for (int i = 1; i < si(diff); ++i) l = gcd(l, diff[i]);
  for (auto& i : diff) ans += (i / l) - 1;
  cout << ans << "\n";
}