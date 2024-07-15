#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

vector<string> split(const string& s, const string& sep) {
  int pos = 0;
  vector<string> ret;
  while (pos < si(s)) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = s.size();
    if (nxt_pos - pos > 0) ret.pb(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + si(sep);
  }
  return ret;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  fastio;
  string s;
  cin >> s;
  vector<string> a = split(s, ":");
  int b = stoi(a[0]), c = stoi(a[1]);
  int g = gcd(b, c);
  cout << b / g << ":" << c / g << "\n";
}