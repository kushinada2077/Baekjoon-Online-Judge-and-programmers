#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MX = 100000 * 10 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
int num[MX];

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c] == 0) nxt[v][c] = unused++;
    v = nxt[v][c];
  }
  num[v]++;
}

string prefix(string& s) {
  int v = ROOT;
  string cur = "";
  for (auto c : s) {
    if (nxt[v][c] == 0) return cur += c;
    cur += c;
    v = nxt[v][c];
  }
  if (num[v] > 0)
    return s + to_string(num[v] + 1);
  else
    return s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n;

  while (n--) {
    cin >> s;
    string nickname = prefix(s);
    cout << nickname << "\n";

    insert(s);
  }
}