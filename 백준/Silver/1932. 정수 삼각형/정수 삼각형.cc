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

int d[505][505];
// f(n, k) => 좌표 (n(row), k(col))까지 도달한 합
int f(vector<vector<int>>& tri, int n, int k) {
  if (n == 1) return tri[1][1];
  if (d[n][k] != -1) return d[n][k];

  int ret;
  if (k == 1) ret = f(tri, n - 1, k) + tri[n][k];
  else if (k == n) ret = f(tri, n - 1, k - 1) + tri[n][k];
  else ret = max(f(tri, n - 1, k - 1), f(tri, n - 1, k)) + tri[n][k];
  d[n][k] = ret;
  return ret;
}
int main() {
  fastio;
  int n, x, ans = 0;
  cin >> n;
  for_in(i, 0, n + 1) fill(d[i], d[i] + n + 1, -1);
  vector<vector<int>> tri(n + 1, vector<int>(n + 1, 0));
  for_in(i, 1, n + 1) {
    for_in(j, 0, i) { cin >> tri[i][j + 1]; }
  }
  for_in(i, 1, n + 1) ans = max(ans, f(tri, n, i));
  cout << ans << "\n";
}