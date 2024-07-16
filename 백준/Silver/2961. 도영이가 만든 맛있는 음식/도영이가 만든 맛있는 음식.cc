#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_set>
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

int n, x, y;
int ans = 0x3f3f3f3f;
vector<pair<int, int>> a;
void f(int N, int s, int b) {
  if (n == N) {
    if (b != 0) ans = min(ans, abs(s - b));
    return;
  }

  f(N + 1, s, b);
  f(N + 1, s * a[N].X, b + a[N].Y);
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    a.pb({x, y});
  }
  f(0, 1, 0);
  cout << ans << "\n";
}