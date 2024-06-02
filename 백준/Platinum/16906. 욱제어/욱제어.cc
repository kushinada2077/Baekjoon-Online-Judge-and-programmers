#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MX = 1000 * 1000 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][2];
bool chk[MX];
bool flag;
string w;

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c - '0'] == 0) nxt[v][c - '0'] = unused++;
    v = nxt[v][c - '0'];
  }
  chk[v] = true;
}

void dfs(int v, int c_len, int t_len, string& s) {
  if (chk[v] || flag || c_len > t_len) return;
  if (c_len == t_len && !nxt[v][0] && !nxt[v][1]) {
    w = s;
    flag = true;
    return;
  }
  dfs(nxt[v][0], c_len + 1, t_len, s += "0");
  s.pop_back();
  if (flag) return;
  dfs(nxt[v][1], c_len + 1, t_len, s += "1");
  s.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n);
  vector<string> word;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (auto len : l) {
    flag = false;
    w = "";
    string tmp = "";
    dfs(ROOT, 0, len, tmp);
    if (w == "") {
      cout << "-1";
      exit(0);
    }
    insert(w);
    word.push_back(w);
  }

  cout << "1\n";
  for (auto w : word) cout << w << "\n";
}