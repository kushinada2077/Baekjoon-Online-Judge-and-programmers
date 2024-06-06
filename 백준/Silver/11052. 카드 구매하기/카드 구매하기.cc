#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int N;
int d[1001][1001];
int card[1001];
const int IMPOSSIBLE = -0x3f3f3f3f;
// n개를 k번째 팩부터 샀을 때 최댓값
int f(int n, int k) {
  if (k == N) return n ? IMPOSSIBLE : 0;
  if (d[n][k] != -1) return d[n][k];

  int result = f(n, k + 1);
  if (n >= k + 1) result = max(result, f(n - k - 1, k) + card[k]);
  d[n][k] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < 1001; ++i) fill(d[i], d[i] + 1001, -1);
  for (int i = 0; i < N; ++i) cin >> card[i];
  cout << f(N, 0);
}