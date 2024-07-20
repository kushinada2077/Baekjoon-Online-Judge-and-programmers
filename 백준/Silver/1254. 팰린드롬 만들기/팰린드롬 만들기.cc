#include <algorithm>
#include <iostream>
#include <queue>
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

bool is_pal(const string& s, int l, int r) {
  if (l >= r) return true;
  if (s[l] != s[r]) return false;
  return true & is_pal(s, l + 1, r - 1);
}
int main() {
  fastio;
  string s;
  cin >> s;
  for (int i = 0; i < si(s); ++i) {
    string add = s.substr(0, i);
    reverse(all(add));
    string tmp = s + add;
    if (is_pal(tmp, 0, si(s) + i - 1)) {
      cout << si(s) + i << "\n";
      return 0;
    }
  }
}