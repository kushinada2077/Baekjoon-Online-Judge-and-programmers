#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long ans = 0;
  multiset<int> bags;
  vector<pair<int, int>> jews;
  int n, k;
  cin >> n >> k;

  while (n--) {
    int m, v;
    cin >> m >> v;
    jews.push_back({v, m});
  }

  while (k--) {
    int c;
    cin >> c;
    bags.insert(c);
  }

  sort(jews.begin(), jews.end(), greater<pair<int, int>>());

  for (auto jew : jews) {
    int m, v;
    tie(v, m) = jew;
    auto iter = bags.lower_bound(m);

    if (iter != bags.end()) {
      ans += v;
      bags.erase(iter);
    }
  }

  cout << ans;
}