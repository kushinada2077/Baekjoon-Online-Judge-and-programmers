#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string _map =
    "\\!#$%&'()-0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`"
    "abcdefghijklmnopqrstuvwxyz{}~";
const int MX = 500 * 80 + 5;
const int ROOT = 1;
int unused = ROOT + 1;
int nxt[MX][150];
bool chk[MX];
unordered_map<char, int> _c2i;
char i2c(int i) { return _map[i]; }
int c2i(char c) { return _c2i[c]; }

void setup() {
  for (int i = 0; i < _map.size(); ++i) _c2i[_map[i]] = i;
}

void insert(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    int i = c2i(c);
    if (nxt[cur][i] == 0) nxt[cur][i] = unused++;
    cur = nxt[cur][i];
    if (c == '\\') chk[cur] = true;
  }
  chk[cur] = true;
}

void dfs(int cur, vector<char>& s, int space) {
  for (int i = 0; i < _map.size(); ++i) {
    if (nxt[cur][i] == 0) continue;
    char c = i2c(i);

    if (chk[nxt[cur][i]]) {
      for (int j = 0; j < space; ++j) cout << " ";
      for (auto c : s) cout << c;
      cout << "\n";
      vector<char> n;
      dfs(nxt[cur][i], n, space + 1);
    } else {
      s.push_back(c);
      dfs(nxt[cur][i], s, space);
      s.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("/Users/leedongha/Downloads/PS/input.txt", "r", stdin);
  setup();
  int n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    s += "\\";
    insert(s);
  }

  vector<char> a;
  dfs(ROOT, a, 0);
}