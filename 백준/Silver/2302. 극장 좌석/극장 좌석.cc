#include <algorithm>
#include <iostream>
#include <queue>
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

int d[45];
int main() {
  fastio;
  int n, m, ans = 1;
  cin >> n >> m;
  vector<int> a(m + 1, 0);
  for (int i = 1; i <= m; ++i) cin >> a[i];
  a.pb(n + 1);
  d[0] = 1;
  d[1] = 1;
  d[2] = 2;
  for (int i = 3; i <= 43; ++i) d[i] = d[i - 1] + d[i - 2];
  for (int i = 0; i < (int)si(a) - 1; ++i) ans *= d[a[i + 1] - a[i] - 1];
  cout << ans << "\n";
}