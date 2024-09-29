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

int t, n, m, k, x, y;
bool board[51][51], vis[51][51];
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1', ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vis[nx][ny] || board[nx][ny] == 0) continue;
    dfs(nx, ny);
  }
}
int main() {
  fastio;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < m + 1; ++j) {
        vis[i][j] = board[i][j] = 0;
      }
    }

    for (int i = 0; i < k; ++i) {
      cin >> x >> y;
      board[x][y] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j]) continue;
        if (board[i][j] == 0) continue;
        ans++;
        dfs(i, j);
      }
    }
    cout << ans << "\n";
  }
}