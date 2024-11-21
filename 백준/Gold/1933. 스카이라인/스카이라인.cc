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
priority_queue<P, vector<P>, greater<P>> pq;
set<int> dup;
map<int, int> hSet;
int main() {
  fastio;
  cin >> n;
  for (int l, h, r, i{}; i < n; ++i) {
    cin >> l >> h >> r;
    pq.push(P(l, -h));
    pq.push(P(r, h));
  }

  int he = 0;

  while (!pq.empty()) {
    auto [x, h] = pq.top();
    pq.pop();
    if (h < 0) {
      h *= -1;
      hSet[h]++;
    } else {
      hSet[h]--;
      if (hSet[h] == 0) hSet.erase(h);
    }

    if (hSet.empty()) {
      he = 0;
      cout << x << " " << he << " ";
      dup.insert(x);
    } else if (he != (*prev(hSet.end())).X && !dup.contains(x)) {
      he = (*prev(hSet.end())).X;
      cout << x << " " << he << " ";
      dup.insert(x);
    }
  }
}