#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
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

vector<int> a;
int n, s, x, ans;
void f(int idx, int sum) {
  if (idx == n) {
    ans += s == sum;
    return;
  }
  f(idx + 1, sum + a[idx]);
  f(idx + 1, sum);
}
int main() {
  fastio;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.pb(x);
  }
  f(0, 0);
  if (s == 0) ans--;
  cout << ans << "\n";
}