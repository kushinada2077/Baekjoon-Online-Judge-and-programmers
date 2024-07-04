#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int d[1005][31][2];
int tree[1005];
int t, w;
int f(int n, int k, int i) {
  if (n == 0) return 0;
  if (n == 1 && k == 0 && i == 1) return 0;
  if (k > n) return 0;
  if (d[n][k][i] != -1) return d[n][k][i];
  int ret = f(n - 1, k, i);
  if (k > 0) ret = max(ret, f(n - 1, k - 1, !i));
  ret += (tree[n] == i);
  d[n][k][i] = ret;
  return ret;
}
int main() {
  fastio;
  for_in(i, 1005) { for_in(j, 31) fill(d[i][j], d[i][j] + 2, -1); }
  cin >> t >> w;
  for_in(t) {
    cin >> tree[i + 1];
    tree[i + 1]--;
  }
  int ans = 0;
  for_in(w + 1) ans = max({ans, f(t, i, 0), f(t, i, 1)});
  cout << ans;
}