#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int MX = 2000 * 20 + 5;
const int ROOT = 1;
const string chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.";
int unused = 2;
int nxt[MX][63];
int chk[MX];
int cnt;
char cc[MX];
string s;
unordered_map<char, int> c2i;
unordered_set<int> po;

void setup() {
  for (int i = 0; i < chars.size(); ++i) c2i[chars[i]] = i;
}

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c2i[c]] == 0) {
      nxt[v][c2i[c]] = unused++;
      cc[unused - 1] = c;
    }
    v = nxt[v][c2i[c]];
  }
  chk[v] = 1;
}

void find(string& s) {
  int v = ROOT;
  vector<int> r;
  for (auto c : s) {
    if (nxt[v][c2i[c]] == 0) {
      po.insert(unused);
      nxt[v][c2i[c]] = unused++;
      return;
    }
    if (po.find(nxt[v][c2i[c]]) != po.end()) return;
    if (chk[v]) r.push_back(nxt[v][c2i[c]]);
    v = nxt[v][c2i[c]];
  }

  for (auto c : chars) {
    if (nxt[v][c2i[c]]) {
      cnt++;
      return;
    }
  }
  if (r.size())
    po.insert(r[r.size() - 1]);
  else
    po.insert(v);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setup();
  int t, n;
  cin >> t;

  while (t--) {
    cnt = 0;
    for (int i = 0; i < MX; ++i) fill(nxt[i], nxt[i] + 63, 0);
    fill(chk, chk + MX, 0);
    po.clear();
    unused = 2;
    vector<string> file;
    cin >> n;
    while (n--) {
      cin >> s;
      file.push_back(s);
    }
    cin >> n;
    if (n == 0) {
      cout << "1\n";
      continue;
    }
    while (n--) {
      cin >> s;
      insert(s);
    }

    for (auto f : file) {
      find(f);
      // cout << f << " || " << po.size() + cnt << "\n";
    }
    cout << po.size() + cnt << "\n";
  }
}