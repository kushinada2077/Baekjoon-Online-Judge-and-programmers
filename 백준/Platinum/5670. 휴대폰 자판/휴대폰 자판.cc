#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MX = 1000000 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
int nums[MX];
bool chk[MX];

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c - 'a'] == 0) {
      nxt[v][c - 'a'] = unused++;
      nums[v]++;
    }
    v = nxt[v][c - 'a'];
  }
  chk[v] = true;
}

int typing(string& s) {
  int v = nxt[ROOT][s[0] - 'a'];
  int ret = 1;
  for (int i = 1; i < s.size(); ++i) {
    char c = s[i];
    if (nums[v] > 1 || (chk[v] && nums[v])) ret++;
    v = nxt[v][c - 'a'];
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);
  int n;

  while (cin >> n) {
    unused = 2;
    for (int i = 0; i < MX; ++i) fill(nxt[i], nxt[i] + 26, 0);
    fill(nums, nums + MX, 0);
    fill(chk, chk + MX, 0);
    vector<string> word(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> word[i];
      insert(word[i]);
    }
    for (auto w : word) {
      int tmp = typing(w);
      sum += tmp;
    }
    cout << float(sum) / n << "\n";
  }
}