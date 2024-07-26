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
  int r = 0, c = 0, mx = -1, x;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> x;
      if (x > mx) {
        mx = x;
        r = i;
        c = j;
      }
    }
  }
  cout << mx << "\n";
  cout << r + 1 << " " << c + 1 << "\n";
}