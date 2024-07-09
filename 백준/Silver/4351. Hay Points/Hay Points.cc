#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

vector<string> split(string& s, string& sep) {
  vector<string> ret;
  int pos = 0;
  int idx = 0;
  for (int i = 0; i < si(s); ++i) {
    if (s[i] == sep[idx]) idx++;
    else idx = 0;
    if (idx == si(sep)) {
      ret.pb(s.substr(pos, i - pos - si(sep) + 1));
      pos = i + 1;
      idx = 0;
    }
  }
  ret.pb(s.substr(pos));
  return ret;
}
int main() {
  fastio;
  int m, n, x;
  string s;
  map<string, int> v;
  cin >> m >> n;
  while (m--) {
    cin >> s >> x;
    v[s] = x;
  }
  while (n--) {
    int sum = 0;
    string sen = "";
    s = "";
    while (true) {
      cin >> s;
      if (s == ".") break;
      s += " ";
      sen += s;
    }
    string sep = " ";
    vector<string> res = split(sen, sep);
    for (auto word : res) sum += v[word];
    cout << sum << "\n";
  }
}