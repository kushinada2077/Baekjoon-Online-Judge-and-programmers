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
ll A[100010];
// 구간 [l, r) 에서 최댓값을 찾아내서 반환
ll solve(int left, int right) {
  if (left + 1 == right) return A[left] * A[left];
  int mid = (left + right) / 2;
  ll ret = max(solve(left, mid), solve(mid, right));
  int lo = mid - 1, hi = mid;
  ll sum = A[lo] + A[hi], mn = min(A[lo], A[hi]);
  ret = max(ret, mn * sum);
  while (left < lo || hi < right - 1) {
    if (hi < right - 1 && (lo == left || A[lo - 1] < A[hi + 1])) {
      hi++;
      sum += A[hi];
      mn = min(mn, A[hi]);
      ret = max(ret, mn * sum);
    } else {
      lo--;
      sum += A[lo];
      mn = min(mn, A[lo]);
      ret = max(ret, mn * sum);
    }
  }
  return ret;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cout << solve(0, n) << "\n";
}