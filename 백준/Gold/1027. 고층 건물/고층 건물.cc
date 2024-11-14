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

int n, arr[51];
int main() {
  fastio;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  for (int i = 0; i < n; ++i) {
    double mx = -INF;
    int cnt{};
    for (int j = i + 1; j < n; ++j) {
      double d = ((double)arr[j] - arr[i]) / (j - i);
      if (mx < d) {
        mx = d;
        cnt++;
      }
    }

    double mn = INF;

    for (int j = i - 1; j >= 0; --j) {
      double d = ((double)arr[j] - arr[i]) / (j - i);
      if (mn > d) {
        mn = d;
        cnt++;
      }
    }

    ans = max(ans, cnt);
  }

  cout << ans << "\n";
}