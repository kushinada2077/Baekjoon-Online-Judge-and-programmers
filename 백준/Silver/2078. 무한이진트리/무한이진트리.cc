#include <algorithm>
#include <iostream>
#include <set>
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
  int x, y, l, r;
  cin >> x >> y;
  l = r = 0;
  while (x != 1 && y != 1) {
    if (x < y) {
      r += y / x;
      y %= x;
    } else {
      l += x / y;
      x %= y;
    }
  }

  if (x == 1) r += y - 1;
  else l += x - 1;
  cout << l << " " << r << "\n";
}