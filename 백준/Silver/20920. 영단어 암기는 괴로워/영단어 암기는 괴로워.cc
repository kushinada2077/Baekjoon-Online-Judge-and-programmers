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

map<string, int> cnt;
int main() {
  fastio;
  int n, m;
  string s;
  vector<string> ans;
  cin >> n >> m;
  while (n--) {
    cin >> s;
    if (si(s) < m) continue;
    ans.pb(s);
    cnt[s]++;
  }
  sort(all(ans), [](string& a, string& b) {
    if (cnt.at(a) != cnt.at(b)) return cnt.at(a) > cnt.at(b);
    else if (si(a) != si(b)) return si(a) > si(b);
    else return a < b;
  });
  ans.erase(unique(all(ans)), ans.end());
  for (auto s : ans) cout << s << "\n";
}