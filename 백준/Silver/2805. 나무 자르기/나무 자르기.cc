#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, m;
bool f(int x, vector<int>& a) {
  ll tot = 0;
  for (auto& i : a) {
    tot += 1ll * (i > x ? i - x : 0);
    if (tot >= m) return true;
  }
  return tot >= m;
}
int main() {
  fastio;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  int lo = 0, hi = 1e9 + 5;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid, a)) lo = mid;
    else hi = mid;
  }
  cout << lo << "\n";
}