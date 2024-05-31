#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
int nxt[MX][26];

int c2i(char c) { return c - 'a'; }
void insert(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    if (!nxt[cur][c2i(c)]) nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
}
bool find(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    if (!nxt[cur][c2i(c)]) return false;
    cur = nxt[cur][c2i(c)];
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 0;
  string s;
  cin >> n >> m;
  while (n--) {
    cin >> s;
    insert(s);
  }
  while (m--) {
    cin >> s;
    if (find(s)) cnt++;
  }
  cout << cnt;
}