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

vector<pair<int, int>> a[11];
bool used[11];
int x, tot = 0, ans;

void f(int n) {
  if (n == 11) {
    ans = max(ans, tot);
    return;
  }

  for (auto [ab, pos] : a[n]) {
    if (used[pos]) continue;
    used[pos] = 1;
    tot += ab;
    f(n + 1);
    used[pos] = 0;
    tot -= ab;
  }
}

int main() {
  fastio;
  int c;
  cin >> c;

  while (c--) {
    for (int i = 0; i < 11; ++i) {
      a[i].clear();
      used[i] = 0;
    }
    ans = -1;
    for (int i = 0; i < 11; ++i) {
      for (int j = 0; j < 11; ++j) {
        cin >> x;
        if (x == 0) continue;
        a[i].pb({x, j});
      }
    }
    f(0);
    cout << ans << "\n";
  }
}