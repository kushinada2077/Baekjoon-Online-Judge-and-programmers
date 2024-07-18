
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

int cnt = 0;
bool f(const string& s, int l, int r) {
  cnt++;
  if (r - l < 2) return true;
  if (s[l] != s[r - 1]) return false;
  return f(s, l + 1, r - 1);
}
int main() {
  fastio;
  int t;
  cin >> t;
  string s;
  while (t--) {
    cnt = 0;
    cin >> s;
    cout << f(s, 0, si(s)) << " " << cnt << "\n";
  }
}