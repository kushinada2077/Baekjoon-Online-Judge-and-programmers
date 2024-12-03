#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

const int MOD = 1e9 + 7;
int n, m;
string board[2010];

ll my_pow(ll n, ll r) {
  ll ret = 1;

  while (r) {
    if (r % 2) ret = (ret * n) % MOD;
    n = (n * n) % MOD;
    r /= 2;
  }

  return ret;
}
int main() {
  fastio;
  cin >> n >> m;
  int cnt = n * m;
  for (int i = 0; i < n; ++i) cin >> board[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int dir = 0; dir < 4; ++dir) {
        int ny = i + "2101"[dir] - '1', nx = j + "1210"[dir] - '1';
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[i][j] != board[ny][nx]) {
          cnt--;
          break;
        }
      }
    }
  }

  cout << my_pow(2, cnt) << "\n";
}