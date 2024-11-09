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
int n, board[300][300], A[MX], B[MX];
bool vis[MX];
vector<int> adj[MX];

bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return 1;
    }
  }
  return 0;
}

int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < MX; ++i) A[i] = B[i] = -1;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'X') board[i][j] = -1;
    }
  }

  int rowNum = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == -1) rowNum++;
      else board[i][j] = rowNum;
    }
    if (board[i][n - 1] != -1) rowNum++;
  }

  int colNum = 1;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (board[i][j] == -1) colNum++;
      else adj[2 * board[i][j]].pb(2 * colNum + 1);
    }
    if (board[n - 1][j] != -1) colNum++;
  }

  int ans = 0;
  for (int i = 1; i < rowNum; ++i) {
    fill(vis, vis + MX, 0);
    if (dfs(2 * i)) ans++;
  }

  cout << ans << "\n";
}