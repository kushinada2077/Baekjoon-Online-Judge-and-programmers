#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, k;
int coin[101];
int d[100005];

int f(int k) {
  if (k <= 0) return INF;
  if (d[k] != -1) return d[k];

  int result = INF;
  for (int i = 0; i < n; ++i) result = min(result, f(k - coin[i]) + 1);
  d[k] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  fill(d, d + 100005, -1);
  for (int i = 0; i < n; ++i) {
    cin >> coin[i];
    d[coin[i]] = 1;
  }
  int ans = f(k);
  if (ans == INF) ans = -1;
  cout << ans;
}