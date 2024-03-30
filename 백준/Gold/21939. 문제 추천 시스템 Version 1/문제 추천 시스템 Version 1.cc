#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<int, int> dif;

struct cmp {
  bool operator()(const int& p1, const int& p2) const {
    if (dif[p1] == dif[p2]) return p1 < p2;
    return dif[p1] < dif[p2];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<int, cmp> s;
  while (n--) {
    int p, l;
    cin >> p >> l;
    dif[p] = l;
    s.insert(p);
  }
  int m;
  cin >> m;
  while (m--) {
    string op;
    cin >> op;

    if (op == "add") {
      int p, l;
      cin >> p >> l;
      dif[p] = l;
      s.insert(p);
    }

    else if (op == "recommend") {
      int x;
      cin >> x;
      int opt;
      if (x == 1) {
        opt = *prev(s.end());
      } else {
        opt = *s.begin();
      }
      cout << opt << "\n";
    } else {
      int p;
      cin >> p;
      s.erase(p);
      dif.erase(p);
    }
  }
}