#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int tc, k, _size = 1, t[50];
bool isPoss(int k) {
  for (int i = 1; i < _size; ++i) {
    for (int j = 1; j < _size; ++j) {
      for (int l = 1; l < _size; ++l) {
        if (t[i] + t[j] + t[l] == k) return 1;
      }
    }
  }
  return 0;
}
int main() {
  fastio;
  cin >> tc;
  for (int i = 1; (i + 1) * i / 2 <= 1000; ++i, ++_size) t[i] = (i + 1) * i / 2;
  while (tc--) {
    cin >> k;
    cout << isPoss(k) << "\n";
  }
}