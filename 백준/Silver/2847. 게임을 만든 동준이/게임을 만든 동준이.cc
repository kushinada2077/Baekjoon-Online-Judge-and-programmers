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
#include <unordered_set>
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;

  int ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] >= a[i + 1]) {
      ans += a[i] - a[i + 1] + 1;
      a[i] = a[i + 1] - 1;
    }
  }
  cout << ans << "\n";
}