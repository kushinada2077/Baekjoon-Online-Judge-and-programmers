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
    int mx = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      days.push_back(x);
    }

    for (int i = n - 1; i >= 0; i--) {
      if (mx < days[i]) mx = days[i];
      if (mx > days[i]) ans += mx - days[i];
    }

    cout << ans << "\n";
  }
}