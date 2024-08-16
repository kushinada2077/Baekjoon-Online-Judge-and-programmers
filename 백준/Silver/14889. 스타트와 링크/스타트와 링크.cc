#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, ans = 0x3f3f3f3f;
vector<vector<int>> a(20, vector<int>(20, 0));
vector<bool> mark(20, false);
void f(int k, int N) {
  if (N == n / 2) {
    int sum[2] = {0, 0};
    vector<int> arr[2];
    for (int i = 0; i < n; ++i) arr[mark[i]].pb(i);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        for (int l = j + 1; l < n / 2; ++l) {
          sum[i] += a[arr[i][j]][arr[i][l]] + a[arr[i][l]][arr[i][j]];
        }
      }
    }
    ans = min(ans, abs(sum[0] - sum[1]));
    return;
  }

  for (int i = k; i < n; ++i) {
    mark[i] = true;
    f(i + 1, N + 1);
    mark[i] = false;
  }
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j];
  }
  f(0, 0);
  cout << ans << "\n";
}