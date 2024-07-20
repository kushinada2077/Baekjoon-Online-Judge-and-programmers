#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
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

int main() {
  fastio;
  cout << fixed;
  cout.precision(4);
  vector<string> tree;
  unordered_map<string, int> cnt;
  string ip;
  while (getline(cin, ip)) {
    tree.pb(ip);
    cnt[ip]++;
  }
  double tot = si(tree);
  sort(all(tree));
  tree.erase(unique(all(tree)), tree.end());
  for (auto& s : tree) cout << s << " " << cnt[s] / tot * 100 << "\n";
}