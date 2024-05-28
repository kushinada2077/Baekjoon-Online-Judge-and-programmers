#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
  string s;
  while (true) {
    cin >> s;
    if (s == ".") break;
    auto f = failure(s);
    int len = s.size() - f[s.size() - 1];
    if (s.size() % len)
      cout << "1\n";
    else
      cout << s.size() / len << "\n";
  }
  return 0;
}