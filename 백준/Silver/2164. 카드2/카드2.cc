#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
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
  int n, x = 1;
  cin >> n;
  while (n >= (x << 1)) x <<= 1;
  if (n == x) cout << n;
  else cout << 2 * (n - x) << "\n";
}