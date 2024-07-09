#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int n;
bool chk(vector<vector<int>>& a) {
  for_in(n) {
    for_in(j, n - 1) {
      if (a[i][j] >= a[i][j + 1]) return false;
      if (a[j][i] >= a[j + 1][i]) return false;
    }
  }
  return true;
}
int main() {
  fastio;
  int T;
  char x;
  cin >> T;
  for_in(t, T) {
    cin >> n;
    vector<vector<int>> a;
    for_in(2 * n - 1) {
      vector<int> tmp(n);
      for_in(j, n) cin >> tmp[j];
      a.pb(tmp);
    }
    vector<int> aa;
    for_in(2 * n - 1) aa.pb(i < n ? 0 : 1);
    do {
      vector<vector<int>> rc;
      for_in(2 * n - 1) {
        if (aa[i] == 0) rc.pb(a[i]);
      }
      sort(all(rc));
      for_in(2 * n - 1) {
        if (aa[i]) rc.pb(a[i]);
      }
      if (!chk(rc)) continue;
      vector<vector<int>> c;
      for_in(n) {
        vector<int> tmp;
        for_in(j, n) { tmp.pb(rc[j][i]); }
        c.pb(tmp);
      }
      vector<vector<int>> tmp;
      for_in(n) {
        bool flag = false;
        for_in(j, n - 1) {
          if (c[i] == rc[j + n]) flag = true;
        }
        if (!flag) tmp.pb(c[i]);
      }
      if (si(tmp) == 1) {
        cout << "Case #" << t + 1 << ": ";
        for (auto a : tmp[0]) cout << a << " ";
        cout << "\n";
        break;
      }
    } while (next_permutation(all(aa)));
  }
}