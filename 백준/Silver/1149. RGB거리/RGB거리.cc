#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, c[1005][3], d[1005][3];
int change(int k) { return (k + 1) % 3; }
// f(n, k) = 집 1~N개를 칠할 때 드는 비용, N번째는 k색
int f(int n, int k) {
  if (n == 1) return c[n][k];
  if (d[n][k]) return d[n][k];
  int result = f(n - 1, change(k)) + c[n][k];
  result = min(result, f(n - 1, change(change(k))) + c[n][k]);
  d[n][k] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) cin >> c[i][j];
  }

  cout << min(min(f(N, 0), f(N, 1)), f(N, 2));
}