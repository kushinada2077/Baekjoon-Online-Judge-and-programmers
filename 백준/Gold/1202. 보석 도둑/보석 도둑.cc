#define ll long long
#define PAIR pair<int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n, k, m, v, ans = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> bag;
  priority_queue<PAIR, vector<PAIR>, greater<PAIR>> jew;
  priority_queue<PAIR> val;
  ll ans = 0;
  while (n--) {
    cin >> m >> v;
    jew.push({m, v});
  }
  while (k--) {
    cin >> m;
    bag.push(m);
  }

  while (!bag.empty()) {
    int b = bag.top();
    bag.pop();
    while (!jew.empty() && jew.top().first <= b) {
      auto [m, v] = jew.top();
      jew.pop();
      val.push({v, m});
    }
    if (!val.empty()) {
      ans += val.top().first;
      val.pop();
    }
  }
  cout << ans;
}