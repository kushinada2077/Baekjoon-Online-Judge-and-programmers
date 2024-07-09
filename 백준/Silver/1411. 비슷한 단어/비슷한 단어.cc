#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int main() {
  fastio;
  int n, ans = 0;
  cin >> n;
  vector<string> a(n);
  for_in(n) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      bool flag = true;
      vector<char> cv(26, 0);
      vector<char> rcv(26, 0);
      for (int k = 0; k < si(a[i]); ++k) {
        char c1 = a[i][k], c2 = a[j][k];
        if ((cv[c2 - 'a'] != 0 && cv[c2 - 'a'] != c1) || rcv[c1 - 'a'] != 0 && rcv[c1 - 'a'] != c2) {
          flag = false;
          break;
        } else if (cv[c2 - 'a'] == 0) {
          cv[c2 - 'a'] = c1;
          rcv[c1 - 'a'] = c2;
        }
      }
      if (flag) ans++;
    }
  }
  cout << ans << "\n";
}