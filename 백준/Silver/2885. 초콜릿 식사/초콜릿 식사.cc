#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int main() {
  fastio;
  int k;
  cin >> k;
  int size = 1, cnt = 0;
  while (size < k) {
    size *= 2;
    cnt++;
  }
  cout << size << " ";
  while (k > 0) {
    if (k % 2) {
      cout << cnt << "\n";
      break;
    }
    k /= 2;
    cnt--;
  }
}