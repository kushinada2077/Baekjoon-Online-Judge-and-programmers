#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  int a[3], b[2];
  for (int i = 0; i < 3; ++i) cin >> a[i];
  for (int i = 0; i < 2; ++i) cin >> b[i];
  int ans = 1420132;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) ans = min(ans, a[i] + b[j]);
  }
  cout << ans - 50 << "\n";
}