#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int main() {
  fastio;
  string s;
  char c;
  int a, b;
  cin >> s;
  vector<vector<int>> r(26, vector<int>(1, 0));
  for (int i = 0; i < si(s); ++i) {
    int idx = s[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      r[j].pb(r[j].back());
      if (j == idx) r[j].back()++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> c >> a >> b;
    c -= 'a';
    cout << r[c][b + 1] - r[c][a] << "\n";
  }
}