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
  int a, b, n;
  cin >> a >> b >> n;
  vector<int> predef(n);
  for (auto& i : predef) cin >> i;
  int ans = abs(b - a);
  for (auto& pre : predef) {
    ans = min(ans, abs(pre - b) + 1);
  }
  cout << ans << "\n";
}