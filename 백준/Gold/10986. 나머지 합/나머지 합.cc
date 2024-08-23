#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
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
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, m, x;
  ll ans = 0;
  cin >> n >> m;
  vector<int> cnt(1000, 0);
  cnt[0] = 1;
  ll tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    tot = (tot + x) % m;
    ans += cnt[tot];
    cnt[tot]++;
  }

  cout << ans << "\n";
}