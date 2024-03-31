#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int N, Q, t, curr = 1;
set<int> attr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> t;
    if (t) attr.insert(i);
  }
  while (Q--) {
    cin >> t;
    if (t == 1) {
      cin >> t;
      if (attr.find(t) != attr.end())
        attr.erase(t);
      else
        attr.insert(t);

    } else if (t == 2) {
      cin >> t;
      curr = (curr - 1 + t) % N + 1;
    } else if (t == 3) {
      if (attr.empty()) {
        cout << "-1\n";
      } else {
        auto dest = attr.lower_bound(curr);
        if (dest == attr.end())
          cout << N - curr + *attr.begin() << "\n";
        else
          cout << *dest - curr << "\n";
      }
    }
  }
}