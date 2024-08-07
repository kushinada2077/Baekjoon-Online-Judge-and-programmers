#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 5;
int nxt[MX][26];
int c2i(char c) { return c - 'a'; }
void insert(const string& s) {
  int cur = ROOT;
  for (auto& c : s) {
    if (nxt[cur][c2i(c)] == 0) nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
}
bool chk(const string& s) {
  int cur = ROOT;
  for (auto& c : s) {
    if (nxt[cur][c2i(c)] == 0) return false;
    cur = nxt[cur][c2i(c)];
  }
  return true;
}
int main() {
  fastio;
  int n, m, ans = 0;
  string s;
  cin >> n >> m;
  FOR(n) {
    cin >> s;
    insert(s);
  }
  FOR(m) {
    cin >> s;
    ans += chk(s);
  }
  cout << ans << "\n";
}