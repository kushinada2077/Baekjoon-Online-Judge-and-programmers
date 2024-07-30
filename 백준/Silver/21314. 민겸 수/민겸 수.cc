#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

ll ten = 10;
string f1(const char first, const int n) {
  string ret = "";
  ret += first;
  for (int i = 0; i < n; ++i) ret += '0';
  return ret;
}
int main() {
  fastio;
  string s, num = "", ans = "";
  cin >> s;
  for (int i = 0; i < si(s); ++i) {
    char c = s[i];
    if (c == 'K') {
      ans += f1('5', si(num));
      num = "";
    } else {
      num += c;
    }
  }
  if (si(num))
    for (int i = 0; i < si(num); ++i) ans += '1';
  cout << ans << "\n";
  num = "";
  ans = "";
  for (int i = 0; i < si(s); ++i) {
    char c = s[i];
    if (c == 'K') {
      if (si(num)) ans += f1('1', si(num) - 1);
      ans += '5';
      num = "";
    } else {
      num += c;
    }
  }
  if (si(num)) ans += f1('1', si(num) - 1);
  cout << ans << "\n";
}