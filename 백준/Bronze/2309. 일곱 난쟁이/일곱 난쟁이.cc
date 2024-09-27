#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  vector<int> a(9);
  int sum = 0;
  for (auto& i : a) {
    cin >> i;
    sum += i;
  }
  sort(all(a));
  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j < 9; ++j) {
      sum -= a[i] + a[j];
      if (sum == 100) {
        for (int k = 0; k < 9; ++k) {
          if (k == i || k == j) continue;
          cout << a[k] << "\n";
        }
        return 0;
      }
      sum += a[i] + a[j];
    }
  }
}