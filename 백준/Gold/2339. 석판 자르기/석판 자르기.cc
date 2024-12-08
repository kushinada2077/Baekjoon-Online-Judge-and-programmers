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

int n, slate[21][21];
// (sy, sx)부터 (ey, ex)까지의 석판 중에서 경우의 수

bool isEmptyRow(int y, int sx, int ex) {
  for (int i = sx; i < ex; ++i) {
    if (slate[y][i] == 2) return false;
  }
  return true;
}
bool isEmptyCol(int x, int sy, int ey) {
  for (int i = sy; i < ey; ++i) {
    if (slate[i][x] == 2) return false;
  }
  return true;
}
bool isEnded(int sy, int sx, int ey, int ex) {
  int jewel = 0;
  for (int i = sy; i < ey; ++i) {
    for (int j = sx; j < ex; ++j) {
      if (slate[i][j] == 1) return false;
      if (slate[i][j] == 2) jewel++;
    }
  }

  return jewel == 1;
}
// type이 0이면 가로, 1이면 세로
int solve(int sy, int sx, int ey, int ex, bool type) {
  // 기저 사례: 분할이 완료된 판의 경우

  if (isEnded(sy, sx, ey, ex)) return 1;

  // 그렇지 않을 경우 불순물마다 각각 분리
  int ret = 0;

  for (int i = sy; i < ey; ++i) {
    for (int j = sx; j < ex; ++j) {
      if (slate[i][j] == 1) {
        if (type == 0 && isEmptyRow(i, sx, ex)) ret += solve(sy, sx, i, ex, !type) * solve(i + 1, sx, ey, ex, !type);
        else if (type == 1 && isEmptyCol(j, sy, ey)) ret += solve(sy, sx, ey, j, !type) * solve(sy, j + 1, ey, ex, !type);
      }
    }
  }

  return ret;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> slate[i][j];
  }

  int ans = solve(0, 0, n, n, 0) + solve(0, 0, n, n, 1);
  if (ans == 0) ans = -1;
  cout << ans << "\n";
}