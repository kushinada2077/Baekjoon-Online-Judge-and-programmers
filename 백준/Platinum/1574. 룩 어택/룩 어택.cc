#include <algorithm>
#include <cmath>
#include <iostream>
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

const int MX = 10000;
int r, c, n, board[400][400], B[MX];
bool vis[MX];
vector<int> adj[MX];

bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      B[b] = a;
      return 1;
    }
  }

  return 0;
}
int main() {
  fastio;
  cin >> r >> c >> n;
  for (int i = 0; i < MX; ++i) B[i] = -1;
  for (int y, x, i{}; i < n; ++i) {
    cin >> y >> x;
    board[y - 1][x - 1] = 1;
  }

  int rowNum = 2;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (board[i][j] != 1) board[i][j] = rowNum;
    }
    rowNum++;
  }

  int colNum = 2;
  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < r; ++i) {
      if (board[i][j] != 1) adj[2 * board[i][j]].pb(2 * colNum + 1);
    }
    colNum++;
  }

  int ans = 0;
  for (int i = 2; i < rowNum; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(2 * i)) ans++;
  }

  cout << ans << "\n";
}