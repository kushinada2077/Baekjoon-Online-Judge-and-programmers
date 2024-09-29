#include <algorithm>
#include <iostream>
#include <queue>
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
  int n, k;
  cin >> n >> k;
  ll ans = n;
  vector<int> a = {0, 0, 6, 4, 2};

  if (n == 1 || n == 5) {
    ans += 8ll * k - 1;
  } else {
    ans += 8ll * (k / 2) + a[n] * (k % 2) - 1;
  }

  cout << ans << "\n";
}