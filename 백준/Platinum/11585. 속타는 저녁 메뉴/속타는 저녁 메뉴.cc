#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string func(int a, int b) {
  int n = 2;

  while (n <= a) {
    if (a % n || b % n) n++;
    if (a % n == 0 && b % n == 0) {
      a /= n;
      b /= n;
    }
  }

  return to_string(a) + "/" + to_string(b);
}

vector<int> failure(const string& s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }

  return f;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt = 0;
  cin >> n;
  string s = "", t = "";
  string tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    s += tmp;
  }
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    t += tmp;
  }
  s += s;

  vector<int> f = failure(t);

  int j = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    while (j > 0 && s[i] != t[j]) j = f[j - 1];
    if (s[i] == t[j]) j++;
    if (j == t.size()) {
      cnt++;
      j = f[j - 1];
    }
  }

  cout << func(cnt, n);
}