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

const int MX = 50000;
int n, m, board[105][105], B[MX];
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
  fill(B, B + MX, -1);
  cin >> n >> m;
  for (int y, x, i{}; i < m; ++i) {
    cin >> y >> x;
    board[y - 1][x - 1] = 1;
  }

  int num = 2;
  for (int i = 0; i < n; ++i) {
    for (int x = i, y = 0; x < n && y < n; ++x, ++y) {
      if (board[y][x] == 1) num++;
      else board[y][x] = num;
    }
    num++;
  }

  for (int i = 1; i < n; ++i) {
    for (int x = 0, y = i; x < n && y < n; ++x, ++y) {
      if (board[y][x] == 1) num++;
      else board[y][x] = num;
    }
    num++;
  }

  int cnt = num;
  num = 2;
  for (int i = 0; i < n; ++i) {
    for (int x = i, y = 0; x >= 0 && y < n; --x, ++y) {
      if (board[y][x] == 1) num++;
      else adj[2 * board[y][x]].pb(2 * num + 1);
    }
    num++;
  }

  for (int i = 1; i < n; ++i) {
    for (int x = n - 1, y = i; x >= 0 && y < n; --x, ++y) {
      if (board[y][x] == 1) num++;
      else adj[2 * board[y][x]].pb(2 * num + 1);
    }
    num++;
  }

  int ans = 0;
  for (int i = 0; i < cnt; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(2 * i)) ans++;
  }

  cout << ans << "\n";
}