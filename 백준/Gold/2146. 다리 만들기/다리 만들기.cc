#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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

int a[105][105], country[105][105], cn = 1, n;
int vis[105][105];
vector<vector<int>> dist(105, vector<int>(105, -1));
queue<pair<int, int>> a_q;
bool adj_sea(int x, int y) {
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1';
    int ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if (a[nx][ny] == 0) return true;
  }
  return false;
}
void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  vis[sx][sy] = true;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    country[x][y] = cn;
    if (adj_sea(x, y)) a_q.push({x, y});
    dist[x][y] = 0;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (a[nx][ny] == 0 || vis[nx][ny]) continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!vis[i][j] && a[i][j]) {
        bfs(i, j);
        cn++;
      }
    }
  }

  int ans = 0x3f3f3f3f;
  while (!a_q.empty()) {
    auto [x, y] = a_q.front();
    a_q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + "2101"[dir] - '1';
      int ny = y + "1210"[dir] - '1';
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (country[x][y] == country[nx][ny] && dist[nx][ny] != -1) continue;
      if (country[nx][ny] && country[nx][ny] != country[x][y]) {
        ans = min(ans, dist[x][y] + dist[nx][ny]);
        continue;
      }
      a_q.push({nx, ny});
      dist[nx][ny] = dist[x][y] + 1;
      country[nx][ny] = country[x][y];
    }
  }
  cout << ans << "\n";
}