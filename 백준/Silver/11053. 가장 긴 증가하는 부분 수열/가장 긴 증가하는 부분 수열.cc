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

// lis(start) = A[start]에서 시작하는 부분 증가 수열 중 최대 길이

int n, A[1001], dp[1002];
int lis(int start) {
  int& ret = dp[start + 1];
  if (ret != -1) return ret;
  ret = 1;
  for (int next = start + 1; next < n; ++next) {
    if (A[start] < A[next]) ret = max(ret, lis(next) + 1);
  }

  return ret;
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  fill(dp, dp + 1002, -1);
  cout << lis(-1) - 1 << "\n";
}