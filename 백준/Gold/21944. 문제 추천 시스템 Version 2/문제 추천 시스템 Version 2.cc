#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>

using namespace std;

struct Info {
  int l;
  int g;
};
unordered_map<int, Info> dif;

struct cmp {
  bool operator()(const int& p1, const int& p2) const {
    if (dif[p1].l == dif[p2].l) return p1 < p2;
    return dif[p1].l < dif[p2].l;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<int, cmp> s[101];
  while (n--) {
    int p, l, g;
    cin >> p >> l >> g;
    Info info = {l, g};
    dif[p] = info;
    s[g].insert(p);
  }
  int m;
  cin >> m;
  while (m--) {
    string op;
    cin >> op;

    if (op == "add") {
      int p, l, g;
      cin >> p >> l >> g;
      Info info = {l, g};
      dif[p] = info;
      s[g].insert(p);
    }

    else if (op == "recommend") {
      int g, x;
      cin >> g >> x;
      int opt;
      if (x == 1) {
        opt = *prev(s[g].end());
      } else {
        opt = *s[g].begin();
      }
      cout << opt << "\n";
    } else if (op == "recommend2") {
      int x;
      int p = 0;
      cin >> x;
      set<int, cmp> tmp;

      if (x == 1) {
        for (set<int, cmp>& c : s) {
          if (!c.empty()) {
            int num = *prev(c.end());
            tmp.insert(num);
          }
        }
        p = *prev(tmp.end());
      } else {
        for (set<int, cmp>& c : s) {
          if (!c.empty()) {
            int num = *c.begin();
            tmp.insert(num);
          }
        }
        p = *tmp.begin();
      }

      cout << p << "\n";
    } else if (op == "recommend3") {
      int x, l;
      cin >> x >> l;
      int p = -1;
      set<int, cmp> tmp;
      if (x == 1) {
        dif[0] = {l, 0};
        for (set<int, cmp>& c : s) {
          auto flag = c.lower_bound(0);
          if (flag != c.end()) {
            tmp.insert(*flag);
          }
        }

        if (!tmp.empty()) {
          p = *tmp.begin();
        }
        dif.erase(0);
      } else {
        dif[100001] = {l - 1, 0};
        for (set<int, cmp>& c : s) {
          auto flag = c.upper_bound(100001);
          if (flag != c.begin()) {
            tmp.insert(*prev(flag));
          }
        }

        if (!tmp.empty()) {
          p = *prev(tmp.end());
        }
        dif.erase(100001);
      }

      cout << p << "\n";
    } else {
      int p, g;
      cin >> p;
      g = dif[p].g;
      s[g].erase(p);
      dif.erase(p);
    }
  }
}