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
string board[30];
bool vis[30][30];

int dfs(int x, int y) {
  int ret = 1;
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + "2101"[dir] - '1', ny = y + "1210"[dir] - '1';
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if (board[nx][ny] == '0' || vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    ret += dfs(nx, ny);
  }
  return ret;
}

int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> board[i];
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vis[i][j] || board[i][j] == '0') continue;
      vis[i][j] = 1;
      int s = dfs(i, j);
      if (s) ans.pb(s);
    }
  }

  sort(all(ans));
  cout << si(ans) << "\n";
  for (auto& i : ans) cout << i << "\n";
}