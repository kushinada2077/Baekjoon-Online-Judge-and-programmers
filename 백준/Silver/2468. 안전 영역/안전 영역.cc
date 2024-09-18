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

int n;
int area[105][105];
bool vis[105][105];
void dfs(int x, int y, int h) {
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1', ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if (vis[nx][ny] || area[nx][ny] <= h) continue;
    vis[nx][ny] = 1;
    dfs(nx, ny, h);
  }
}
int main() {
  fastio;
  cin >> n;
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> area[i][j];
      if (area[i][j] > mx) mx = area[i][j];
    }
  }
  int ans = -1;
  for (int h = 0; h <= mx; ++h) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) fill(vis[i], vis[i] + n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (vis[i][j] || area[i][j] <= h) continue;
        vis[i][j] = 1;
        dfs(i, j, h);
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}