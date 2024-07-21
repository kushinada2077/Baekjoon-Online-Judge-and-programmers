#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define TUPLE tuple<int, int, int>
using namespace std;

int main() {
  fastio;
  int n;
  cin >> n;
  vector<bool> is_p(500, true);
  for (int i = 2; i * i <= 150; ++i) {
    for (int j = i * i; j <= 150; j += i) {
      is_p[j] = false;
    }
  }
  int pre = 2;

  for (int i = 3; i <= 150; ++i) {
    if (is_p[i] && pre * i > n) {
      cout << pre * i << "\n";
      break;
    }
    if (is_p[i]) pre = i;
  }
}