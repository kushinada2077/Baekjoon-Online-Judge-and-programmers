#include <algorithm>
#include <climits>
#include <iostream>
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

int n, m, k;
vector<vector<bool>> vis(105, vector<bool>(105)), board(105, vector<bool>(105));
int dfs(int y, int x) {
  int ret = 1;
  for (int dir = 0; dir < 4; ++dir) {
    int ny = y + "2101"[dir] - '1', nx = x + "1210"[dir] - '1';
    if (ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
    if (vis[ny][nx] || board[ny][nx] == 0) continue;
    vis[ny][nx] = true;
    ret += dfs(ny, nx);
  }
  return ret;
}
int main() {
  fastio;
  int x, y;
  vector<pair<int, int>> coor;
  cin >> n >> m >> k;
  while (k--) {
    cin >> y >> x;
    board[y][x] = 1;
    coor.pb({y, x});
  }

  int ans = -1;
  for (auto [y, x] : coor) {
    if (vis[y][x]) continue;
    vis[y][x] = 1;
    ans = max(ans, dfs(y, x));
  }
  cout << ans << "\n";
}