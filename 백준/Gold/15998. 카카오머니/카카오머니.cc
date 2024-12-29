#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

vector<pair<i64, i64>> query;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  i64 M = 0, bal = 0, a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a > 0) {
      if (bal + a != b) {
        M = -1;
        break;
      }
      bal = b;
    }

    else {
      a = -a;
      if (bal < a) {
        query.push_back({a, b});
        M = gcd(b + a - bal, M);
      } else {
        if (bal - a != b) {
          M = -1;
          break;
        }
      }
      bal = b;
    }
  }

  if (M == 0) M = 1;

  bal = 0;
  for (auto [a, b] : query) {
    if (M <= b) {
      M = -1;
      break;
    }

    bal = b;
  }

  cout << M << "\n";
}