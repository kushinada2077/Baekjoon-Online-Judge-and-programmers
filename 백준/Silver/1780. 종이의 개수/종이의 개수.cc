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

int board[2200][2200];
bool theSameNumber(int y, int x, int sz) {
  for (int i = y; i < y + sz; ++i) {
    for (int j = x; j < x + sz; ++j) {
      if (board[y][x] != board[i][j]) return false;
    }
  }
  return true;
}
// (y, x)서부터 sz만큼에 -1, 0, 1의 종이가 몇 개 채워져있는지 반환한다
vector<int> solve(int y, int x, int sz) {
  vector<int> ret(3, 0);
  // 기저사례: 모두 같은 수로 되어있을 때
  if (theSameNumber(y, x, sz)) {
    ret[board[y][x] + 1] += 1;
    return ret;
  }

  // 아닌 경우 9개로 분할
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      vector<int> numOfPaper = solve(y + i * sz / 3, x + j * sz / 3, sz / 3);
      for (int k = 0; k < 3; ++k) ret[k] += numOfPaper[k];
    }
  }

  return ret;
}
int n;
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> board[i][j];
  }
  vector<int> ans = solve(0, 0, n);
  for (auto v : ans) cout << v << "\n";
}