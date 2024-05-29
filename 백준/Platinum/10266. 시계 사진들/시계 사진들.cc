#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, mod = 360000;
vector<int> s;
vector<int> t;

int diff(int a, int b) { return ((a + mod) - b) % mod; }
vector<int> failure(vector<int>& s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }

  return f;
}

bool kmp(vector<int>& s, vector<int>& t, vector<int>& f) {
  int j = 0;
  for (int i = 0; i < s.size(); ++i) {
    while (j > 0 && s[i] != t[j]) j = f[j - 1];
    if (s[i] == t[j]) j++;
    if (j == t.size()) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    s.push_back(tmp);
  }
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    t.push_back(tmp);
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < n - 1; ++i) s.push_back(s[i]);

  vector<int> a;
  vector<int> b;
  for (int i = 0; i < (int)s.size() - 1; ++i) a.push_back(diff(s[i + 1], s[i]));
  for (int i = 0; i < (int)t.size() - 1; ++i) b.push_back(diff(t[i + 1], t[i]));
  vector<int> f = failure(b);
  if (kmp(a, b, f))
    cout << "possible";
  else
    cout << "impossible";
}