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

int n, m, lo, hi, arr[100001];

bool f(int c) {
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > c) return 0;
    sum += arr[i];
    if (sum > c) {
      cnt++;
      sum = arr[i];
    }
  }

  return ++cnt <= m;
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    hi += arr[i];
  }

  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid)) hi = mid;
    else lo = mid;
  }

  cout << hi << "\n";
}