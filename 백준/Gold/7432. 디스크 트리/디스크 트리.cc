#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
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

const int ROOT = 1, MX = 505 * 80;
int unused = 2;
vector<map<string, int>> nxt(MX);
vector<bool> chk(MX);
int n;
string s;
vector<string> split(const string& s, const string& sep) {
  vector<string> ret;
  int pos = 0;
  while (pos < si(s)) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = si(s);
    if (nxt_pos - pos > 0) ret.pb(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + si(sep);
  }
  return ret;
}
void insert(const string& s) {
  vector<string> sp = split(s, "\\");
  int cur = ROOT;
  for (auto& p : sp) {
    if (nxt[cur][p] == 0) nxt[cur][p] = unused++;
    cur = nxt[cur][p];
  }
  chk[cur] = true;
}
void traverse(int cur, int dep) {
  for (auto [p, n] : nxt[cur]) {
    if (n == 0) continue;
    for (int i = 0; i < dep; ++i) cout << " ";
    cout << p << "\n";
    traverse(n, dep + 1);
  }
}
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    insert(s);
  }
  traverse(ROOT, 0);
}