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
string board[65];

bool isChunk(int y, int x, int sz) {
  for (int i = y; i < y + sz; ++i) {
    for (int j = x; j < x + sz; ++j) {
      if (board[y][x] != board[i][j]) return false;
    }
  }
  return true;
}
// (y, x)부터 sz만큼의 영상을 문자열로 압축해서 반환
string compress(int y, int x, int sz) {
  // 기저 사례: 한 덩어리라면
  if (isChunk(y, x, sz)) {
    return string(1, board[y][x]);
  }
  string ret = "(";
  // 아니라면 4분할
  ret += compress(y, x, sz / 2);
  ret += compress(y, x + sz / 2, sz / 2);
  ret += compress(y + sz / 2, x, sz / 2);
  ret += compress(y + sz / 2, x + sz / 2, sz / 2);
  ret += ")";
  return ret;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> board[i];
  cout << compress(0, 0, n) << "\n";
}