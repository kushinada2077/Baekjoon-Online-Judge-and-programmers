#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int N, Q, x, i, q;
long long loca = 1;
set<int> attr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for (i = 0; i < N; i++) {
    cin >> x;
    if (x) {
      attr.insert(i + 1);
      attr.insert(i + 1 + N);
    }
  }
  while (Q--) {
    cin >> q;
    if (q == 1) {
      cin >> i;
      if (attr.find(i) != attr.end()) {
        attr.erase(i);
        attr.erase(i + N);
      } else {
        attr.insert(i);
        attr.insert(i + N);
      }
    } else if (q == 2) {
      cin >> x;
      loca = (loca - 1 + x) % N + 1;
    } else if (q == 3) {
      if (attr.find(loca) != attr.end()) {
        cout << "0\n";
        continue;
      }
      auto dest = attr.upper_bound(loca);
      if (dest == attr.end())
        cout << "-1\n";
      else
        cout << (*dest - loca) << "\n";
    }
  }
}