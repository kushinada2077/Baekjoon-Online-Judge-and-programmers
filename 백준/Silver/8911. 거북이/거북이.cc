#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir = 0;  // r +1 l -1
int main() {
  fastio;
  int t;
  string path;
  cin >> t;
  while (t--) {
    int x, y, mn_x, mn_y, mx_x, mx_y;
    dir = x = y = mn_x = mn_y = mx_x = mx_y = 0;
    cin >> path;
    for (auto& op : path) {
      if (op == 'F') {
        x += dx[dir];
        y += dy[dir];
      } else if (op == 'B') {
        x -= dx[dir];
        y -= dy[dir];
      } else if (op == 'L') {
        dir = (dir + 3) % 4;
      } else if (op == 'R') {
        dir = (dir + 1) % 4;
      }
      mn_x = min(mn_x, x);
      mn_y = min(mn_y, y);
      mx_x = max(mx_x, x);
      mx_y = max(mx_y, y);
    }
    cout << ((mx_x - mn_x) * (mx_y - mn_y)) << "\n";
  }
}