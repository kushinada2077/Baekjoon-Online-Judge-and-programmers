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

int n, dist[1000001];
queue<int> q;
int main() {
  fastio;
  cin >> n;
  fill(dist, dist + n + 1, -1);

  q.push(n);
  dist[n] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur < 1) continue;

    if (cur % 3 == 0 && dist[cur / 3] == -1) {
      q.push(cur / 3);
      dist[cur / 3] = dist[cur] + 1;
    }
    if (cur % 2 == 0 && dist[cur / 2] == -1) {
      q.push(cur / 2);
      dist[cur / 2] = dist[cur] + 1;
    }
    if (dist[cur - 1] == -1) {
      q.push(cur - 1);
      dist[cur - 1] = dist[cur] + 1;
    }
  }
  cout << dist[1] << "\n";
}