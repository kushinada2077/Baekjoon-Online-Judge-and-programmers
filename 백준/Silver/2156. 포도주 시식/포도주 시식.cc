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

int d[10005][3];
int wine[10005];
// f(n, k) => n번째 포도주까지 탐색했을 때 k개를 연속으로 마신 상태에서 최대 포도주 양
int n;
int f(int n, int k) {
  if (n <= 0) return 0;
  if (d[n][k] != -1) return d[n][k];

  int ret;
  if (k == 0) ret = max({f(n - 1, 0), f(n - 1, 1), f(n - 1, 2)});
  if (k == 1) ret = wine[n] + f(n - 1, 0);
  if (k == 2) ret = wine[n] + f(n - 1, 1);
  d[n][k] = ret;
  return ret;
}
int main() {
  fastio;
  cin >> n;
  for_in(n + 1) fill(d[i], d[i] + 3, -1);
  for_in(n) cin >> wine[i + 1];
  cout << max({f(n, 1), f(n, 2), f(n, 0)});
}