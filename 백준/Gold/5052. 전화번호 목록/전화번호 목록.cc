#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 10 + 5;
int nxt[MX][10];
bool chk[MX];

void setup() {
  unused = 2;
  fill(chk, chk + MX, 0);
  for (int i = 0; i < MX; ++i) fill(nxt[i], nxt[i] + 10, 0);
}

int c2i(char c) { return c - '0'; }
bool insert(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    if (!nxt[cur][c2i(c)]) nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
    if (chk[cur]) return false;
  }
  if (unused - 1 != cur) return false;
  chk[cur] = true;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  string s;
  cin >> t;

  while (t--) {
    setup();
    cin >> n;
    bool flag = true;
    while (n--) {
      cin >> s;
      if (!insert(s)) {
        flag = false;
      }
    }

    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}