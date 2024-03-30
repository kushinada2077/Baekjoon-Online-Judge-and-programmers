#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    multiset<int> s;
    int k;
    cin >> k;
    while (k--) {
      string op;
      int n;
      cin >> op >> n;

      if (op == "I") {
        s.insert(n);
      } else {
        if (s.empty()) continue;
        if (n == 1) {
          s.erase(prev(s.end()));
        } else {
          s.erase(s.begin());
        }
      }
    }
    if (s.size()) {
      auto mn = *s.begin();
      auto mx = *prev(s.end());
      cout << mx << " " << mn << "\n";
    } else {
      cout << "EMPTY\n";
    }
  }
}