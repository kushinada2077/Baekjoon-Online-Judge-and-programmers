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

int n, d[100001];

// d[i] = i번째에서 시작했을 때 가장 큰 연속합
int main() {
  fastio;
  cin >> n;
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    d[i + 1] = max(x, d[i] + x);
  }
  cout << *max_element(d + 1, d + 1 + n) << "\n";
}