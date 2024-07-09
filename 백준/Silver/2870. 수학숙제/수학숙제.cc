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

bool is_num(char& c) { return '0' <= c && c <= '9'; }
vector<string> find_num(string& s) {
  vector<string> ret;
  for (int i = 0; i < si(s); ++i) {
    string tmp = "";
    while (i < si(s) && is_num(s[i])) tmp += s[i++];
    if (tmp != "") {
      int idx = 0;
      while (idx < si(tmp) - 1 && tmp[idx] == '0') idx++;
      ret.pb(tmp.substr(idx));
      i--;
    }
  }
  return ret;
}
int main() {
  fastio;
  vector<string> ans;
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    vector<string> a = find_num(s);
    for (auto v : a) ans.pb(v);
  }
  sort(all(ans), [](string& a, string& b) {
    if (si(a) != si(b)) return si(a) < si(b);
    for (int i = 0; i < si(a); ++i) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return true;
  });
  for (auto v : ans) cout << v << "\n";
}