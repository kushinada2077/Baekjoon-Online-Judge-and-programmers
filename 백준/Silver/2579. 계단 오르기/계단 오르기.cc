#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int IM = -100;
int N, stair[305];
int d[305][3];
// f(n, k) = n번째 계단까지 올랐을 때 k개의 계단을 연속으로 밟은 상태에서 최댓값
int f(int n, int k) {
  if (n == 0) return 0;
  if (n == 1) return k == 1 ? stair[1] : IM;
  if (d[n][k] != IM) return d[n][k];

  int result = IM;
  if (k == 1)
    result = max(max(result, f(n - 2, 2) + stair[n]), f(n - 2, 1) + stair[n]);
  if (k == 2) result = max(result, f(n - 1, 1) + stair[n]);
  d[n][k] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> stair[i];
    fill(d[i], d[i] + 3, IM);
  }
  int ans = max(f(N, 1), f(N, 2));
  cout << ans;
}