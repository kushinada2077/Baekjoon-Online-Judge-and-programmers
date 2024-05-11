#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n;
ll m, lo, hi = 1e9, h;
vector<ll> trees;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (n--) {
    cin >> h;
    trees.push_back(h);
  }

  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    ll sum = 0;
    for (auto hei : trees) {
      sum += hei - mid > 0 ? hei - mid : 0;
    }
    if (sum >= m)
      lo = mid;
    else
      hi = mid;
  }

  cout << lo;
}