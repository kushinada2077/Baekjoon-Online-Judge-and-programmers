
#include <algorithm>
#include <bitset>
#include <iostream>
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
  int n, l = 1, r, o, h, ans = 0;
  cin >> n >> r >> o;
  while (o--) {
    cin >> h;
    if (l <= h && h <= r) continue;
    int rh = abs(r - h), lh = abs(l - h);
    if (rh > lh) {
      l = h;
      r -= lh;
      ans += lh;
    } else {
      r = h;
      l += rh;
      ans += rh;
    }
  }
  cout << ans << "\n";
}