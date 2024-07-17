#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

bool comp(const string& a, const string& b) {
  int l = si(a);
  for (int st = 0; st < l; ++st) {
    bool f = true;
    for (int i = 0; i < l; ++i) {
      if (a[i] != b[(st + i) % l]) {
        f = false;
        break;
      }
    }
    if (f) return true;
  }
  string rev = "";
  for (auto& c : b) rev += "3412"[c - '1'];
  reverse(all(rev));

  for (int st = 0; st < l; ++st) {
    bool f = true;
    for (int i = 0; i < l; ++i) {
      if (a[i] != rev[(st + i) % l]) {
        f = false;
        break;
      }
    }
    if (f) return true;
  }
  return false;
}
int main() {
  fastio;
  int n, m;
  vector<string> ans;
  cin >> n;
  string std = "";
  for_in(n) {
    char c;
    cin >> c;
    std += c;
  }
  cin >> m;
  while (m--) {
    string op = "";
    for_in(n) {
      char c;
      cin >> c;
      op += c;
    }
    if (comp(std, op)) ans.pb(op);
  }

  cout << si(ans) << "\n";
  for (auto& s : ans) {
    for (auto& c : s) cout << c << " ";
    cout << "\n";
  }
}