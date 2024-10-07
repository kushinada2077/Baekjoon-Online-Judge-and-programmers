#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int board[501][501];
int main() {
  fastio;
  int n, m, b;
  cin >> n >> m >> b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> board[i][j];
  }

  int ans_t = 0x3f3f3f3f, ans_h = -1;
  for (int brute = 0; brute <= 256; ++brute) {
    int limit = b, cnt = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] < brute) {
          cnt += brute - board[i][j];
          limit -= brute - board[i][j];
        } else if (board[i][j] > brute) {
          cnt += 2 * (board[i][j] - brute);
          limit += board[i][j] - brute;
        }
      }
    }

    if (limit < 0) continue;
    if (ans_t >= cnt) {
      ans_t = cnt;
      ans_h = brute;
    }
  }

  cout << ans_t << " " << ans_h << "\n";
}