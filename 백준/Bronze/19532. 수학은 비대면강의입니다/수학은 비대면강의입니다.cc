#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int main() {
  fastio;
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ad = a - d, be = b - e, cf = c - f;

  for (int x = -999; x < 1000; ++x) {
    for (int y = -999; y < 1000; ++y) {
      if (ad * x + be * y == cf && a * x + b * y == c && d * x + e * y == f) {
        cout << x << " " << y << "\n";
        return 0;
      }
    }
  }
}