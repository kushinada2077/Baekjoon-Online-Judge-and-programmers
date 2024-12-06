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
ll h[100010];
// 구간 [left, right) 에서 가장 큰 직사각형의 넓이를 반환
ll solve(int left, int right) {
  if (left + 1 == right) return h[left];
  int mid = (left + right) / 2;
  ll ret = max(solve(left, mid), solve(mid, right));
  int lo = mid - 1, hi = mid;
  ll height = min(h[lo], h[hi]);
  ret = max(ret, height * (hi - lo + 1));
  while (left < lo || hi < right - 1) {
    if (hi < right - 1 && (left == lo || h[lo - 1] < h[hi + 1])) {
      hi++;
      height = min(height, h[hi]);
      ret = max(ret, height * (hi - lo + 1));
    } else {
      lo--;
      height = min(height, h[lo]);
      ret = max(ret, height * (hi - lo + 1));
    }
  }
  return ret;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> h[i];
  cout << solve(0, n) << "\n";
}