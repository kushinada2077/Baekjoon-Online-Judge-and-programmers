#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  int t;
  ll x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    ll diff = y - x, cur = 1;
    while (cur * cur <= diff) {
      cur++;
    }
    cur--;
    ll sum = cur + 2 * cur * (cur - 1) / 2;
    ll ans = cur * 2 - 1, rest = diff - sum;

    while (rest) {
      if (rest >= cur) {
        rest -= cur;
        ans++;
      } else cur--;
    }
    cout << ans << "\n";
  }
}