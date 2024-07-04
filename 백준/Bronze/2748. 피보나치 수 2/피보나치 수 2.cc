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

ll d[95];
ll f(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;
  if (d[n] != -1) return d[n];
  ll ret = f(n - 1) + f(n - 2);
  d[n] = ret;
  return ret;
}
int main() {
  fastio;
  fill(d, d + 95, -1);
  int n;
  cin >> n;
  cout << f(n);
}