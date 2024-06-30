#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
  fastio;
  int n;
  ll ans1 = 1e9 + 1, ans2 = 1e9 + 1;
  cin >> n;
  vector<ll> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(s.begin(), s.end(), -s[i]) - s.begin();
    if (i != idx && idx < n && abs(ans1 + ans2) > abs(s[idx] + s[i])) {
      ans1 = s[i];
      ans2 = s[idx];
    } else if (i != idx - 1 && idx - 1 > -1 && abs(ans1 + ans2) > abs(s[idx - 1] + s[i])) {
      ans1 = s[i];
      ans2 = s[idx - 1];
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  cout << ans1 << " " << ans2;
}