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

const int MX_COL = 11, MX = MX_COL * MX_COL + 1000;
int TC, n, m, B[MX];
bool vis[MX];
string board[MX_COL];
vector<int> adj[MX];
void init() {
  for (int i = 0; i < MX; ++i) {
    B[i] = -1;
    adj[i].clear();
  }
}
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
  cin >> TC;
  while (TC--) {
    init();
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      cin >> board[i];
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == '.') tot++;
      }
    }

    for (int j = 0; j < m; j += 2) {
      for (int i = 0; i < n; ++i) {
        if (board[i][j] == 'x') continue;
        for (int dir = 0; dir < 6; ++dir) {
          int ny = i + "100122"[dir] - '1', nx = j + "220020"[dir] - '1';
          if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
          if (board[ny][nx] == 'x') continue;
          adj[MX_COL * i + j].pb(MX_COL * ny + nx);
        }
      }
    }

    int cnt = 0;
    for (int j = 0; j < m; j += 2) {
      for (int i = 0; i < n; ++i) {
        int u = MX_COL * i + j;
        fill(vis, vis + MX, 0);
        if (dfs(u)) cnt++;
      }
    }

    cout << tot - cnt << "\n";
  }
}