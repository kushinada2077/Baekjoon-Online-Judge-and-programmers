
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
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& i : a) cin >> i;

  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int sum = a[i] + a[j] + a[k];
        if (sum <= m && ans < sum) ans = sum;
      }
    }
  }
  cout << ans << "\n";
}