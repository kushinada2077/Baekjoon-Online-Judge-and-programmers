#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

inline ll cross(ll x1, ll y1, ll x2, ll y2) { return x1 * y2 - x2 * y1; }

ll n, arr[51];
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int ans = 0;

  for (ll ax, ay, bx, by, i = 0; i < n; ++i) {
    int cnt = 0, cntt = 0;
    for (ll j = i - 1; j >= 0; --j) {
      bool f = 1;
      ax = i;
      ay = arr[i];
      bx = j;
      by = arr[j];

      for (ll cx, cy, dx, dy, k = i - 1; k > j; --k) {
        cx = dx = k;
        cy = 0;
        dy = arr[k];
        ll d1 = cross(bx - ax, by - ay, cx - ax, cy - ay), d2 = cross(bx - ax, by - ay, dx - ax, dy - ay);
        if (!(d1 > 0 && d2 > 0 || d1 < 0 && d2 < 0 || d1 == 0 && d2 == 0)) {
          f = 0;
          break;
        }
      }

      if (!f) continue;
      cnt++;
    }

    cntt += cnt;
    cnt = 0;

    for (ll j = i + 1; j < n; ++j) {
      bool f = 1;
      ax = i;
      ay = arr[i];
      bx = j;
      by = arr[j];

      for (ll cx, cy, dx, dy, k = i + 1; k < j; ++k) {
        cx = dx = k;
        cy = 0;
        dy = arr[k];
        ll d1 = cross(bx - ax, by - ay, cx - ax, cy - ay), d2 = cross(bx - ax, by - ay, dx - ax, dy - ay);
        if (!(d1 > 0 && d2 > 0 || d1 < 0 && d2 < 0 || d1 == 0 && d2 == 0)) {
          f = 0;
          break;
        }
      }

      if (!f) continue;
      cnt++;
    }

    cntt += cnt;
    ans = max(ans, cntt);
  }

  cout << ans << "\n";
}