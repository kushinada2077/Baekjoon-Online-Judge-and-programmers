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

const int M = 1e9 + 9;
int d[1000005];
int f(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (n == 3) return 4;
  if (d[n]) return d[n];
  int sum = ((ll)(f(n - 1) + f(n - 2)) % M + f(n - 3)) % M;
  d[n] = sum;
  return d[n];
}
int main() {
  fastio;
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << f(n) << "\n";
  }
}