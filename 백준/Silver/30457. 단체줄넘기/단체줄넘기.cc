
#include <algorithm>
#include <iostream>
#include <set>
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  vector<int> b;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == a[i]) b.pb(a[i]);
  }
  auto a_st = unique(all(a));
  auto b_st = unique(all(b));
  int ans = (a_st - a.begin()) + (b_st - b.begin());
  cout << ans << "\n";
}