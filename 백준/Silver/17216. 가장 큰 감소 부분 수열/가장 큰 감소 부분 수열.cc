#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n), dp(n);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n; ++i) {
    dp[i] = a[i];
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[i] && dp[j] + a[i] > dp[i]) {
        dp[i] = dp[j] + a[i];
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}