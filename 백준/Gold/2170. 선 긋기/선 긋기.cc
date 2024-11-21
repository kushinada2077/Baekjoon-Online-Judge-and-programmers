#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n;
vector<P> llist;
int main() {
  fastio;
  cin >> n;
  for (int l, r, i{}; i < n; ++i) {
    cin >> l >> r;
    llist.pb(P(l, -r));
  }

  sort(all(llist));

  auto [curL, curR] = llist[0];
  curR *= -1;
  ll ans = curR - curL;

  for (int i = 1; i < n; ++i) {
    auto [l, r] = llist[i];
    r *= -1;

    if (curR < l) {
      curL = l;
      curR = r;
      ans += 1ll * r - l;
    } else if (curR < r) {
      ans += 1ll * r - curR;
      curR = r;
    }
  }
  cout << ans << "\n";
}