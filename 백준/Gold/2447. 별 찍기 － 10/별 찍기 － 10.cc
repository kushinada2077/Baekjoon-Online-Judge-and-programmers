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

int n;
char board[2200][2200];
// (y, x)부터 sz 크기 별 찍기
void solve(int y, int x, int sz, int type) {
  // 기저 사례: sz가 1이면 찍음
  if (sz == 1) {
    if (type) board[y][x] = '*';
    else board[y][x] = ' ';
    return;
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (3 * i + j == 4) solve(y + i * sz / 3, x + j * sz / 3, sz / 3, 0);
      else solve(y + i * sz / 3, x + j * sz / 3, sz / 3, type);
    }
  }
}
int main() {
  fastio;
  cin >> n;
  solve(0, 0, n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << board[i][j];
    cout << "\n";
  }
}