#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

ll ans;
int n, c[20], d1[60], d2[60];
void f(int k) {
  if (n == k) {
    ans++;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (c[i] || d1[k + i] || d2[k - i + 15]) continue;
    c[i] = d1[k + i] = d2[k - i + 15] = 1;
    f(k + 1);
    c[i] = d1[k + i] = d2[k - i + 15] = 0;
  }
}
int main() {
  fastio;
  cin >> n;
  f(0);
  cout << ans << "\n";
}