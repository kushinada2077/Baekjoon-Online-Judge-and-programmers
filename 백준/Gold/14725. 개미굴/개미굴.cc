#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MX = 500 * 15 + 5;
const int ROOT = 1;
int unused = 2;
unordered_map<string, int> nxt[MX];
string name[MX];
int depth[MX];

void insert(vector<string>& route) {
  int v = ROOT;
  for (auto r : route) {
    int nv = nxt[v][r];
    if (nv == 0) nv = nxt[v][r] = unused++;
    depth[nv] = depth[v] + 1;
    name[nv] = r;
    v = nv;
  }
}

void dfs(int v) {
  if (ROOT != v) {
    for (int i = 0; i < depth[v] - 1; ++i) cout << "--";
    cout << name[v] << "\n";
  }

  vector<pair<string, int>> m(nxt[v].begin(), nxt[v].end());
  sort(m.begin(), m.end());
  for (auto mm : m) dfs(mm.second);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  string s;
  cin >> n;
  while (n--) {
    cin >> k;
    vector<string> route;
    while (k--) {
      cin >> s;
      route.push_back(s);
    }
    insert(route);
  }

  dfs(ROOT);
}