#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int MX = 1000000 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
int nums[MX];
bool chk[MX];
string s;

int c2i(char c) { return c - 'a'; }
void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c2i(c)] == 0) {
      nxt[v][c2i(c)] = unused++;
      nums[v]++;
    }
    v = nxt[v][c2i(c)];
  }
  chk[v] = true;
}
int cal(string& s) {
  int sum = 1;
  int v = nxt[ROOT][c2i(s[0])];
  for (int i = 1; i < s.size(); ++i) {
    auto c = s[i];
    if (nums[v] > 1 || (chk[v] && nums[v])) sum++;
    v = nxt[v][c2i(c)];
  }
  return sum;
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
    int sum = 0;
    vector<string> word(n);
    for (int i = 0; i < n; ++i) {
      cin >> word[i];
      insert(word[i]);
    }
    for (auto w : word) {
      sum += cal(w);
    }
    cout << float(sum) / n << "\n";
  }
}