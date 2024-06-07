#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int ROOT = 1;
const int MX = 2000 * 20 + 5;
unordered_set<int> x;
vector<pair<char, int>> nxt[MX];
int t, n, cnt;
int unused = 2;
string s;

int find(char c, int v) {
  for (auto [d, nv] : nxt[v]) {
    if (c == d) return nv;
  }
  return -1;
}

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    int nv = find(c, v);
    if (nv == -1) {
      nv = unused;
      nxt[v].push_back({c, unused++});
    }
    v = nv;
  }
}

void locate(string& s) {
  int v = ROOT;
  for (auto c : s) {
    int nv = find(c, v);
    if (nv == -1) {
      x.insert(unused);
      nxt[v].push_back({c, unused++});
      return;
    }
    if (x.find(nv) != x.end()) return;
    v = nv;
  }

  cnt++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    unused = 2;
    cnt = 0;
    for (int i = 0; i < MX; ++i) nxt[i].clear();
    x.clear();
    vector<string> file(n);
    for (int i = 0; i < n; ++i) cin >> file[i];
    cin >> n;
    if (n == 0) {
      cout << "1\n";
      continue;
    }
    for (int i = 0; i < n; ++i) {
      cin >> s;
      insert(s);
    }
    for (auto f : file) locate(f);
    cout << x.size() + cnt << "\n";
  }
}