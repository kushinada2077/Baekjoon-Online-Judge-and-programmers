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

int n, r, c;
ll cnt;
void Z(int y, int x, int sz) {
  // 기저 사례: 1칸
  if (sz == 1) {
    if (y == r && x == c) cout << cnt << "\n";
    return;
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (y + i * sz / 2 <= r && r < y + (i + 1) * sz / 2 && x + j * sz / 2 <= c && c < x + (j + 1) * sz / 2) {
        cnt += 1ll * sz * sz * (2 * i + j) / 4;
        Z(y + i * sz / 2, x + j * sz / 2, sz / 2);
      }
    }
  }
}
int main() {
  fastio;
  cin >> n >> r >> c;
  Z(0, 0, (1 << n));
}