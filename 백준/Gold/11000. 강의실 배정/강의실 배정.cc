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

int n;
priority_queue<int, vector<int>, greater<int>> pq;
P A[200010];
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i].X >> A[i].Y;
  sort(A, A + n);

  for (int i = 0; i < n; ++i) {
    auto [s, e] = A[i];
    if (pq.empty() || pq.top() > s) {
      pq.push(e);
    } else if (pq.top() <= s) {
      pq.pop();
      pq.push(e);
    }
  }

  cout << si(pq) << "\n";
}