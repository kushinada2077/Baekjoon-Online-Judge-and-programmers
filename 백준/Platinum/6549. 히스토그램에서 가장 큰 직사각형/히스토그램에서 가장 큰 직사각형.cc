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

int tc, n, h[100010];
// [left, right) 구간에서 잘라낼 수 있는 최대 직사각형의 크기
ll solve(int left, int right) {
  // 기저 사례: 너비가 1이면 넓이 반환
  if (left + 1 == right) return h[left];
  // 구간 분할
  int mid = (left + right) / 2;
  // 각개격파
  ll ret = max(solve(left, mid), solve(mid, right));
  // 3번 케이스
  int lo = mid - 1, hi = mid, curH = min(h[lo], h[hi]);
  ret = max(ret, 2ll * curH);
  while (left < lo || hi < right - 1) {
    if (hi < right - 1 && (lo == left || h[lo - 1] < h[hi + 1])) {
      hi++;
      curH = min(curH, h[hi]);
      ret = max(ret, 1ll * curH * (hi - lo + 1));
    } else {
      lo--;
      curH = min(curH, h[lo]);
      ret = max(ret, 1ll * curH * (hi - lo + 1));
    }
  }

  return ret;
}
int main() {
  fastio;
  while (1) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; ++i) cin >> h[i];
    cout << solve(0, n) << "\n";
  }
}