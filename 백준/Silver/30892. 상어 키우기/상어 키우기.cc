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

ll n, k, t, a[300000];
priority_queue<ll> pq;
int main() {
  fastio;
  cin >> n >> k >> t;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < t) pq.push(a[i]);
  }

  sort(a, a + n);
  ll idx = 0, cnt = 0;

  while (a[idx] < t) idx++;
  while (!pq.empty() && cnt < k) {
    t += pq.top();
    pq.pop();
    cnt++;
    while (idx < n && a[idx] < t) {
      pq.push(a[idx]);
      idx++;
    }
  }

  cout << t << "\n";
}