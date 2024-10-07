#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  string s;
  deque<char> dq;
  int ans = -1;
  cin >> s;
  int st = 0, en = si(s) - 1;

  while (st < en) {
    if (s[st] != s[en]) {
      cout << si(s) << "\n";
      return 0;
    }
    st++;
    en--;
  }
  st = 0;
  en = si(s) - 2;
  while (st < en) {
    if (s[st] != s[en]) {
      cout << si(s) - 1 << "\n";
      return 0;
    }
    st++;
    en--;
  }
  if (si(s) == 1 || s[0] == s[si(s) - 2]) cout << -1 << "\n";
  else cout << si(s) - 2 << "\n";
}