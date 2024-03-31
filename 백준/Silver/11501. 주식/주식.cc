#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    vector<int> days;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      days.push_back(x);
    }

    auto b = days.begin();
    auto e = days.end();
    auto mx = prev(e);
    for (auto i = prev(e); i >= b; i--) {
      if (*mx < *i) mx = i;
    }

    while (b != e) {
      while (b <= mx) {
        ans += *mx - *b;
        b++;
      }
      mx = prev(e);
      for (auto i = prev(e); i >= b; i--) {
        if (*mx < *i) mx = i;
      }
    }

    cout << ans << "\n";
  }
}