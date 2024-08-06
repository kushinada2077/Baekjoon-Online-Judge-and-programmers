#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int n;
int a[200][200];
int ans[2];
void f(int bx, int by, int ex, int ey) {
  if (bx + 1 == ex && by + 1 == ey) {
    ans[a[bx][by]]++;
    return;
  }

  int cnt_b = 0, cnt_w = 0;
  for (int i = bx; i < ex; ++i) {
    for (int j = by; j < ey; ++j) {
      if (a[i][j] == 0) cnt_w++;
      if (a[i][j] == 1) cnt_b++;
      if (cnt_w && cnt_b) {
        int mid_x = (bx + ex) / 2, mid_y = (by + ey) / 2;
        f(bx, by, mid_x, mid_y);
        f(mid_x, by, ex, mid_y);
        f(bx, mid_y, mid_x, ey);
        f(mid_x, mid_y, ex, ey);
        return;
      }
    }
  }
  ans[a[bx][by]]++;
}

int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  }
  f(0, 0, n, n);
  cout << ans[0] << "\n" << ans[1] << "\n";
}